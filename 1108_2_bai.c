#include <stdio.h>


/*�ۑ���e�F
���͂��ꂽ2�̐������l�̍ŏ����{�����v�Z���ďo�͂���v���O���������B
���͂́C2�̐��������󔒂P�ŋ�؂��ĕ��ׂ��P�s�Ƃ��ė^������B
�o�͂́C�ŏ����{���������P�s�Ƃ��ď����o���B
*/
/*1w120310-7 ���^�O�@11/09*/

int main(void){

	unsigned long x,y;
	unsigned long a,b; 
	unsigned long temp,r;
	

	scanf("%ld%ld",&x,&y);

	//�͔C���̃��[�v���A��Ɍ��񐔂������Ă����������@�������Ɣ��f����
	//���[�N���b�h�̌ݏ��@
	//a<b���Ƃ�����l�����ւ���
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	//�l��a,b�ɕۑ�
	a = x;
	b = y;
	// a/b�̂��܂肪0�ɂȂ�܂Ń��[�v����
	while((r = a % b) != 0 ){
		//0����Ȃ������烆�[�N���b�h�̌ݏ��@�ɂ��a��b b��r�Ƃ��A������x
		a = b;
		b = r;
	}
	//�o��
	printf("xy = %ld\n",x*y);
	printf("%ld",(x*y)/b);


	return 0;
}