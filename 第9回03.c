
/*15個のパネルを移動させるプログラム。*/
/* なぜかchar型でやると結果は正しいのに自動採点だとエラー吐かれるので全部数字にして再挑戦*/

/* 1w120310-7 滝川真弘 20140129*/

#include <stdio.h>
#include <string.h>

int main(void){
    
    
    int i,j,point[16]; //ループ用 15個のパネルを入れる配列 
    int blank = 16;	 //空白は16とする
    char move[1000] = "";   //移動する命令
    
    //パズルに数字を入れていく
    for(i = 0; i < 16; i++){
        point[i] = i + 1;
    }
    
    scanf("%s",move); //命令の入力
	//命令に従って移動する
    for(i=0;i<strlen(move);i++){
        //previous→上
        if(move[i] == 'p'){
            for(j = 0;j < 16; j++){
                if(point[j] == 16){
                    point[j] = point[j-4];
                    point[j-4] = blank;
                }
            }
        }
        //next→下
        if(move[i] == 'n'){
            for(j = 0; j < 16; j++){
                if(point[j] == 16){
                    point[j] = point[j+4];
                    point[j+4] = blank;
                    break;
                }
            }
        }
        //backward→左
        if(move[i] == 'b'){
            for(j = 0; j < 16; j++){
                if(point[j] == 16){
                    point[j] = point[j-1];
                    point[j-1] = blank;
                }
            }
        }
        //forward→右
        if(move[i] == 'f'){
            for(j=0;j<16;j++){
                if(point[j] == 16){
                    point[j] = point[j+1];
                    point[j+1] = blank;
                    break;
                }
            }
        }
    }
    //出力
    for( i = 0 ; i < 16 ; i++){
        //数字の部分はそのまま
        if(point[i] < 10){
            printf("%d",point[i]);
        }
        //英語の部分は変換
        else if(9 < point[i] && point[i] < 16){
            printf("%c",point[i]-10+'a');
        }
        //blank(=16)なら-
        else if(point[i] == 16){
            printf("-");
        }
        //4つ目までは空白
        if((i+1)%4 != 0){
            printf(" ");
        }
        //4つごとに改行
        if((i+1)%4 == 0){
            printf("\n");
        }
    }
    return 0;
    
}
