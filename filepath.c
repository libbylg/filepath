#include "filepath.h"
#include <string.h>
#include <stdlib.h>

static  char filepath_const_cur[] = ".";
static  char filepath_const_root[] = "/";

EXTERN  char*   dirname(char* path)
{

    char* p1 = strrchr(path, '/');
    char* p2 = strrchr(path, '\\');

    if ((NULL == p1) && (NULL == p2))
    {
        return filepath_const_cur;
    }

    char* p = p1;
    if ((NULL != p1) && (NULL != p2))
    {
        p = ((p1 > p2)?p1:p2);
    }
    else
    {
        p = ((NULL == p1)?p2:p1);
    }

    *p = '\0';

    if (path == p)
    {
        return filepath_const_root;
    }

    return path;
}

EXTERN  char*   basename(char* path)
{
    char* p1 = strrchr(path, '/');
    char* p2 = strrchr(path, '\\');

    if ((NULL == p1) && (NULL == p2))
    {
        return path;
    }

    char* p = p1;
    if ((NULL != p1) && (NULL != p2))
    {
        p = ((p1 > p2)?p1:p2);
    }
    else
    {
        p = ((NULL == p1)?p2:p1);
    }

    if (p == path)
    {
        return filepath_const_root;
    }


    return p + 1;
}



struct filepath_t
{
    int     err;

    size_t  cap;
    size_t  len;
    char*   path;
    int     modify;

    int     ref_modify;


};

struct filepath_t*  filepath_new        (char* path)
{
    if (NULL == path)
    {
        return NULL;
    }

    struct filepath_t* p = (struct filepath_t*)malloc(sizeof(struct filepath_t));
    if (NULL == p)
    {
        return NULL;
    }
    memset(p, 0, sizeof(struct filepath_t));

    size_t len = strlen(path);
    p->path = (char*)malloc(len + 1);
    if (NULL == p->path)
    {
        free(p);
        return NULL;
    }

    p->cap          = len + 1;
    p->len          = len;
    memcpy(p->path, path, len + 1);
    p->modify       = 0;
    p->ref_modify   = -1;   //  初始阶段，所有的引用都应该是失效的


    return p;

}

void                filepath_del        (struct filepath_t* p);

struct filepath_t*  filepath_abs        (struct filepath_t* p)
{
    
}

struct filepath_t*  filepath_clean      (struct filepath_t* p)
{
#define IS_SPLIT(c) (((c) == '/') || ((c) == '\\'))

    register char* c = p->path;

retry:
    if (IS_SPLIT(*c))
    {

    }
    


#undef IS_SPLIT
}

struct filepath_t*  filepath_join       (struct filepath_t* p, char* elem, ...);
int                 filepath_ok         (struct filepath_t* p);


char*   filepath_print      (struct filepath_t* p);
char*   filepath_dirname    (struct filepath_t* p);
char*   filepath_basename   (struct filepath_t* p);
char*   filepath_ext        (struct filepath_t* p);
int     filepath_split      (struct filepath_t* p, int (*callback)(void* context, char* elem), void* context);
