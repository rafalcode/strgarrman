#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
   /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
	if(argc!=2) {
		printf("Error. Pls supply argument (name of file).\n");
		exit(EXIT_FAILURE);
	}

   /* declarations */
   int i, j, n=atoi(argv[1]);
   int partcsz=n%64; /* size of the partial container */
   int basz=n/64;
   unsigned long *mask=calloc(basz+1, sizeof(unsigned long));
   mask[basz] = (partcsz)? (unsigned long)partcsz : 0x01UL;
   for(i=0;i<basz+1;++i) 
       for(j=0;j<64;++j) 
           if(mask[i]&(1UL<<j)) {
               printf("%d/%d ", i, j); 
           }
   printf("\n"); 

   free(mask);
   return 0;
}
