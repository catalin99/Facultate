#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n=0,i,j,s=0,prim;
	cin>>n;
	i=n;
	while (i!=0){
		prim=1;
		for (j=2;j<=i/2;j++){
			if ((i%j)==0) prim=0;
							}
	if (prim==1) s+=i;
	i--;
				}

	printf("%d",s);
return 0;
}



