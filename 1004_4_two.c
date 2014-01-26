#include <stdio.h>
#include <math.h>
/*桁数 n (0 ＜ n ＜ 75 ) が入力から与えられると，その桁数まで（の十進数）で表せる最大の 2 の冪 2^k を左詰めで表示するプログラムを作れ。
範囲外の数字を入力した場合はerrorと出力して終わるようにすること。*/
/*1w120310 滝川真弘 提出日 10/06*/

#define  MAX 100 //多倍長における一つの配列の中の上限(double)
#define NUMBER 100 //用意する配列の数

int tabai(int count){

	double a[NUMBER];
	double ans;
	int i,n,j;
	int up; //繰り上がり
	int up_count = 0; //どの桁まで入っているか 
	//初期設定
	for(i =0 ; i < NUMBER; i++){
		a[i] = 0;
	}
	a[0] = 1;
	
	for(i = 0; i < count; i++){
		n = 0;
		up = 0;
		for(n = 0; n < up_count + 1; n++){
			printf("i=%d\n",i);
			printf("a[n]=%lf\n",a[n]);
			ans = a[n] * 2 + up;
			
			if(ans > MAX){ //ansが指定した上限より超えていたら
				a[n] = ans - MAX; //超えないように引き算して
				up = 1; //繰り上げる
					if(a[n+1] == 0){ //もし次の桁が0だったら＝新しく入る領域だったら
								up_count++;
							}
			}else { //超えていなかったら
				a[n] = ans; //そのまま代入
				up = 0; //繰り上がりはない
			}
		}	
	}
	//出力
	for(j = up_count ; j >= 0 ; j--){
		printf("%.0lf",a[j]);
		}
	return 0;
}

int main(void){

	int n; //入力される値
	double keta;
	//int x = 0;
	int count = 0;

	scanf("%d",&n);
	//範囲内かどうか
	if((0 < n) && (n < 75)){
		//桁数を用意する
		keta = pow(10.0 , n);
		
		//その桁を2進数に直しその桁を数える
		while( keta > 2){ 
			keta = keta/2.0; 
			count++; 
			}
	
		//多倍長計算させる
		tabai(count);
	//範囲外ならエラー
	}else{
		printf("error");
	}
	return 0;
}

