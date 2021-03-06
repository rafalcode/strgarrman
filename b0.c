#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
   /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
	if(argc!=2) {
		printf("Error. Enter an integer.\n");
		exit(EXIT_FAILURE);
	}

   /* declarations */
   int i, j, n=atoi(argv[1]);
   int rn=(int)n*(float)rand()/RAND_MAX;
   int partcsz=n%64; /* size of the partial container */
   int basz=n/64;
   unsigned long *mask=calloc(basz+1, sizeof(unsigned long));
	
   mask[rn/64]|=(0x01UL<<(rn%64)); /* set the bit for this number */
   rn=(int)n*(float)rand()/RAND_MAX;
   mask[rn/64]|=(0x01UL<<(rn%64)); /* set the bit for this number */
   rn=(int)n*(float)rand()/RAND_MAX;
   mask[rn/64]|=(0x01UL<<(rn%64)); /* set the bit for this number */
	
/* detect the bit set */
   for(i=0;i<basz+1;++i) 
       for(j=0;j<64;++j) 
           if(mask[i]&(1UL<<j)) {
               printf("%d+%d=%d ", i, j, i*64+j); 
           }
   printf("rn was %d\n", rn); 

   free(mask);
   return 0;
}
