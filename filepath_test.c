#include <stdio.h>
#include <string.h>
#include <assert.h>


#include "filepath.h"


#define TEST_SET    \
    TEST_CASE("/", "/", "/")    \
TEST_CASE("/usr/lib",    "/usr",    "lib")  \
TEST_CASE("/usr/"   ,   "/"    ,    "usr")  \
TEST_CASE("/usr"    ,   "/"    ,    "usr")  \
TEST_CASE("usr"     ,    "."   ,    "usr")  \
TEST_CASE("."       ,    "."   ,    ".")    \
TEST_CASE(".."      ,    "."   ,    "..")


int main(int argc, char* argv[])
{

#define TEST_CASE(p,d,b)                       \
    {                                          \
        printf("test: %s\n", p);               \
        char* t = strdup(p);                   \
        assert(0 == strcmp(d, dirname(t)));    \
                                               \
        t = strdup(p);                         \
        assert(0 == strcmp(b, basename(t)));   \
    }

    TEST_SET

#undef TEST_CASE

        return 0;
}

