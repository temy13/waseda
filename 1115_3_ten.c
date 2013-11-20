#include <stdio.h>
#include <stdlib.h>

/*課題内容：
数の十進表現は数字を並べ替えると別の数を表す。 このことを使って数列を作ってみる。
最初に，非負の整数 a0 と桁数  L を与える。 つぎの規則を適用して ai から  ai+1 を得る。整数 ai を，  L 桁の十進表現で表記する。 必要であれば上位の桁に   0 を付け加える。 たとえば  2012 という数は 6 桁の十進表現で表記する場合は  002012 となる。
   
各桁の数字を並べ替えて，最も大きい整数と最も小さい整数を作る。 上の例では，最も大きい整数は  221000 であり， 最も小さい整数は  000122 = 122 となる。    最も大きい整数から最も小さな整数を引いて，整数 ai+1 を得る。 上の例では  ai+1 = 221000 − 122 を計算して  ai+1 = 220878 を得る。
この計算を繰り返すと，数列 a0 ,  a1  ,  a2  , 。。。 が得られる。
整数を表すための桁数が指定されているので，a0, a1, a2,　… と順に計算していくといずれ同じ数が現れる。 
すなわち，条件 ai = aj   を満たすような i  と j  (ただし i  > j  ) の組が必ず存在する。
最初の整数 a0 と桁数 L  が与えられた場合に，条件 ai = aj (ただし i  > j  ) を満たす最小の i を求めるプログラムを作成せよ。

入力は，複数のデータセットからなる。 各データセットは2つの整数 a0  と  L  が1個のスペースで区切られた1行であり， a0    が最初の整数を， 
L が桁数を表す。 ただし， 1 ≤ L  ≤ 6 かつ 0 ≤ a0  < 10L である。
入力の終わりは2個の0を含む行で示される。この行はデータセットではない。

各データセットに対して，条件 ai = aj   ( i  > j ) を満たす最小の i  を求め， そのときの j の値，  ai の値， 
 i − j  の値をスペース1個ずつで区切り，1行で出力せよ。 数値を出力する時は，余分な上位のゼロがあってはならない。
出力に余分な文字は含んではならない。

上記の i  は20を超えないと仮定して構わない。*/

/*1w120310 滝川真弘　11/17*/

//iの上限は20と仮定する
#define I 20

//Lの上限は6 初期値の上限は1000000
#define L_MAX 6
#define MAX 1000000
//データの数の上限。本当はこういうの設定するの嫌いだけどこれ以外思いつかなかったから仕方ない
#define DATA_NUM 10000


//与えられた数字を並び替える
int MinSort(int number[], int L){
	
	int i,j,k,min,temp; //これはこの関数内だけに使用し、他の関数のi,jとは全く関係がない
	int keta = 1;
	int n = 0;//返す値
	

	//単純選択ソート
	for (i = 0; i < L - 1; i++) {
        min = number[i];                 /* i 番目の要素を暫定的に最小値とし */
        k = i;                        /* 添字を保存 */
        for (j = i + 1; j < L; j++) {
            if (number[j] < min) {       /* より小さい値が現れたら */
                min = number[j];         /* 最小値の入れ替え */
                k = j;                /* 添字を保存 */
            }
        }                             /* このループを抜けるとk に最小値の添字が入っている */
        temp = number[i];                /* i 番目の要素と最小値の交換 */
        number[i] = number[k];
        number[k] = temp;
    }
    //ソートした値をソートの上から位を上げつつ足していく
	for(i = L-1; i >= 0; i--){
		n += number[i] * keta;
		keta = keta * 10;
	}
	return n;
}

int MaxSort(int number[], int L){
	
	int i,j,k,min,temp; //これはこの関数内だけに使用し、他の関数のi,jとは全く関係がない
	int keta = 1;
	int n = 0;//返す値
	

	//単純選択ソート
	for (i = 0; i < L - 1; i++) {
        min = number[i];                 /* i 番目の要素を暫定的に最小値とし */
        k = i;                        /* 添字を保存 */
        for (j = i + 1; j < L; j++) {
            if (number[j] < min) {       /* より小さい値が現れたら */
                min = number[j];         /* 最小値の入れ替え */
                k = j;                /* 添字を保存 */
            }
        }                             /* このループを抜けるとk に最小値の添字が入っている */
        temp = number[i];                /* i 番目の要素と最小値の交換 */
        number[i] = number[k];
        number[k] = temp;
    }
    //ソートした値をソートの下から位を上げつつ足していく
	for(i = 0; i < L; i++){
		n += number[i] * keta;
		keta = keta * 10;
	}
	return n;
}

//データ処理
int data(int L, int a0,int number[]){
	
	int a[I];//入れ替わっていく数
	int i=0,j,k;
	int count = 0;//aの要素数
	int n; //なんかわかりづらくなりそうなのでnという変数を用意
	int ten = 10;//バラしていれる用
	int max,min;//入れ替えによって生じたmaxとmin
	
	a[0] = a0;
	count++;
	n = a0; //一度nに保存
	
	//hitするまで回す
	for(i = 1; i < I; i++){
		//入力された数値(a0)をそれぞれバラして配列numberに入れる
		for(k = 0; k < L; k++){
			if(n != 0){number[k] = (n % ten);
			//printf("%d",number[k]);
			n = n/10;
			}else{
				number[k] = 0;
			}
		}
	
		//並べかえて生まれる最大と最小
		max = MaxSort(number,L);
		min = MinSort(number,L);
		//引き算
		a[i] = max - min;
	
		//もしどっかで一致してたら表示してreturnする
		for(j = 0; j < count; j++){
			if(a[i] == a[j]){
				//表示
				printf("%d %d %d\n",j,a[i],i-j);
				return 0;
			}	
		}
		//個数をカウント
		count++;
		//今入れた値を記憶し同じことを
		n = a[j];
	}
	return 0;
}


int main(void){

	int L[DATA_NUM]; //桁数
	int a0[DATA_NUM];//最初の数
	int n = 0;	
	int k,l;
	int *number;//桁数だけ配列を用意
	
	while(scanf("%d%d",&a0[n],&L[n]) == 2){
		//0,0が入力されたら終わる
		if((a0[n] == 0) && (L[n] ==0)){
			break;
		}
		//入力された値が範囲外ならスキップ
		if((L[n] < 1) || (L[n] > L_MAX) ||( a0[n] < 0) || (a0[n] > MAX)){
			continue;
		}
		n++;

	}
	
	for(l = 0; l < n; l++){
		
				// 動的に確保
		number = (int*)malloc(sizeof(int)*L[l]);
			if (number == NULL) {
		    //printf( "memory allocation error\n" );
		    return 0;
		  }
		//初期化
		for(k = 0;k< L[l];k++){
			number[l] = 0;
		}
		data(L[l],a0[l],number);
		free(number);
		
	}

	return 0;
}

