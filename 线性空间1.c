#include <stdio.h>
#include <math.h>
float det(float array[20][20], int n);
float turn(float array[20][20], int n, int g, int h);
void qiuni(int n, float a[20][20],float b[20][20]); 
main(){
	int n;
	int i,j;
	float a[20][20],b[20][20];
	printf("请输入所给基对应的矩阵的阶数：");
	scanf("%d",&n);				//n表示 矩阵的阶数 
	printf("请输入所给基对应的矩阵：\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f",&a[i][j]);
		}
	}
	qiuni(n,a,b);
	printf("逆矩阵为：\n"); 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%-15f",b[i][j]);
		}
		printf("\n");
	}
	printf("请输入向量的坐标：");
	float yuan[4],result[4];
	int m;
	for(m=0;m<4;m++){
		scanf("%f",&yuan[m]) ;
	}
	i=0;j=0;
	for(i=0;i<n;i++){
		result[i]=0;
		for(j=0;j<n;j++){
			result[i]+=b[i][j]*yuan[j];
		}
		j=0;
	}
	printf("向量在基(ε1，ε2，ε3，ε4)下的坐标为：\n("); 
	for(j=0;j<n;j++){
		printf("%f ",result[j]);
		if(j==n-1){
			printf(")\n");break;
		}
		printf(",");
	}
	
}
void qiuni(int n, float a[20][20],float b[20][20]){
	float  d;
	int i, j;
	d=det(a, n);                 //d表示矩阵的行列式的值 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			b[j][i]=pow(-1,(i+j+2))*turn(a, n, i, j);
			
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			b[i][j]=b[i][j]/d;
		}
	}
}

float turn(float array[20][20], int n, int g, int h){  //进行代数余子式计算
	float temp[20][20];
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			temp[i][j]=array[i][j];
	for(i=g; i<n-1; i++)
		for(j=0; j<n; j++)
			temp[i][j]=temp[i+1][j];
	for(j=h; j<n-1; j++)
		for(i=0; i<n-1; i++)
			temp[i][j]=temp[i][j+1];
			
	return det(temp, n-1);
}

float det(float array[20][20], int n){  //进行行列式计算
	float temp[20][20], k, sum=1;
	int i, j, plus=0, x, y;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			temp[i][j]=array[i][j];
	for(i=0; i<n-1; i++){
		for(j=i; j<n-1; j++){
			if(temp[i][i]==0)
				for(plus=i+1; plus<n; plus++){
					if(temp[plus][i]==0)//判断首位是否为零
						continue;
					for(x=0; x<n; x++)
						temp[i][x]+=temp[plus][x];
					break;
				
				}
			if(plus==n)
				continue;
			k=temp[j+1][i]/temp[i][i];//化成阶梯矩阵
			for(y=i; y<n; y++)
				temp[j+1][y]-=k*temp[i][y];
		}
	}
	for(i=0; i<n; i++)//对角线元素求积
		sum*=temp[i][i];
	return sum;
}
