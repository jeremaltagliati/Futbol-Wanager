#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    int c;
    struct timeval t1;
    time_t t;
    int n=4;
    int i,j;
    int numero;
    int suma1=0,suma2=0;
    char resultado;
    int equipo1 [n];
    int equipo2 [n];
    /*
    for (i=0; i<=n; i++)
    {
        fflush(stdin);
        printf("OVR del jugador %d del primer equipo\n",i+1);
        scanf("%d",&equipo1[i]);
        suma1 = suma1 + equipo1[i];
    }
    printf("%d\n",suma1);
    for (j=0; j<=n; j++)
    {
        fflush(stdin);
        printf("OVR del jugador %d del segundo equipo\n",j+1);
        scanf("%d",&equipo2[j]);
        suma2 = suma2 + equipo2[j];
    }
    printf("%d\n",suma2);
    */

    
    for(i=0; i<5; i++){
        Sleep(37);
        gettimeofday(&t1, NULL);
        srand(t1.tv_usec * t1.tv_sec);
        fflush(stdin);
        printf("\n%d\n",rand()%100);
        //getchar();
    }
    return 0;
}
