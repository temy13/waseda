
/*字下げの文法を定めたプログラム Stylish */
/* 1w120310-7 滝川真弘 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isvalid(int r,int c,int s,int data[][3],int indent[],int p);
int calc(int count[],int cand[]);

int main(void){

    char data[81],data2[81];
    int p,q;
    int datacount[3],datacountrecord[1000][3],*indent;
    int datacount2[3],datacountrecord2[1000][3];
    int ans[100][1000],Q[100];
    int i,j,length,length2,r,c,s;
    int cand[3],cand2[3],value1,value2,Num=0;
    int first;
    int *isNA;
    
    //配列ansを初期化
    for(i=0;i<100;i++){
        for(j=0;j<1000;j++){
            ans[i][j] = 0;
        }
    }
    
    //終端記号00が入力されるまでループ
    while(1){
        
        //ルールを読み取る範囲とそれを活用する範囲
        scanf("%d%d",&p,&q);

        //Qにqを記録
        Q[Num] = q;
        
        //もし00と入力された場合、break
        if(p==0 && q==0){
            break;
        }
        
        //各配列を初期化しておく。
        indent = malloc(p*sizeof(int));
        for(i=0;i<p;i++){
            indent[i] = 0;
        }
        for(i=0;i<3;i++){
            datacount[i] = 0;
        }
        for(i=0;i<1000;i++){
            for(j=0;j<3;j++){
                datacountrecord[i][j] = 0;
            }
        }
        
        for(i = 0; i < p+1; i++){
            gets(data);
            length = strlen(data);
            //もし先頭が.の場合、.の数をindentに代入する。
            for(j = 0; j < length; j++){
                if(data[j] != '.'){
                    break;
                }
                indent[i-1]++;
            }
            //実行部における各行のかっこの数を数える。
            datacountrecord[i-1][0] = datacount[0];
            datacountrecord[i-1][1] = datacount[1];
            datacountrecord[i-1][2] = datacount[2];
            
            //かっこ始めの場合は加算、かっこ終わりの場合は減算
            for(j = 0; j < length; j++){
                if(data[j] == '('){
                    datacount[0]++;
                }if(data[j] == ')'){
                    datacount[0]--;
                }
                if(data[j] == '{'){
                    datacount[1]++;
                }if(data[j] == '}'){
                    datacount[1]--;
                }
                if(data[j] == '['){
                    datacount[2]++;
                }if(data[j] == ']'){
                    datacount[2]--;
                }
            }
        }
        //実行部に移るため、ここでまた各配列を初期化
        for(i = 0; i < 3; i++){
            datacount2[i] = 0;
        }
        for(i = 0;i < 1000; i++){
            for(j = 0; j < 3; j++){
                datacountrecord2[i][j] = 0;
            }
        }
        for(i = 0; i < q; i++){
        
            gets(data2);
            length2 = strlen(data2);
            //実行部における各行のかっこの数を数える。
            datacountrecord2[i][0] = datacount2[0];
            datacountrecord2[i][1] = datacount2[1];
            datacountrecord2[i][2] = datacount2[2];
            
            //かっこ始めの場合は加算、かっこ終わりの場合は減算する。
            for(j = 0; j < length2; j++){
                if(data2[j] == '('){
                    datacount2[0]++;
                }
                if(data2[j] == ')'){
                    datacount2[0]--;
                }
                if(data2[j] == '{'){
                    datacount2[1]++;
                }
                if(data2[j] == '}'){
                    datacount2[1]--;
                }
                if(data2[j] == '['){
                    datacount2[2]++;
                }
                if(data2[j] == ']'){
                    datacount2[2]--;
                }
            }
            
    }
        for(i = 0; i < 3; i++){
            cand[i]=0;
    }
        first = 1;
        isNA = malloc(q*sizeof(int));
        
        for(i = 0; i < q; i++){
            *(isNA+i) = 0;
        }
        //r,c,sのあらゆる組み合わせを試す
        for(r = 1; r <= 20; r++){
            for(c = 1;c <= 20; c++){
                for(s = 1; s <= 20; s++){
                    if(isvalid(r,c,s,datacountrecord,indent,p)==1){
                        if(first==1){
                            first = 0;
                            cand[0] = r;
                            cand[1] = c;
                            cand[2] = s;
                        }else{
                            cand2[0] = r;
                            cand2[1] = c;
                            cand2[2] = s;
                            for(i=0;i<q;i++){
                                if(isNA[i] == 1){
                                    continue;
                                }
                                value1 = calc(datacountrecord2[i],cand);
                                value2 = calc(datacountrecord2[i],cand2);
                                if(value1 != value2){
                                    isNA[i] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        //後に答えとして出力するため、インデントの数をansに収納する。
        for(i=0;i<q;i++){
            //特定できない場合は時は-1。
            if(isNA[i] == 1){
                ans[Num][i] = -1;
            }else{
                value1 = calc(datacountrecord2[i],cand);
                ans[Num][i] = value1;
            }
        }
        
        //Numをプラスする。
        Num++;
        
        //解放するのを忘れずに。
        free(indent);
        free(isNA);
    
    }
    
    //結果を出力する。
    for(i=0;i<Num;i++){
        
        printf("0");
        
        for(j=1;j<Q[i];j++){
            printf(" %d",ans[i][j]);
        }
        
        printf("\n");
    
    }
    
    return 0;

}

//インデントを求める関数。
int calc(int count[],int cand[]){
    int i,sum=0;
    for(i=0;i<3;i++){
        if(count[i]>0&&cand[i]<=0){
            return -1;
        }
        sum = sum + (count[i] * cand[i]);
    }
    
    return sum;

}

//インデントの正否を判定する関数。
int isvalid(int r,int c,int s,int data[][3],int indent[],int p){
    
    int i;
    
    for(i=0;i<p;i++){
        if(indent[i] == (r*data[i][0]+c*data[i][1]+s*data[i][2])){ }
        else{
            return 0;
        }
    }
    
    return 1;

}