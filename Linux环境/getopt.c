#include <stdio.h>
#include <unistd.h>//该头文件定义了getopt函数
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int opt;
	//该循环用于将参数按照指定格式处理
	while((opt = getopt(argc,argv,":if:lr")) != -1){
		switch(opt){
			case 'i':
			case 'l':
			case 'r':
				//输出选项本身
				//可以是-i -l -r
				//也可以是-ilr
				printf("option: %c\n",opt);
				break;
			case 'f':
				//输出选项的值
				printf("filename: %s\n",optarg);
				break;
			case ':':
				//:匹配需要值但没有给定值得选项
				//前提是格式字符串必须以:开头
				//否则未给定值时用?匹配
				printf("option neads a value!\n");
				break;
			case '?':
				//匹配未识别的选项
				printf("unknown option: %c\n",optopt);
				break;
		}
	}
	//该循环用于处理之前未识别的选项
	for(;optind < argc;optind++){
		printf("argument: %s\n",argv[optind]);
	}
	exit(0);

}
