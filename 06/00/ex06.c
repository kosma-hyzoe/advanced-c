#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 128

struct person{
    char name[MAX_NAME_LEN];
    char surname[MAX_NAME_LEN];
    int id;
};

int main(int argc, char const *argv[])
{
    struct person foo = {"Foobian", "Barsky", 1};
    printf("Name: %s\nSurname: %s\nID: %i\n", foo.name, foo.surname, foo.id);

    struct person *fooptr = &foo; 

    strcpy(fooptr->name, "");
    strcpy(fooptr->surname, "");
    fooptr->id = 0;
    printf("Name: %s\nSurname: %s\nID: %i\n", foo.name, foo.surname, foo.id);
    return 0;
}




