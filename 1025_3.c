#include <stdio.h>

/*�ۑ���e�F
CSE�����ł͎Ј��̍ݎЎ��Ԃ��^�C���J�[�h�ŊǗ����Ă���B �Ј��́C�o�Ђ���Ɛ�p�̑��u���g���ă^�C���J�[�h�ɏo�Ў��������󂷂�B
�Ζ����I���ގЂ���Ƃ��ɂ��C�^�C���J�[�h�ɑގЎ��������󂷂�B ������24���Ԑ��ň�����B
�h�Ə�̗��R����C�Ј��̏o�Ў�����7���ȍ~�ł���B �܂��C�S�Ă̎Ј���23�����O�ɑގЂ���B
�Ј��̑ގЎ����͏�ɏo�Ў�������ł���B
���͂Ƃ���CSE������3�l�̎Ј�A����CB����CC����̏o�Ў����ƑގЎ������^����ꂽ�Ƃ��C 
���ꂼ��̎Ј��̍ݎЎ��Ԃ��v�Z����v���O�������쐬����B*/
/*1w120310-7 ���^�O*/

#define MEMBER 3

int main(void){

	int i;
	int h_in[MEMBER], m_in[MEMBER], s_in[MEMBER], h_out[MEMBER], m_out[MEMBER], s_out[MEMBER]; //���ꂼ����o����
	int a_h[MEMBER], a_m[MEMBER], a_s[MEMBER];//

	//����
	for(i = 0; i < MEMBER; i++){
		scanf("%d%d%d%d%d%d",&h_in[i], &m_in[i], &s_in[i], &h_out[i], &m_out[i], &s_out[i]);
		//�͈̓`�F�b�N���͈͊O��������G���[
		if((h_in[i] < 7 ) || (h_out[i] < 7 ) || (h_in[i] > 22 ) || (h_in[i] > 22 ) || (m_in[i] < 0 ) || (m_out[i] > 59 ) || (s_in[i] < 0 ) || (s_out[i] > 59 )){
		//printf("error");
			return 0;
		}
	}
	


	//MEMBER�̐������ގЎ��Ԃ�����Ў��Ԃ�����
	for( i = 0; i<MEMBER; i++){

		//�b
		if(s_out[i] >= s_in[i]){
			a_s[i] = s_out[i] - s_in[i];
		}else{//��̈ʁi���j����60�Ƃ��Ă���
			a_s[i] = 60 +  s_out[i] - s_in[i];
			//�J��オ��̊֌W�ŏ�̈�(���j��1����
			m_out[i]--;
		}
		//��
		if(m_out[i] >= m_in[i]){
			a_m[i] = m_out[i] - m_in[i];
		}else{
			a_m[i] = 60 + m_out[i] - m_in[i];
			//�J��オ��̊֌W��
			h_out[i]--;
		}
		//��
		if(h_out[i] >= h_in[i]){
			a_h[i] = h_out[i] - h_in[i];
		}else{
			printf("error");
		}

		//�o��
		printf("%d %d %d\n",a_h[i],a_m[i],a_s[i]);

	}



	return 0;
}