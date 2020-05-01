// REGULI
// 1. Carte magica (5C) - oricine detine aceasta carte castiga runda sau razboiul
// 2. Daca dupa un razboi toti jucatorii raman fara carti, atunci se considera egalitate
// 3. Daca dupa un razboi unul sau mai multi jucatori raman fara carti, atunci acestia pierd,
// iar cartile lor sunt date castigatorului
// 4. Dupa un razboi cartile sunt luate de cel cu cea mai mare carte, chiar daca acesta nu a
// in razboi participat

// ALTE CHESTII ADAUGATE
// 1. Un cod foarte flexibil si modular
// 2. Scor pentru fiecare jucator
// 2. Top players


#include <string.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>

using namespace std;

const unsigned int WIDTH = 1000;
const unsigned int HEIGTH = 600;

// numarul de carti de joc
const unsigned short NR_CARTI = 52;
unsigned short nr_carti_actuale = 52;

// spatiul din fata intentionat lasat liber, pt. a incepe cu 1
const char *NUMERE = " 234567890JQKA";

// trefla, romb (caro), cupa, pica
const char *SIMBOLURI = " TRCP";

// numarul maxim de jucatori
const unsigned short NR_JUCATORI_MAX = 4;
int nrJucatori = 0;

struct numarCarte
{
	int indice;
	int valRazboi;
	char display;

	//pentru K; indice = 11, display = 'K'
};

struct carteJoc {
	numarCarte numar;
	char simbol;
} carte[NR_CARTI];

struct node
{
	carteJoc info;
	node* urm;
};

struct jucator
{
	int numar;
	char nume[51];
	int nrCarti = 0;
	bool inRazboi;
	int scor = 0;
	node* prim;
	node* ultim;
}jucatori[NR_JUCATORI_MAX + 1];

struct castigatorRunda
{
	int indiceCarte;
	int nrJucator;
	int valCarte;
}castigator;

void AmestecaPachet(carteJoc carte[])
{
	unsigned short int i1, i2;
	carteJoc aux;

	srand(time(NULL));
	for (int i = 1; i <= 100; i++)
	{
		i1 = 1 + rand() % nr_carti_actuale;
		i2 = 1 + rand() % nr_carti_actuale;

		aux = carte[i1];
		carte[i1] = carte[i2];
		carte[i2] = aux;
	}
}

void AfisarePachet(carteJoc carte[])
{
	for (int i = 1; i <= nr_carti_actuale; i++)
		cout << "{" << carte[i].numar.display << "," << carte[i].simbol << "}\t";

	cout << "\n";
}

void GenerarePachet(carteJoc carte[])
{
	int nrCarte = 1;
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			numarCarte numarC;
			numarC.display = NUMERE[i];
			numarC.indice = i + 1;
			numarC.valRazboi = i + 1;

			if (i >= 10)
			{
				if (NUMERE[i] == 'A')
				{
					numarC.valRazboi = 11;
				}
				else
				{
					// pentru J Q K
					numarC.valRazboi = 10;
				}
			}

			carte[nrCarte].numar = numarC;
			carte[nrCarte].simbol = SIMBOLURI[j];

			nrCarte++;
		}
	}
}

void EliminareCarti(carteJoc carte[], int cartiElim)
{
	for (int i = cartiElim; i <= NR_CARTI; i++)
	{
		carte[i - cartiElim] = carte[i];
	}
	nr_carti_actuale = NR_CARTI - cartiElim;
}

void InsereazaCarte(jucator &juc, carteJoc carte)
{
	node *elem = new node;
	elem->info = carte;
	elem->urm = NULL;

	if (juc.prim == NULL)
	{
		juc.prim = elem;
	}
	else
	{
		node *nod = juc.prim;
		while (nod->urm != NULL)
			nod = nod->urm;

		nod->urm = elem;
	}

	juc.nrCarti++;
}

void AfisarePachetJucator(jucator juc)
{
	node *c = juc.prim;
	for (int i = 1; i <= juc.nrCarti; i++)
	{
		cout << "{" << c->info.numar.display << "," << c->info.simbol << "}\t";
		c = c->urm;
	}
	cout << "\n";
}

void CartiJucator(int nrJucatori, int nrCartiJucator)
{
	//Cream cate o lista de carti pentru fiecare jucator

	int carte_ST = 1; //prima carte pt primul jucator
	int carte_F = nrCartiJucator; //ultima carte pt primul jucator

	for (int i = 1; i <= nrJucatori; i++)
	{
		jucatori[i].numar = i;
		for (int j = carte_ST; j <= carte_F; j++)
			InsereazaCarte(jucatori[i], carte[j]);
		carte_ST = carte_F + 1;
		carte_F += nrCartiJucator;
	}
}

