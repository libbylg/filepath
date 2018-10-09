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


struct filepath_t;

void                filepath_del        (struct filepath_t* p);
struct filepath_t*  filepath_new        (char* path);
struct filepath_t*  filepath_abs        (struct filepath_t* p);
struct filepath_t*  filepath_clean      (struct filepath_t* p);
struct filepath_t*  filepath_join       (struct filepath_t* p, char* elem, ...);
int                 filepath_ok         (struct filepath_t* p);


char*   filepath_print      (struct filepath_t* p);
char*   filepath_dirname    (struct filepath_t* p);
char*   filepath_basename   (struct filepath_t* p);
char*   filepath_ext        (struct filepath_t* p);
int     filepath_split      (struct filepath_t* p, int (*callback)(void* context, char* elem), void* context);


#endif//__filepath_H_
