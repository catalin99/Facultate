#include <iostream>
using namespace std;
//Suma cifrelor unui numar(pentru numere cel mult alcatuite din 10 cifre,adica n<pow(10,10)-1
int main()
{
   int n,a;
   cin>>n;
   a=10;
   _asm
   {
	   mov eax,n
	   mov ecx,0
	start_do:
	   mov edx,0
	   div a
	   add ecx,edx
	   cmp eax,0
	   jne start_do
		   		   	 mov n,ecx
     }
   cout<<n<<endl;


}