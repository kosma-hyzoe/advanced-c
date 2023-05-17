void increment(int *intptr, int x)
{
    *intptr += x;    
}

void multiply(int *intptr, int x)
{
    *intptr *= x;
}

int main()
{
    int i = 3;
    printf("i: %i\n", i);

    int x = 5;
    increment(&i, x);
    printf("i after adding %i: %i\n", x, i);

    x = 10;
    multiply(&i, x);
    printf("i after multiplying by %i: %i\n", x, i);
}