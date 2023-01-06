#include <stdio.h>

#define NAJMANJSE_NADSTROPLJE -1 //podrum
#define NAJVECJE_NADSTROPLJE 7  //balkon



//globalne spremennjivke
int trenutno_nadstroplje = 1; //inicializacija trenutnega nadstroplja
int stevilo_putnikov = 0; //inicializacija stevila putnikov



//tipi funkcija
int get_destinacija_nadstroplje(void);
void pot(int trenutno_nadstroplje, int cilj);
void izkrcani_putnikov(int nadstroplje);



int main(void)
{
    int cilj;

    //lift zacne od prizemlja
    izkrcani_putnikov(trenutno_nadstroplje);



    
    while (1)   //lift ide dok neko ne zeli da izadje
    {
        //tukaj dobil kam lift gre od uporabnika
        cilj = get_destinacija_nadstroplje();



        
        while (cilj == 0)   //ako uporabnik vstavi napako nadstroplje, tole je napaka in vprasa enkrat z nadstroplje
        {
            printf("Napaka. Prosim vnesite enkrat nadstroplje: ");
            cilj = get_destinacija_nadstroplje();
        }



       
    while (cilj == trenutno_nadstroplje)   //ako je destinacijsto nadstroplje isto kot trenutno nadstroplje, tole je napaka in vprasa z drugo nadstroplje
    {
        printf("Napaka lift je na tom nadstroplju. Prosim vnesite enkrat nadstroplje: ");
        cilj = get_destinacija_nadstroplje();
    }



        //pot do destinacijskog nadstroplja
        pot(trenutno_nadstroplje, cilj);



        //uzstop in izstop potnikov
        izkrcani_putnikov(cilj);



        //spremeni trenutno nadstroplje in stevilo potnikov
        trenutno_nadstroplje = cilj;
    }

    return 0;
}



int get_destinacija_nadstroplje(void)   //tole funkcia dobil destinacijsko nadstroplje
{
    int cilj;
    char nadstroplje;

    printf("Vnesite kam grete: (P, R, 1, 2, 3, 4, 5, B): ");
    scanf(" %c", &nadstroplje);

    switch (nadstroplje)
    {
        case 'P':
            cilj = NAJMANJSE_NADSTROPLJE;
            break;
        case 'R':
            cilj = 1;
            break;
        case '1':
            cilj = 2;
            break;
        case '2':
            cilj = 3;
            break;
        case '3':
            cilj = 4;
            break;
        case '4':
            cilj = 5;
            break;
        case '5':
            cilj = 6;
            break;
        case 'B':
            cilj = NAJVECJE_NADSTROPLJE;
            break;
        default:
            cilj = 0;
            break;
    }

    return cilj;
}




void pot(int trenutno_nadstroplje, int cilj)   //tole funkcija dela lift, gre do destinacijskog nadstroplja
{
    char *trenutno_nadstroplje_ime;
    char *cilj_ime;

    switch (trenutno_nadstroplje)
    {
        case -1:
            trenutno_nadstroplje_ime = "Podrum";
            break;
        case 1:
            trenutno_nadstroplje_ime = "Prizemlje";
            break;
        case 2:
            trenutno_nadstroplje_ime = "1.";
            break;
        case 3:
            trenutno_nadstroplje_ime = "2.";
            break;
        case 4:
            trenutno_nadstroplje_ime = "3.";
            break;
        case 5:
            trenutno_nadstroplje_ime = "4.";
            break;
        case 6:
            trenutno_nadstroplje_ime = "5.";
            break;
        case 7:
            trenutno_nadstroplje_ime = "Balkon";
            break;
        default:
            trenutno_nadstroplje_ime = "Napako nadstroplje";
            break;
    }

    switch (cilj)
    {
        case -1:
            cilj_ime = "Podrum";
            break;
        case 1:
            cilj_ime = "Prizemlje";
            break;
        case 2:
            cilj_ime = "1.";
            break;
        case 3:
            cilj_ime = "2.";
            break;
        case 4:
            cilj_ime = "3.";
            break;
        case 5:
            cilj_ime = "4.";
            break;
        case 6:
            cilj_ime = "5.";
            break;
        case 7:
            cilj_ime = "Balkon";
            break;
        default:
            cilj_ime = "Napako nadstroplje";
            break;
    }

    printf("Gre od %s nadstroplja do %s nadstroplja...\n", trenutno_nadstroplje_ime, cilj_ime);
}




void izkrcani_putnikov(int nadstroplje)    //tole funkcia delka uzstop in izstop putnikov
{
    int potnici;

    printf("Stevilo putnikov ki uztopajo v lift: ");
    scanf("%d", &potnici);
    stevilo_putnikov += potnici;



    printf("Stevilo putnikov ki izstopajo iz lifta: ");
    scanf("%d", &potnici);
    stevilo_putnikov -= potnici;



    
    if (stevilo_putnikov < 0)   //ako stevilo putnikov manjse od nic, tole je napaka in vstavi stevilo putnikov na nic.
    {
        printf("Napaka, ni moguce stevilo putnikov.\n");
        stevilo_putnikov = 0;
    }

    printf("Stevilo putnikov ki so ostali v liftu: %d\n", stevilo_putnikov);
}