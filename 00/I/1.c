#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
* ODPOWIEDZI 
*

Linijka 38: 

W praktyce zachowanie undefined - nie przypisaliśmy odpowiednio pamięci do
wskaźnika buf. Po zrobeniu tego, zakładając odpowiednią długość stringa,
ustawiłby pierwsze 8 wskazanych przez ptr bajtów (w tym wypadku od 8 do 16 bajta
pola`buf` po operacji `ptr += 8;`) na 0.

Linijka 45:

Segentation fault! Próbujemy przeprowadzić dereferencję wskaźnika NULL. 
Zmieniając kod na `printf("%p\n", buf);` wyprintowalibyśmy ładnie '(nill)`.

*             
*/


struct Data {
    char *buf;
    size_t size;

    unsigned int id;
    const char *name;
};
struct Data data;

inline void DataSetup()
{
    const size_t size = 1024;
    void *ptr = data.buf;

    data.size = size;
    ptr = malloc(size);
    memset(ptr, 123, size); /* <-  przypisanie wartosci do arraya */
    data.id = 3;
    data.name = "First Instance";
}

int main()
{
    void *buf;

    
        char *ptr = malloc(123);
        ptr = (char *)(struct Data *)&data;
        ptr += 8;

        memset((char *)ptr, 0,  sizeof(long long)); /* co spowoduje ta operacja */
        *ptr = 148;
        ptr[1] = 1;

        buf = data.buf;
    

    printf("%p\n", buf); /* co zostanie wyprintowane na ekran? */

    return 0;
}
