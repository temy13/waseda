#include <stdio.h>
#include <stdlib.h>

/*�ۑ���e�F
�����̋�̔�Ԃ́C�㉺�����C���E�����ɏ��ڂ������Ă������ǂ��ւł��ړ��ł���B
���ɁC�󂢂Ă��邻�̐�ɓG�̋����΁C���̈ʒu�ɐi��ł��̋����邱�Ƃ��ł���B����ɁC��Ԃ́C����Ɨ��ƂȂ�C���E�΂ߑO����э��E�΂ߌ�̂S�̏��ڂɂ���G�̋����邱�Ƃ��ł���悤�ɂȂ�B�����̋�Ɏ���Ď�邱�Ƃ̂ł���ʒu�ɂ���i�G�́j��𓖂���̋�Ƃ����B

������ n �ɂ��� n�~n �̏��ڂ����Ղ��l���C���̏�� n �̗���
�݂��ɓ�����ɂȂ�Ȃ��悤�ɔz�u���邱�Ƃ��l���C�\�Ȕz�u�̑������o�͂���v���O���������B
�@
���͂́C������ n ��������ׂ��P�s����Ȃ�B

�o�͂́C�\�Ȕz�u�̑����������P�s�Ƃ��ď����o���B*/
/*1w120310 ���^�O*/

/*�܂��A��Ԃ̐����セ�̉��͑S�悾�߂Ȃ̂�����A���������J�E���g���Ȃ�
���ɁA���̏c���_���Ȃ̂�����A�z���p���Ă��̏c���_���Ȉ������B
���ɁA��Ԃ��u���ꂽ���̍s�́}�P��NG�@0�͂������c������ʖ�*/




//���݂̔Ղ̏�ԂƂЂƂO�̍s���ǂ��ɒu���ꂽ���̃f�[�^�������āA���̍s�̂�����ꏊ��T��
int search(int *x, int *y, int prev,int gyo,int n){
	int *new_x;
	int *new_y; //�����Ă���s�̏�Ԃ��L���z������@1���g���Ȃ� 0���g����
	int i,j;
	int count = 0;
	new_x = malloc(sizeof(int)*n);
	new_y = malloc(sizeof(int)*n);
	//������	
	for(i = 0; i< n; i++){
 		new_x[i] = 0;
 		new_y[i] = y[i];
 	}
 	//�����Ă���s�����ׂČ��Ă����A
	for( i = 0; i<n; i++){
		//�ЂƂO�̍s�ɂ����Ă����ԁ}1�͈̔͂Ƃ��łɂǂ����̗�ɂ�����Ă���ꍇ��NG
		if((new_y[i] != 1) && (i != prev+1) && (i != prev-1)){//�����炻��ȊO�̏ꏊ������΂����ɂ�����
			//���ɂ����Ă݂�
			new_x[gyo] = 1;
			new_y[i] = 1;
			//�ċN���Ď��̍s��(���̍s���Ȃ������炵�Ȃ��B
			if(gyo+1 < n){
				count += search(new_x,new_y,i,gyo+1,n);
			}else{//�ŏI�܂ōs�����̂Ȃ�Acount��Ԃ�
				count++;
				return count;
			}
			//�A���Ă�������Ƃ̔Ղ̏�Ԃɖ߂�
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
	int *x; //�s�����āA���̍s�������Ă�����P�Ȃ��Ȃ�0
	int *y; //������āA���̗񂪓����Ă�����P�Ȃ��Ȃ�0
	
	int i;
	int retu = 0; //�l�@����ׂ��񐔁B�\�Ȕz�񐔂͂ǂ�ȂɊ撣���Ă�n�͒����Ȃ��B
	int count = 0;
	
	scanf("%d",&n);
	/*���ꂼ��m�ۂ���*/
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
 
 	//������
 	for(i = 0; i< n; i++){
 		x[i] = 0;
 		y[i] = 0;
 	}
 	i = 0;
 	//n��l�@
 	while( retu < n){
 	
 		//��ԍŏ�
 		x[0]=1; //��0�Ԗڂ̉��͎g�p�֎~
 		y[retu]=1; //��retu�Ԗڂ̏c�͎g�p�֎~
 		count += search(x,y,retu,1,n); //x�̏�ԁAy�̏�ԁA
 		//���̉񂪏I������̂ŁA�Ղ̏�Ԃ�������
 		for(i = 0; i< n; i++){
	 		x[i] = 0;
	 		y[i] = 0;
 		}
 		
 		retu++;
 		
 	}
	
	
	printf("%d\n",count);
	
	return 0;
}