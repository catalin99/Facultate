#pragma once
#include "Video.h"
class EditorVideo
{
	vector<Video> continut;
public:
	EditorVideo();
	EditorVideo(initializer_list<Video> v);
	Video* begin();
	Video* end();
	//friend bool operator!=(Video *v1, Video *v2);
	void operator+=(Video z);
	void operator=(Video eq);
	void afiseaza_invervale_video();
};

