#include "stdafx.h"
#include "MyString.h"

using namespace std;
typedef unsigned int ui;
#pragma warning(disable:4996)

MyString::MyString()
{
	AllocatedSize = 16;
	sir = (char*)(malloc (AllocatedSize));
	Size = 0;
	strcpy(sir, "\0");
	
}

MyString::MyString(const char *text)
{
	AllocatedSize = 1+strlen(text);
	sir = (char*)(malloc(AllocatedSize) );
	Size = strlen(text);
	strcpy(sir, text);
}

MyString::~MyString()
{
	free (sir);
	Size = 0;
	AllocatedSize = 0;
}

ui MyString::GetSize()
{
	return Size;
}

void MyString::Set(const char *text)
{
	if (strlen(text) + 1 != AllocatedSize)
	{
		AllocatedSize = strlen(text) + 1;
		sir = (char*)realloc(sir, AllocatedSize);
	}
	Size = strlen(text);
	strcpy(sir, text);
	sir[Size] = '\0';
}

void MyString::Set(MyString &m)
{
	if (m.AllocatedSize != AllocatedSize)
	{
		AllocatedSize = m.AllocatedSize;
		sir = (char*)realloc(sir, AllocatedSize);
	}
	Size = strlen(m.sir);
	strcpy(sir, m.sir);
}

void MyString::Add(const char *text)
{
	AllocatedSize += strlen(text);
	Size += strlen(text);
	sir = (char*)realloc(sir, AllocatedSize);
	strcat(sir, text);
}

void MyString::Add(MyString &m)
{
	AllocatedSize += m.AllocatedSize;
	Size += m.Size;
	sir = (char*)realloc(sir, AllocatedSize);
	strcat(sir, m.sir);
}

const char* MyString::GetText()
{
	return sir;
}

MyString* MyString::SubString(ui start, ui size) // complete - varianta cu new
{
	if (start > Size)
		return NULL;
	if (start + size > Size)
		return NULL;
	char *newchar = new char;
	strncpy(newchar, sir+start, size);
	newchar[size] = '\0';
	MyString *newobj= new MyString;
	newobj->Set(newchar);
	//delete newchar;
	return newobj;
}

bool MyString::Delete(ui start, ui size)
{
	if (start > Size || start + size > Size)
		return false;
	strcpy(sir + start, sir + start + size);
	return true;
}

int MyString::Compare(const char *text)
{
	if (strcmp(sir, text) < 0)
		return -1;
	else if (strcmp(sir, text) > 0)
		return 1;
	else return 0;
}

int MyString::Compare(MyString &m)
{
	if (strcmp(sir, m.sir) < 0)
		return -1;
	else if (strcmp(sir, m.sir) > 0)
		return 1;
	else return 0;
}

char MyString::GetChar(ui index)
{
	if (index <= Size)
		return sir[index];
	return '0';
}

bool MyString::Insert(ui index, const char *text) //complete
{
	if (index > Size)
		return false;
	if (AllocatedSize < strlen(sir) + strlen(text) + 1)
		AllocatedSize = strlen(sir) + strlen(text) + 1;
	char *temp = new char[strlen(sir) - index];
	Size += strlen(text);
	sir = (char*)realloc(sir, AllocatedSize);
	strcpy(temp, sir + index);
	strcpy(sir + index, text);
	strcpy(sir + index + strlen(text), "\0");
	strcpy(sir + index + strlen(text), temp);
	return true;
}

bool MyString::Insert(ui index, MyString &m)//Complete....After 3 hours....
{
	if (index > Size)
		return false;
	if (AllocatedSize < strlen(sir) + strlen(m.sir) + 1)
		AllocatedSize = strlen(sir) + strlen(m.sir) + 1;
	char *temp = new char[strlen(m.sir) + 1];
	Size += strlen(m.sir);
	strcpy(temp, sir + index);
	strcpy(sir + index, m.sir);
	sir = (char*)realloc(sir, AllocatedSize);
	strcat(sir, temp);
	return true;
	//return Insert(index, m.sir); ///Or just this beauty
}

int MyString::Find(const char * text)
{
	for(int i=0; i<Size-strlen(text); i++)
		if (sir[i] == text[0])
		{
			int j = 0, ok = 1;
			while (j < strlen(text))
			{
				if (sir[i + j] != text[j])
				{
					ok = 0; break;
				}
				j++;
			}
			if (ok)
				return i;
		}
	return -1;
}

int MyString::FindLast(const char *text)
{
	int ret = -1;
	for (int i = 0; i<=Size-strlen(text); i++)
		if (sir[i] == text[0])
		{
			int j = 0, ok = 1;
			while (j < strlen(text))
			{
				if (sir[i + j] != text[j])
				{
					ok = 0; break;
				}
				j++;
			}
			if (ok)
				ret=i;
		}
	return ret;
}

void MyString::TestData()
{
	//AllocatedSize += 10;
	//sir = (char*)(realloc(sir,AllocatedSize));
	//strcat(sir, " functie");
	//cout << sizeof(sir) << endl;
	//cout << AllocatedSize << endl;
	//cout << sir << endl;
	//cout << "Test complete" << '\n';
	cout << sir << endl;
	cout << "Hai salut"<<'\n';

}