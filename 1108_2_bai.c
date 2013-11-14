#include <stdio.h>


/*課題内容：
入力された2つの正整数値の最小公倍数を計算して出力するプログラムを作れ。
入力は，2つの正整数を空白１個で区切って並べた１行として与えられる。
出力は，最小公倍数だけを１行として書き出せ。
*/
/*1w120310-7 滝川真弘　11/09*/

int main(void){

	unsigned long x,y;
	unsigned long a,b; 
	unsigned long temp,r;
	

	scanf("%ld%ld",&x,&y);

	//力任せのループより、先に公約数を見つけてそれを割る方法が早いと判断した
	//ユークリッドの互除法
	//a<bだとしたら値を入れ替える
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	//値をa,bに保存
	a = x;
	b = y;
	// a/bのあまりが0になるまでループする
	while((r = a % b) != 0 ){
		//0じゃなかったらユークリッドの互除法によりa←b b←rとし、もう一度
		a = b;
		b = r;
	}
	//出力
	printf("xy = %ld\n",x*y);
	printf("%ld",(x*y)/b);


	return 0;
}