void StergeCarte(jucator &juc, carteJoc carte)
{
	if (juc.prim == NULL)
		return;

	juc.nrCarti--;
	node *c = juc.prim;

	// daca primul nod trebuie eliminat
	if (c->info.numar.indice == carte.numar.indice && c->info.simbol == carte.simbol)
	{
		juc.prim = juc.prim->urm;
		delete c;

		return;
	}

	// in caz ca e in interiorul listei sau ultimul nod
	for (int i = 1; i <= juc.nrCarti; i++)
	{
		if (c->urm->info.numar.indice == carte.numar.indice && c->urm->info.simbol == carte.simbol)
		{
			node *q = c->urm;
			c->urm = q->urm;
			delete q;

			break;
		}

		c = c->urm;
	}
}

void MutaCarte(jucator &juc1, jucator &juc2, carteJoc carte)
{
	StergeCarte(juc1, carte);
	InsereazaCarte(juc2, carte);
}

void AfiseazaToatePachetele()
{
	for (int i = 1; i <= nrJucatori; i++)
	{
		cout << "Jucatorul " << jucatori[i].numar << ' ' << jucatori[i].nume << endl;
		AfisarePachetJucator(jucatori[i]);
		cout << endl;
	}
}

int CarteSpeciala()
{
	// Noua regula: Exista o carte speciala, anume 5♥.
	// Cand se da o runda, daca un jucator are aceasta carte, acesta va fi castigatorul rundei, indiferent de cartea maxima din runda.
	// Verificam daca unul dintre jucatori are ca prima carte cartea speciala.
	for (int i = 1; i <= nrJucatori; i++)
		if (jucatori[i].nrCarti > 0)
			if (jucatori[i].prim->info.numar.display == '5' && jucatori[i].prim->info.simbol == 'C')
				return i;

	return 0; // daca nimeni nu a avut cartea speciala
}

void CarteMaxRunda()
{
	//verific daca vreun castigator are cartea speciala
	int castigator_cspeciala = CarteSpeciala();
	if (castigator_cspeciala != 0)
	{
		castigator.nrJucator = castigator_cspeciala;
		castigator.indiceCarte = 12; //un nr mai mare decat orice carte, ca sa evitam gasirea altor carti de 5 si inceperea unui razboi
		castigator.valCarte = 5;
	}
	else
	{
		//initializare
		castigator.indiceCarte = jucatori[1].prim->info.numar.indice;
		castigator.valCarte = jucatori[1].prim->info.numar.valRazboi;
		castigator.nrJucator = 1;

		int carte_curenta = 0;
		for (int i = 2; i <= nrJucatori; i++)
		{
			carte_curenta = jucatori[i].prim->info.numar.indice;
			if (castigator.indiceCarte < carte_curenta)
			{
				castigator.indiceCarte = carte_curenta;
				castigator.valCarte = jucatori[i].prim->info.numar.valRazboi;
				castigator.nrJucator = i;
			}
		}
	}
}

int CartiEgaleRunda(int carte_max)
{
	int carti_egale = 0;
	int carte_curenta = 0;
	for (int i = 1; i <= nrJucatori; i++)
	{
		carte_curenta = jucatori[i].prim->info.numar.indice;
		if (carte_curenta == carte_max)
		{
			carti_egale++;
		}
	}
	return carti_egale;
}

void StergeJucator(int nr)
{
	for (int i = nr; i < nrJucatori; i++)
	{
		jucatori[i] = jucatori[i + 1];
	}
	jucatori[nrJucatori].nrCarti = 0;
	jucatori[nrJucatori].prim = NULL;
	nrJucatori--;
}

void VerificaJucatori()
{
	for (int i = 1; i <= nrJucatori; i++)
	{
		if (jucatori[i].nrCarti == 0)
		{
			StergeJucator(i);
			i--;
		}
	}
}

// Avem nevoie de definirea asta ca sa il putem apela in Runda()
void Razboi(int nrCartiRazboi);

