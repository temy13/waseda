#include <stdio.h>


/*CSE�p�X�^�X�ł́C�����`�̂������߃p�X�^�ƍ�肽�ăW���[�X�̃Z�b�g���j���[���D�]�ł���B���̃Z�b�g���j���[�𒍕�����Ƃ��́C���̓��� 3 ��ނ̃p�X�^�� 2 ��ނ̃W���[�X���� 1 ���I�ԁB�p�X�^�ƃW���[�X�̒l�i�̍��v���� 50 �~�����������z������ƂȂ�B

������̃p�X�^�ƃW���[�X�̒l�i���^����ꂽ�Ƃ��C���̓��̃Z�b�g���j���[�̑���̍ŏ��l�����߂�v���O�������쐬����B*/
/*1w120310-7 ���^�O 10/25*/

#define PASTA 3
#define DRINK 2
#define MAX 2000
#define MIN 100

int main(void){

	int i;
	int temp = 0;
	int p = MAX; //�ŏ��l�ɂ�MAX�̒l�����Ă���
	int d = MAX;



	//����
	for(i = 0; i< PASTA; i++){
		scanf("%d",&temp);
		if((temp >= MIN) && (temp < p)){ //100�ȏ�ł��ŏ��l���Ⴉ������㏑��������������
			p = temp;
		}
	}
	for(i = 0; i< DRINK; i++){
		scanf("%d",&temp);
		if((temp >= MIN) && (temp < d)){ //100~2000�ł��ŏ��l���Ⴉ������㏑��������������
			d = temp;
		}
	}

	//�o��
	printf("%d",(p+d-50));





	return 0;
}
