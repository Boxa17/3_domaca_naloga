#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAPAKI 6



//niz beseda ki so v igri
char *besede[] = 
{
    "hekovanje",
    "lift",
    "cyber",
    "praktikum",
    "profesor"
};



//random biranje besed
char *odabir_besed() 
{
    srand(time(NULL));
    int index = rand() % (sizeof(besede) / sizeof(besede[0]));
    return besede[index];
}



//inicializacija igre 
void zacetak_igre(char *beseda, char *pogodak, int *napaka) {
    *napaka = 0;
    for (int i = 0; i < strlen(beseda); i++)
    {
        pogodak[i] = '_';
    }
    pogodak[strlen(beseda)] = '\0';
}



//tiskanje vesala, ako delate napaku
void tiskanje_vesala(int napaka) {
    switch (napaka) 
    {
        case 0:
            printf("\n\n\n\n\n");
            break;
        case 1:
            printf("\n\n\n\n ___\n");
            break;
        case 2:
            printf("\n  |\n  |\n  |\n ___\n");
            break;
        case 3:
            printf("   _________\n  |\n  |\n  |\n ___\n");
            break;
        case 4:
            printf("   _________\n  |         O\n  |\n  |\n ___\n");
            break;
        case 5:
            printf("   _________\n  |         O\n  |         |\n  |\n ___\n");
            break;
        case 6:
            printf("   _________\n  |         O\n  |         |\n  |         ^\n ___\n");
            break;
        case 7:
            printf("   _________\n  |         O\n  |         |\n  |         ^\n ___       / \\\n");
            break;
        case 8:
            printf("   _________\n  |         O\n  |         |\n  |         ^\n ___       / \\\n              \n");
            break;
        default:
            break;
    }
}



//proveri ali je resno, in shrani stanje igrov
int provera(char pogodi, char *beseda, char *pogodak, int *napaka) {
    int resno = 0;
    for (int i = 0; i < strlen(beseda); i++) 
    {
        if (pogodi == beseda[i]) 
        {
            pogodak[i] = pogodi;
            resno = 1;
        }
    }
    if (!resno) 
    {
        (*napaka)++;
    }
    return resno;
}



//provera ali je pobedio 
int provera_pob(char *beseda, char *pogodak) {
    return strcmp(beseda, pogodak) == 0;
}



int main() {

    //bira besedu in starta igrov
    char *beseda = odabir_besed();
    char pogodak[strlen(beseda) + 1];
    int napaka;
    zacetak_igre(beseda, pogodak, &napaka);



    //igraj 
    while (napaka < MAX_NAPAKI) 
    {
        
        tiskanje_vesala(napaka);   //tiska vesalo dok je napaka

        
        printf("Trenotni pogodak %s\n", pogodak);   //pise trenutnu resnu besedu


        //pogodak igralec
        char pogodi;
        printf("Vnesi besedo: ");
        scanf(" %c", &pogodi);



        //proverava pogodak in shrani igro
        int resno = provera(pogodi, beseda, pogodak, &napaka);
        if (resno) 
        {
            printf("Resno.\n");
        } else 
        {
            printf("Napaka.\n");
        }



        //proverava ali je igrlaces pobedio
        if (provera_pob(beseda, pogodak)) 
        {
            printf("Beseda je: %s\n", beseda);
            printf("Pobedio si.\n");
            return 0;
        }
    }

    //ako nije pobedio, igralec je izgubio :)
    tiskanje_vesala(napaka);
    printf("Beseda je: %s\n", beseda);
    printf("Izgubio si.\n");
    return 0;
}