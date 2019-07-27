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
	printf("扩充补给池概率模拟请输入0\n精准补给池模拟请输入1\n");
	scanf("%d", &n1);
	if(n1==0){
		printf("请分别输入一次抽多少张补给卡，且需要抽几个角色卡(中间用空格分隔)\n");
		scanf("%d %d", &n2, &n3);
        x=100*P_kc(n2,n3);
        printf("模拟得概率约为"); 
	    printf("%lf", x);
	    printf("%\n");
	}
	else{
		printf("请输入一次抽多少张补给卡\n");
		scanf("%d", &n4); 
		printf("请选择模拟类型\n1.抽出up内武器\n2.抽出up内指定一件圣痕\n3.抽出up内指定两件套\n4.抽出up内三件套\n5.抽出up内武器+指定两件套\n6.抽出up内武器+三件套\n");
		x=100*P_jz(n4);
		printf("模拟得概率约为"); 
	    printf("%lf", x);
	    printf("%\n");	
	}
    system("pause");
	return 0;
} 

double P_kc(int N, int requiredn){
	int snumber=0, k_10=0, k_100=0, i=0, j=0, n=0;
	double s, P, G;
	double a=0.09427342057266558;/*变量申明和初始化*/ 
	srand((int)time(0));/*为随机函数生成种子*/
	for(i=1;i<=1000000;i++){
		snumber=0;
		k_10=0;
		k_100=0;/*保底重置*/
		for(j=1;j<=N;j++){
			if(k_100==99){
				k_10=0;
				k_100=0;
				snumber++;/*一百连保底的情况*/ 
			}
			else if(k_10==9){
				k_10=0;
				k_100++;/*十连保底的情况*/	
				n=rand()%10;
				if(n==0){
				snumber++;
				k_100=0;/*十连保底抽出s的情况（概率为1/10，通过随机函数实现模拟）*/	
				}
			}
			else {
			s=(double)rand()/RAND_MAX;
			if(s<=a)/*单抽抽出紫的情况*/
			{
				k_10=0;
				k_100++;
				n=rand()%10;
				if(n==0){/*单抽抽出s的情况*/
				snumber++;
				k_100=0;	
			}
			}
			else{
				k_10++;
				k_100++;
			}
			}
			if(snumber==requiredn){/*判断是否满足条件*/
				G++;
				break;
			}	
		}		
	}
    P=G/1000000;/*满足条件的情况的频率（可视作概率）*/ 
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

