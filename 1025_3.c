#include <stdio.h>

/*課題内容：
CSE商事では社員の在社時間をタイムカードで管理している。 社員は，出社すると専用の装置を使ってタイムカードに出社時刻を刻印する。
勤務を終え退社するときにも，タイムカードに退社時刻を刻印する。 時刻は24時間制で扱われる。
防犯上の理由から，社員の出社時刻は7時以降である。 また，全ての社員は23時より前に退社する。
社員の退社時刻は常に出社時刻より後である。
入力としてCSE商事の3人の社員Aさん，Bさん，Cさんの出社時刻と退社時刻が与えられたとき， 
それぞれの社員の在社時間を計算するプログラムを作成せよ。*/
/*1w120310-7 滝川真弘*/

#define MEMBER 3

int main(void){

	int i;
	int h_in[MEMBER], m_in[MEMBER], s_in[MEMBER], h_out[MEMBER], m_out[MEMBER], s_out[MEMBER]; //それぞれ入出時刻
	int a_h[MEMBER], a_m[MEMBER], a_s[MEMBER];//

	//入力
	for(i = 0; i < MEMBER; i++){
		scanf("%d%d%d%d%d%d",&h_in[i], &m_in[i], &s_in[i], &h_out[i], &m_out[i], &s_out[i]);
		//範囲チェック→範囲外だったらエラー
		if((h_in[i] < 7 ) || (h_out[i] < 7 ) || (h_in[i] > 22 ) || (h_in[i] > 22 ) || (m_in[i] < 0 ) || (m_out[i] > 59 ) || (s_in[i] < 0 ) || (s_out[i] > 59 )){
		//printf("error");
			return 0;
		}
	}
	


	//MEMBERの数だけ退社時間から入社時間を引く
	for( i = 0; i<MEMBER; i++){

		//秒
		if(s_out[i] >= s_in[i]){
			a_s[i] = s_out[i] - s_in[i];
		}else{//上の位（分）から60とってくる
			a_s[i] = 60 +  s_out[i] - s_in[i];
			//繰り上がりの関係で上の位(分）が1減る
			m_out[i]--;
		}
		//分
		if(m_out[i] >= m_in[i]){
			a_m[i] = m_out[i] - m_in[i];
		}else{
			a_m[i] = 60 + m_out[i] - m_in[i];
			//繰り上がりの関係で
			h_out[i]--;
		}
		//時
		if(h_out[i] >= h_in[i]){
			a_h[i] = h_out[i] - h_in[i];
		}else{
			printf("error");
		}

		//出力
		printf("%d %d %d\n",a_h[i],a_m[i],a_s[i]);

	}



	return 0;
}