#include <stdio.h>
#include <stdlib.h>
/*正方形を隣接するように並べていき、最後のその並べ終わった
正方形がすべてはいるような長方形を用意する*/

/*1w120310 滝川真弘 12/19 */
#define N 200

//正方形のデータ
struct Data{
	int index; /*番号*/
	int width;	/* 中心からの横の距離 */
	int height;	/* 中心からの縦の距離 */
	struct Data *next;
};


int main(void){
	int n; // 要素数
	int i;
	int now,d; //その時隣接させる正方形の番号と隣接させる向き。0→左 1→下 2→右 3→上
	int count = 0; //何回この作業を行ったか
	int width_n,height_n; //隣接させる正方形の状態
	int max_width = 0, max_height = 0, min_width = 0, min_height = 0; //最後の状態のMAX,MINの横と縦
	int width,height; //最終的な縦と横の長さ
	struct Data *head,*p,*q;
	//最後の表示用
	int last_width[N]; 
	int last_height[N];
	
	while(1){
	//初期化
	max_width = 0;
	max_height = 0;
	min_width = 0;
	min_height = 0;
printf("start\n");
	//一番初めにheadの定義と0番目の正方形の定義
	head = (struct Data *)malloc( sizeof(struct Data));
	//ここを見ることがあってはならないので、indexは負の値に。
	head->index = -1;
	head->width = 0;
	head->height = 0;
	//0番目の正方形の定義
	p = (struct Data *)malloc( sizeof(struct Data));
	head->next = p;
	p->index = 0;
	//本来1×1の正方形だが、マイナスを考慮するため0とする 最後の１を足してこの部分をつけたす
	p->width = 0;
	p->height = 0;
	scanf("%d",&n);
	if( n == 0) break;
	//n回正方形を敷き詰める
printf("n = %d\n",n);
		for(i = 1; i < n; i++){
			scanf("%d%d",&now,&d);
			p->next = (struct Data *)malloc( sizeof(struct Data)); //新しく構造体を確保
			p = p->next; //pを新しい構造体に移動
			p->next = NULL; //次の構造体はまだない
			p->index = i; //indexに今の番号を表示
			//構造体を見て言ってnowの数字をもつ正方形を探す
			for(q = head; q!=NULL; q = q->next){
				if(q->index == now){
					width_n = q->width;
					height_n = q->height;
					break;
					}
				}
			//dの番号に従って中心からの距離を追記する
			switch(d){
				case 0:
					p->width = width_n -1;
					p->height = height_n;
					break;
				case 1:
					p->width = width_n;
					p->height = height_n-1;
					break;
				case 2:
					p->width = width_n +1;
					p->height = height_n;
					break;
				case 3:
					p->width = width_n;
					p->height = height_n+1;
					break;
				}
			}
		//全部終わったので最大最小の更新
		for(q = head; q!=NULL; q = q->next){
			if(max_width < q->width) max_width = q->width;
			if(min_width > q->width) min_width = q->width;
			if(max_height< q->height)max_height= q->height;
			if(min_height> q->height)min_height= q->height;
				}
		//最初の値を0としているためつじつまを合わせながら
		width = max_width - min_width + 1;
		height= max_height- min_height+ 1;
		last_width[count] = width;
		last_height[count]= height;
		//何回この作業をやったかのカウント
		count++;
	}
	for(i =0; i < count; i++){
		printf("%d %d\n",last_width[i],last_height[i]);
	}
	return 0;
}
