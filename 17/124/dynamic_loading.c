#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
/* NOT including math.h */

// gcc -o run dynamic_loading.c -ldl
int main()
{
    void *handle = dlopen("../121/lib/libstrfun.so", RTLD_LAZY);
    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror(); // clear the error code?
    int (*cfreq)(char *s, char c) = NULL;
    int (*rmnonalpha)(char *src);
    size_t (*mystrlen)(const char *s);
    char *(*mystrstr)(const char *haystack, const char *needle);
    char *(*mystrcat)(char *dest, const char *src);
    char *(*mystrcpy)(char *dest, const char *src);


    cfreq = dlsym(handle, "cfreq");
    rmnonalpha = dlsym(handle, "rmnonalpha");
    mystrlen = dlsym(handle, "mystrlen");
    mystrstr = dlsym(handle, "mystrstr");
    mystrcat = dlsym(handle, "mystrcat");
    mystrcpy = dlsym(handle, "mystrcpy");

    {
        char foo[] = "f00b@r";
        char *bar = "fooobarbaz";
        char foobar[127] = "...";
        char baz[10];

        rmnonalpha(foo);
        printf("rmnonalpha(): %s\n", foo);

        printf("cfreq(): %d\n", cfreq(bar, 'o'));

        printf("mystrlen(): %ld\n", mystrlen(bar));
        printf("mystrstr(): %s\n", mystrstr(bar, "bar"));

        mystrcat(foobar, foo);
        mystrcat(foobar, bar);
        printf("mystrcat(): %s\n", foobar);

        printf("mystrcpy(): %s\n", mystrcpy(baz, bar));

        dlclose(handle);
    }
}
