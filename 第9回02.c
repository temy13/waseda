

/* 迷路の最短距離 */
/* 1w1203107 滝川真弘  20140129*/

#include <stdio.h>

#define F 1000

//距離→point、コスト→cost、使用済みかどうか→used、更新したときの場所→next
int n,point[F][F],cost[F],used[F],next[F];

//ダイクストラ法
void search(int goal){
 
    int x, y, min;
    //初期化しておく。
    //すべてのコストを無限大→どの点も使っていないということに
    for(x=0;x<n;x++){
        cost[x] = F;
        used[x] = 0;
        next[x] = F;
    }
    cost[goal] = 0; //ゴールのコスト→0
    next[goal] = goal; //goalでコストを更新したことを記録
    
    while(1){  //すべての点を使用済みにするまで繰り返す。
        
        //まず最小の値を無限大
        min = F;
        
        for(x=0;x<n;x++){
            if(used[x] == 0 && min > cost[x]){ //その点を使用しておらず、かつ最小値がコストより大きかったら
                //最小値をコストに
                min = cost[x];
                //yにその位置を記録
                y = x;
            }
        }
        //もし発見できなければ探索を終了する。
        if(min == F){
            break;
    }
        //ｙでコストを更新
        for(x=0;x<n;x++){
            if(cost[x] > point[x][y] + cost[y]){
                //yで更新したことを記録
                next[x] = y;
                cost[x] = point[x][y] + cost[y];
            }
        }
        //yを使用済みに
        used[y] = 1;
    }
}

int main(void){
    
    int x,y,z,i,j;
    //点の数
    scanf("%d",&n);
    //ポイントはすべて無限大
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            point[i][j] = F;
        }
    }
    //道がある場所には距離z
    while(scanf("%d%d%d",&x,&y,&z) != EOF){
        point[x][y] = point[y][x] = z;
    }
    //1までの距離を探索する。
    search(1);
    //0から1までの最短距離を出力する。
    printf("%d\n",cost[0]);
    return 0;
}
