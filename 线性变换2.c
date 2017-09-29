#include <stdio.h>
#include <math.h>
float det(float array[20][20], int n);
float turn(float array[20][20], int n, int g, int h);
void qiuni(int n, float a[20][20],float b[20][20]); 
void mul(int n,float first[20][20],float second[20][20],float result[20][20]);
main(){
	int n;
	int i,j;
	float a[20][20],b[20][20],c[20][20],f[20][20],g[20][20];
	printf("��������ɾ���Ľ�����\n");
	scanf("%d",&n);				//n��ʾ ����Ľ��� 
	printf("��������ɾ���\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("�������ڻ���1����2�µľ���\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f",&c[i][j]);
		}
	}
	qiuni(n,a,b);
	printf("�����bΪ��\n"); 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%10f",b[i][j]);
		}
		printf("\n");
	}
	mul(n,b,c,f);
	mul(n,f,a,g);
	printf("�ڻ���1����2�µľ���Ϊ��\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%10f",g[i][j]);
		}
		printf("\n");
	}
}
void mul(int n,float first[20][20],float second[20][20],float result[20][20]){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			result[i][j]=0;
			for(k=0;k<n;k++){
				result[i][j]+=(first[i][k]*second[k][j]);
				//printf("%10f\n",result[i][j]);
			}
			k=0;
		}
		j=0;
	}
} 
void qiuni(int n, float a[20][20],float b[20][20]){
	float  d;
	int i, j;
	d=det(a, n);                 //d��ʾ���������ʽ��ֵ 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			b[j][i]=pow(-1,(i+j+2))*turn(a, n, i, j);
			
		}
	}
	i=0;j=0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			b[i][j]=b[i][j]/d;
		}
	}
}

float turn(float array[20][20], int n, int g, int h){  //���д�������ʽ����
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

float det(float array[20][20], int n){  //��������ʽ����
	float temp[20][20], k, sum=1;
	int i, j, plus, x, y;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			temp[i][j]=array[i][j];
	for(i=0; i<n-1; i++){
		for(j=i; j<n-1; j++){
			if(temp[i][i]==0)
				for(plus=i+1; plus<n; plus++){
					if(temp[plus][i]==0)//�ж���λ�Ƿ�Ϊ��
						continue;
					for(x=0; x<n; x++)
						temp[i][x]+=temp[plus][x];
					break;
				
				}
			if(plus==n)
				continue;
			k=temp[j+1][i]/temp[i][i];//���ɽ��ݾ���
			for(y=i; y<n; y++)
				temp[j+1][y]-=k*temp[i][y];
		}
	}
	for(i=0; i<n; i++)//�Խ���Ԫ�����
		sum*=temp[i][i];
	return sum;
}
