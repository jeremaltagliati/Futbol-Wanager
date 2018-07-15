#include <stdio.h>
#include <stdlib.h>+
#include <time.h>
#include <windows.h>

int main()
{
    struct timeval t1;
    time_t t;
    int Q1=900;
    int Q2=900;
    int Q3=900;
    int Q4=900;
    int resultado_equipo1=0;
    int resultado_equipo2=0;
    int pase,finpase;
    int completo;
    int acarreo,finacarreo;
    int jugada;
    int posesion=1;
    int yarda_actual=25;
    int yarda_apasar=35;
    int yardas;
    int oportunidad=1;
    int avance;
    int avan;
    int ava;
    int avanceac;
    int intercepcion;
    int patada;
    int goldecampo;

    printf("INICIO DEL PARTIDO\n");
    while (Q1>0)
    {   //Se esta jugando el primer cuarto
        //Presentacion actual
        printf("Resultado del partido: %d - %d\n",resultado_equipo1,resultado_equipo2);
        printf("\nLa posesion es del equipo %d\n",posesion);
        printf("\n%d:%d\n",(Q1/60),(Q1%60));
        printf("\nYarda actual=%d\n",yarda_actual);
        printf("\n%d",oportunidad);
        printf("&");
        yardas=yarda_apasar-yarda_actual;
        if (yarda_apasar<100)
        {
            printf("%d\n",yardas);
        }
        else
        {
            printf("GOAL\n");

        }
        //getchar();
        if (posesion==1)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("Intento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;
                    if(goldecampo<77)
                    {
                        printf("El gol de campo es bueno\n");
                        resultado_equipo1=resultado_equipo1+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=2;
                        goto etiqueta_pos1;
                    }
                }
                else
                {
                    printf("Despeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=2;
                    goto etiqueta_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;
                if (jugada<50)
                {
                printf("\nPase\n");
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                finpase=rand()%100;
                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo1=resultado_equipo1+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo1=resultado_equipo1+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;
                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }

                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo1=resultado_equipo1+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85){
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo1=resultado_equipo1+1;
                            }
                            else{
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=2;
                            goto etiqueta_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=2;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta_pos1;
                    }
                }
            }
        }

        if(posesion==2)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("\nIntento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;
                    if(goldecampo<77)
                    {
                        printf("\nEl gol de campo es bueno\n");
                        resultado_equipo2=resultado_equipo2+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=1;
                        goto etiqueta_pos1;
                    }
                }
                else
                {
                    printf("\nDespeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=1;
                    goto etiqueta_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;
                if (jugada<50)
                {
                    printf("\nPase\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finpase=rand()%100;

                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }    
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo2=resultado_equipo2+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo2=resultado_equipo2+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
    
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo2=resultado_equipo2+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85)
                            {
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo2=resultado_equipo2+1;
                            }
                            else
                            {
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=1;
                            goto etiqueta_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=1;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta_pos1;
                    }
                }
            }
        }
    etiqueta_pos1:
    Q1=Q1-30;
    }

    printf("\nFin del primer cuarto\n");
    printf("Resultado: %d - %d\n",resultado_equipo1,resultado_equipo2);
    printf("INICIO DEL SEGUNDO CUARTO\n");

    while (Q2>0)
    {   //Se esta jugando el segundo cuarto
        printf("Resultado del partido: %d - %d\n",resultado_equipo1,resultado_equipo2);
        printf("\nLa posesion es del equipo %d\n",posesion);
        printf("\n%d:%d\n",(Q2/60),(Q2%60));
        printf("\nYarda actual=%d\n",yarda_actual);
        printf("\n%d",oportunidad);
        printf("&");
        yardas=yarda_apasar-yarda_actual;
        if (yarda_apasar<100)
        {
            printf("%d\n",yardas);
        }
        else
        {
            printf("GOAL\n");

        }
        //getchar();
        if (posesion==1)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("Intento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;

                    if(goldecampo<77)
                    {
                        printf("El gol de campo es bueno\n");
                        resultado_equipo1=resultado_equipo1+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta2_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=2;
                        goto etiqueta2_pos1;
                    }
                }
                else
                {
                    printf("Despeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=2;
                    goto etiqueta2_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;

                if (jugada<50)
                {
                printf("\nPase\n");
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                finpase=rand()%100;
                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta2_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta2_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo1=resultado_equipo1+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo1=resultado_equipo1+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta2_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
    
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }                        
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo1=resultado_equipo1+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85){
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo1=resultado_equipo1+1;
                            }
                            else{
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=2;
                            goto etiqueta2_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=2;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta2_pos1;
                    }
                }
            }
        }

        if(posesion==2)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("\nIntento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;

                    if(goldecampo<77)
                    {
                        printf("\nEl gol de campo es bueno\n");
                        resultado_equipo2=resultado_equipo2+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta2_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=1;
                        goto etiqueta2_pos1;
                    }
                }
                else
                {
                    printf("\nDespeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=1;
                    goto etiqueta2_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;
                if (jugada<50)
                {
                    printf("\nPase\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finpase=rand()%100;

                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta2_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta2_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo2=resultado_equipo2+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo2=resultado_equipo2+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta2_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
    
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }                        
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo2=resultado_equipo2+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85)
                            {
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo2=resultado_equipo2+1;
                            }
                            else
                            {
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=1;
                            goto etiqueta2_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=1;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta2_pos1;
                    }
                }
            }
        }
    etiqueta2_pos1:
    Q2=Q2-30;
    }
    printf("\nFin de la primera mitad\n");
    printf("Resultado: %d - %d\n",resultado_equipo1,resultado_equipo2);
    posesion=2;
    printf("INICIO DE LA SEGUNDA MITAD\n");
    while (Q3>0)
    {   //Se esta jugando el tercer cuarto
        printf("Resultado del partido: %d - %d\n",resultado_equipo1,resultado_equipo2);
        printf("\nLa posesion es del equipo %d\n",posesion);
        printf("\n%d:%d\n",(Q3/60),(Q3%60));
        printf("\nYarda actual=%d\n",yarda_actual);
        printf("\n%d",oportunidad);
        printf("&");
        yardas=yarda_apasar-yarda_actual;
        if (yarda_apasar<100)
        {
            printf("%d\n",yardas);
        }
        else
        {
            printf("GOAL\n");

        }
        //getchar();
        if (posesion==1)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("Intento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;

                    if(goldecampo<77)
                    {
                        printf("El gol de campo es bueno\n");
                        resultado_equipo1=resultado_equipo1+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta3_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=2;
                        goto etiqueta3_pos1;
                    }
                }
                else
                {
                    printf("Despeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=2;
                    goto etiqueta3_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;

                if (jugada<50)
                {
                printf("\nPase\n");
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                finpase=rand()%100;
                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta3_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta3_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo1=resultado_equipo1+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo1=resultado_equipo1+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta3_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
    
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }                        
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo1=resultado_equipo1+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85){
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo1=resultado_equipo1+1;
                            }
                            else{
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=2;
                            goto etiqueta3_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=2;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta3_pos1;
                    }
                }
            }
        }

        if(posesion==2)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("\nIntento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;

                    if(goldecampo<77)
                    {
                        printf("\nEl gol de campo es bueno\n");
                        resultado_equipo2=resultado_equipo2+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta3_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=1;
                        goto etiqueta3_pos1;
                    }
                }
                else
                {
                    printf("\nDespeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=1;
                    goto etiqueta3_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;
                if (jugada<50)
                {
                    printf("\nPase\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finpase=rand()%100;

                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta3_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta3_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo2=resultado_equipo2+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo2=resultado_equipo2+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta3_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
    
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo2=resultado_equipo2+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85)
                            {
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo2=resultado_equipo2+1;
                            }
                            else
                            {
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=1;
                            goto etiqueta3_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=1;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta3_pos1;
                    }
                }
            }
        }
    etiqueta3_pos1: 
    Q3=Q3-30;
    }
    printf("INICIO DEL CUARTO CUARTO\n");
    while (Q4>0)
    {   //Se esta jugando el cuarto cuarto
        printf("Resultado del partido: %d - %d\n",resultado_equipo1,resultado_equipo2);
        printf("\nLa posesion es del equipo %d\n",posesion);
        printf("\n%d:%d\n",(Q4/60),(Q4%60));
        printf("\nYarda actual=%d\n",yarda_actual);
        printf("\n%d",oportunidad);
        printf("&");
        yardas=yarda_apasar-yarda_actual;
        if (yarda_apasar<100)
        {
            printf("%d\n",yardas);
        }
        else
        {
            printf("GOAL\n");

        }
        //getchar();
        if (posesion==1)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("Intento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;

                    if(goldecampo<77)
                    {
                        printf("El gol de campo es bueno\n");
                        resultado_equipo1=resultado_equipo1+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta4_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=2;
                        goto etiqueta4_pos1;
                    }
                }
                else
                {
                    printf("Despeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=2;
                    goto etiqueta4_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;

                if (jugada<50)
                {
                printf("\nPase\n");
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                finpase=rand()%100;
                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta4_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=2;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta4_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo1=resultado_equipo1+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo1=resultado_equipo1+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=2;
                        goto etiqueta4_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
    
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo1=resultado_equipo1+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85){
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo1=resultado_equipo1+1;
                            }
                            else{
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=2;
                            goto etiqueta4_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=2;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta4_pos1;
                    }
                }
            }
        }

        if(posesion==2)
        {
            if(oportunidad==4)
            {
                if(yarda_actual>=67)
                {
                    printf("\nIntento de gol de campo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    goldecampo=rand()%100;

                    if(goldecampo<77)
                    {
                        printf("\nEl gol de campo es bueno\n");
                        resultado_equipo2=resultado_equipo2+3;
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta4_pos1;
                    }
                    else
                    {
                        printf("\nEl gol de campo fue fallado\n");
                        oportunidad=1;
                        yarda_actual = 100 - yarda_actual;
                        yarda_apasar = yarda_actual +10;
                        posesion=1;
                        goto etiqueta4_pos1;
                    }
                }
                else
                {
                    printf("\nDespeje(Punt)\n");
                    oportunidad=1;
                    yarda_actual=100 - yarda_actual - 60;
                    if(yarda_actual<0)
                    {
                        yarda_actual=25;
                    }
                    yarda_apasar=yarda_actual+10;
                    posesion=1;
                    goto etiqueta4_pos1;
                }
            }
            else
            {
                gettimeofday(&t1, NULL);
                srand(t1.tv_usec * t1.tv_sec);
                jugada=rand()%100;
                if (jugada<50)
                {
                    printf("\nPase\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finpase=rand()%100;

                    if(finpase<35)
                    {
                        printf("\nPase completo\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        ava=rand()%100;
                        if(ava<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%8-7;
                        }
                        if((ava>=10)&&(ava<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6;    
                        }
                        if((ava>=55)&&(ava<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%6+5;
                        }
                        if((ava>=85)&&(ava<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%21+10;    
                        }
                        if(ava>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avance=rand()%71+30;    
                        }
                        if((yarda_actual+avance)>=yarda_apasar)
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nPase de %d yardas\n",avance);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avance;
                            yarda_apasar=yarda_apasar;
                        }
                    }
                    if((finpase>=35)&&(finpase<80))
                    {
                    printf("\nPase incompleto\n");
                    completo=0;
                    yarda_actual = yarda_actual;
                    yarda_apasar = yarda_apasar;
                    oportunidad=oportunidad+1;
                    }
                    if ((finpase>=80)&&(finpase<87))
                    {
                    printf("\nINTERCEPTADO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual = 100-yarda_actual;
                    yarda_apasar = yarda_actual +10;
                    goto etiqueta4_pos1;
                    }
                    if ((finpase>=87)&&(finpase<94))
                    {
                    printf("\nSACK\n");
                    oportunidad=oportunidad+1;
                    yarda_actual=yarda_actual - 5;
                    }
                    if ((finpase>=94)&&(finpase<100))
                    {
                    printf("\nBALON SUELTO\n");
                    oportunidad=1;
                    posesion=1;
                    yarda_actual=100-yarda_actual;
                    yarda_apasar=yarda_actual +10;
                    goto etiqueta4_pos1;
                    }
                    if(yarda_actual>=100)
                    {
                        printf("\nTOUCHDOWN\n");
                        resultado_equipo2=resultado_equipo2+6;
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        patada=rand()%100;
                        if(patada<85){
                            printf("\nEl punto extra es bueno!\n");
                            resultado_equipo2=resultado_equipo2+1;
                        }
                        else{
                            printf("\nFalla el punto extra!\n");
                        }
                        oportunidad=1;
                        yarda_actual=25;
                        yarda_apasar=35;
                        posesion=1;
                        goto etiqueta4_pos1;
                    }
                }
                else
                {
                    printf("\nAcarreo\n");
                    gettimeofday(&t1, NULL);
                    srand(t1.tv_usec * t1.tv_sec);
                    finacarreo=rand()%100;

                    if(finacarreo<90)
                    {
                        printf("\nAcarreo exitoso\n");
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avan=rand()%100;
                        if(avan<10)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%8-7;
                        }
                        if((avan>=10)&&(avan<55))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6;    
                        }
                        if((avan>=55)&&(avan<85))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%6+5;
                        }
                        if((avan>=85)&&(avan<95))
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%21+10;    
                        }
                        if(avan>=95)
                        {
                        gettimeofday(&t1, NULL);
                        srand(t1.tv_usec * t1.tv_sec);
                        avanceac=rand()%71+30;    
                        }
                        if((yarda_actual+avanceac)>=yarda_apasar)
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=1;
                            yarda_actual=yarda_actual+avanceac;
                            yarda_apasar=yarda_actual+10;
                        }
                        else
                        {
                            printf("\nAcarreo de %d yardas\n",avanceac);
                            oportunidad=oportunidad+1;
                            yarda_actual=yarda_actual+avanceac;
                        }
                        if(yarda_actual>=100)
                        {
                            printf("\nTOUCHDOWN\n");
                            resultado_equipo2=resultado_equipo2+6;
                            gettimeofday(&t1, NULL);
                            srand(t1.tv_usec * t1.tv_sec);
                            patada=rand()%100;
                            if(patada<85)
                            {
                                printf("\nEl punto extra es bueno!\n");
                                resultado_equipo2=resultado_equipo2+1;
                            }
                            else
                            {
                                printf("\nFalla el punto extra!\n");
                            }
                            oportunidad=1;
                            yarda_actual=25;
                            yarda_apasar=35;
                            posesion=1;
                            goto etiqueta4_pos1;
                        }
                    }
                    else
                    {
                        printf("\nBALON SUELTO\n");
                        oportunidad=1;
                        posesion=1;
                        yarda_actual=100-yarda_actual;
                        yarda_apasar=yarda_actual +10;
                        goto etiqueta4_pos1;
                    }
                }
            }
        }
    etiqueta4_pos1:    
    Q4=Q4-30;
    }

printf("RESULTADO FINAL: %d - %d\n",resultado_equipo1,resultado_equipo2);
if(resultado_equipo1>resultado_equipo2)
{
    printf("Ganador: Equipo 1\n");
}
if(resultado_equipo2>resultado_equipo1)
{
    printf("Ganador: Equipo 2\n");
}
if(resultado_equipo1==resultado_equipo2)
{
    printf("Resultado: Empate\n");
}


    return 0;
}