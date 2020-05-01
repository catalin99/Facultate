#include "stdafx.h"
#include "EditorVideo.h"


EditorVideo::EditorVideo()
{
	continut.push_back(Video("Film", 0));
}

EditorVideo::EditorVideo(initializer_list<Video> v)
{
	initializer_list<Video>:: iterator i;
	for (i = v.begin(); i < v.end(); i++)
		continut.push_back(*i);
}

Video * EditorVideo::begin()
{
	return &continut[0];
}


Video * EditorVideo::end()
{
	return &continut[continut.size()];
}
/*
bool operator !=(Video *v1, Video *v2)
{
	if ((*v1).getName() == (*v2).getName())
		return false;
	return true;
}*/

void EditorVideo::operator+=(Video z)
{
	continut.push_back(z);
}

void EditorVideo::operator=(Video eq)
{
	continut.clear();
	continut.push_back(eq);
}


void EditorVideo::afiseaza_invervale_video()
{
	for (auto i : continut)
		cout << i.getName() << " (" << i.getLung() << ")" << '\n';
}


