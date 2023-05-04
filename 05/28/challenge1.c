/* global double variable only accessible inside this file */
static double bar;
/* global float variable accessible within the entire program */
extern int baz;

/* function accessible only within the file where it is defined */
static char *helloWorld()
{
        return "\"Now I am become Death, the destroyer of worlds.\"";
}

int main()
{
        /* int variable with block scope and temp. storage */
        int foo; 
        /* a float var with permanent storage */
        static int foobar;
        /* a register int variable */
        register int reg;

        return 0;
}
