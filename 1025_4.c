#include <stdio.h>
/*�ۑ���e�F
���E�̊��� �g(�h�e�Ɓg)�h���������ԗ��ǂݍ��݁A���ꂪ�������Ă���
�i���E�̊��ʂ�������ƑΉ����Ă���j���ۂ��𔻒肷��v���O���������B*/
/*����
���͂͂P�s����Ȃ�B

�o��
���͂̒��Ɍ��ꂽ���ʂ��������Ă���ꍇ��1���C�E�̊��ʂ������ꍇ��2���C���̊��ʂ������ꍇ��3���C�P�s�Ƃ��ď����o���B*/
/*1w120310-7 ���^�O 10/27*/


int main(void){

	char c;
	char c_r = ')';
	char c_l =  '(';
	int right = 0,left = 0;
	int answer;

	//����
	while (scanf("%c", &c) != EOF) {
		//(�����͂��ꂽ��right���{�{
		if(c == c_r){
			right++;
			printf("right = %d\n",right);
		}else if(c == c_l){//)�����͂��ꂽ��left���{�{
			left++;
			printf("left = %d\n",left);
		}

	}

	if(right == left){answer = 1;}
	else if(right > left){answer = 2;}
	else if(left < right){answer = 3;}

	printf("%d",answer);

	return 0;
}