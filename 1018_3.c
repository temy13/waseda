#include <stdio.h>
#include <string.h>
/*���Ȃ���N�̎w�ւ������Ă���D�ǂ̎w�ւɂ��C�A���t�@�x�b�g�̑啶��10��������Ȃ镶���񂪍��󂳂�Ă���D
�w�ւɂ͕�����̍ŏ��ƍŌオ�Ȃ������`�ŕ��������󂳂�Ă���D�w�ւɍ��󂳂ꂽ��������t���ɓǂސS�z�͂Ȃ��D
�T�����������񂪗^����ꂽ�Ƃ��C���̕�������܂ގw�ւ������邩�����߂�v���O�������쐬����D*/


/*1w120310-7 ���^�O�@10/20*/

#define N 10 //ring�ɏ�����镶���̐�


int main(void){

	//�����z��́A�����10�����ȏ���͂���邱�Ƃ��l�������������߂ɂƂ��Ă���
	char s[256]; //�T���o��������
	int n; //���L���郊���O�̐�
	int i = 0 , j = 0 , k = 0; //���[�v���̃J�E���g�p
	char ring[256]; //�����O�ɂ��镶��
	int count = 0; //���𐔂���
	int boolean = 0; //�����̂Ƃ��g��
	char *str;
	char cpy[256];
	int len;

	//�������镶����̓���
	scanf("%s",s);
	//���������͈͓����ǂ���
	if((strlen(s) < 1) || (strlen(s) > N)){
		//printf("�͈͊O�ł�");
		return 0;
	}
	//ring�̐�N�̓���
	scanf("%d",&n);
	for(i = 0; i< n; i++){
		scanf("%s",ring);
		//ring�̕�������N�ƈ�v���邩�ۂ�
		len = strlen(ring);
		if(len == N){
		//ring����s������ �ӂ��ɂ��ƍ���͗ւȂ̂�strstr�͎g���Ȃ��B
		strcpy(cpy,ring);
		strcat(ring,cpy);
		str = strstr(ring,s);
			if(str != NULL){
			count++;
				}
			printf("%s\n",ring);
			}
		
		}
		//�o��
	printf("%d",count);

	return 0;


	}

	