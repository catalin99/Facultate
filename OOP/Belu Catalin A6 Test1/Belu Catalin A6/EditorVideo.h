#pragma once
#include "Video.h"
#include <vector>
#include <initializer_list>
class EditorVideo
{
	vector<Video> continut;
public:
	EditorVideo();
	EditorVideo(initializer_list<Video> init);
	void afiseaza_invervale_video();
	EditorVideo &operator+=( EditorVideo &z);
};

