#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coabsm1(char *s1, char *s2) /* absolute match minus one, i.e. excluding null byte */
{
    int i;
    size_t slen=strlen(s1);
    for(i=0;i<slen;++i) {
        if(s1[i]==s2[i])
            continue;
        else
            return 0;
    }
    return 1;
}

int coabs(char *s1, char *s2) /* absolute match including null byte */
{
    int i;
    size_t slen=strlen(s1);
    for(i=0;i<=slen;++i) {
        if(s1[i]==s2[i])
            continue;
        else
            return 0;
    }
    return 1;
}

int cofirst(char *s1, char *s2) /* the first or more characters match */
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
    memset(matcha, 0, nstrs); /* initial state */
    printf("%d elements to be compared with one another.\n", nstrs);
    printf("Right now any initial similarity will be a positive, and will be represented by the index of its earliest appearance\n");

    /* we use a mask to avoid mark off positions that have already matched */
   int basz=nstrs/64;
   unsigned long *mask=calloc(basz+1, sizeof(unsigned long));

    int i, j, pn, fn;
    for(i=0;i<nstrs ;++i) {
        fn=i/64;
        pn=i%64;
        if(mask[fn]&(1UL<<pn)) /* already set? */
			continue;
   		mask[fn]|=(1UL<<(pn)); /* set the bit for this number */
        for(j=i+1;j<nstrs;++j) {
        	if(mask[j/64]&(1UL<<(j%64))) /* already set? */
				continue;
            printf("%s/%s: %d ", argv[i+1], argv[j+1], coabs(argv[i+1], argv[j+1])); /* just printout comparison going on */
            if(coabs(argv[i+1], argv[j+1])) {
        		matcha[j]=i;
   				mask[j/64]|=(1UL<<(j%64)); /* set the bit for this number */
            } else
        		matcha[j]=j;
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
