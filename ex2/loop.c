#include <stdio.h>
#include <unistd.h>

int main () { 
	long int i; 
	long int n = 500000000; 

	while (1) { 
		/* ~ 1 second run */ 
		printf ("*Ready*\n"); 
		for (i = 0; i < n; i++); 

		/* 2 seconds sleep */ 
		printf ("*Sleep*\n"); 
		sleep (2); 
	}
    return 0;
} 
