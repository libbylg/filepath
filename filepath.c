#include "filepath.h"
#include <string.h>

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

