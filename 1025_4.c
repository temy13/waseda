#include <stdio.h>
/*‰Û‘è“à—eF
¶‰E‚ÌŠ‡ŒÊ g(he‚Æg)h‚¾‚¯‚ª•À‚Ô—ñ‚ð“Ç‚Ýž‚ÝA‚»‚ê‚ª®‡‚µ‚Ä‚¢‚é
i¶‰E‚ÌŠ‡ŒÊ‚ª‚«‚¿‚ñ‚Æ‘Î‰ž‚µ‚Ä‚¢‚éj‚©”Û‚©‚ð”»’è‚·‚éƒvƒƒOƒ‰ƒ€‚ðì‚êB*/
/*“ü—Í
“ü—Í‚Í‚Ps‚©‚ç‚È‚éB

o—Í
“ü—Í‚Ì’†‚ÉŒ»‚ê‚½Š‡ŒÊ‚ª®‡‚µ‚Ä‚¢‚éê‡‚Í1‚ðC‰E‚ÌŠ‡ŒÊ‚ª‘½‚¢ê‡‚Í2‚ðC¶‚ÌŠ‡ŒÊ‚ª‘½‚¢ê‡‚Í3‚ðC‚Ps‚Æ‚µ‚Ä‘‚«o‚¹B*/
/*1w120310-7 ‘êì^O 10/27*/


int main(void){

	char c;
	char c_r = ')';
	char c_l =  '(';
	int right = 0,left = 0;
	int answer;

	//“ü—Í
	while (scanf("%c", &c) != EOF) {
		//(‚ª“ü—Í‚³‚ê‚½‚çright‚ð{{
		if(c == c_r){
			right++;
			printf("right = %d\n",right);
		}else if(c == c_l){//)‚ª“ü—Í‚³‚ê‚½‚çleft‚ð{{
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