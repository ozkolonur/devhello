#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // strdup
#include <debug.h> // printd

void print_usage();

int main(int argc, char *argv[])
{

    char *cvalue = NULL;
    int index;
    int c;
     
    opterr = 0;
    cvalue=strdup("World");

    while ((c = getopt (argc, argv, "hn:")) != -1)
    switch (c)
    {
	case 'h':
    	    print_usage();
    	    break;
        case 'n':
	    cvalue = optarg;
	    break;
	case '?':
	    if (optopt == 'n')
	    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
	    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
    	    fprintf (stderr,"Unknown option character `\\x%x'.\n", optopt);
	    return 1;
	default:
	    cvalue = optarg;
    }

    printd(DEBUG, "hello %s!\n", cvalue);
    printd(INFO, "hello %s!\n", cvalue);
    printd(NOTICE, "hello %s!\n", cvalue);
    printd(WARNING, "hello %s!\n", cvalue);
    printd(ERR, "hello %s!\n", cvalue);
    printd(CRIT, "hello %s!\n", cvalue);
    printd(ALERT, "hello %s!\n", cvalue);
    printd(EMERG, "hello %s!\n", cvalue);

/* incase sb need it
    for (index = optind; index < argc; index++)
	printf ("Non-option argument %d: %s\n", argv[index], index);
*/
    return 0;
}

void print_usage()
{
    printf("\nprints hello message\n");
    printf("Usage:\n"); 
    printf("hello \t\t [OPTIONS]\n");
    printf("\nOPTIONS:\n");
    printf("-n NAME\t says hello to NAME\n");
    printf("-h     \tprints this help message\n");
    exit(0);
}
