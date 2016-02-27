/* $Revision: 1.1 $ */
/* $Author: christos $ */
/* $Id: main.c,v 1.1 2001/02/11 16:16:03 christos Exp $ */


#include "dfn.h"
#include "vector.h"
#include "kdtree.h"

#define CMDLINE

#ifdef CMDLINE
#define ERRACT	fprintf(stderr, \
    "usage: %s [-d numberOfDimensions]\n", pgname)
#endif

#define PROMPT "kdtree ('h' for help)> "

void checkword(char *s);
void strip_newline(char *s);

main(argc, argv)
  int argc;
  char *argv[];
{
  char *pgname;
  char inp[MAXLEN];
  char cmd[MAXLEN];
  VECTOR *inputVectorPtr;
  VECTOR *vpLow;
  VECTOR *vpHigh;
  int numdims;
  int i;
  NUMBER val;
  TREENODE *root;
  int count;
  int k_nearest_neighbors;
  NUMBER k_nearest_neighbors_radius;

  void prhelp();

  count = 0; /* number of nodes touched - not used, yet */

  numdims = 4; /* to be changed, from the command-line interface */

  k_nearest_neighbors = 5;

  k_nearest_neighbors_radius = 0.002;

  vpLow = vecalloc(numdims);
  vpHigh = vecalloc(numdims);
  root = NULL;

  /* initialize */
  pgname = argv[0];

#ifdef CMDLINE
  while( argc > 1 && argv[1][0] == '-' ) {
    switch( argv[1][1]) {

      case 'd':	/* set number of dimensions */
        if( argc>2){
          checkword(argv[2]);
          strcpy(inp, argv[2]);
          numdims = atoi(inp);
          /* printf("num. dimensions = %d\n", numdims); */
          vecfree( vpLow);
          vecfree( vpHigh);
          vpLow = vecalloc(numdims);
          vpHigh = vecalloc(numdims);
          argc--; argv++;
        } else {
          ERRACT;
          exit(1);
        }
        break;


#ifdef JUNK
      case 's':	/* set fname for file to show */
        if( argc>2){
          checkword(argv[2]);
          strcpy(fname,  argv[2]);
          argc--; argv++;
        } else {
          ERRACT;
          exit(1);
        }
        break;
#endif

      default:
        fprintf(stderr, "%s: unknown arg %s\n", pgname, argv[1]);
        exit(1);
    }
    argc--;
    argv++;
  }

  if( argc != 1){
    ERRACT;
    exit(1);
  }
#endif

  inputVectorPtr = vecalloc(numdims);

  /*prhelp();
  printf(PROMPT);*/
  /* printf("kdtree1> "); */
  fgets(inp, MAXLEN, stdin); checkword(inp); strip_newline(inp);
  while( strlen(inp)==0 || inp[0]=='\n'){
    /* printf("kdtree2> "); */
    fgets(inp,MAXLEN, stdin); checkword(inp); strip_newline(inp);
  }

  while( inp[0] != 'x' ){
#ifdef DEBUG
    printf("********Testing: input line is: %s\n", inp);
#endif

    switch( inp[0] ){
      case 'i':		 /* insert a vector */
      #ifdef DEBUG
        printf("inserting ...\n");
      #endif
        for(i=0;i<numdims;i++){
          /* #ifdef DEBUG
           printf("%d-th attr. value= \n", i);
           #endif */
          scanf("%lf", &val);
#ifdef DEBUG
          printf("%f \n", val);
#endif
          vecput( inputVectorPtr, i, val);
        }
#ifdef DEBUG
        printf("\n");
        printf("   inserting point: ");
        vecprint( inputVectorPtr);
#endif

        root = insert(root, inputVectorPtr);

        break;

      case 'p':		 /* print the whole tree */
        tprint(root);
        break;

      case 'r':		 /* range search */
        printf("range searching ...\n");

        for(i=0;i<numdims;i++){
        /*  printf("%d-th attr. low value= \n", i);*/
          scanf("%lf", &val);
#ifdef DEBUG
          printf("%f \n", val);
#endif
          vecput( vpLow, i, val);
        }
#ifdef DEBUG
        printf("\n");
#endif

        for(i=0;i<numdims;i++){
        /*  printf("%d-th attr. high value= \n", i);*/
          scanf("%lf", &val);
#ifdef DEBUG
          printf("%f ", val);
#endif
          vecput( vpHigh, i, val);
        }
#ifdef DEBUG
        printf("\n");
#endif

        printf("   range searching - low  values: ");
        vecprint( vpLow);
        printf("                   - high values: ");
        vecprint( vpHigh);
        rangesearch(root, vpLow, vpHigh);
        break;

      case 'm':

        for(i=0; i<numdims; i++){
          /*printf("%d-th attr. value= ", i);*/
          scanf("%lf", &val);

          #ifdef DEBUG
            printf("%f \n", val);
          #endif

          vecput(inputVectorPtr, i, val);
        }
        /* (Rui Wang): range_knn query */
        knnsearch(root, inputVectorPtr, k_nearest_neighbors, k_nearest_neighbors_radius);
        break;

      case 'n':		 /* nn search for a similar vector */
        printf("nn searching ...\n");
        /* printf("# of neighbors= ");
           scanf("%d", &count);
           */
        for(i=0;i<numdims;i++){
        /*  printf("%d-th attr. value= \n", i);*/
          scanf("%lf", &val);
#ifdef DEBUG
          printf("%f \n", val);
#endif
          vecput( inputVectorPtr, i, val);
        }
#ifdef DEBUG
        printf("\t\t for %d nn\n", count);
#endif
        printf("   nn searching - query point: ");
        vecprint( inputVectorPtr);
        nnsearch(root, inputVectorPtr, count);
        break;

      case 'x':		 /* exit */
        break;

      case 'h':		 /* print help file */
        prhelp();
        break;

      default:
        printf("illegal command: |%s| \n", inp);
    }

    /* prhelp(); */
    /*printf(PROMPT);*/
    /* printf("kdtree3> "); */
    fgets(inp,MAXLEN, stdin); checkword(inp); strip_newline(inp);
    while( strlen(inp)==0){
      /* printf("kdtree4> "); */
      fgets(inp,MAXLEN,stdin); checkword(inp); strip_newline(inp);
    }
  }

  printf("exiting\n");

  exit(0);

}

/********************************************/
/** check whether the arg. is a valid word **/
/********************************************/
void checkword(char *s){
  assert(strlen(s) < MAXLEN);
}

/********************************************/
/** strips new-line character, if any      **/
/********************************************/
void strip_newline(char *s){
  int len;
  len = strlen(s);
  if ( '\n' == s[len-1] ){
    s[len-1]='\0';
  }
}

/********************************************/
/** print the help message                 **/
/********************************************/
void prhelp(){
  printf("\t i \t\t for insertion\n");
  printf("\t n \t\t for nn search \n");
  printf("\t r \t\t for range search \n");
  printf("\t m \t\t for knn search \n");
  printf("\t p \t\t to print the tree\n");
  printf("\t x \t\t to exit\n");
  printf("\t h \t\t to print this help message\n");
}
