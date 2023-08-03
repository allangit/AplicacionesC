#include <stdio.h>
#include <stdlib.h>

int *temperatura();


int main() {
	
	int i=0;
	int *pointer=0;
	pointer=temperatura();
	
	for(i ; i< 3; i++){
		
		printf("%d\n",*(pointer+i));
	}
	
	return 0;
}


int *temperatura(){
	

	static int lista[]={1,25,7};
	
	return lista;

}
