#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
double P_kc(int N, int requiredn);
double P_jz(int M);
int Get(int snumber, int def);
int main(){
	int n1, n2, n3, n4;
	double x;
	printf("���䲹���ظ���ģ��������0\n��׼������ģ��������1\n");
	scanf("%d", &n1);
	if(n1==0){
		printf("��ֱ�����һ�γ�����Ų�����������Ҫ�鼸����ɫ��(�м��ÿո�ָ�)\n");
		scanf("%d %d", &n2, &n3);
        x=100*P_kc(n2,n3);
        printf("ģ��ø���ԼΪ"); 
	    printf("%lf", x);
	    printf("%\n");
	}
	else{
		printf("������һ�γ�����Ų�����\n");
		scanf("%d", &n4); 
		printf("��ѡ��ģ������\n1.���up������\n2.���up��ָ��һ��ʥ��\n3.���up��ָ��������\n4.���up��������\n5.���up������+ָ��������\n6.���up������+������\n");
		x=100*P_jz(n4);
		printf("ģ��ø���ԼΪ"); 
	    printf("%lf", x);
	    printf("%\n");	
	}
    system("pause");
	return 0;
} 

double P_kc(int N, int requiredn){
	int snumber=0, k_10=0, k_100=0, i=0, j=0, n=0;
	double s, P, G;
	double a=0.09427342057266558;/*���������ͳ�ʼ��*/ 
	srand((int)time(0));/*Ϊ���������������*/
	for(i=1;i<=1000000;i++){
		snumber=0;
		k_10=0;
		k_100=0;/*��������*/
		for(j=1;j<=N;j++){
			if(k_100==99){
				k_10=0;
				k_100=0;
				snumber++;/*һ�������׵����*/ 
			}
			else if(k_10==9){
				k_10=0;
				k_100++;/*ʮ�����׵����*/	
				n=rand()%10;
				if(n==0){
				snumber++;
				k_100=0;/*ʮ�����׳��s�����������Ϊ1/10��ͨ���������ʵ��ģ�⣩*/	
				}
			}
			else {
			s=(double)rand()/RAND_MAX;
			if(s<=a)/*�������ϵ����*/
			{
				k_10=0;
				k_100++;
				n=rand()%10;
				if(n==0){/*������s�����*/
				snumber++;
				k_100=0;	
			}
			}
			else{
				k_10++;
				k_100++;
			}
			}
			if(snumber==requiredn){/*�ж��Ƿ���������*/
				G++;
				break;
			}	
		}		
	}
    P=G/1000000;/*���������������Ƶ�ʣ����������ʣ�*/ 
	return P;	
}

double P_jz(int M){
	int snumber=0, k_10, j, i, GG, def;
	scanf("%d", &def);
	double s, G=0, b=0.04877033334098730, t;
	srand((int)time(0));
	for(i=1;i<=1000000;i++){		
		snumber=0;
		k_10=0;
		for(j=1;j<=M;j++){
			if(k_10==9){
				k_10=0;
				snumber++;	
				}
			else {
			s=(double)rand()/RAND_MAX;
			if(s<=b)
			{
				k_10=0;
			    snumber++;
			}
			else
				k_10++;
			}
		}
		GG=Get(snumber,def);

		if(GG)
		G++; 

	}
	t=G/1000000;
    return t;
}

int Get(int snumber, int def){
	int W=0, T=0, C=0, B=0, n=0, i, t=0; 
	for(i=1;i<=snumber;i++){

		n=rand()%10;

		if(n<=1)
		W+=1;
		else if(n==2)
		T+=1;
		else if(n==3)
		C+=1;
		else if(n==4)
		B+=1;}

       switch(def){
        case 1:	
		    if(W)
			t++;
	        break;
		case 2:
			if(T||B*C*((B+C)>=4))
			t++;
			break;
		case 3:
			if(T*C||B*C*((B+C)>=4)||T*B*((B+T)>=4))
			t++;
			break;
		case 4:
			if(T*C*B||B*C*((B+C)>=4)||T*B*((B+T)>=4)||C*T*((C+T)>=4))
			t++;
			break;
		case 5:
			if(W*T*C||W*B*C*((B+C)>=4)||W*T*B*((B+T)>=4))
			t++;
			break;
		case 6:
			if(W*T*C*B||W*B*C*((B+C)>=4)||W*T*B*((B+T)>=4)||W*C*T*((C+T)>=4))
			t++;
			break;
	}
	return t;	
	}

