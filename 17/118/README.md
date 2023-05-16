The executable can be compiled with:

```bash
# compile lib source into an object file
gcc -c src/strfun.c -o obj/lib_strfun.o

# create a static library (.a) from the object file
ar rcs lib/lib_strfun.a obj/lib_strfun.o

# compile main.c with the include dir and create an object file
gcc -I ./incl -c ./src/main.c -o obj/main.o
```
