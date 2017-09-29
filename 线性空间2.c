#include <stdio.h>
#include <math.h>
float det(float array[20][20], int n);
float turn(float array[20][20], int n, int g, int h);
void qiuni(int n, float a[20][20],float b[20][20]); 
void mul(int n,float first[20][20],float second[20][20],float result[20][20]);
main(){
	int n;
	int i,j;
	float a[20][20],b[20][20],c[20][20],d[20][20],result[20][20];
	printf("������ά����");
	scanf("%d",&n);				//n��ʾ ����Ľ��� 
	printf("�������ɵ�λ��(e1,e2,e3,e4)����(��1����2����3����4)�Ĺ��ɾ���\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("�������ɵ�λ��(e1,e2,e3,e4)����(��1����2����3����4)�Ĺ��ɾ���\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f",&c[i][j]);
		}
	}
	qiuni(n,a,b);//�Ի�(��1����2����3����4)�ľ������棬bΪ������� 
	printf("�ɵ�λ��(e1,e2,e3,e4)����(��1����2����3����4)�Ĺ��ɾ���a�������bΪ��\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%-15f",b[i][j]);
		}
		printf("\n");
	}
	mul(n,b,c,result);
	printf("�ɻ�(��1����2����3����4)����(��1����2����3����4)�Ĺ��ɾ���Ϊ��\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%-15f",result[i][j]);
		}
		printf("\n");
	}
	printf("�����������ε����꣺");
	float coord[4],res[4];
	int m;
	for(m=0;m<4;m++){
		scanf("%f",&coord[m]) ;
	}
	qiuni(n,c,d);
	printf("�ɵ�λ��(e1,e2,e3,e4)����(��1����2����3����4)�Ĺ��ɾ���c�������dΪ��\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%-15f",d[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++){
		res[i]=0;
		for(j=0;j<n;j++){
			res[i]+=d[i][j]*coord[j];
		}
		j=0;
	}
	printf("�������ڻ�(��1����2����3����4)�µ�����Ϊ\n( ");
	for(j=0;j<n;j++){
		printf("%f ",res[j]);
		if(j==n-1){
			printf(" )\n");
			break;
		}
		printf(",\n");
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
		}
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
