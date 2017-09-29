#include<stdio.h> 
int juzhen[4][4];
int flag=0;
void mul(int a[2][2],int b[2][2],int count){
	int result[2][2];
	int i,j,k;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			result[i][j]=0;
			for(k=0;k<2;k++){
				result[i][j]+=a[i][k]*b[k][j];
			}
			//printf("%d",result[i][j]);
			k=0;
		}
		j=0;
	}
	if(flag==0){
		flag=1;
		mul(result,a,count);
	}
	if(flag==1){
		int m=0;
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				juzhen[m][count]=result[i][j];
				m++;
			}
		}
		flag=0; 
	} 
}
main(){
	int stat[2][2]={1,2,3,4};
	int bas_1[2][2]={1,0,0,0};
	int bas_2[2][2]={0,1,0,0};
	int bas_3[2][2]={0,0,1,0};
	int bas_4[2][2]={0,0,0,1};
	int test[2][2]={1,0,0,1};
	mul(stat,bas_1,0);
	mul(stat,bas_2,1);
	mul(stat,bas_3,2);
	mul(stat,bas_4,3);
	int i=0,j=0;
	printf(" A对应的矩阵是：\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%3d",juzhen[i][j]);
		}
		printf("\n");
	}
	//mul(stat,bas_1);
}
