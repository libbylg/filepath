#ifndef __filepath_H_
#define __filepath_H_




#ifndef     EXTERN
#ifdef __cplusplus
#define     EXTERN  extern  "C"
#else
#define     EXTERN  extern  
#endif
#endif//    EXTERN




#ifdef _MSC_VER
EXTERN  char*   dirname(char* p);
EXTERN  char*   basename(char* p);
#else
#include <libgen.h>
#endif


struct filepath_t
{

};

void    filepath_exit       (struct filepath_t* p);
int     filepath_init       (struct filepath_t* p, char* path);
int     filepath_abs        (struct filepath_t* p, char* path);
int     filepath_clean      (struct filepath_t* p, char* path);
int     filepath_join       (struct filepath_t* p, char* elem, ...);


char*   filepath_print      (struct filepath_t* p);
char*   filepath_dirname    (struct filepath_t* p);
char*   filepath_basename   (struct filepath_t* p);
char*   filepath_ext        (struct filepath_t* p);
int     filepath_split      (struct filepath_t* p, int (*callback)(void* context, char* elem). void* context);


#endif//__filepath_H_
