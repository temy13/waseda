#include <stdio.h>
#include <math.h>
/*���� n (0 �� n �� 75 ) �����͂���^������ƁC���̌����܂Łi�̏\�i���j�ŕ\����ő�� 2 �̙p 2^k �����l�߂ŕ\������v���O���������B
�͈͊O�̐�������͂����ꍇ��error�Əo�͂��ďI���悤�ɂ��邱�ƁB*/
/*1w120310 ���^�O ��o�� 10/06*/

#define  MAX 100 //���{���ɂ������̔z��̒��̏��(double)
#define NUMBER 100 //�p�ӂ���z��̐�

int tabai(int count){

	double a[NUMBER];
	double ans;
	int i,n,j;
	int up; //�J��オ��
	int up_count = 0; //�ǂ̌��܂œ����Ă��邩 
	//�����ݒ�
	for(i =0 ; i < NUMBER; i++){
		a[i] = 0;
	}
	a[0] = 1;
	
	for(i = 0; i < count; i++){
		n = 0;
		up = 0;
		for(n = 0; n < up_count + 1; n++){
			printf("i=%d\n",i);
			printf("a[n]=%lf\n",a[n]);
			ans = a[n] * 2 + up;
			
			if(ans > MAX){ //ans���w�肵�������蒴���Ă�����
				a[n] = ans - MAX; //�����Ȃ��悤�Ɉ����Z����
				up = 1; //�J��グ��
					if(a[n+1] == 0){ //�������̌���0�������灁�V��������̈悾������
								up_count++;
							}
			}else { //�����Ă��Ȃ�������
				a[n] = ans; //���̂܂ܑ��
				up = 0; //�J��オ��͂Ȃ�
			}
		}	
	}
	//�o��
	for(j = up_count ; j >= 0 ; j--){
		printf("%.0lf",a[j]);
		}
	return 0;
}

int main(void){

	int n; //���͂����l
	double keta;
	//int x = 0;
	int count = 0;

	scanf("%d",&n);
	//�͈͓����ǂ���
	if((0 < n) && (n < 75)){
		//������p�ӂ���
		keta = pow(10.0 , n);
		
		//���̌���2�i���ɒ������̌��𐔂���
		while( keta > 2){ 
			keta = keta/2.0; 
			count++; 
			}
	
		//���{���v�Z������
		tabai(count);
	//�͈͊O�Ȃ�G���[
	}else{
		printf("error");
	}
	return 0;
}

