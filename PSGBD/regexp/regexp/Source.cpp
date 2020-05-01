re
#include <iostream>
#include <string.h>
using namespace std;

int index = 0;
bool check_escape(string exp, int poz)
{
	if (poz < 0)
		return false;
	if (exp[poz] == '\\')
		return true;
	return false;
}

bool check_square_parenthesis(string square, string data, int dataindex)
{
	int index = 0;
	while (index < square.size())
	{
		if (index + 1 < square.size())
		{
			if (square[index + 1] == '-' && !check_escape(square,index))
			{
				if (square[index] <= data[dataindex] && square[index + 2] >= data[dataindex])
					return true;
				else index += 2;
			}
			else if (square.find(data[dataindex]) >= 0 && square.find(data[dataindex]) < square.size())
			{
				return true;
			}
		}
		else if (square.find(data[dataindex]) >= 0 && square.find(data[dataindex]) < square.size())
		{
			return true;
		}
		index++;
	}
	return false;
}

bool check_square_parenthesis_reverse(string square, string data, int dataindex)
{
	int index = 0;
	while (index < square.size())
	{

		if (index + 1 < square.size())
		{
			if (square[index + 1] == '-' && !check_escape(square, index))
			{
				if (square[index] <= data[dataindex] && square[index + 2] >= data[dataindex])
					return false;
				else index += 2;
			}
			else if (square.find(data[dataindex]) >= 0 && square.find(data[dataindex]) < square.size())
			{
				return false;
			}
		}
		else if (square.find(data[dataindex]) >= 0 && square.find(data[dataindex]) < square.size())
		{
			return false;
		}
		index++;
	}
	return true;
}

bool check_regexp(string regexp, string data)
{
	int poz_exp = 0;
	while (index < data.size())
	{

		/*if (poz_exp >= regexp.size())
		{
			cout << "Sirul nu a fost parcurs pana la final\n";
			cout << poz_exp << ' ' << regexp << endl << index << ' ' << data;
			return false;
		}*/
		if (poz_exp >= regexp.size())
			return true;
		if (regexp[poz_exp] == '[' && !check_escape(regexp, poz_exp - 1))
		{
			string square_p = "";
			bool reverse = false;
			poz_exp++;
			if (regexp[poz_exp] == '^')
			{
				reverse = true;
				poz_exp++;
			}
			while (regexp[poz_exp] != ']' && !check_escape(regexp, poz_exp - 1))
			{
				if(regexp[poz_exp]!='\\')
					square_p += regexp[poz_exp];
				poz_exp++;
			}
			if (reverse == false)
			{
				if (check_square_parenthesis(square_p, data, index) == false)
				{
					return false;
				}
			}
			else
			{
				if (check_square_parenthesis_reverse(square_p, data, index) == false)
				{
					return false;
				}
			}
			square_p.clear();
			poz_exp++;
		}
		else if (regexp[poz_exp] == '.')
		{
			if (data[index] == '\n')
			{
				return false;
			}
			poz_exp++;
		}
		else if (regexp[poz_exp] == '(' && !check_escape(regexp, poz_exp - 1))
		{
			string normal_p = "";
			poz_exp++;
			while (regexp[poz_exp] != ')' && !check_escape(regexp, poz_exp - 1))
			{
				if (regexp[poz_exp] != '\\')
					normal_p += regexp[poz_exp];
				poz_exp++;
			}
			poz_exp++;
			int reset_index = index;
			if (regexp[poz_exp] == '*')
			{
				while (check_regexp(normal_p, data) == true)
				{
					reset_index = index;
				}
				index=reset_index;
				index--;
			}
			else if (regexp[poz_exp] == '+')
			{
				if (check_regexp(normal_p, data) == false)
				{
					return false;
				}
				while (check_regexp(normal_p, data) == true)
				{
					reset_index = index;
				}
				index = reset_index;
				index--;
			}
			poz_exp++;
		}
		else
		{
			if (data[index] != regexp[poz_exp] && regexp[poz_exp] != '\\')
			{
				return false;
			}
			if (regexp[poz_exp] == '\\')
				index--;
			
			poz_exp++;
			cout << poz_exp << endl;
		}
		index++;
	}
	if (regexp.size() > poz_exp)
	{
		cout << "Expresia regulata nu a fost parcursa pana la final\n";
		return false;
	}
	return true;

}

int main()
{
	char r[20];
	char s[200];
	cout << "regexp: ";
	cin.getline(r, 20);
	string regexp(r);
	cout << "data: ";
	cin.getline(s,200);
	string data(s);
	if (check_regexp(regexp, data))
		cout << "expresie corecta";
	else
		cout << "expresie gresita";
	cout << endl;
	cout << regexp <<' ' <<data;

	return 0;
}