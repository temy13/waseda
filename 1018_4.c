#include<stdio.h>
#include <stdlib.h>

/*n 個の整数からなる数列 a1, a2, ..., an と正整数 k (1≦k≦n) が
与えられる．このとき，連続して並ぶ k 個の整数の和 Si = ai + ai+1 + ･･･+ ai+k-1 (1≦i≦n-k+1)
の最大値を出力するプログラムを作りなさい．*/
/*1w120310-7 滝川真弘 10/21*/

#define N 100000

int main(void){
	int n,k;//数の指定
	int *a;//nこ
	int S;//sum
	int i,j,temp;//ル―プ用
	int max = 0; //最大値
	int nk; //n-k+1

	//入力
	scanf("%d%d",&n,&k);
	//ｎが範囲外ならエラー
	if((n < 1) || ( n > N)){
		//printf("範囲外です\n");
		return 0;
	}
	//kが範囲外ならerror
	if((k < 1) || ( k > n)){
		//printf("範囲外です\n");
		return 0;
	}

	nk = n-k+1;
	
	//aの配列をnこmallocで確保する
	a = (int*)malloc(n*sizeof(int));
	if (a == NULL) 
      { //printf("Insufficient memory.\n"); 
	return 0; }




	
	//nこaiに値を入れていく
	for(i = 0; i < n; i++){
		scanf("%d",&temp);
		//a[i]を初期化
		a[i] = 0;
		//tempが範囲内ならa[i]に
		if((temp >= -1*N) && ( temp <= N)){
			a[i] = temp;
		}
	}
	
	//Siの計算
	for(i = 0; i < nk; i++){
		//Siの初期化
		S = 0;
		//Siにiからkこaの値を入れていく
		for(j = i; j < i+k; j++){
			S = S + a[j];
		}
		//Siの値がmaxより大きかったら上書き
		if(S > max){
			max = S;
		}
	}

	//出力
	printf("%d",max);

	//使ったmallocの部分を解放
	free(a);
	return 0;
}
