#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void main(){
	while(1){
		time_t secondes;
		struct tm instant;
		time(&secondes);
		instant=*localtime(&secondes);
		printf("%d:%d:%d\n", instant.tm_hour, instant.tm_min,instant.tm_sec);
		sleep(10);
	}
}
