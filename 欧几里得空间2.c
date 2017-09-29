#include<stdio.h>
#define N 4
#include<Math.h>
double a[N][N]={1,1,0,0,-1,0,0,1,1,0,1,0,1,-1,-1,1};
double dot(double a[N],double b[N]){
	double sum=0;
	int i;
	for(i=0;i<N;i++){
		sum+=a[i]*b[i];
	}
	return sum;
};
void mul(double n,double a[N]){
	int i;
	for(i=0;i<N;i++){
		a[i]*=n;
	}
};
void subtraction(double a[N],double b[N]){
	int i;
	for (i=0;i<N;i++){
		a[i]=a[i]-b[i];
	}	
};
void copy(double a[N],double b[N]){
		int i;
	for (i=0;i<N;i++){
		a[i]=b[i];
	}	
};
void print(double a[N]){
	int i;
	for (i=0;i<4;i++){
		printf("%0.2f ",a[i]);
	} 
	printf("\n——————\n");
}
void unit(double a[N][N]){
	int i;
	int j;
	double sum[N]={0};
	for(i=0;i<4;i++){
		for (j=0;j<4;j++){
			sum[i]+=a[i][j]*a[i][j];		
		}
		sum[i]=sqrt(sum[i]);
	} 
	printf("单位正交向量组为：\n"); 
	for(i=0;i<4;i++){
		printf("η%d:",i+1);
		for (j=0;j<4;j++){
			a[i][j]=a[i][j]/sum[i];	
			printf("%6.2f ",a[i][j]);
		}
		printf("\n");
	} 	
}
main(){
	int i;
	double q[4]={0},w[4],r[4],t,y,u; 
	double b[N][N]={0};
	copy(b[0],a[0]);
	t=dot(a[1],b[0])/dot(b[0],b[0]);
	copy(q,b[0]);
	mul(t,q);
	subtraction(a[1],q);
	copy(b[1],a[1]);
	t=dot(a[2],b[0])/dot(b[0],b[0]);
	y=dot(a[2],b[1])/dot(b[1],b[1]);
	copy(q,b[0]);
	copy(w,b[1]);
	mul(t,q);
	mul(-y,w);
	subtraction(q,w);
	subtraction(a[2],q);
	copy(b[2],a[2]);
	t=dot(a[3],b[0])/dot(b[0],b[0]);
	y=dot(a[3],b[1])/dot(b[1],b[1]);
	u=dot(a[3],b[2])/dot(b[2],b[2]);
	copy(q,b[0]);copy(w,b[1]);copy(r,b[2]);
	mul(t,q);mul(y,w);mul(u,r);
	subtraction(a[3],q);
	subtraction(a[3],w);
	subtraction(a[3],r);
	unit(a);
}
