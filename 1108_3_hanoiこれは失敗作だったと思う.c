#include <stdio.h>
#include <stdlib.h>

void Print(int **ary,int nn)
{
	
	int left = ary[0][0];
	int center = ary[1][0];
	int right = ary[2][0];
	int i;
	
	//printf("L:%d C:%d R:%d\n",left,center,right);
	//ループで表示(ディスク番号を1から始めているためそれぞれ-1する。また0は空白を意味するので'.'を出力する
	for (i = nn; i > 0; i--)
  {
  	if(ary[0][i] == 0){
  	printf(".");
  	}else{
    printf("%d",ary[0][i]-1);
		}
  }
  printf(" ");
  	for (i = nn; i > 0; i--)
  {
    if(ary[1][i] == 0){
  	printf(".");
  	}else{
    printf("%d",ary[1][i]-1);
		}
  }
  printf(" ");
 	for (i = nn; i > 0; i--)
  {
    if(ary[2][i] == 0){
  	printf(".");
  	}else{
    printf("%d",ary[2][i]-1);
		}
  }
  printf("\n");
  
  //表示ここまで
}

void Hanoi(int n, int from, int work, int dest, int** ary,int nn){
	
	int i = 1;
	
	if(n>=2){Hanoi(n-1, from, dest, work, ary,nn);}	
	
	//ary[from]の一番上の数をary[dest]のできる限り下に置く
	ary[dest][ary[dest][0]+1] = ary[from][ary[from][0]];
	 ary[from][ary[from][0]] =0;
	//枚数の合計を記録する
	ary[from][0]--;
	ary[dest][0]++;
	
	Print(ary,nn);

	if(n>=2){Hanoi(n-1, work, from, dest, ary,nn);}
}

int main(void){
	int n;	//値入力用
	int i,j,nn;//ループ用、nの値記録用×②
	int *ary[3];//塔の数

	//printf("ディスクは何枚ですか ");
	scanf("%d",&n);	//nの値を入力
	
	//ｎの値をnnとして保存
  	nn=n;
	j = n;
	//枚数分の配列を確保
	for (i = 0; i < 3; i++)
  {
    ary[i] = malloc(sizeof(int) * n+1);
  }
	//ary0(left)に枚数を入れる
	ary[0][0] = n;
	//0にディスクの数字を上から入れる
	for (i = 1; i < n+1; i++)
  {
    ary[0][i] = j;
	j--;
  }
  //それ以外に空の証として0を入れる
  for (i = 1; i < n+1; i++)
  {
    ary[1][i] = 0;
    ary[2][i] = 0;
  }
  //ｎの値をnnとして保存
  nn=n;
  
  Print(ary,n);
	Hanoi(n,0,1,2,ary,nn);

	return 0;
}
