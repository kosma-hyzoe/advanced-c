# Advanced C

## Storage classes

* auto - "within a block", only specified for extra clarity /overwriting extern
* register -
* static  

Extern:

```c
// source1.c
#include <stdio.h>

// option one: declared 'globally'
extern int count; 

void increment(void) {
   // option two: in a function body. exclusive with option 1?
   extern int count; 
   count++;
}

int main() {
   increment();
   printf("The value of count is: %d", count);
   return 0;
}

// source2.c
#include <stdio.h>

int count = 0; // external variable definition
```
