#include<stdio.h>
#include<math.h> 
struct solution{
	int a;
	int subm[10];//submultipleԼ�� 
	int count;//��subm���� 
}mult[2];//multinomail����ʽ 
main(){
	//int a[2];
	int i=0,j=0,t=0;
	float sol[100];//solution
	float sol2[20];
	float xishu[10];
	printf("��������ߴ���Ĵ�����");
	int cishu;
	scanf("%d",&cishu); 
	printf("�����μ�����ϵ���������ߴ����ϵ����ֵ��\n");
	for(i=0;i<2;i++){
		scanf("%d",&mult[i].a);
		if(mult[i].a<0){
			mult[i].a=0-mult[i].a;
		}
	}
	printf("��Ӹߵ��������������ϵ����\n");
	i=0;
	for(i=0;i<=cishu;i++){
		scanf("%f",&xishu[i]);
	}
	i=0;
	for(j=0;j<2;j++){
		for(i=1;i<=mult[j].a;i++){// ������ϵ��mult[0] ��������mult[1] 
			t=(mult[j].a)%i;
			if(t==0){
				mult[j].subm[mult[j].count]=i;
				(mult[j].count)++;
			} 
		}
	}
	i=0;j=0;
	int count_sol=0;
	printf("����ʽ�����������Ϊ��\n");
	for(i=0;i<mult[0].count;i++){
		for(j=0;j<mult[1].count;j++){
			sol[count_sol]=(float)(mult[0].subm[i])/(float)(mult[1].subm[j]);
			count_sol++; 
		}
	}
	int k=1,p=0;
	int count_sol2=1,count_temp=0;
	sol2[0]=sol[0];
	for(k=1;k<count_sol;k++){
		count_temp=0;//ÿ��ѭ��ˢ����ʱ��������count_temp 
		for(p=0;p<count_sol2;p++){
			if(sol2[p]!=sol[k]){
				count_temp++;
			}	
		}
		if(count_temp==count_sol2){//����sol�еı���sol[k]������sol2�е�ÿ����������ͬ�����������Ҳ���뵽����sol2�� 
			sol2[count_sol2]=sol[k];
			count_sol2++;
		}
		p=0;
	}
	i=count_sol2;
	for(i=count_sol2;i<(2*count_sol2);i++){
		sol2[i]=(-sol2[i-count_sol2]);
	}
	int m;
	for(m=0;m<(2*count_sol2);m++){
		printf("%f\n",sol2[m]);
	}

	printf("\n"); 
	i=0;j=0;
	int flag=0;
	float jieguo=0;
	for(i=0;i<2*(count_sol2);i++){
		jieguo=0;
		for(j=0;j<=cishu;j++){
			jieguo+=xishu[j]*pow(sol2[i],(cishu-j)); 
		}
		//printf("hh%f\n",jieguo);
		if((jieguo<0.00001)&&(((-1)*jieguo)<0.00001)){
			printf("����ʽ�������Ϊlove%f\n",sol2[i]);
		}
		else{
			flag++;
		}
		j=0;
	}
	if(flag==2*(count_sol2)){
		printf("����ʽ�������"); 
	}
} 
