#include "stdafx.h"
#include "EditorVideo.h"
#include <vector>

EditorVideo::EditorVideo()
{
}

EditorVideo::EditorVideo(initializer_list<Video> init)
{
	initializer_list<Video>::iterator it;
	for (it = init.begin(); it < init.end(); it++)
		this->continut.push_back(*it);
}

void EditorVideo::afiseaza_invervale_video()
{
	vector<Video>::iterator ii;
	for (ii = continut.begin();ii < continut.end(); ii++)
	{
		cout << (*ii);
	}
}

EditorVideo & EditorVideo::operator+=( EditorVideo &z)
{
	vector<Video>::iterator iz;
	for (iz = z.continut.begin(); iz < z.continut.end(); iz++)
		this->continut.push_back(*iz);
	return *this;
}