void Runda()
{
	CarteMaxRunda();
	int carti_egale = CartiEgaleRunda(castigator.indiceCarte);

	if (carti_egale > 1)
	{
		Razboi(castigator.valCarte);
	}
	else
	{
		jucatori[castigator.nrJucator].scor++;
		cout << jucatori[castigator.nrJucator].nume << " are cea mai mare carte! "<< endl;
		for (int i = 1; i <= nrJucatori; i++)
			MutaCarte(jucatori[i], jucatori[castigator.nrJucator], jucatori[i].prim->info);
	}

	// Stergem jucatorii fara carti
	VerificaJucatori();
}

// Avem nevoie de doua variabile globale in caz ca dupa ce s-a dat un razboi mai trebuie sa se dea unul
jucator auxRazboi;
void Razboi(int nrCartiRazboi)
{
	cout << "RAZBOI!\n";

	// Luam jucatorii care sunt in razboi
	for (int i = 1; i <= nrJucatori; i++)
	{
		if (jucatori[i].prim->info.numar.indice == castigator.indiceCarte)
		{
			jucatori[i].inRazboi = true;
		}
		else
		{
			jucatori[i].inRazboi = false;
		}
	}

	// Verificam cati jucatori au un numar insificient de carti
	int jucFaraCartiDestule = 0;
	for (int i = 1; i <= nrJucatori; i++)
	{
		if (jucatori[i].inRazboi == true)
		{
			if (jucatori[i].nrCarti <= nrCartiRazboi)
				jucFaraCartiDestule++;
		}
	}

	// REGULA: daca toti jucatorii nu au carti suficiente atunci se considera egalitate
	if (jucFaraCartiDestule == nrJucatori)
	{
		cout << "EGALITATE intre jucatorii: ";

		int aux = 1;
		for (int i = 1; i <= nrJucatori; i++)
		{
			cout << aux++ << " ";
			StergeJucator(i);
			i--;
		}

		cout << endl;
		return;
	}

	// Jucatorii cu carti insuficiente vor pierde
	for (int i = 1; i <= nrJucatori; i++)
	{
		if (jucatori[i].inRazboi == true)
		{
			int aux = jucatori[i].nrCarti;
			if (aux <= nrCartiRazboi)
			{
				for (int j = 1; j <= aux; j++)
				{
					MutaCarte(jucatori[i], auxRazboi, jucatori[i].prim->info);
				}
				StergeJucator(i);
				i--;
			}
		}
	}

	// Mutam cartile de la jucatorii ramasi in aux
	for (int i = 1; i <= nrJucatori; i++)
	{
		if (jucatori[i].inRazboi == true)
		{
			for (int j = 1; j <= nrCartiRazboi; j++)
			{
				MutaCarte(jucatori[i], auxRazboi, jucatori[i].prim->info);
			}
		}
	}

	// Aflam cartea maxima
	CarteMaxRunda();

	int cartiEgale = CartiEgaleRunda(castigator.indiceCarte);
	if (cartiEgale > 1)
	{
		Razboi(castigator.valCarte);
	}
	else
	{
		// Mutam cartile la castigator

		for (int i = 1; i <= nrJucatori; i++)
		{
			MutaCarte(jucatori[i], auxRazboi, jucatori[i].prim->info);
		}

		jucatori[castigator.nrJucator].scor++;
		cout << jucatori[castigator.nrJucator].nume << " are cea mai mare carte! " << endl;
		int aux = auxRazboi.nrCarti;
		for (int i = 1; i <= aux; i++)
		{
			MutaCarte(auxRazboi, jucatori[castigator.nrJucator], auxRazboi.prim->info);
		}

		auxRazboi.nrCarti = 0;
		auxRazboi.prim = NULL;
	}
}

void MakeRazboi(int carteMax = 0)
{
	bool seDaRazboi = false;

	if (carteMax == 0)
	{
		CarteMaxRunda();
		carteMax = castigator.indiceCarte;
	}

	for (int i = 1; i < nrJucatori; i++)
	{
		for (int j = i + 1; j <= nrJucatori; j++)
		{
			if (jucatori[i].prim->info.numar.indice == jucatori[j].prim->info.numar.indice)
			{
				if (jucatori[i].prim->info.numar.indice == carteMax)
					seDaRazboi = true;
			}
		}
	}

	if (!seDaRazboi)
	{
		for (int i = 1; i <= nrJucatori; i++)
		{
			jucatori[i].prim = NULL;
			jucatori[i].nrCarti = 0;
		}

		AmestecaPachet(carte);

		CartiJucator(nrJucatori, NR_CARTI / nrJucatori);

		MakeRazboi(carteMax);
	}
}


