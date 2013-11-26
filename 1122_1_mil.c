#include <stdio.h>
#include <stdlib.h>
/*賢王が新しい暦を定めた．「明日を1年1月1日と定める．1年には1月から10月までの10ヶ月があり，大の月から始まる．ふつうの年は，1月が大の月，2月は小の月，3月は大の月，
そして最後の10月は小の月というように，大の月と小の月が交互に訪れる．大の月の日数は20日，小の月の日数は19日である．
しかし，3年，6年，9年，…のように，3で割り切れる年には，小の月は訪れず，10すべての月を大の月とする．」

幾年月が流れた．やがて1000年1月1日のミレニアム記念日の祝賀式において，
誕生してからの日数が王立のくじ引きで選ばれた数と一致する国民に景品を与えることになった．
国民らを手助けして，生まれた日からミレニアム記念日までの日数を計算するプログラムを奉ぜよ．*/

/*1w120310-7 滝川真弘 11/23*/
/*
1. 月末までの日数を求める 
2. これに、年末まで各月の日数を加算する 
3. さらに、翌年から 999 年まで各年の日数を加算する 
4. これに 1 加えると、1000 年 1 月 1 日までの日数となる 
*/

//ミレニアムまでの年
#define MIL 1000
//大の月
#define MAJ 20
//小の月
#define MIN 19
//一年の月の数
#define MONTH 10

//	大の月なら 20、小の月なら 19 を返す	
int	ndm(int	y,int m)	
{
	//年が3で割り切れるか奇数月なら大月
	if( (y % 3 == 0) || (m % 2 == 1)){
		return MAJ;
	}else{
		return MIN;
	}
}

int days(int y, int m, int d){
	
	int ans;
	int i;
	//まず月末まで(生まれた日含める)
	ans = ndm(y,m)  - d + 1;
	//次に年末まで
	for(i = m+1; i <= MONTH; i++){
		ans +=ndm(y,i);
	}
	
	//999年10/20まで
	for(i = y + 1; i<=999; i++){
		if(i % 3 == 0){ //3で割り切れたら
			ans += (MAJ*10);
		}else{ //違ったら
			ans +=( (MAJ + MIN)*5);
		}
	}
	
	return ans;
	}	

int main(void){
	
	int n; //データ数
	int *y,*m,*d;//それぞれの誕生日
	int i;//ループ用
	int year,month,day;
	int ans;
	
	scanf("%d",&n);
	//データ数だけmallocで確保
	y = malloc(sizeof(int)*n);
	if (y == NULL) {
    //printf( "memory allocation error\n" );
    return 0;
  }
	m = malloc(sizeof(int)*n);
	if (m == NULL) {
    //printf( "memory allocation error\n" );
    return 0;
  }
	d = malloc(sizeof(int)*n);
	if (d == NULL) {
    //printf( "memory allocation error\n" );
    return 0;
  }
  //データ入力
	for(i = 0; i<n;i++){
		scanf("%d%d%d",&y[i],&m[i],&d[i]);
	}
	//日数の計算
	for(i = 0; i<n;i++){
		
		ans = days(y[i],m[i],d[i]);
		printf("%d\n",ans);
	}
	
	
return 0;	
}