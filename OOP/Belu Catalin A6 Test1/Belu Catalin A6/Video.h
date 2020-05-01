#pragma once

using namespace std;

class Video
{
	string nume;
	int lungime;
public:
	Video(string name, int lung);
	friend ostream& operator<<(ostream& out, Video &v);
};

