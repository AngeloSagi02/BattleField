/********************************************************
ANGELO SAGIANRIO INGEGNERIA INFORMATICA 1 ANNO 2 SEMESTRE
        INIZIO: 06/02/21    FINE: 07/02/21
********************************************************/


#include <stdio.h>
#include <stdlib.h>

#define VCOLPI 1        //QUANDO COLPISCI IL VUOTO
#define BARCAp 2        //Barca Piccola
#define BARCAm 3        //Barca Media
#define BARCAg 4        //Barca Grande
#define COLPITA 5
#define AFFONDATA 6

void banner(void);

void tabella1 (void);        //generazione tab1 nemica
void tabella2 (void);        //generazione tab2 alleata
void random (int);           //Navi generate in modo randomico
void posi (void);            //posizionamento delle barche in modo casuale
void sparo (void);           //funzione che gestisce lo sparo e il controllo
int fine (int, int);              //Funzione che decreta la vittoria o la sconfitta

int tab1[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

int tab2[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

int main()
{
    int win = 0, lose = 0;
    char scelta;

    banner();
    printf("\n\nBenvenuto in BATTLEFIELD!");
    printf("\nVuoi posizionare le navi in un modo casuale? [s/n]\n");
    scelta = getchar();

    if(scelta == 'n' || scelta == 'N')
    {
        posi();
    }

    random(scelta);

    do
    {
        system("cls");
        banner();

        printf("\n\nLEGENDA: \nG = N.GRANDE  \nM = N.MEDIA \nP = N.PICCOLA  \n~ = ACQUA  \nO = C.VUOTO\n# = COLPITO\n");

        tabella1();
        tabella2();
        sparo();

        fine(win, lose);

        system("PAUSE");
    }while(fine(win, lose) != 27);

    return 0;
}

void banner (void)
{
     printf("______        _     _________  _________  _____     ________  ________  _____  ________  _____     ______    \n");
     printf("|_   _ \\      / \\   |  _   _  ||  _   _  ||_   _|   |_   __  ||_   __  ||_   _||_   __  ||_   _|   |_   _ `.  \n");
     printf("  | |_) |    / _ \\  |_/ | | \\_||_/ | | \\_|  | |       | |_ \\_|  | |_ \\_|  | |    | |_ \\_|  | |       | | `. \ \n");
     printf("  |  __'.   / ___ \\     | |        | |      | |   _   |  _| _   |  _|     | |    |  _| _   | |   _   | |  | | \n");
     printf(" _| |__) |_/ /   \\ \\_  _| |_      _| |_    _| |__/ | _| |__/ | _| |_     _| |_  _| |__/ | _| |__/ | _| |_.' /  \n");
     printf("|_______/|____| |____||_____|    |_____|  |________||________||_____|   |_____||________||________||______.'   \n");
}

void tabella1 (void)
{
    int x, y;

    printf("\n  CAMPO NEMICO");
    printf("\n   0 1 2 3 4 5 6 7 8 9 ");
    printf("\n   -------------------\n");

    for(y = 0; y<=9; y++)
    {
        printf("%d| ", y);

        for(int x = 0; x<=9; x++)
        {
            if(tab1[y][x] == VCOLPI)
            {
                printf("O ");
            }
            else if(tab1[y][x] == COLPITA)
            {
                printf("# ");
            }
            else if(tab1[y][x] == AFFONDATA)
            {
                printf("X ");
            }
            else
            {
                printf("~ ");
            }
            //printf("%d ", tab1[y][x]);
        }
        printf("\n");
    }
}

void tabella2 (void)
{
    int x, y;

    printf("\n  CAMPO ALLEATO");
    printf("\n   0 1 2 3 4 5 6 7 8 9 ");
    printf("\n   -------------------\n");


    for(y = 0; y<=9; y++)
    {
        printf("%d| ", y);

        for(int x = 0; x<=9; x++)
        {
            if(tab2[y][x] == BARCAg)
            {
                printf("G ");
            }
            else if(tab2[y][x] == BARCAm)
            {
                printf("M ");
            }
            else if(tab2[y][x] == BARCAp)
            {
                printf("P ");
            }
            else if(tab2[y][x] == AFFONDATA)
            {
                printf("X ");
            }
            else if(tab2[y][x] == COLPITA)
            {
                printf("# ");
            }
            else if(tab2[y][x] == VCOLPI)
            {
                printf("O ");
            }
            else if(tab2[y][x] == 0)
            {
                printf("~ ");
            }
            //printf("%d ", tab2[y][x]);
        }
        printf("\n");
    }
}

void random (int scelta)
{
    int x = 0, y = 0, i = 0;

    srand(time(NULL));

    if(scelta == 's' || scelta == 'S')
    {
        for(i=0; i<=3; i++) // GENRAZIOENE BARCHE GRANDI
        {
            x = 0,y = 0;

            x=0+rand()%10;
            y=0+rand()%8;

            if(tab2[y][x] == 0 && tab2[y-1][x] == 0 && tab2[y+1][x] == 0 && tab2[y+2][x] == 0 && tab2[y+3][x] == 0)  //controllo se le posizioni prima e dopo sulla colonna y sono occupate
            {
                tab2[y][x] = BARCAg;
                tab2[y+1][x] = BARCAg;
                tab2[y+2][x] = BARCAg;
            }
            else
            {
                i--;
            }
/*
            printf("y:%d\n", y);
            printf("x:%d\n", x);
            printf("i:%d\n", i);
*/
        }

        for(i=0; i<5; i++) // GENRAZIOENE BARCHE MEDIE
        {
            //printf("%d\n\n", i);

            x = 0, y = 0;

            x=0+rand()%10;
            y=0+rand()%9;

            if(tab2[y][x] == 0 && tab2[y-1][x] == 0 && tab2[y+2][x] == 0 && tab2[y+1][x] == 0)
            {
                tab2[y][x] = BARCAm;
                tab2[y+1][x] = BARCAm;
            }
            else
            {
                i--;
            }
        }

        for(i=0; i<5; i++) // GENRAZIOENE BARCHE PICCOLE
        {
            //printf("%d\n\n", i);

            x = 0, y = 0;

            x=0+rand()%10;
            y=0+rand()%10;

            if(tab2[y][x] == 0 && tab2[y-1][x] == 0 && tab2[y+1][x] == 0)
            {
                tab2[y][x]= BARCAp;
            }
            else
            {
                i--;
            }

        }
    }


// GENERAZIONE DELLE BARCHE NEMICHE

    for(i=0; i<=3; i++) // GENRAZIOENE BARCHE GRANDI
    {
        x = 0;
        y = 0;

        x=0+rand()%10;
        y=0+rand()%8;

        if(tab1[y][x] == 0 && tab1[y-1][x] == 0 && tab1[y+1][x] == 0 && tab1[y+2][x] == 0 && tab1[y+3][x] == 0)  //controllo se le posizioni prima e dopo sulla colonna y sono occupate
        {
            tab1[y][x] = BARCAg;
            tab1[y+1][x] = BARCAg;
            tab1[y+2][x] = BARCAg;
        }
        else
        {
            i--;
        }
/*
        printf("y:%d\n", y);
        printf("x:%d\n", x);
        printf("i:%d\n", i);
*/
    }

    for(i=0; i<5; i++) // GENRAZIOENE BARCHE MEDIE
    {
        //printf("%d\n\n", i);

        x = 0, y = 0;

        x=0+rand()%10;
        y=0+rand()%9;

        if(tab1[y][x] == 0 && tab1[y-1][x] == 0 && tab1[y+2][x] == 0 && tab1[y+1][x] == 0)
        {
            tab1[y][x] = BARCAm;
            tab1[y+1][x] = BARCAm;
        }
        else
        {
            i--;
        }
    }

    for(i=0; i<5; i++) // GENRAZIOENE BARCHE PICCOLE
    {
        //printf("%d\n\n", i);

        x = 0, y = 0;

        x=0+rand()%10;
        y=0+rand()%10;

        if(tab1[y][x] == 0 && tab1[y-1][x] == 0 && tab1[y+1][x] == 0)
        {
            tab1[y][x]= BARCAp;
        }
        else
        {
            i--;
        }

    }
}

void sparo(void)
{
    int x = 0, y = 0;

    srand(time(NULL));

    printf("Dove vuoi colpire?\n");

    printf("\nDammi la x:");
    scanf("%d", &x);

    printf("Dammi la y:");
    scanf("%d", &y);

    if(tab1[y][x] == VCOLPI || tab1[y][x] == COLPITA || tab1 == AFFONDATA)
    {
        printf("\nNon e' utile colpire dove hai già colpito!\n\n");
    }
    if(tab1[y][x] == 0)
    {
        printf("\nNon abbiamo colpito nulla!\n\n");
        tab1[y][x] = VCOLPI;
    }
    if(tab1[y][x] == BARCAp)
    {
        printf("\nNe abbiamo distrutta una piccola!\n\n");
        tab1[y][x] = AFFONDATA;
    }

    if(tab1[y][x] == BARCAm)
    {
        printf("Abbiamo colpito una nave media!\n\n");
        tab1[y][x] = COLPITA;

        if(tab1[y+1][x] == COLPITA || tab1[y-1][x] == COLPITA)
        {
            printf("Abbiamo distrutto una nave di medie dimensioni!\n\n");
            tab1[y][x] = AFFONDATA;

            if(tab1[y-1][x] == COLPITA)
            {
                tab1[y-1][x] = AFFONDATA;
            }
            else if(tab1[y+1][x] == COLPITA)
            {
                tab1[y+1][x] = AFFONDATA;
            }
        }
    }
    if(tab1[y][x] == BARCAg)
    {
        printf("\nAbbiamo colpito una Nave grande!\n\n");
        tab1[y][x] = COLPITA;

        if(tab1[y+1][x] == COLPITA && tab1[y-1][x] == COLPITA ||
            tab1[y+1][x] == COLPITA && tab1[y+2][x] == COLPITA ||
            tab1[y-1][x] == COLPITA && tab1[y-2][x] == COLPITA)
        {
            tab1[y][x] = AFFONDATA;

            printf("\nL'hai distrutta!!\n\n");

            if(tab1[y+1][x] == COLPITA && tab1[y-1][x] == COLPITA)
            {
                tab1[y-1][x] = AFFONDATA;
                tab1[y+1][x] = AFFONDATA;
            }
            else if(tab1[y+1][x] == COLPITA && tab1[y+2][x] == COLPITA)
            {
                tab1[y+1][x] = AFFONDATA;
                tab1[y+2][x] = AFFONDATA;
            }
            else if(tab1[y-1][x] == COLPITA && tab1[y-2][x] == COLPITA)
            {
                tab1[y-1][x] = AFFONDATA;
                tab1[y-2][x] = AFFONDATA;
            }
        }
    }

    //GESTIONE SPARO NEMICO

    x = 0, y=0;

    do
    {
            x=0+rand()%10;
            y=0+rand()%10;
            //printf("%d", x);

    }while((tab2[y][x] == VCOLPI || tab2[y][x] == COLPITA || tab2 == AFFONDATA));
    //NEL CASO LA  COORDINATA E' STATA GIA' COLPITA, GENERA UNA NUOVA CORDINATA)

    if(tab2[y][x] == 0)
    {
        printf("Ci ha mancato!\n\n");
        tab2[y][x] = VCOLPI;
    }

    if(tab2[y][x] == BARCAp)
    {
        printf("Ci ha distrutto una nave piccola!\n\n");
        tab2[y][x] = AFFONDATA;
    }

    if(tab2[y][x] == BARCAm)
    {
        printf("Ci ha colpito una nave media!\n\n");
        tab2[y][x] = COLPITA;

        if(tab2[y+1][x] == COLPITA || tab2[y-1][x] == COLPITA)
        {
            printf("Ci ha distrutto una nave di medie dimensioni!\n\n");
            tab2[y][x] = AFFONDATA;

            if(tab2[y-1][x] == COLPITA)
            {
                tab2[y-1][x] = AFFONDATA;
            }
            else if(tab2[y+1][x] == COLPITA)
            {
                tab2[y+1][x] = AFFONDATA;
            }
        }
    }


    if(tab2[y][x] == BARCAg)
    {
        printf("\nHa colpito una nave grande!\n\n");
        tab2[y][x] = COLPITA;

        if(tab2[y+1][x] == COLPITA && tab2[y-1][x] == COLPITA ||
            tab2[y+1][x] == COLPITA && tab2[y+2][x] == COLPITA ||
            tab2[y-1][x] == COLPITA && tab2[y-2][x] == COLPITA)
        {
            tab2[y][x] = AFFONDATA;

            printf("\nL'hai distrutta!!\n\n");

            if(tab2[y+1][x] == COLPITA && tab2[y-1][x] == COLPITA)
            {
                tab2[y-1][x] = AFFONDATA;
                tab2[y+1][x] = AFFONDATA;
            }
            else if(tab2[y+1][x] == COLPITA && tab2[y+2][x] == COLPITA)
            {
                tab2[y+1][x] = AFFONDATA;
                tab2[y+2][x] = AFFONDATA;
            }
            else if(tab2[y-1][x] == COLPITA && tab2[y-2][x] == COLPITA)
            {
                tab2[y-1][x] = AFFONDATA;
                tab2[y-2][x] = AFFONDATA;
            }
        }
    }
}

void posi(void)
{
    int x, y, i;

    for(i=3; i>=1; i--) // GENRAZIOENE BARCHE GRANDI
    {
        x = 0;
        y = 0;

        printf("\n|G|\n|G|\n|G|\n");

        tabella2();

        printf("Ne hai ancora %d. ", i);

        printf("Dove vuoi mettere le Barche grandi? Dammi la x ");
        scanf("%d", &x);

        printf("Dove vuoi mettere le Barche grandi? Dammi la y ");
        scanf("%d", &y);

        if(tab2[y][x] == 0 && tab2[y-1][x] == 0 && tab2[y+1][x] == 0 && tab2[y+2][x] == 0 && tab2[y+3][x] == 0)  //controllo se le posizioni prima e dopo sulla colonna y sono occupate
        {
            tab2[y][x] = BARCAg;
            tab2[y+1][x] = BARCAg;
            tab2[y+2][x] = BARCAg;
        }
        else
        {
            printf("Non puoi mettere le navi troppo vicine o si colpiranno!\n");
            i++;
        }
/*
        printf("y:%d\n", y);
        printf("x:%d\n", x);
        printf("i:%d\n", i);
*/
    }

    for(i=5; i>=1; i--) // GENRAZIOENE BARCHE MEDIE
    {
        //printf("%d\n\n", i);

        x = 0, y = 0;

        printf("\n|M|\n|M|\n");

        tabella2();

        printf("Ne hai ancora %d. ", i);

        printf("Dove vuoi mettere le Barche grandi? Dammi la x ");
        scanf("%d", &x);

        printf("Dove vuoi mettere le Barche grandi? Dammi la y ");
        scanf("%d", &y);


        if(tab2[y][x] == 0 && tab2[y-1][x] == 0 && tab2[y+2][x] == 0 && tab2[y+1][x] == 0)
        {
            tab2[y][x] = BARCAm;
            tab2[y+1][x] = BARCAm;
        }
        else
        {
            printf("Non puoi mettere le navi troppo vicine o si colpiranno!\n");
            i++;
        }
    }

    for(i=6; i>=1; i--) // GENRAZIOENE BARCHE PICCOLE
    {
            //printf("%d\n\n", i);

        x = 0, y = 0;

        printf("\n|P|\n");

        tabella2();

        printf("Ne hai ancora %d. ", i);

        printf("Dove vuoi mettere le Barche Piccole? Dammi la x ");
        scanf("%d", &x);

        printf("Dove vuoi mettere le Barche Piccole? Dammi la y ");
        scanf("%d", &y);

        if(tab2[y][x] == 0 && tab2[y-1][x] == 0 && tab2[y+1][x] == 0)
        {
            tab2[y][x] = BARCAp;
        }
        else
        {
            printf("Non puoi mettere le navi troppo vicine o si colpiranno!\n");
            i++;
        }

    }
}

int fine (int counterA, int counterN)
{

    printf("ao");
    for(int y = 0; y<=9; y++)
    {
        for(int x = 0; x<=9; x++)
        {
            if(tab1[y][x] == AFFONDATA)
            {
                counterN++;
            }

            if(tab2[y][x] == AFFONDATA)
            {
                counterA++;
            }
        }
    }
    //printf("%\nd a", counterA);
    //printf("\n%d n", counterN);

    if(counterA == 27)
    {
        printf("\n\nHai vinto!");
        return counterA;
    }

    if(counterN == 27)
    {
        printf("\n\nHai Perso!");
        return counterN;
    }
}
