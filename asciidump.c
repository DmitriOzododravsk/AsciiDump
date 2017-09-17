#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define USAGE puts("Error, Missing Arguments\n\n \tBy Eduardo Cardozo\n\n\tUsage: ascii <Number> <Modificator>\n\tUse -h to show all possible opitions!\n")
#define HELP  fprintf(stdout,"\n=====HELP=====\n\n-b  ------> Show The Values In Decimal Format\n-h  ------> Show The Values In Hexadecimal Values\n-a  ------> Show The Values Aligned\n\n\n")

void fatal(const char msg[]) {
    USAGE;
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    char st[15] = {0};
    int aflag=0, bflag=0, xflag=0, helpflag=0;
    int i, c;

    if(argc < 2)
        fatal("Error, Missing Arguments");

    strcpy(st,argv[1]);

    while((c = getopt(argc,argv,"habx")) != -1 ) {
        switch(c){
            case 'a':
                aflag = 1;
                break;
            case 'b':
                bflag = 1;
                break;
            case 'x':
                xflag = 1;
                break;
            case 'h':
                helpflag = 1;
                break;
        }
    }
    
    for ( i = 0;i < 15; i++ ) {
        if( bflag == 1 && aflag == 0 and st[i] != 0  )
            printf("%c - %d\n", st[i], (int)st[i] );

        if( bflag == 1 && aflag == 1 and st[i] != 0  )
            printf("%d,  ", (int)st[i] );

        if( xflag == 1 && aflag == 0 and st[i] != 0  )
            printf("%c - 0x%x\n", st[i], (int)st[i] );

        if( xflag == 1 && aflag == 1 and st[i] != 0  )
            printf("0x%x,  ", (int)st[i]); 
        if( helpflag == 1 )
            HELP;
    }
    
    printf("\n");

    return 0;
}
