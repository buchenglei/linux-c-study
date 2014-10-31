#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

const char *lock_file="/tmp/LCK.test3";

int main()
{
	int file_desc;
	int tries =10;
	 while(tries--){
	 	file_desc=open(lock_file,O_RDWR | O_CREAT | O_EXCL,0444);
		if(file_desc==-1){
			printf("%d - Lock already present\n",getpid());
			sleep(3);
		}else{
			printf("%d - I have exclusive access\n",getpid());
			sleep(1);
			(void)close(file_desc);
			(void)unlink(lock_file);
			sleep(2);
		}
	 }
	 exit(EXIT_SUCCESS);
}
/*
 * 出于演示的目的，使用while语句让程序循环10次，然后创建唯一一个的锁文件来访问临界资源
 * 如果因为文件存在而失败，程序将等待一小段时间后尝试
 * 如果成功就可以访问“临界区”的部分
 */
