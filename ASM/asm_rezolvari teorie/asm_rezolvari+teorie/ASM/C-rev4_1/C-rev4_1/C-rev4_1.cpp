#include "stdafx.h"

#include <windows.h>
#include <stdio.h>

#pragma warning (disable:4996)

#define PluginsPath "Plugins"
#define MAX_CODE_SZ 0x1000
#define CODE_END    0xC35D

#pragma pack(1)
struct plugin{
	char description[512];
	char pname[25];
	int params;
	int code_size;
	unsigned char buffer[MAX_CODE_SZ];
};

struct make_plg_params{
	void *faddr;
	char *fname;
	char *desc;
	int prms;
	char *plgname;
};

void MakePlugin(void *func_addr, char *func_name, char *desc, int params, char *plgname)
{
	HANDLE f;
	DWORD write;
	int i;
	char *buffer;
	char *start = (char*)func_addr;
	plugin *local = new plugin;

	memset(local, 0, sizeof(plugin));

	for (i = 0; i<MAX_CODE_SZ; i++)
	{
		if (*(unsigned short*)(start + i) == CODE_END)
			break;
	}

	local->code_size = i + 2;
	strcpy(local->pname, func_name);
	strcpy(local->description, desc);
	local->params = params;
	memcpy(local->buffer, start, local->code_size);

	f = CreateFile(plgname, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(f, local, sizeof(plugin), &write, NULL);
	CloseHandle(f);
}

int suma(int a, int b)
{
	return a + b;
}

int diferenta(int a, int b)
{
	return a - b;
}

int cat(int a, int b)
{
	return a / b;
}

int rest(int a, int b)
{
	return a%b;
}

int produs(int a, int b)
{
	return a*b;
}

int fibo(int nth)
{
	int sim1 = 1;
	int sim2 = 0;
	int s = 0;
	int i;

	if (nth == 0)
		return 0;
	else
	if (nth == 1)
		return 1;
	else
	do{
		s = sim1 + sim2;
		sim2 = sim1;
		sim1 = s;
		nth--;
	} while (nth >= 2);
	return s;
}

int suman(int nth)
{
	int s = 0, i;

	for (i = 1; i <= nth; i++)
		s = s + i;

	return s;
}

int power(int a, int b)
{
	int i, x = 1;

	if (b == 0)
		return 1;

	for (i = 0; i<b; i++)
		x = x*a;

	return x;
}

int tobin(int number, char *data)
{
	int i;

	for (i = 0; i<33; i++)
		data[i] = 0;

	if ((unsigned int)number <= 0xFF)
	{
		for (i = 0; i<8; i++)
		{
			if (number & 0x80)
				data[i] = '1';
			else
				data[i] = '0';
			number <<= 1;
		}
	}
	else
	if ((unsigned int)number <= 0xFFFF)
	{
		for (i = 0; i<16; i++)
		{
			if (number & 0x8000)
				data[i] = '1';
			else
				data[i] = '0';
			number <<= 1;
		}
	}
	else
	if ((unsigned int)number <= 0xFFFFFFFF)
	{
		for (i = 0; i<32; i++)
		{
			if (number & 0x80000000)
				data[i] = '1';
			else
				data[i] = '0';
			number <<= 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i;

	make_plg_params plugins[9] = {
		{ tobin, "to_bin", "conversie numar int in char* binar", 2, "Plugins\\to_bin.plg" },
		{ power, "power", "ridicare numar a la puterea b a^b", 2, "Plugins\\power.plg" },
		{ suman, "suman", "suma primelor n numere naturale sum(n)", 1, "Plugins\\suman.plg" },
		{ fibo, "fibo", "calcul al n-lea numar fibonacci (0-primul)", 1, "Plugins\\fibo.plg" },
		{ suma, "suma", "suma a 2 numere a+b", 2, "Plugins\\suma.plg" },
		{ diferenta, "diferenta", "diferenta a 2 numere a-b", 2, "Plugins\\diferenta.plg" },

		{ produs, "produs", "produsul a 2 numere a*b", 2, "Plugins\\produs.plg" },
		{ cat, "cat", "catul a 2 numere a/b", 2, "Plugins\\cat.plg" },
		{ rest, "rest", "restul a 2 numere naturale a%b", 2, "Plugins\\rest.plg" }
	};

	printf("Program calculator cu pluginuri pentru functii!\n\n");

	for (i = 0; i<9; i++)
		MakePlugin(plugins[i].faddr, plugins[i].fname, plugins[i].desc, plugins[i].prms, plugins[i].plgname);

	return 0;
}