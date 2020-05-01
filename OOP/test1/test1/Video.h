#pragma once
class Video
{
	string nume;
	int lungime;
public:
	Video(string name, int lung);
	friend ostream& operator<<(ostream& out, Video v);
	string getName();
	int getLung();
	void set(string a, int b);
	void init();
	friend Video& operator|(Video &unu, Video &doi);
};

