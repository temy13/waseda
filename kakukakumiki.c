#include <stdio.h>
#include <stdlib.h>
/*�����`��אڂ���悤�ɕ��ׂĂ����A�Ō�̂��̕��׏I�����
�����`�����ׂĂ͂���悤�Ȓ����`��p�ӂ���*/

/*1w120310 ���^�O 12/19 */
#define N 200

//�����`�̃f�[�^
struct Data{
	int index; /*�ԍ�*/
	int width;	/* ���S����̉��̋��� */
	int height;	/* ���S����̏c�̋��� */
	struct Data *next;
};


int main(void){
	int n; // �v�f��
	int i;
	int now,d; //���̎��אڂ����鐳���`�̔ԍ��Ɨאڂ���������B0���� 1���� 2���E 3����
	int count = 0; //���񂱂̍�Ƃ��s������
	int width_n,height_n; //�אڂ����鐳���`�̏��
	int max_width = 0, max_height = 0, min_width = 0, min_height = 0; //�Ō�̏�Ԃ�MAX,MIN�̉��Əc
	int width,height; //�ŏI�I�ȏc�Ɖ��̒���
	struct Data *head,*p,*q;
	//�Ō�̕\���p
	int last_width[N]; 
	int last_height[N];
	
	while(1){
	//������
	max_width = 0;
	max_height = 0;
	min_width = 0;
	min_height = 0;
printf("start\n");
	//��ԏ��߂�head�̒�`��0�Ԗڂ̐����`�̒�`
	head = (struct Data *)malloc( sizeof(struct Data));
	//���������邱�Ƃ������Ă͂Ȃ�Ȃ��̂ŁAindex�͕��̒l�ɁB
	head->index = -1;
	head->width = 0;
	head->height = 0;
	//0�Ԗڂ̐����`�̒�`
	p = (struct Data *)malloc( sizeof(struct Data));
	head->next = p;
	p->index = 0;
	//�{��1�~1�̐����`�����A�}�C�i�X���l�����邽��0�Ƃ��� �Ō�̂P�𑫂��Ă��̕�����������
	p->width = 0;
	p->height = 0;
	scanf("%d",&n);
	if( n == 0) break;
	//n�񐳕��`��~���l�߂�
printf("n = %d\n",n);
		for(i = 1; i < n; i++){
			scanf("%d%d",&now,&d);
			p->next = (struct Data *)malloc( sizeof(struct Data)); //�V�����\���̂��m��
			p = p->next; //p��V�����\���̂Ɉړ�
			p->next = NULL; //���̍\���̂͂܂��Ȃ�
			p->index = i; //index�ɍ��̔ԍ���\��
			//�\���̂����Č�����now�̐������������`��T��
			for(q = head; q!=NULL; q = q->next){
				if(q->index == now){
					width_n = q->width;
					height_n = q->height;
					break;
					}
				}
			//d�̔ԍ��ɏ]���Ē��S����̋�����ǋL����
			switch(d){
				case 0:
					p->width = width_n -1;
					p->height = height_n;
					break;
				case 1:
					p->width = width_n;
					p->height = height_n-1;
					break;
				case 2:
					p->width = width_n +1;
					p->height = height_n;
					break;
				case 3:
					p->width = width_n;
					p->height = height_n+1;
					break;
				}
			}
		//�S���I������̂ōő�ŏ��̍X�V
		for(q = head; q!=NULL; q = q->next){
			if(max_width < q->width) max_width = q->width;
			if(min_width > q->width) min_width = q->width;
			if(max_height< q->height)max_height= q->height;
			if(min_height> q->height)min_height= q->height;
				}
		//�ŏ��̒l��0�Ƃ��Ă��邽�߂��܂����킹�Ȃ���
		width = max_width - min_width + 1;
		height= max_height- min_height+ 1;
		last_width[count] = width;
		last_height[count]= height;
		//���񂱂̍�Ƃ���������̃J�E���g
		count++;
	}
	for(i =0; i < count; i++){
		printf("%d %d\n",last_width[i],last_height[i]);
	}
	return 0;
}
