#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
	char c;
	int in,out;
	in=open("file.in",O_RDONLY);
	out=open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while(read(in,&c,1)==1){
		write(out,&c,1);
	}
	exit(0);
}
/*
 * 未做优化的执行结果
 * real    0m38.885s
 * user    0m2.044s
 * sys     0m36.758s
 */
