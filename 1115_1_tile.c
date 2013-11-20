#include <stdio.h>
#include <stdlib.h>

/*入力
入力は全部で 2 + K 行からなる  。 1 行目には，壁画の一辺の長さ  N （1 ≦ N ≦ 1000000000 = 109) が，
 2 行目には，はがれたタイルの枚数  K（1 ≦ K ≦ 1000） が書かれている  。  2+i 行目 （1 ≦ i ≦ K） には
2 つの整数  ai と bi （1 ≦ ai ≦ N, 1 ≦ bi ≦ N） が空白区切りで書かれており， i 枚目のはがれたタイルが， 左から ai 列目，上から bi 行目のタイルであることを表す。
入力の 3 行目から 2 + K 行目には同じタイルを表す行が重複して現れることはない。 また，与えられる入力データ 
 40% では，  N ≦ 1000 をみたしている。
出力
出力は  K 行からなる。 各行は 1 つの整数からなり，  i 行目（1 ≦ i ≦ K）の整数は，
i 枚目のはがれたタイルが赤のときは 1 を，青のときは 2 を，黄色のときは 3 を表す  */

/*1w120310-7 滝川真弘  11/17*/

/*一番最初はすべてのタイルの色を記憶した後、入力されたx,yの値の位置の色を出力する方法を考えたが、計算量が多すぎると判断し
x,yの数値から壁までの距離をそれぞれ（4方向)出し、一番小さいものを3で割る方法を用いた*/

//最小値を出す
int Min(unsigned long right, unsigned long left, unsigned long up, unsigned long down){
	
	unsigned long min;
	min = right;
	if(min > left){
		min = left;
	}
	if(min > up){
		min = up;
	}
	if(min > down){
		min = down;
	}
	return min;
	
}

int main(void){

unsigned long n;
int k; //それぞれのデータ
int i;//ループ用
unsigned long *x,*y;;
unsigned long right,left,up,down; //4方向への距離
int color;

//入力
scanf("%ld",&n);
scanf("%d",&k);

//入力される位置のデータ分を動的に確保
x = malloc(sizeof(unsigned long)*k);
	if (x == NULL) {
    //printf( "memory allocation error\n" );
    return 0;
  }
y = malloc(sizeof(unsigned long)*k);
	if (y == NULL) {
    //printf( "memory allocation error\n" );
    return 0;
  }
for(i = 0; i< k; i++){
		scanf("%ld%ld",&x[i],&y[i]);
}

//タイルの色を把握する
for(i = 0; i<k; i++){
	
	right = x[i] -1;
	left = n-x[i];
	up = y[i] - 1;
	down = n -y[i];
	
	switch(Min(right,left,up,down) % 3){
		case 0:
			color = 1;
			break;
		case 1:
			color = 2;
			break;
		case 2:
			color = 3;
			break;
		}
	printf("%d\n",color);
}


	
	return 0;
}

