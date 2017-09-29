#include<stdio.h>
#include<math.h>
main(){
	int a[4]={1,2,3,4};
	int b[4]={3,1,-3,2};
	int c=0;
	int d=0,e=0;
	int i,j;
	for(i=0;i<4;i++){
		d+=pow(a[i],2);
		e+=pow(b[i],2);	
		c+=a[i]*b[i];
	}
	double f=sqrt(d);
	double g=sqrt(e);
	double k=c/(f*g);
	printf("向量间的夹角为：%.2f", acos(k)*180/3.14);
} 
