#include <stdio.h>
#include <stdlib.h>

/*課題内容：
将棋の駒の飛車は，上下方向，左右方向に升目があいている限りどこへでも移動できる。
特に，空いているその先に敵の駒があれば，その位置に進んでその駒を取ることができる。さらに，飛車は，成ると竜となり，左右斜め前および左右斜め後の４つの升目にある敵の駒も取ることができるようになる。将棋の駒に取って取ることのできる位置にある（敵の）駒を当たりの駒という。

正整数 n について n×n の升目をもつ盤を考え，その上に n 個の竜を
互いに当たりにならないように配置することを考え，可能な配置の総数を出力するプログラムを作れ。
　
入力は，正整数 n だけを並べた１行からなる。

出力は，可能な配置の総数だけを１行として書き出せ。*/
/*1w120310 滝川真弘*/

/*まず、飛車の性質上その横は全域だめなのだから、そもそもカウントしない
次に、その縦もダメなのだから、配列を用いてその縦がダメな印をつける。
次に、飛車が置かれた次の行の±１もNG　0はもちろん縦だから駄目*/




//現在の盤の状態とひとつ前の行がどこに置かれたかのデータをもって、次の行のおける場所を探す
int search(int *x, int *y, int prev,int gyo,int n){
	int *new_x;
	int *new_y; //今見ている行の状態を記す配列を作る　1→使えない 0→使える
	int i,j;
	int count = 0;
	new_x = malloc(sizeof(int)*n);
	new_y = malloc(sizeof(int)*n);
	//初期化	
	for(i = 0; i< n; i++){
 		new_x[i] = 0;
 		new_y[i] = y[i];
 	}
 	//今見ている行をすべて見ていき、
	for( i = 0; i<n; i++){
		//ひとつ前の行においてある飛車±1の範囲とすでにどこかの列におかれてある場合はNG
		if((new_y[i] != 1) && (i != prev+1) && (i != prev-1)){//だからそれ以外の場所があればそこにおける
			//仮においてみる
			new_x[gyo] = 1;
			new_y[i] = 1;
			//再起して次の行へ(次の行がなかったらしない。
			if(gyo+1 < n){
				count += search(new_x,new_y,i,gyo+1,n);
			}else{//最終まで行ったのなら、countを返す
				count++;
				return count;
			}
			//帰ってきたらもとの盤の状態に戻す
			for(j = 0; j< n; j++){
		 		new_x[j] = 0;
		 		new_y[j] = y[j];
		 	}
			
		}else{
				new_x[i] = 1;
		}
	}
	return count;
}

int main(void){
	
	int n;
	int *x; //行を見て、その行が入っていたら１ないなら0
	int *y; //列を見て、その列が入っていたら１ないなら0
	
	int i;
	int retu = 0; //考察するべき回数。可能な配列数はどんなに頑張ってもnは超えない。
	int count = 0;
	
	scanf("%d",&n);
	/*それぞれ確保する*/
	x = malloc(sizeof(int)*n);
	if (x == NULL) {
	   //printf( "memory allocation error\n" );
	   return 0;
 	 }
	y = malloc(sizeof(int)*n);
	if (y == NULL) {
	    //printf( "memory allocation error\n" );
	    return 0;
 	 }
 
 	//初期化
 	for(i = 0; i< n; i++){
 		x[i] = 0;
 		y[i] = 0;
 	}
 	i = 0;
 	//n回考察
 	while( retu < n){
 	
 		//一番最初
 		x[0]=1; //第0番目の横は使用禁止
 		y[retu]=1; //第retu番目の縦は使用禁止
 		count += search(x,y,retu,1,n); //xの状態、yの状態、
 		//この回が終わったので、盤の状態を初期化
 		for(i = 0; i< n; i++){
	 		x[i] = 0;
	 		y[i] = 0;
 		}
 		
 		retu++;
 		
 	}
	
	
	printf("%d\n",count);
	
	return 0;
}