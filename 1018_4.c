#include<stdio.h>
#include <stdlib.h>

/*n �̐�������Ȃ鐔�� a1, a2, ..., an �Ɛ����� k (1��k��n) ��
�^������D���̂Ƃ��C�A�����ĕ��� k �̐����̘a Si = ai + ai+1 + ���+ ai+k-1 (1��i��n-k+1)
�̍ő�l���o�͂���v���O���������Ȃ����D*/
/*1w120310-7 ���^�O 10/21*/

#define N 100000

int main(void){
	int n,k;//���̎w��
	int *a;//n��
	int S;//sum
	int i,j,temp;//���\�v�p
	int max = 0; //�ő�l
	int nk; //n-k+1

	//����
	scanf("%d%d",&n,&k);
	//�����͈͊O�Ȃ�G���[
	if((n < 1) || ( n > N)){
		//printf("�͈͊O�ł�\n");
		return 0;
	}
	//k���͈͊O�Ȃ�error
	if((k < 1) || ( k > n)){
		//printf("�͈͊O�ł�\n");
		return 0;
	}

	nk = n-k+1;
	
	//a�̔z���n��malloc�Ŋm�ۂ���
	a = (int*)malloc(n*sizeof(int));
	if (a == NULL) 
      { //printf("Insufficient memory.\n"); 
	return 0; }




	
	//n��ai�ɒl�����Ă���
	for(i = 0; i < n; i++){
		scanf("%d",&temp);
		//a[i]��������
		a[i] = 0;
		//temp���͈͓��Ȃ�a[i]��
		if((temp >= -1*N) && ( temp <= N)){
			a[i] = temp;
		}
	}
	
	//Si�̌v�Z
	for(i = 0; i < nk; i++){
		//Si�̏�����
		S = 0;
		//Si��i����k��a�̒l�����Ă���
		for(j = i; j < i+k; j++){
			S = S + a[j];
		}
		//Si�̒l��max���傫��������㏑��
		if(S > max){
			max = S;
		}
	}

	//�o��
	printf("%d",max);

	//�g����malloc�̕��������
	free(a);
	return 0;
}
