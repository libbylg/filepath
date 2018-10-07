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




#endif//__filepath_H_
