#include <stdio.h>
#include <stdlib.h>

// Cteni znak po znaku


int main()
{
    int cislo_radku = 0;
    double suma_radku = 0;
    double suma = 0;
    char c;

    FILE *input = fopen("data/input.txt", "r");
    FILE *output = fopen("data/output.txt", "w");

    if(input == NULL)
    {
        perror("Error in opening file");
        return(-1);
    }

    char cislo[10] = { 0 };
    int znak_v_cisle = 0;
    // Cte do konce souboru
    do
    {
        c = fgetc(input);

        if((48 <= c && c <= 57) || c == '.') // Pokud se jedna o cast cisla
            cislo[znak_v_cisle++] = c;


        else // if(c == ' ' || c == '\t' || c == '\n') Pokud se jedna o konce cisel
        {
            cislo[znak_v_cisle+1] = '\0';

            suma_radku += atof(cislo);
            znak_v_cisle = 0;

            if (c == '\n' || c == EOF)
            {
                printf("Suma %d. radku je: %f\n", ++cislo_radku, suma_radku);
                fprintf(output, "%f\n", suma_radku);
                suma += suma_radku;
                suma_radku = 0;
            }
        }
    }
    while (c != EOF);

    printf("\nSuma vsech radku je: %f\n", suma);
    fprintf(output,"\nSuma vsech radku je: %f\n", suma);

    return 0;
}
