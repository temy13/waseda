#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*課題内容：
英単語が１個以上の空白類（空白または改行）で区切られて並んでいるとする。入力の中で辞書順で一番若い単語
（通常の英語辞書の見出しとして最も前にくる単語）を出力するプログラムを作れ。*/
/*1w120310-7 滝川真弘*/


//最長の英単語が20万なので100万文字用意すればすべて入ると判断
//と思ったのですが100万はいらなかったので10万で妥協
#define MAX 100000

 /* 文字列中の英大文字を小文字に変換 */
char StrToLower(char str[])
{
   int length,i;

   length=strlen(str);

   for(i = 0; i < length; i++){

	   str[i] = tolower(str[i]);
   }

   

}

int main(void){
	char min[MAX];//最小
	char s[MAX];//入力する値
	char temp[MAX];//大文字を小文字に変換するとき一時的に保存する
	char min_temp[MAX];//もし大文字の単語が入力された場合、小文字に変換したminをここに入れる
	

	scanf("%s",min); //一つ目を基準に
	//min_tempにコピーして、min_tempの中身が大文字なら小文字に変換する
	strcpy(min_temp,min);
	StrToLower(min_temp);


	//入力
	while(scanf("%s", s) != EOF){
		//辞書的に比べる
	strcpy(temp,s);//一度tempに保存し、
	StrToLower(temp);//もし大文字なら小文字に直す
		//小文字同士で比べる
		if(strcmp(temp,min_temp) < 0){//minより小さかったら
			strcpy(min_temp,temp);//小文字のものを上書き
			strcpy(min,s);//元のものも上書き
		}
		
		
	}
	
	printf("%s",min);


	return 0;
}

