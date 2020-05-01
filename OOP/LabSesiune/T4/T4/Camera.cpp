#include "stdafx.h"
#include "Camera.h"




Camera::Camera(string m, bool lum, string n)
{
	miros = m;
	lumina = lum;
	nume = n;
}

Camera::~Camera()
{
}

void Camera::PrintInfo()
{
	string lum;
	if (lumina)
		lum = "luminos";
	else
		lum= "intunecat";
	//for (auto i : L)
		cout << nume << " are " << 0 << " camere, miros " << miros << " , "<<lum << '\n';
}
