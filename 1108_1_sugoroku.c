#include <stdio.h>
/*�ۑ���e�F
CSE����͈�l�ł����낭�V�т����Ă���B ���̂����낭�́C���v�̕����Տ��12�̃}�X���~����ɂ���B
�X�^�[�g�n�_��12���̈ʒu�ɂ���}�X�ł���C�S�[����12���̈ʒu�̃}�X�ł���B
CSE����̓T�C�R����6��U��B���ڂł́C�o���ڂ̐��������v���ɐi�݁C
������ڂł͏o���ڂ̐����������v���ɐi�ށB�T�C�R����6��U�����Ƃ��S�[���̃}�X�ɍs���������ǂ����𒲂ׂ�v���O�������쐬����*/
/*1w120310-7 ���^�O�@11/09*/

//�񐔂̒�`
#define NUM 6



int main(void){

	int num;//���͂��ꂽ��
	int i;//���[�v�p
	int point = 0;	//�ʒu�B�ŏ��̒l��0�B���̒l���ŏI�I��12��������0�ɂȂ����̂Ȃ�S�[�������Ƃ���

	//����
	for(i = 1; i < NUM+1; i++){
		scanf("%d",&num);
		//�{���Ȃ炱���Ŗ{���ɃT�C�R���̐����i�P�`�U�j���f����ׂ�	
		if(i % 2 == 1){//���������
		point += num;//���v���i+�j
		}else if(i % 2 == 0){//������������
		point -= num; //�����v���(-)
		}

	}
	
	//������point�̒l��1�`12�ɂȂ�悤�ɒ�������
	while(point < 1 || point > 12){
		if(point < 1){ point += 12;}
		else if(point > 12){ point -= 12;}
	}


	//�o��
	if(point == 12){
		printf("yes\n");
		printf("%d",point);

	}else{
		printf("no\n");
		printf("%d",point);
	}

	


	return 0;

}