#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ext/stdio_filebuf.h>
#include <dirent.h>
#include <pwd.h>
#include <vector> 
#include <sys/vfs.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/wait.h>

using namespace std;
bool logat=0;


struct UserData
{
	string Name;
	string Password;
	string nrQ;
	string Question;
	string Answer;
}userdata;

struct Recover
{
	string user;
	string pass;
	string nrq;
	string quest;
	string ans;
}recoverdata;

string realQuestion(string NrQ)
{
	ifstream Rq("secretquestions.txt");
	string nrQ, RealQ;
	while(!Rq.eof())
	{
		Rq>>nrQ;
		getline(Rq,RealQ);
		if(nrQ==NrQ)
		{
			return RealQ;
		}
	}
	Rq.close();
	return NULL;
}

bool fillstruct(string N, string P, string nr, string A)//, int nr, string ANS)
{
	//string N, P, nr, A;
	//ifstream infifo(userfifo);
	//infifo>>N>>P>>nr;
	//getline(infifo,A);
	//infifo.close();
	userdata.Name=N;
	userdata.Password=P;
	userdata.nrQ=nr;
	userdata.Answer=A;
	userdata.Answer.erase(0,2);
	userdata.Question=realQuestion(nr);
	return true;
}

bool printUserData()
{
	cout<<"User: "<<userdata.Name<<'\n';
	cout<<"Password: "<<userdata.Password<<'\n';
	cout<<"Secret question: "<<userdata.Question<<'\n';
	cout<<"Answer: "<<userdata.Answer<<"\n";
	return true;
}

bool printRecoverData()
{
	cout<<"User: "<<recoverdata.user<<'\n';
	cout<<"Password: "<<recoverdata.pass<<'\n';
	cout<<"Secret question: "<<recoverdata.quest<<'\n';
	cout<<"Answer: "<<recoverdata.ans<<"\n";
	return true;
}

