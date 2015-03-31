#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef u64 unsigned long;

void rndmask(u64 *rmask, int n)
{
   int pn=n%31;
   int fnsz=n/31;
   int q=(pn)? fnsz+1: fnsz;
   int r;
   u64 rb;
   for(i=0;i<q;++i) {
	r=rand();
    rb=
	
}
	

}



int main(int argc, char *argv[])
{
   /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
	if(argc!=2) {
		printf("Error. Enter an integer.\n");
		exit(EXIT_FAILURE);
	}

   /* declarations */
   int rn=rand();
   int i, j, n=atoi(argv[1]);
   int partcsz=n%64; /* size of the partial container */
   int basz=n/64;
   unsigned long *mask=calloc(basz+1, sizeof(unsigned long));
   mask[basz] = (unsigned long)n;
   for(i=0;i<basz+1;++i) 
       for(j=0;j<64;++j) 
           if(mask[i]&(1UL<<j)) {
               printf("%d+%d=%d ", i, j, i*64+j); 
           }
   printf("\n"); 

   free(mask);
   return 0;
}
