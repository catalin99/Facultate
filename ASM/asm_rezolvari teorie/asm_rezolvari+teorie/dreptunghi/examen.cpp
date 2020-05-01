#include<iostream.h>
struct rect {
int x,y; // coordonatele coltului din stanga jos
int width; // latimea
int height; // inaltimea
};
/*int intersectie(rect *r1,rect *r2)
{
	if(r1->y<r2->y || r1->y>r2->y)
		return 0;
	if(r1->y+r1->height>=r2->y+r2->height && r1->x+r1->width>=r2->x+r2->width)
		return 1; //r2 inclus in r1
	if(r1->y+r1->height<=r2->y+r2->height && r1->x+r1->width<=r2->x+r2->width)
		return 2; // r1 este inclus in r2
}
*/
int intersectie(rect *r1,rect *r2)
{
	int verificare;
	_asm{

	mov esi,r1 
		mov edi,r2
		mov eax,[esi]+4 //r1.y
		mov ebx,[edi]+4 //r2.y
		cmp eax,ebx
		je afara_if1 //daca e egal iesi afara
		mov verificare,1
afara_if1:
		mov ebx,[esi]+4  //r1.y
		add ebx,[esi]+12 //r1->y+r1->height
		mov ecx,[edi]+4  //r2.y
		add ecx,[edi]+12 //r2->+r2->height
		cmp ebx,ecx
		jb if2
		mov edx,[esi]   //r1.x
		add edx,[esi]+8 //r1->x+r1->width
		mov eax,[edi]	//r2.x
		add eax,[edi]+8 //r2->x+r2->width
		cmp edx,eax
		jb if2
		mov verificare,1
if2:
	cmp edx,eax
		ja finish
		mov verificare,2
finish:
	}
	return verificare;
}
int main()
{
	rect r1,r2;
	r1.x=2;
	r2.x=4;
	r1.y=6;
	r2.y=7;
	r1.width=9;
	r2.width=10;
	r1.height=5;
	r2.height=6;
	if(intersectie(&r1,&r2)==0)
		cout<<"Niciun dreptunghi nu este inclus in celalalt";
	if(intersectie(&r1,&r2)==1)
		cout<<"Dreptunghiul r2 este inclus in r1";
	if(intersectie(&r1,&r2)==2)
		cout<<"Dreptunghiul r1 este inclus in r2";

	return 0;
}

