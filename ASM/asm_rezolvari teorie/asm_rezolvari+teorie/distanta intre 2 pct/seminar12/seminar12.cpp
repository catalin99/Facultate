#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
/*struct S{
	int x;
	char y;
	int a;
	short z;
};
int main()
{
	S b;
	cout<<sizeof(S)<<endl;
	cout<<&b<<endl;
	cout<<&b.x<<endl;
	cout<<(int*)&b.y<<endl;
	cout<<&b.a<<endl;
	cout<<&b.z<<endl;
	return 0;
}*/
struct point{
	int x,y;
};
/*float dist(point *a,point *b)
{
	return sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y));
}*/
int dist(point *a,point *b)
{
	int   rad;
	_asm{
		mov esi,a
			mov edi,b
		mov eax,[esi]
		sub eax,[edi]
		imul eax,eax
		mov ecx,eax
		mov eax,[esi]+4
		sub eax,[edi]+4
		imul eax,eax
		add ecx,eax
		mov rad,ecx
	}
	return sqrt(rad);
}


int main()
{
	point a,b;
	a.x=2;
	a.y=7;
	b.x=6;
	b.y=6;
	cout<<"Distanta este="<<dist(&a,&b)<<endl;
	return 0;
}




