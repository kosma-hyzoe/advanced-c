
#include <stddef.h>
#include <stdint.h>

int
main()
{
    typedef struct {
        void *corrupted_buf;
        size_t size;
    } local_data_t;

    local_data_t data;

    /* zmodyfikowac zawartosc danych w buforze ``corrupted_buf`` wedlug schematu:
     *
     * 1. dla kazdego bajta:   [indeksacja 0-7 !]
     *   - 0. bit kazdego bajta- ustawic na 0
     *   - 2-3 bity - zamienic miejscami z bitami 6-7
     *
     * 2. zamienic kolejnosc bajtow w slowach 4 bajtowych od 0 do ``size``-1
     *    +slowa czytane wedlug LSB zamienic na MSB  (1. slowo rozpoczyna sie od 0. bajtu)
     *    np. dla slowa:       12 34 56 78
     *          po zamiannie:  78 56 34 12
     *        dla ``corrupted_buf``:       12 34 56 78 90 09
     *           poprawna zamiana to:      78 56 34 12 90 09
     *                (tj. ostatnie dwa bajty nie zostaly zamienione poniewac nie da utworzyc sie z nich slowa 4 bajtowego)
     * */
}
