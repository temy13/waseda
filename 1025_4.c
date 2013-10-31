#include <stdio.h>
/*課題内容：
左右の括弧 “(”‘と“)”だけが並ぶ列を読み込み、それが整合している
（左右の括弧がきちんと対応している）か否かを判定するプログラムを作れ。*/
/*入力
入力は１行からなる。

出力
入力の中に現れた括弧が整合している場合は1を，右の括弧が多い場合は2を，左の括弧が多い場合は3を，１行として書き出せ。*/
/*1w120310-7 滝川真弘 10/27*/


int main(void){

	char c;
	char c_r = ')';
	char c_l =  '(';
	int right = 0,left = 0;
	int answer;

	//入力
	while (scanf("%c", &c) != EOF) {
		//(が入力されたらrightを＋＋
		if(c == c_r){
			right++;
			printf("right = %d\n",right);
		}else if(c == c_l){//)が入力されたらleftを＋＋
			left++;
			printf("left = %d\n",left);
		}

	}

	if(right == left){answer = 1;}
	else if(right > left){answer = 2;}
	else if(left < right){answer = 3;}

	printf("%d",answer);

	return 0;
}