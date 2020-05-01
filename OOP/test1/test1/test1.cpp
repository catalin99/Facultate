// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EditorVideo.h"
#include "Video.h"

int main()
{
	Video video1("Skateboarding", 24);
	Video video2("Driving", 10);
	Video video3("Biking", 19);
	EditorVideo editor = { video1, video2 };
	editor += video3;
	editor.afiseaza_invervale_video();
	editor = ((video1 | video3) | video2);
	//editor.afiseaza_invervale_video();
	for (auto vid : editor)
	{
		cout << vid << endl; //Output: Film: SkateboardingDrivingBiking (53)
	}
	return 0;
}

