/* a random permutation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
   /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
	if(argc!=3) {
		printf("Error. Enter an integer.\n");
		exit(EXIT_FAILURE);
	}

   /* declarations */
   int i, j, n=atoi(argv[1]) /* total range */, nr=atoi(argv[2]) /* number of randnums */;
   int partcsz=nr%64; /* size of the partial container */
   int basz=nr/64;
   unsigned long *mask=calloc(basz+1, sizeof(unsigned long));

    int rn, frn, prn;
    for(i=0;i<nr;++i) {
        rn=(int)(n*(float)rand()/RAND_MAX);
        fn=rn/64;
        pn=rn%64;
        if(mask[fn]&(1UL<<pn)) /* already set? */
            continue;
        mask[fn]|=(1UL<<(pn)); /* set the bit for this number */
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
