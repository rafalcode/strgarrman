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

typedef enum /* stateafterx, staeafter examination */
{
    OUTONZ, /* out on zero, total mistmatch on first character */
    PRFCT, /* perfect and total match */
    PSHRTR, /* perfect but target is shorter than query */
    PLNGR, /* perfect but query is shorter than target */
} staftx;


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

    int i, j;
    int totmatches=0;
    for(i=0;i<nstrs ;++i) {
        for(j=i+1;j<nstrs;++j) {
            pos=0;
            printf("%s/%s: %d ", argv[i+1], argv[j+1], co(argv[i+1], argv[j+1])); /* just printout comparison going on */
            if(co(argv[i+1], argv[j+1])) {
                pos=1;
                totmatches++;
                break;
            }
        }
        matcha[j]=(pos)?i:j-totmatches;
        printf("\n");
    }
    for(i=0;i<nstrs ;++i)
        printf("%d ", matcha[i]);
    printf("\n"); 

   free(matcha);
   return 0;
}

/* learnings:
 * -> last argument includes the newline?
*/
