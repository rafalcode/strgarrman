/* started to see if I could strictly print strings into a
 * columns of a set width only using printf. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define ALWSPACES /* allowed spaces */

int main(int argc, char *argv[])
{
    /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
    if(argc<3) {
        printf("How we format strings somehow properly?\n");
        exit(EXIT_FAILURE);
    }
    int i, nstrs=argc-1;
    for(i=0;i<nstrs;++i) 
        printf((i!=nstrs-1)? "%3c | ": "%3c\n", argv[i+1]);
    return 0;
}
