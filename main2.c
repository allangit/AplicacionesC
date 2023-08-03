#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <pthread.h>


void *mensaje1();
void *mensaje2();
int main(int argc, char *argv[]) {
	
	int i=0;
	pthread_t t1,t2;
	
	
	for(i; i<40; i++) {
		
		pthread_create(&t1,NULL,&mensaje1,NULL);
		pthread_create(&t2,NULL,&mensaje2,NULL);
		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
	}
	
	
	return 0;
}

void *mensaje1(){
	
	
	printf("mostrandos los hilo1\n");
}


void *mensaje2(){
	
	
	printf("mostrandos los hilo2\n");
}
