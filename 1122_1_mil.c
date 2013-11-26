#include <stdio.h>
#include <stdlib.h>
/*�������V��������߂��D�u������1�N1��1���ƒ�߂�D1�N�ɂ�1������10���܂ł�10����������C��̌�����n�܂�D�ӂ��̔N�́C1������̌��C2���͏��̌��C3���͑�̌��C
�����čŌ��10���͏��̌��Ƃ����悤�ɁC��̌��Ə��̌������݂ɖK���D��̌��̓�����20���C���̌��̓�����19���ł���D
�������C3�N�C6�N�C9�N�C�c�̂悤�ɁC3�Ŋ���؂��N�ɂ́C���̌��͖K�ꂸ�C10���ׂĂ̌����̌��Ƃ���D�v

���N�������ꂽ�D�₪��1000�N1��1���̃~���j�A���L�O���̏j�ꎮ�ɂ����āC
�a�����Ă���̓����������̂��������őI�΂ꂽ���ƈ�v���鍑���Ɍi�i��^���邱�ƂɂȂ����D
��������菕�����āC���܂ꂽ������~���j�A���L�O���܂ł̓������v�Z����v���O������򂺂�D*/

/*1w120310-7 ���^�O 11/23*/
/*
1. �����܂ł̓��������߂� 
2. ����ɁA�N���܂Ŋe���̓��������Z���� 
3. ����ɁA���N���� 999 �N�܂Ŋe�N�̓��������Z���� 
4. ����� 1 ������ƁA1000 �N 1 �� 1 ���܂ł̓����ƂȂ� 
*/

//�~���j�A���܂ł̔N
#define MIL 1000
//��̌�
#define MAJ 20
//���̌�
#define MIN 19
//��N�̌��̐�
#define MONTH 10

//	��̌��Ȃ� 20�A���̌��Ȃ� 19 ��Ԃ�	
int	ndm(int	y,int m)	
{
	//�N��3�Ŋ���؂�邩����Ȃ�匎
	if( (y % 3 == 0) || (m % 2 == 1)){
		return MAJ;
	}else{
		return MIN;
	}
}

int days(int y, int m, int d){
	
	int ans;
	int i;
	//�܂������܂�(���܂ꂽ���܂߂�)
	ans = ndm(y,m)  - d + 1;
	//���ɔN���܂�
	for(i = m+1; i <= MONTH; i++){
		ans +=ndm(y,i);
	}
	
	//999�N10/20�܂�
	for(i = y + 1; i<=999; i++){
		if(i % 3 == 0){ //3�Ŋ���؂ꂽ��
			ans += (MAJ*10);
		}else{ //�������
			ans +=( (MAJ + MIN)*5);
		}
	}
	
	return ans;
	}	

int main(void){
	
	int n; //�f�[�^��
	int *y,*m,*d;//���ꂼ��̒a����
	int i;//���[�v�p
	int year,month,day;
	int ans;
	
	scanf("%d",&n);
	//�f�[�^������malloc�Ŋm��
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
  //�f�[�^����
	for(i = 0; i<n;i++){
		scanf("%d%d%d",&y[i],&m[i],&d[i]);
	}
	//�����̌v�Z
	for(i = 0; i<n;i++){
		
		ans = days(y[i],m[i],d[i]);
		printf("%d\n",ans);
	}
	
	
return 0;	
}