void reverseStr(string &str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

char* string_to_char(string str)
{
	unsigned int poz;
	char* mychar=new char[str.size()*sizeof(char)+1];
	for(poz=0; poz<str.size(); poz++)
	{
		mychar[poz]=str.at(poz);
		mychar[poz+1]='\0';
	}
	return mychar;
}

bool search_in_file_user(string data)
{
	string match, inf1, inf3;
	string inf2;
	//string alldata;
	ifstream in("config.txt");
	while (!in.eof())
	{
		match.clear();
		in>>match;
		if(match==data)
		{
			inf1.clear(); inf2.clear();
			in>>inf1; in>>inf2;
			getline(in,inf3);
			//alldata=match+' '+inf1+' '+inf2+' '+inf3;
			//ofstream outfifo(userfifo);
			//outfifo<<alldata;
			//outfifo.close();
			fillstruct(match,inf1,inf2,inf3);
			return true;
		}
		in>>inf1; in>>inf2;
		getline(in,inf3);
	}
	in.close();
	return false;
}

bool search_for_passwd(string data, string user)
{
	string match; 
	string nothing, nothing2, nothing3;
	ifstream in("config.txt");
	while (!in.eof())
	{
		in>>nothing;
		in>>match;
		if(nothing==user)
			if(match==data)
				return true;
		in>>nothing2;
		getline(in,nothing3);
	}
	in.close();
	return false;
}

bool sq_for_recover_password(string UUU)
{
	string iuser, ipass, inr, ianswer;
	ifstream recpass("config.txt");
	while (!recpass.eof())
	{
		iuser.clear();
		recpass>>iuser;
		if(iuser==UUU)
		{
			ipass.clear(); inr.clear();
			recpass>>ipass>>inr;
			getline(recpass,ianswer);
			ianswer.erase(0,1);
			recoverdata.user=iuser;
			recoverdata.pass=ipass;
			recoverdata.nrq=inr;
			recoverdata.quest=realQuestion(inr);
			recoverdata.ans=ianswer;
			return true;
		}
		recpass>>ipass>>inr;
		getline(recpass,ianswer);
	}
	recpass.close();
	return false;
}

bool MakeParams(char *command, string &file, char *params)
{
	unsigned int p=0, f, r=0;
	char reverse[30];
	if(strchr(command,' '))
	{
		if(command[0]!='m' || command[1]!='y' || command[2]!='i' || command[3]!='n' || command[4]!='f' || command[5]!='o' ||command[6]!=' ')
			return false;
	}
	else
	{
		string copie(command);
		file=copie;
		strcpy(params,"tamsrugn");
		return true;
	}
	if(strstr(command,"-t"))
		params[p++]='t';
	if(strstr(command,"-a"))
		params[p++]='a';
	if(strstr(command,"-m"))
		params[p++]='m';
	if(strstr(command,"-s"))
		params[p++]='s';
	if(strstr(command,"-r"))
		params[p++]='r';
	if(strstr(command,"-u"))
		params[p++]='u';
	if(strstr(command,"-g"))
		params[p++]='g';
	if(strstr(command,"-n"))
		params[p++]='n';
	f=strlen(command)-1;
	while(command[f]!=' ')
	{
		reverse[r++]=command[f];
		reverse[r]='\0';
		f--;
	}
	string rev(reverse);
	reverseStr(rev);
	file=rev;
	return true;
}

string ShowDetails(char* file, char* myfile)
//void ShowDetails(char* file, char* myfile)
{
	struct stat status;
    struct passwd *username;       
    char permisiuni[10]="---------";  
    string strforpipe="\n\t   Informatii despre fisierul \n\t\t";

    if(stat(file,&status)!=0 )
    {
       cout<<"Eroare la stat pentru fisierul: "<<myfile<<'\n';
        perror("Motivul erorii: ");
        //return; 
    }
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    //cout<<"\n\t    Informatii despre fisierul\n\t\t "<<blue<<myfile<<"\n\n";
    string temp(myfile);
    strforpipe+=temp;
    strforpipe+="\n\n";
    //cout<<normal<<"\tTipul acestui fisier: ";
    strforpipe+="\tTipul acestui fisier: ";
    switch(status.st_mode & S_IFMT)
    {
        case S_IFSOCK: 
        	//cout<<"Socket\n"; 
        	strforpipe+="Socket\n";
        	break;
        case S_IFLNK : 
        	//cout<<"Link\n";
        	strforpipe+="Link\n";
        	break;
        case S_IFREG : 
        	//cout<<"Fisier obisnuit\n";
        	strforpipe+="Fisier obisnuit\n";
        	break;
        case S_IFBLK : 
        	//cout<<"Block device\n"; 
        	strforpipe+="Block device\n";
        	break;
        case S_IFCHR : 
        	//cout<<"Character device\n"; 
        	strforpipe+="Character device\n";
        	break;
        case S_IFIFO : 
        	//cout<<"Fisier FIFO\n"; 
        	strforpipe+="Fisier FIFO\n";
        	break;
        case S_IFDIR : 
        	//cout<<"Director\n"; 
        	strforpipe+="Director\n";
        	break;
        default: 
        	//cout<<"Tip necunoscut\n";
        	strforpipe+="Tip necunoscut\n";
    }

    //cout<<"\tUltima accesare: "<<ctime(&status.st_atime);
    //cout<<"\tUltima modificare: "<<ctime(&status.st_mtime);
    strforpipe+="\tUltima accesare: ";
    strforpipe+=ctime(&status.st_atime);//.to_string();
    strforpipe+="\tUltima modificare: ";
    strforpipe+=ctime(&status.st_mtime);//.to_string();
    ////cout<<"\tData crearii: "<<ctime(&status.st_birthtimespec); - working progress

    //cout<<"\tDimensiunea: "<<status.st_size<<" octeti\n";
   	strforpipe+="\tDimensiunea: ";
    //char* tempdim;
   // sprintf(tempdim,"%s",status.st_size);
    //string tempdimstr(tempdim);
    //strforpipe+=tempdimstr;
    strforpipe+=status.st_size;
    strforpipe+=" octeti\n";
    if(S_IRUSR & status.st_mode) permisiuni[0]='r';
    if(S_IWUSR & status.st_mode) permisiuni[1]='w';
    if(S_IXUSR & status.st_mode) permisiuni[2]='x';
    if(S_IRGRP & status.st_mode) permisiuni[3]='r';
    if(S_IWGRP & status.st_mode) permisiuni[4]='w';
    if(S_IXGRP & status.st_mode) permisiuni[5]='x';
    if(S_IROTH & status.st_mode) permisiuni[6]='r';
    if(S_IWOTH & status.st_mode) permisiuni[7]='w';
    if(S_IXOTH & status.st_mode) permisiuni[8]='x';

    //cout<<"\tPermisiunile: "<<permisiuni<<'\n';
    strforpipe+="\tPermisiunile: ";
    string tempp(permisiuni);
    strforpipe+=tempp;
    strforpipe+="\n";

    if((username=getpwuid(status.st_uid))!=NULL)
    {
		//cout<<"\tUsername-ul proprietarului: "<<username->pw_name<<'\n';
    	strforpipe+="\tUsername-ul proprietarului: ";
    	string tempu(username->pw_name);
    	strforpipe+=tempu;
    	strforpipe+='\n';
    }
    else
    {
    	//cout<<"\tProprietarul are UID-ul: "<<status.st_uid<<'\n';
    	strforpipe+="\tProprietarul are UID-ul ";
    	strforpipe+=status.st_uid;//.to_string();
    	strforpipe+='\n';
    }
    return strforpipe;
}

bool Check_Archive(string path, string &arhive) //done
{
	char cpath[200];
	strcpy(cpath,string_to_char(path));
	bool arhiva=false;
	vector <char*> archlist={
		(char*)".a", (char*)".ar", (char*)".cpio", (char*)".shar", (char*)".LBR",
		(char*)".iso", (char*)".lbr", (char*)".mar", (char*)".sbx", (char*)".tar"
	};

	vector <char*> compresslist={
		(char*)".bz2", (char*)".F", (char*)".?XF", (char*)".gz", (char*)".lz", 
		(char*)".lzma", (char*)".lzo", (char*)".sfark", (char*)".sz", (char*)".?Q?",
		(char*)".?Z?", (char*)".xz", (char*)".z", (char*)".Z", (char*)".??_"
	};

	vector <char*> archcomplist={
		(char*)".7z", (char*)".s7z", (char*)".ace", (char*)".afa", (char*)".alz",
		(char*)".apk", (char*)".arc", (char*)".arj", (char*)".b1", (char*)".b6z",
		(char*)".ba", (char*)".bh", (char*)".cab", (char*)".car", (char*)".cfs",
		(char*)".cpt", (char*)".dar", (char*)".dd", (char*)".dgc", (char*)".dmg",
		(char*)".ear", (char*)".gca", (char*)".ha", (char*)".hki", (char*)".ice",
		(char*)".jar", (char*)".kgb", (char*)".lzh", (char*)".lha", (char*)".lzx",
		(char*)".pak", (char*)".partimg", (char*)".paq6", (char*)".paq7", (char*)".paq8",
		(char*)".pea", (char*)".pim", (char*)".pit", (char*)".qda", (char*)".rar",
		(char*)".rk", (char*)".sda", (char*)".sea", (char*)".sen", (char*)".sfx",
		(char*)".shk", (char*)".sit", (char*)".sitx", (char*)".sqx", (char*)".tar.gz",
		(char*)".tgz", (char*)".tar.Z", (char*)".tar.bz2", (char*)".tbz2", (char*)".tar.lzma",
		(char*)".tlz", (char*)".tar.xz", (char*)".txz", (char*)".uc", (char*)".uc0",
		(char*)".uc2", (char*)".ucn", (char*)".ur2", (char*)".ue2", (char*)".uca",
		(char*)".uha", (char*)".war", (char*)".wim", (char*)".xar", (char*)".xp3",
		(char*)".yz1", (char*)".zip", (char*)".zipx", (char*)".zoo", (char*)".zpaq",
		(char*)".zz"
	};

	vector <char*> datarecoverylist=
	{
		(char*)".ecc", (char*)"par", (char*)".par2", (char*)".rev"
	};

	for (auto arch : archlist)
	{
		if(strstr(cpath,arch))
		{	
			arhiva=true;
			arhive="Fisierul ";
			arhive+=path;
			arhive+=" este de tipul Arhiva\n";
			arhive+="Extensia sa este specifica pentru 'Arhive Only'\n";
			//cout<<"Fisierul "<<path<<" este de tipul Arhiva\n";
			//cout<<"Extensia sa este specifica pentru 'Archive Only'\n";
			break;
		}
	} 
	if(arhiva==false)
	{
		for (auto compress : compresslist)
		{
			if(strstr(cpath,compress))
			{	
				arhiva=true;
				arhive="Fisierul ";
				arhive+=path;
				arhive+=" este de tipul Arhiva\n";
				arhive+="Extensia sa este specifica pentru 'Compression Only'\n";
				//cout<<"Fisierul "<<path<<" este de tipul Arhiva\n";
				//cout<<"Extensia sa este specifica pentru 'Compression Only'\n";
				break;
			}
		} 
		if(arhiva==false)
		{
			for (auto archcomp : archcomplist)
			{
				if(strstr(cpath,archcomp))
				{	
					arhiva=true;
					arhive="Fisierul ";
					arhive+=path;
					arhive+=" este de tipul Arhiva\n";
					arhive+="Extensia sa este specifica pentru 'Archiving and Compression'\n";
					//cout<<"Fisierul "<<path<<" este de tipul Arhiva\n";
					//cout<<"Extensia sa este specifica pentru 'Archiving and compression'\n";
					break;
				}
			}
			if(arhiva==false)
			for (auto recov : datarecoverylist)
				{
					if(strstr(cpath,recov))
					{	
						arhiva=true;
						arhive="Fisierul ";
						arhive+=path;
						arhive+=" este de tipul Arhiva\n";
						arhive+="Extensia sa este specifica pentru 'Data Recovery'\n";
						//cout<<"Fisierul "<<path<<" este de tipul Arhiva\n";
						//cout<<"Extensia sa este specifica pentru 'Data Recovery'\n";
						break;
					}
				}
		} 
	}
	if(arhiva==true)
		return true;
	else
		//cout<<"Fisierul nu este de tip Arhiva!\n";
		arhive+="Fisierul nu este de tip Arhiva!\n";
	return false;
}

bool Check_Perm(string path, string &perm) //done
{
	struct stat status;
	bool u=false, g=false, o=false;
	char permissions[10]="---------";
	char filestat[200];
	strcpy(filestat,string_to_char(path));

	if(stat(filestat, &status)!=0)
	{
		cout<<"Eroare la deschiderea fisierului "<<filestat<<'\n';
		perror("Cauza aparitiei erorii: ");
		return false;
	}
    if(S_IRUSR & status.st_mode) permissions[0]='r';
    if(S_IWUSR & status.st_mode) permissions[1]='w';
    if(S_IXUSR & status.st_mode) permissions[2]='x';
    if(S_IRGRP & status.st_mode) permissions[3]='r';
    if(S_IWGRP & status.st_mode) permissions[4]='w';
    if(S_IXGRP & status.st_mode) permissions[5]='x';
    if(S_IROTH & status.st_mode) permissions[6]='r';
    if(S_IWOTH & status.st_mode) permissions[7]='w';
    if(S_IXOTH & status.st_mode) permissions[8]='x';
    //cout<<"Permisiunile fiserului "<<path<<" sunt: \n";
    //cout<<"\tUser:\n";
    perm="Permisiunile fisierului ";
    perm+=path;
    perm+=" sunt: \n";
    perm+="\tUser:\n";
    if(permissions[0]=='r' && permissions[1]=='-' && permissions[2]=='-')
    {
    	perm+="\t\tRead Only\n";
   		//cout<<"\t\tRead Only\n";
   		u=true;
   	}
    if(permissions[0]=='-' && permissions[1]=='w' && permissions[2]=='-')
    {	
    	perm+="\t\tWrite Only\n";
    	//cout<<"\t\tWrite Only\n";
    	u=true;
    }
    if(permissions[0]=='-' && permissions[1]=='-' && permissions[2]=='x')
    {
    	perm+="\t\tExecute Only\n";
    	//cout<<"\t\tExecute Only\n";
    	u=true;
    }
    if(u==false)
    {
    	if(permissions[0]=='r')
    		perm+="\t\t-Read\n";
    		//cout<<"\t\t-Read\n";
    	if(permissions[1]=='w')
    		perm+="\t\t-Write\n";
    		//cout<<"\t\t-Write\n";
    	if(permissions[2]=='x')
    		perm+="\t\t-Execute\n";
    		//cout<<"\t\t-Execute\n";
    }
    perm+="\tGroup:\n";
    //cout<<"\tGroup:\n";
    if(permissions[3]=='r' && permissions[4]=='-' && permissions[5]=='-')
    {
    	perm+="\t\tRead Only\n";
   		//cout<<"\t\tRead Only\n";
   		g=true;
   	}
    if(permissions[3]=='-' && permissions[4]=='w' && permissions[5]=='-')
    {
    	perm+="\t\tWrite Only\n";
    	//cout<<"\t\tWrite Only\n";
    	g=true;
    }
    if(permissions[3]=='-' && permissions[4]=='-' && permissions[5]=='x')
    {
    	perm+="\t\tExecute Only\n";
    	//cout<<"\t\tExecute Only\n";
    	g=true;
    }
    if(g==false)
    {
    	if(permissions[3]=='r')
    		perm+="\t\t-Read\n";
    		//cout<<"\t\t-Read\n";
    	if(permissions[4]=='w')
    		perm+="\t\t-Write\n";
    		//cout<<"\t\t-Write\n";
    	if(permissions[5]=='x')
    		perm+="\t\t-Execute\n";
    		//cout<<"\t\t-Execute\n";
    }
    perm+="\tOthers:\n";
    //cout<<"\tOthers:\n";
    if(permissions[6]=='r' && permissions[7]=='-' && permissions[8]=='-')
    {
    	perm+="\t\tRead Only\n";
   		//cout<<"\t\tRead Only\n";
   		o=true;
   	}
    if(permissions[6]=='-' && permissions[7]=='w' && permissions[8]=='-')
    {
    	perm+="\t\tWrite Only\n";
    	//cout<<"\t\tWrite Only\n";
    	o=true;
    }
    if(permissions[6]=='-' && permissions[7]=='-' && permissions[8]=='x')
    {
    	perm+="\t\tExecute Only\n";
    	//cout<<"\t\tExecute Only\n";
    	o=true;
    }
    if(o==false)
    {
    	if(permissions[6]=='r')
    		perm+="\t\t-Read\n";
    		//cout<<"\t\t-Read\n";
    	if(permissions[7]=='w')
    		perm+="\t\t-Write\n";
    		//cout<<"\t\t-Write\n";
    	if(permissions[8]=='x')
    		perm+="\t\t-Execute\n";
    		//cout<<"\t\t-Execute\n";
    }
    return true;
}

bool Check_Hidden(string path, string &hid)
{
	if(path[0]=='.')
	{
		//cout<<"Fisierul "<<path<<" este de tip 'HIDDEN'\n";
		hid="Fisierul ";
		hid+=path;
		hid+=" este de tip 'HIDDEN'\n";
		return true;
	}
	return false;
}

bool Check_System(string path)
{
	struct statfs sf;
	char filesf[200];
	strcpy(filesf,string_to_char(path));
	if(statfs(filesf, &sf)!=0)
	{
		cout<<"Eroare la deschiderea fisierului "<<filesf<<'\n';
		perror("Cauza aparitiei erorii: ");
		return false;
	}
	//cout<<"File Type: "<<sf.f_type<<'\n';
	return true;
}

bool LOGIN()
{
	string user, password;
	cout<<"Pentru a deschide aplicatia va trebuie sa te loghezi\n";
	cout<<"User: ";	
	cin>>user;
	if(!search_in_file_user(user))
	{
		cout<<"Wrong user\n";
		return false;
	}
	cout<<"Password: ";
	cin>>password;
	if(!search_for_passwd(password,user))
	{
		cout<<"Wrong password\n";
		return false;
	}
	logat=1;
	return true;
}

bool REGISTER()
{
	string user, password, answer;
	string check;
	string nrq;
	cout<<"Creare user nou\n";
	cout<<"New User: ";
	//inregistrare user
	cin>>user;
	while(search_in_file_user(user)) // verificare daca userul este deja introdus in sistem
	{
		cout<<"User deja existent\n";
		cout<<"Introduceti LOGIN daca vreti sa va autentificati cu acest user\n";
		cout<<"Introduceti EXIT daca vreti sa va renuntati\n";
		cout<<"Introduceti TRY daca vreti sa incercati din nou\n";
		cin>>check;
		if(check=="TRY" || check=="try")
		{
			cout<<"New User: ";
			user='\0';
			cin>>user;
		}
		else if(check=="LOGIN" || check=="login")
		{
			cout<<"Te vei autentifica cu userul ";
			cout<<user;
			cout<<"\nPassword: ";
			cin>>password;
			if(!search_for_passwd(password,user))
			{
				cout<<"Wrong password\n";
				return false;
			}
			else
			{	
				logat=1;
				return true;
			}
		}
		else
			return false;
	}
	//inregistrare parola
	cout<<"Password: ";
	cin>>password;

	//inregistrare intrebare secreta
	ofstream out("config.txt", std::fstream::app);
	cout<<"Alege o intrebare secreta, scriind numarul ei in linia de comanda: \n";
	ifstream isq("secretquestions.txt");
	char temp[100];
	while(!isq.eof())
	{
		isq.get(temp,99);
		isq.get();
		cout<<temp<<endl;
	}
	isq.close();
	cin>>nrq;
	cout<<"Raspunsul tau pentru intrebarea secreta: \n";
	cin.ignore();
	std::getline(std::cin , answer);
	
	out<<'\n'<<user<<'\t'<<password<<'\t'<<nrq<<'\t'<<answer;
	out.close();

	//start_check 
	if(!search_in_file_user(user))
	{
		cout<<"A aparut o eroare la inregistrare\n";
		return false;
	}
	else
	{
		cout<<"Userul a fost creat cu succes\n";
		//LOGIN();
		return true;
	}
	//end_check

	return false;
} 

bool FORGET_PASSWORD()
{
	string USER, ANSWER;
	cout<<"Ti-ai uitat parola? Te putem ajuta sa o recuperezi\n";
	cout<<"Ai nevoie de user si de raspunsul la intrebarea ta secreta\n";
	cout<<"User: ";
	cin>>USER;
	if(!sq_for_recover_password(USER))
	{
		cout<<"Acest user nu exista. \n";
		return false;
	}
	cout<<"Va trebui sa raspunzi corect la intrebarea ta secreta pentru a-ti putea reacupera parola\n";
	cout<<"Intrebare secreta: \n";
	cout<<recoverdata.quest<<'\n';
	cout<<"Raspuns: ";
	cin.ignore();
	std::getline(std::cin , ANSWER);
	if(ANSWER==recoverdata.ans)
	{
		cout<<"Parola ta este: "<<recoverdata.pass<<'\n';
		return true;
	}
	else
	{
		cout<<"Raspuns gresit \n";
		return false;
	}
}

bool MYFIND(char* myfile, char* file, char* currfile, short &nr, string &detalii)
{
	DIR *desc;
	struct dirent *director;
	struct stat status;
	char newfile[250];
	if(!strcmp(myfile,currfile))
	{
		cout<<"Fisierul cautat ('"<<myfile<<"') a fost gasit in locatia:\n";
		cout<<file<<'\n';
		nr++; //numara cate fisiere a gasit ->in caz de o sa fie nevoie
		detalii=ShowDetails(file, myfile);
	}
	if(stat(file, &status)!=0)
	{
		//cout<<"Eroare la stat pentru fisierul: "<<file<<'\n';
		//perror("Motivul erorii: ");
		return false;
	}

	if(S_ISDIR(status.st_mode))
	{
		desc=opendir(file);
		if(desc==NULL)
		{
			//cout<<"Eroare la deschiderea directorului: "<<file<<'\n';
			//perror("Motivul erorii: ");
			return false;
		}
		while((director=readdir(desc))!=NULL)
		{
			if( strcmp(director->d_name,".") && strcmp(director->d_name,"..") )
			{
				sprintf(newfile,"%s/%s",file,director->d_name);			
				sprintf(currfile,"%s",director->d_name);
				//cout<<myfile<<'\n'<<newfile<<'\n'<<currfile<<"\n\n"; //--test variabile
				MYFIND(myfile, newfile, currfile, nr, detalii);
			}
		}
		closedir(desc);
	}
	if(nr)
		return true;
	return false;
}

bool MYINFO(string fisierstring, char *params, char *director)
{
	struct stat atr;
	struct passwd *userinfo;
	char rights[10]="---------"; 
	char fisier[50];
	strcpy(fisier,string_to_char(fisierstring));
	if(stat(fisier, &atr)!=0)
	{
		cout<<"Eroare la deschiderea fisierului "<<fisier<<'\n';
		perror("Cauza aparitiei erorii: ");
		return false;
	}
	userinfo=getpwuid(atr.st_uid);
	for(unsigned int i=0; i<8; i++)
		if(params[i]!='*')
			switch(params[i])
			{
				case 't': //type
					cout<<"\tTipul acestui fisier: ";
					switch(atr.st_mode & S_IFMT)
    				{
        				case S_IFSOCK: 
        					cout<<"Socket\n"; 
        					break;
        				case S_IFLNK : 
        					cout<<"Link\n";
				        	break;
				        case S_IFREG : 
				        	cout<<"Fisier obisnuit\n";
				        	break;
				        case S_IFBLK : 
				        	cout<<"Block device\n"; 
				        	break;
				        case S_IFCHR : 
				        	cout<<"Character device\n"; 
				        	break;
				        case S_IFIFO : 
				        	cout<<"Fisier FIFO\n"; 
				        	break;
				        case S_IFDIR : 
				        	cout<<"Director\n"; 
				        	break;
				        default: 
				        	cout<<"Tip necunoscut\n";
				    }
				    break;
				case 'a': //last time acces
					cout<<"\tUltima accesare: "<<ctime(&atr.st_atime); 
					break;
				case 'm': //last time modiffied
					cout<<"\tUltima modificare: "<<ctime(&atr.st_mtime); 
					break;
				case 's': //Size
					cout<<"\tDimensiunea: "<<atr.st_size<<" octeti\n";
					break;
				case 'r':
					if(S_IRUSR & atr.st_mode) rights[0]='r';
					if(S_IWUSR & atr.st_mode) rights[1]='w';
				    if(S_IXUSR & atr.st_mode) rights[2]='x';
				    if(S_IRGRP & atr.st_mode) rights[3]='r';
				    if(S_IWGRP & atr.st_mode) rights[4]='w';
				    if(S_IXGRP & atr.st_mode) rights[5]='x';
				    if(S_IROTH & atr.st_mode) rights[6]='r';
				    if(S_IWOTH & atr.st_mode) rights[7]='w';
				    if(S_IXOTH & atr.st_mode) rights[8]='x';
					cout<<"\tPermisiunile: "<<rights<<'\n'; //Rights
					break;
				case 'u': //uid
					cout<<"\tUID: "<<atr.st_uid<<'\n';
					break;
				case 'g': //gid
					cout<<"\tGID: "<<userinfo->pw_gid<<'\n';
					break;
				case 'n': //username
					cout<<"\tUsername-ul proprietarului: "<<userinfo->pw_name<<'\n';
					break;
				default:
					break;

			}
	return true;
}

bool MYSTAT(string PATH, string &final)
{
	bool Archive=false, Perm=false, Hidden=false, System=false;
	struct stat statuscheck;
	if(stat(PATH.c_str(), &statuscheck)!=0)
	{
		cout<<"Eroare la deschiderea fisierului "<<PATH<<'\n';
		perror("Cauza aparitiei erorii: ");
		return false;
	}
	string arc, rights, hidd;
	Archive=Check_Archive(PATH,arc);
	Perm=Check_Perm(PATH,rights);
	Hidden=Check_Hidden(PATH,hidd);
	System=Check_System(PATH);
	final="\t\tMySTAT: \n";
	if(Archive==true||Perm==true||Hidden==true||System==true)
	{
		if(Archive==true)
			final+=arc;
		else
			final+="\tFisierul NU este de tip arhiva!\n";
		if(Perm==true)
			final+=rights;
		if(Hidden=true)
			final+=hidd;
		else
			final+="\tFisierul NU este de tip HIDDEN\n";
		return true;
	}
	return false;
}

int main()
{
	//canale comunicatie
	int p1[2], p2[2];
	int sp[2];
	if(pipe(p1)==-1)
	{
		perror("Eroare la crearea primului pipe, motiv: ");
		exit(0);
	}
	if(pipe(p2)==-1)
	{
		perror("Eroare la crearea pipeului al doilea, motiv: ");
		exit(1);
	}
	
	pid_t fiu=fork();
	if(fiu==-1)
	{
		perror("Eroare la crearea procesului fiului, motiv: ");
		exit(2);
	}
	if(fiu==0)//proces fiu pentru comenzi
	{
		close(p2[0]);
		close(p1[1]); //inchidem capat scriere pentru fiu, p1
		char* FileName=new char(100);
		char CurentFile[250]="\0";
		short count=0;
		string output;
		char *outputchr=new char [2048];
		if(read(p1[0],FileName,100)<0)
			perror("Eroare la read-pipe1 myfind in procesul fiu, motiv: ");
		close(p1[0]);
		if(FileName[0]=='d')
			exit(0);
		if(!MYFIND(FileName, (char*)"/home", CurentFile, count, output))
		{
			cout<<"Fisierul "<<FileName<<" nu a fost gasit!\n";
			close(p2[1]);
		}
		else
		{
			outputchr=string_to_char(output);
			write(p2[1],outputchr,2048);
			close(p2[1]);
		}
		
	}
	else
	{		
		if (socketpair(AF_LOCAL, SOCK_STREAM, 0, sp) < 0) 
      	{ 
        	perror("Eroare la socketpair!, motiv: ");
        	return 0;
      	}
		pid_t fiulogin=fork();
		if(fiulogin==-1)
		{
			perror("Eroare la crearea procesului fiului pentru login, motiv: ");
			exit(2);
		}
		if(fiulogin==0)//proces pentru login
		{
			close(p1[0]);
			close(p1[1]);
			close(p2[0]);
			close(p2[1]);
			close(sp[1]); //inchidem capatul pentru tata
			char* commlogin=new char(30);
			char complete[30]="Autentificare completa";
			char no[30]="Autentificare esuata";
			char wrong[20]="Comanda gresita";
			if(read(sp[0],commlogin,30)<0)
				perror("Eroare la read (login), in procesul fiu, motiv: ");
			if(strstr(commlogin, (char*)"login") || strstr(commlogin, (char*)"LOGIN"))
			{
				if(LOGIN())
				{
					if(write(sp[0],complete,sizeof(complete))<0)
						perror("Eroare la write-complete (login), in procesul fiu, motiv: ");
				}
				else if(write(sp[0],no,sizeof(no))<0)
					perror("Eroare la write-fail (login), in procesul fiu, motiv: ");
			}
			else if(strstr(commlogin, (char*)"register") || strstr(commlogin,(char*)"REGISTER"))
			{
				REGISTER();
				if(LOGIN())
				{
					if(write(sp[0],complete,sizeof(complete))<0)
						perror("Eroare la write-complete (login), in procesul fiu, motiv: ");
				}
				else if(write(sp[0],no,sizeof(no))<0)
					perror("Eroare la write-fail (login), in procesul fiu, motiv: ");
			}
			else if(strstr(commlogin, (char*)"password") || strstr(commlogin, (char*)"PASSWORD"))
			{
				FORGET_PASSWORD();
				if(LOGIN())
				{
					if(write(sp[0],complete,sizeof(complete))<0)
						perror("Eroare la write-complete (login), in procesul fiu, motiv: ");
				}
				else if(write(sp[0],no,sizeof(no))<0)
						perror("Eroare la write-fail (login), in procesul fiu, motiv: ");
			}
			else if(strstr(commlogin, (char*)"quit") || strstr(commlogin,(char*)"QUIT"))
			{
				cout<<"Programul se va inchide/n";
				return 0;
			}
			else
			{
				if(write(sp[0],wrong,sizeof(wrong))<0)
					{
						perror("Eroare la write-complete (login), in procesul fiu, motiv: ");
						exit(0);
					}
				else
					exit(0);
			}
			close(sp[0]); //inchidem capatul pentru fiu
		}
		else //proces tata
		{
			close(p1[0]); //inchidem capat citire pentru tata, p1
			close(p2[1]);//inchidem capat scriere pentru tata, p1
			close(sp[0]); //inchidem capatul pentru fiu;
			char *login;
			char statuslogin[30];
			string input;
			bool confirm=false;
			cout<<"Aceasta este aplicatia pentru tema 1.\n";
			cout<<"Pentru a continua va trebui sa te autentifici\n";
			cout<<"Introdu comanda corespunzatoare actiunii pe care doresti s-o faci\n";
			cout<<"\t LOGIN - autentificare\n";
			cout<<"\t REGISTER - inregistrare utilizator nou\n";
			cout<<"\t PASSWORD - recuperare parola pierduta\n";
			cout<<"\t QUIT - inchidere program\n";
			std::getline(std::cin,input);
			login=string_to_char(input);
			if(write(sp[1],login,sizeof(login))<0)
				perror("Eroare la write (login) in procesul parinte, motiv: ");
			if(read(sp[1],statuslogin,30)<0)
				perror("Eroare la read (login) in procesul parinte: ");
			if(strstr(statuslogin,(char*)"compl"))
			{
				cout<<"Autentificare completa. Acum puteti executa o comanda\n";
				confirm=true;
			}
			else if(strstr(statuslogin,(char*)"esuat"))
			{
				cout<<"Autentificare gresita. Programul se va incheia\n";
				exit(0);
			}
			close(sp[1]); //inchidem capatul pentru tata
			string input2;
			char *command;
			if(confirm==false)
				exit(0);
			cout<<"Introduceti comanda pe care vreti sa o folositi! Optiuni:\n";
			cout<<"\tMYFIND\n";
			cout<<"\tMYSTAT\n";
			cout<<"\tMYINFO\n";
			cout<<"\tQUIT\n";
			std::getline(std::cin,input2);
			command=string_to_char(input2);
			if(strstr(command,(char*)"MYFIND") || strstr(command,(char*)"myfind"))
			{
				string FileForSearch;
				char* FileName;
				cout<<"Introduceti fisierul pe care vreti sa il cautati\n";
				std::getline(std::cin,FileForSearch);
				//FileName=new char[FileForSearch.size()*sizeof(char)+1];
				FileName=string_to_char(FileForSearch);
				if(write(p1[1],FileName,100)<0)
					perror("Eroare la write (pipe1-myfind) in procesul parinte, motiv: ");
				char *line=new char[2048];
				close(p1[1]);
				if(read(p2[0],line,2048)<0)
					perror("Eroare la read (pipe-myfind) in procesul parinte, motiv: ");
				cout<<line;
				close(p2[0]);
				 //inchidem capat citire pentru tata, p1
			}
			else if(strstr(command,(char*)"MYINFO") || strstr(command,(char*)"myinfo"))
			{
					char parametri[10]="********";
					char *Read;
					string filename;
					char start[5]=".";
					string stringread;
					cout<<"Introduceti comanda: \n";
					cout<<"Exemplu: <myinfo -t -g numefisier>\n";
					cout<<"Nota:\n\tPuteti introduceti doar numele fisierului/calea daca vreti sa afisati toate detaliile disponibile despre acel fisier\n";
					//cin.ignore();
					std::getline(std::cin,stringread);
					Read=string_to_char(stringread);
					if(MakeParams(Read,filename,parametri))
					{
						MYINFO(filename,parametri,start);
					}
					else
						cout<<"Comanda gresita";
			}
			else if(strstr(command,(char*)"MYSTAT") || strstr(command, (char*)"mystat"))
			{
				char* statfifo = (char*)"stat.txt";
				mkfifo(statfifo,0766);
				int pstat[2];
				if(pipe(pstat)==-1)
				{
					perror("Eroare la crearea pipe ului pentru stat, motiv: ");
					exit(0);
				}
				pid_t statfork=fork();
				if(statfork==-1)
				{
					perror("Eroare la crearea procesului fiu pentru stat, motiv: ");
					exit(0);
				}
				if(statfork==0) //fiu
				{
					close(pstat[1]);
					char *nameoffile=new char[100];
					if(read(pstat[0],nameoffile,100)<0)
					{
						perror("Eroare la citirea din pipestat, motiv: ");
						exit(0);
					}
					close(pstat[0]);
					string forfifo;
					char *fifochar=new char [2048];
					MYSTAT(nameoffile, forfifo);
					fifochar=string_to_char(forfifo);
					int fifow;
					fifow=open(statfifo,O_WRONLY);
					if(write(fifow,fifochar,2048)<0)
						perror("Eroare la scrierea in fifo, motiv: ");
					close(fifow);
					//cout<<forfifo<<"***\n";
				}
				else //parinte
				{
					close(pstat[0]);
					string statfile;
					cout<<"Introduceti numele fisierului/calea pentru care vreti sa vizualizati atributele\nFile: ";
					std::getline(std::cin,statfile);
					char *statchar=new char[100];
					statchar=string_to_char(statfile);
					if(write(pstat[1],statchar,100)<0)
					{	
						perror("Eroare la scrierea in pipestat, motiv: ");
						exit(0);
					}
					close(pstat[1]);
					int fifor;
					fifor=open(statfifo,O_RDONLY);
					char *returnfifo=new char[2048];
					if(read(fifor,returnfifo,2048)<0)
						perror("Eroare la citirea din fifo, motiv: ");
					close(fifor);
					cout<<returnfifo;
				}
				//MYSTAT(statfile);
			}
			else if(strstr(command,(char*)"QUIT") || strstr(command, (char*)"quit"))
			{
				cout<<"Programul se va inchide";
				exit(1);
			}
			else
			{
				cout<<"Comanda gresita. Executia programului se va incheia";
				exit(2);
			}
		}
	}
	return 0;
}