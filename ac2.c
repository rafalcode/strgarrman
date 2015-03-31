#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int co(char *s1, char *s2)
{
    int i=0;
    while(s1[i]) {
        if(s1[i]!=s2[i])
            break;
        else
            i++;
    }
    return i;
}


int main(int argc, char *argv[])
{
   /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
	if(argc<3) {
		printf("String array matcher. strings to be presented on the command line.\n");
		exit(EXIT_FAILURE);
	}
    int nstrs=argc-1;
    int *matcha=malloc(nstrs*sizeof(int));
    memset(matcha, -1, nstrs);
    printf("%d elements to be compared with one another.\n", nstrs);
    printf("Right now any initial similarity will be a positive, and will be represented by the index of its earliest appearance\n");

   int partcsz=nstrs%64; /* size of the partial container */
   int basz=nstrs/64;
   unsigned long *mask=calloc(basz+1, sizeof(unsigned long));

    int i, j, pn, fn;
    int totmatches=0;
    int ptotmatches=0; /* partial totmatches */
    for(i=0;i<nstrs ;++i) {
        fn=i/64;
        pn=i%64;
		ptotmatches=0;
        if(mask[fn]&(1UL<<pn)) /* already set? */
			continue;
   		mask[fn]|=(1UL<<(pn)); /* set the bit for this number */
        for(j=i+1;j<nstrs;++j) {
        	if(mask[j/64]&(1UL<<(j%64))) /* already set? */
				continue;
            printf("%s/%s: %d ", argv[i+1], argv[j+1], co(argv[i+1], argv[j+1])); /* just printout comparison going on */
            if(co(argv[i+1], argv[j+1])) {
        		matcha[j]=i;
   				mask[j/64]|=(1UL<<(j%64)); /* set the bit for this number */
                ptotmatches++;
            } else
        		matcha[j]=j-totmatches;
			totmatches += ptotmatches;
        }
        printf("\n");
    }
    for(i=0;i<nstrs ;++i)
        printf("%d ", matcha[i]);
    printf("\n"); 

   free(matcha);
   free(mask);
   return 0;
}
