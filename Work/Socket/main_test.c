#include <stdio.h>

int main(int argc, char *argv[] )
{
	printf("전달된 인자 갯수 : %d\n", argc);
	printf("실행파일 : %s\n", argv[0]);
	for (int i = 0; i < argc; i++)
	{
		printf("전달한 데이터 : %s", argv[i]);
	}
	
	return 0;
}