void AfiseazaScorJucatori()
{
    ifstream fin("clasament.txt");
    int n;
    fin>>n;
    for(int i = 1; i <= n; i++)
    {
        int scor;
        char nume[51];

        fin.get();
        fin>>scor;
        fin.get();
        fin.get(nume, 50);

        cout<<"#"<<i<<": "<<nume<<" - "<<scor<<endl;
    }
}

void ModificaTopPlayers()
{
    // Modificam doar daca nu este egalitate
    if(nrJucatori > 0)
    {

        fstream fin;
        fin.open("clasament.txt");

        int n;
        fin>>n;

        jucator topJucatori[11];

        for(int i = 1; i <= n; i++)
        {
            fin.get();
            fin>> topJucatori[i].scor;
            fin.get();
            fin.get(topJucatori[i].nume, 50);
        }


        topJucatori[n+1].scor = jucatori[1].scor;
        strcpy(topJucatori[n+1].nume, jucatori[1].nume);

        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n+1; j++)
                if(topJucatori[i].scor < topJucatori[j].scor)
                {
                    swap(topJucatori[i].nume, topJucatori[j].nume);
                    swap(topJucatori[i].scor, topJucatori[j].scor);
                }
        }
        if(n < 10)
            n++;

        fin.close();
        ofstream fout("clasament.txt");

        fout<<n<<endl;
        for(int i = 1; i <= n; i++)
        {
            fout<<topJucatori[i].scor<<" "<<topJucatori[i].nume<<endl;
        }

        fout.close();
    }

}

void WaitForMouseClick(int &x, int &y)
{
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(10);
    }

    delay(10);
    getmouseclick(WM_LBUTTONDOWN, x, y);
}

void StartGameButton();
void TopPlayersButton();
void QuitGameButton();

void WaitForButtonClick()
{
    int x = -1, y = -1;

    while(x == -1 && y == -1)
    {

        WaitForMouseClick(x, y);

        if(x >= 400 && x <= 600 && y >= 100 && y <= 175)
            StartGameButton();
        else if(x >= 400 && x <= 600 && y >= 200 && y <= 275)
            TopPlayersButton();
        else if(x >= 400 && x <= 600 && y >= 300 && y <= 375)
            QuitGameButton();
        else
            x = y = -1;
    }
}


void StartGameButton()
{
    system("cls");
    do
	{
		cout << "Numarul de jucatori (max - " << NR_JUCATORI_MAX << "): ";
		cin >> nrJucatori;
	} while (nrJucatori > NR_JUCATORI_MAX || nrJucatori < 2);

	cout << "Numele jucatorilor: " << endl;
	cin.get();
	for (int i = 1; i <= nrJucatori; i++)
	{
		cin.get(jucatori[i].nume, 51);
		cin.get();
	}
	// Generam pachetul de carti
	GenerarePachet(carte);

	// Eliminam cartile in plus
	EliminareCarti(carte, NR_CARTI % nrJucatori);

	// Amestecam pachetul
	AmestecaPachet(carte);

	// Impartim cartile la jucatori
	int nrCartiJucator = NR_CARTI / nrJucatori;
	cout << "\nNumarul de carti per jucator:\n" << nrCartiJucator << endl << endl;
	CartiJucator(nrJucatori, nrCartiJucator);

	// Creem un razboi
	// MakeRazboi();

	AfiseazaToatePachetele();

	while (nrJucatori > 1)
	{
		Runda();

		cout << endl;
		AfiseazaToatePachetele();
	}

	cout << endl;
	cout << "Castigator: "<<jucatori[1].nume<<endl;
	cout << "Scor: " << jucatori[1].scor<<endl;

	ModificaTopPlayers();

	WaitForButtonClick();
}

void TopPlayersButton()
{
    system("cls");
    cout << "----- TOP JUCATORI -----"<<endl;
	cout << endl;
    AfiseazaScorJucatori();
	WaitForButtonClick();
}

void QuitGameButton()
{
    exit(0);
}


void MainMenu()
{
    readimagefile("images/background.jpg", 0, 0, WIDTH, HEIGTH);
    readimagefile("images/start_game.jpg", (WIDTH/2) - 100, 100, 200, 175);
    readimagefile("images/top_players.jpg", (WIDTH/2) - 100, 200, 200, 125);
    readimagefile("images/quit_game.jpg", (WIDTH/2) - 100, 300, 200, 225);

    WaitForButtonClick();
}

int main()
{
    int x, y;
    initwindow(WIDTH, HEIGTH, "RAZBOI");

    MainMenu();


    return 0;
}
