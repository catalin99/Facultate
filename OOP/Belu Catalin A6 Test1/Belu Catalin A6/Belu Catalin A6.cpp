// Belu Catalin A6.cpp : Defines the entry point for the console application.
//Nr 2

#include "stdafx.h"
#include "Video.h"
#include "EditorVideo.h"

int main()
{
	Video video1("Skateboarding", 24);
	Video video2("Driving", 10);
	Video video3("Biking", 19);
	EditorVideo editor = { video1, video2 };
	editor += video3;

	
	//editor = ((video1 | video3) | video2);
	//for (auto vid : editor)
	//{
		//cout << vid << endl; //Output: Film: SkateboardingDrivingBiking (53)
	//}
	return 0;
	//Operatorul | concateneaza 2 video-uri (si numele si lungimea). 
	//Functia afiseaza_intervale_video afiseaza toate video-urile din editor, 
	//in ordine in care au fost adaugate iar apoi lungimea totala a video-ului. 
	//Puteti folosi containere stl pentru a asigura functionalitatea din clasa.
}

