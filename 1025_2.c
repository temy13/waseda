#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*�ۑ���e�F
�p�P�ꂪ�P�ȏ�̋󔒗ށi�󔒂܂��͉��s�j�ŋ�؂��ĕ���ł���Ƃ���B���͂̒��Ŏ������ň�ԎႢ�P��
�i�ʏ�̉p�ꎫ���̌��o���Ƃ��čł��O�ɂ���P��j���o�͂���v���O���������B*/
/*1w120310-7 ���^�O*/


//�Œ��̉p�P�ꂪ20���Ȃ̂�100�������p�ӂ���΂��ׂē���Ɣ��f
//�Ǝv�����̂ł���100���͂���Ȃ������̂�10���őË�
#define MAX 100000

 /* �����񒆂̉p�啶�����������ɕϊ� */
char StrToLower(char str[])
{
   int length,i;

   length=strlen(str);

   for(i = 0; i < length; i++){

	   str[i] = tolower(str[i]);
   }

   

}

int main(void){
	char min[MAX];//�ŏ�
	char s[MAX];//���͂���l
	char temp[MAX];//�啶�����������ɕϊ�����Ƃ��ꎞ�I�ɕۑ�����
	char min_temp[MAX];//�����啶���̒P�ꂪ���͂��ꂽ�ꍇ�A�������ɕϊ�����min�������ɓ����
	

	scanf("%s",min); //��ڂ����
	//min_temp�ɃR�s�[���āAmin_temp�̒��g���啶���Ȃ珬�����ɕϊ�����
	strcpy(min_temp,min);
	StrToLower(min_temp);


	//����
	while(scanf("%s", s) != EOF){
		//�����I�ɔ�ׂ�
	strcpy(temp,s);//��xtemp�ɕۑ����A
	StrToLower(temp);//�����啶���Ȃ珬�����ɒ���
		//���������m�Ŕ�ׂ�
		if(strcmp(temp,min_temp) < 0){//min��菬����������
			strcpy(min_temp,temp);//�������̂��̂��㏑��
			strcpy(min,s);//���̂��̂��㏑��
		}
		
		
	}
	
	printf("%s",min);


	return 0;
}

