#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};
int getchoice(char *greet,char *choices[]);

int main()
{
	int choice = 0;
	//判断是否是将信息输出到屏幕上，禁止重定向
	if(!isatty(fileno(stdout))){
		fprintf(stderr,"You are not a terninal!\n");
		exit(1);
	}
	do{
		choice = getchoice("please select an action",menu);
		printf("You have chosen:%c\n",choice);
	}while(choice != 'q');
	exit(0);
}

int getchoice(char *greet,char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;
	do{
		printf("Choice: %s\n",greet);
		option = choices;
		while(*option){
			printf("%s\n",*option);
			option++;
		}
		do{
			selected = getchar();
		}while(selected=='\n');
		option = choices;
		while(*option){
			if(selected == *option[0]){
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen){
			printf("Incorrect choice, select again\n");
		}
	}while(!chosen);
	return selected;
}
/*
 *	do{
 *		selected = getchar();
 *	}while(selected=='\n');
 *	这段代码如果直接写成：
 *	selected = getchar();
 *	那么每当你做出正确选择的时候，屏幕上都会提示Incorrect choice, select again.
 *	原因是：
 *	Linux会暂存用户输入的内容，直到用户按下回车键，然后将用户选择的字符和紧随其后的回车符一起传递给程序，
 *	当你输完一个选项时并按下回车时，程序就调用getchar函数处理输入，而当下一次循环中，由于上一次的回车符尚未处理，
 *	再次调用getcgar函数时，它并不会等待你输入，而是直接取走上次的回车符
 *
 */
