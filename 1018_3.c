#include <stdio.h>
#include <string.h>
/*あなたはN個の指輪を持っている．どの指輪にも，アルファベットの大文字10文字からなる文字列が刻印されている．
指輪には文字列の最初と最後がつながった形で文字が刻印されている．指輪に刻印された文字列を逆順に読む心配はない．
探したい文字列が与えられたとき，その文字列を含む指輪が何個あるかを求めるプログラムを作成せよ．*/


/*1w120310-7 滝川真弘　10/20*/

#define N 10 //ringに書かれる文字の数


int main(void){

	//文字配列は、誤って10文字以上入力されることを考慮しすこし多めにとっておく
	char s[256]; //探し出す文字列
	int n; //所有するリングの数
	int i = 0 , j = 0 , k = 0; //ループ時のカウント用
	char ring[256]; //リングにある文字
	int count = 0; //個数を数える
	int boolean = 0; //検索のとき使う
	char *str;
	char cpy[256];
	int len;

	//検索する文字列の入力
	scanf("%s",s);
	//文字数が範囲内かどうか
	if((strlen(s) < 1) || (strlen(s) > N)){
		//printf("範囲外です");
		return 0;
	}
	//ringの数Nの入力
	scanf("%d",&n);
	for(i = 0; i< n; i++){
		scanf("%s",ring);
		//ringの文字数がNと一致するか否か
		len = strlen(ring);
		if(len == N){
		//ringからsを検索 ふつうにやると今回は輪なのでstrstrは使えない。
		strcpy(cpy,ring);
		strcat(ring,cpy);
		str = strstr(ring,s);
			if(str != NULL){
			count++;
				}
			printf("%s\n",ring);
			}
		
		}
		//出力
	printf("%d",count);

	return 0;


	}

	