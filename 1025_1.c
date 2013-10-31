#include <stdio.h>


/*CSEパスタ店では，ランチのおすすめパスタと搾りたてジュースのセットメニューが好評である。このセットメニューを注文するときは，その日の 3 種類のパスタと 2 種類のジュースから 1 つずつ選ぶ。パスタとジュースの値段の合計から 50 円を引いた金額が代金となる。

ある日のパスタとジュースの値段が与えられたとき，その日のセットメニューの代金の最小値を求めるプログラムを作成せよ。*/
/*1w120310-7 滝川真弘 10/25*/

#define PASTA 3
#define DRINK 2
#define MAX 2000
#define MIN 100

int main(void){

	int i;
	int temp = 0;
	int p = MAX; //最小値にはMAXの値を入れておく
	int d = MAX;



	//入力
	for(i = 0; i< PASTA; i++){
		scanf("%d",&temp);
		if((temp >= MIN) && (temp < p)){ //100以上でかつ最小値より低かったら上書きだったら入れる
			p = temp;
		}
	}
	for(i = 0; i< DRINK; i++){
		scanf("%d",&temp);
		if((temp >= MIN) && (temp < d)){ //100~2000でかつ最小値より低かったら上書きだったら入れる
			d = temp;
		}
	}

	//出力
	printf("%d",(p+d-50));





	return 0;
}
