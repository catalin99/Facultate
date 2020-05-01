#include "stdafx.h"
#include "Video.h"
#include <iostream>
using namespace std;
Video::Video(string name, int lung)
{
	nume = name;
	lungime = lung;
}

ostream & operator<<(ostream & out, Video & v)
{
	out << " (" << v.lungime << ")" << '\n';
	return out;
}
