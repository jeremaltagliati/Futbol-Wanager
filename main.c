#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "sitxbuenos.h"
//#include <tiroslibres.h>

struct timeval t1;
time_t t;
char e1[25];
char e2[25];
int situaciones1=0,situaciones2=0;
int claras1=0,claras2=0;
int chancegol;
int goles1=0, goles2=0;
int ovreq1 [11] = {88,79,85,84,79,88,88,84,83,88,82}; //Francia
char neq1 [12][20] = {"Lloris","Pavard","Umtiti","Varane","Hernandez","Kante","Pogba","Matuidi","Griezmann","Mbappe","Giroud","Francia"};
//int ovreq2 [11] = {81,81,79,80,78,87,84,78,81,82,80}; //Croacia
//char neq2 [12][20] = {"Subasic","Vrsaljko","Lovren","Vida","Strnic","Brozovic","Rakitic","Modric","Perisic","Rebic","Mandzukic","Croacia"};
int ovreq2[11] = {69,65,67,61,62,69,65,63,63,61,70}; //Olimpo de Bahia Blanca
char neq2[12][20] = {"Carranza","Villanueva","Ojeda","Ramirez","Pantaleone","Bellocq","Villarruel","Vidal","Fornari","Troyanski","Depetris","Olimpo"};
int ovr1=0,ovr2=0;
int defensores1,medio1,delanteros1;
int defensores2,medio2,delanteros2;
int ovrdef1=0;
int ovrdef2=0;
int ovrmed1=0;
int ovrmed2=0;
int ovrdel1=0;
int ovrdel2=0;
int difovr;
int difdef2del1;
int difdef1del2;
int difmed;
int i,j,a,b;
int d = 0;
int pateador;
int vl=0;
int vv=0;
int emp=0;
char formacion;

void sitxbuenos (){
    situaciones1+=sitxovr(ovr1);
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    a=rand()%100;
    Sleep(a);
    situaciones2+=sitxovr(ovr2);
    printf("Situaciones creadas porque los del %s son moi buenos(OVR:%d): %d\n",neq1+11,ovr1,situaciones1);
    printf("Situaciones creadas porque los del %s son moi buenos(OVR:%d): %d\n",neq2+11,ovr2,situaciones2);
}

void promedioOvr(){
    for(i=0;i<11;i++)
    {
        ovr1=ovr1+ovreq1[i];
        ovr2=ovr2+ovreq2[i];
    }
    ovr1/=11;
    ovr2/=11;
}

int random(){
    Sleep(d);
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    d=rand()%250+13;
    return d;
}
void volvertodoacero (){
    situaciones1=0;
    situaciones2=0;
    claras1=0;
    claras2=0;
    goles1=0;
    goles2=0;
}
void selformacion (){

}
int main()
{
    // printf("Escriba el nombre del equipo local: ");
    // fgets(e1,sizeof(e1),stdin);
    // strtok(e1,"\n"); //Borra el \n del string.
    // printf("\nEscriba el nombre del equipo visitante: ");
    // fgets(e2,sizeof(e2),stdin);
    // strtok(e2,"\n"); //Borra el \n del string.

    printf("Seleccione la formacion de %s\n",neq1+11);
    printf("1_ 3-4-3\n");
    printf("2_ 3-5-2\n");
    printf("3_ 4-4-2\n");
    printf("4_ 4-3-3\n");
    printf("5_ 4-5-1\n");
    printf("6_ 5-4-1\n");
    printf("7_ 5-3-2\n");
    formacion=getchar();
    fflush(stdin);
    
    switch(formacion){
        case'1':{
            defensores1=3;
            medio1=4;
            delanteros1=3;
            break;
        }
        case'2':{
            defensores1=3;
            medio1=5;
            delanteros1=2;
            break;
        }
        case'3':{
            defensores1=4;
            medio1=4;
            delanteros1=2;
            break;
        }
        case '4':{
            defensores1=4;
            medio1=3;
            delanteros1=3;
            break;
        }
        case '5':{
            defensores1=4;
            medio1=5;
            delanteros1=1;
            break;
        }
        case '6':{
            defensores1=5;
            medio1=4;
            delanteros1=1;
            break;
        }
        case '7':{
            defensores1=5;
            medio1=3;
            delanteros1=2;
            break;
        }
    }
    printf("Seleccione la formacion de %s\n",neq2+11);
    printf("1_ 3-4-3\n");
    printf("2_ 3-5-2\n");
    printf("3_ 4-4-2\n");
    printf("4_ 4-3-3\n");
    printf("5_ 4-5-1\n");
    printf("6_ 5-4-1\n");
    printf("7_ 5-3-2\n");
    formacion=getchar();
    fflush(stdin);
    
    switch(formacion){
        case'1':{
            defensores2=3;
            medio2=4;
            delanteros2=3;
            break;
        }
        case'2':{
            defensores2=3;
            medio2=5;
            delanteros2=2;
            break;
        }
        case'3':{
            defensores2=4;
            medio2=4;
            delanteros2=2;
            break;
        }
        case '4':{
            defensores2=4;
            medio2=3;
            delanteros2=3;
            break;
        }
        case '5':{
            defensores2=4;
            medio2=5;
            delanteros2=1;
            break;
        }
        case '6':{
            defensores2=5;
            medio2=4;
            delanteros2=1;
            break;
        }
        case '7':{
            defensores2=5;
            medio2=3;
            delanteros2=2;
            break;
        }
    }
    printf("%s sale con un %d-%d-%d\n",neq1+11,defensores1,medio1,delanteros1);
    printf("%s sale con un %d-%d-%d\n",neq2+11,defensores2,medio2,delanteros2);
    promedioOvr();
    sitxbuenos();

    for(i=1;i<=defensores1;i++)
    {
        ovrdef1=ovrdef1 + ovreq1[i];
    }
    ovrdef1=ovrdef1/defensores1;
    //printf("OVR Defensores de %s:%d\n",neq1+11,ovrdef1);

    for(i=1;i<=defensores2;i++)
    {
        ovrdef2=ovrdef2 + ovreq2[i];
    }
    ovrdef2=ovrdef2/defensores2;
    //printf("OVR Defensores de %s:%d\n",neq2+11,ovrdef2);

    for(i=defensores1+1;i<=defensores1+medio1;i++)
    {
        ovrmed1=ovrmed1 + ovreq1[i];
    }
    ovrmed1=ovrmed1/medio1;
    //printf("OVR Mediocampistas de %s:%d\n",neq1+11,ovrmed1);

    for(i=defensores2+1;i<=defensores2+medio2;i++)
    {
        ovrmed2=ovrmed2 + ovreq2[i];
    }
    ovrmed2=ovrmed2/medio2;
    //printf("OVR Mediocampistas de %s:%d\n",neq2+11,ovrmed2);

    for(i=defensores1+medio1+1;i<=defensores1+medio1+delanteros1;i++)
    {
        ovrdel1=ovrdel1 + ovreq1[i];
    }
    ovrdel1=ovrdel1/delanteros1;
    //printf("OVR Delanteros de %s:%d\n",neq1+11,ovrdel1);    

    for(i=defensores2+medio2+1;i<=defensores2+medio2+delanteros2;i++)
    {
        ovrdel2=ovrdel2 + ovreq2[i];
    }
    ovrdel2=ovrdel2/delanteros2;
    //printf("OVR Delanteros de %s:%d\n",neq2+11,ovrdel2);
    getchar();
    difovr=ovr1-ovr2;
    difmed=ovrmed1-ovrmed2;
    difdef1del2=ovrdef1-ovrdel2;
    difdef2del1=ovrdel1-ovrdef2;
    printf("\nDiferencia de overall: %d\n",difovr);
    printf("Diferencia de mediocampo: %d\n",difmed);
    printf("Diferencia delanteros (%s) y defensores (%s): %d\n", e2, e1, difdef1del2);
    printf("Diferencia delanteros (%s) y defensores (%s): %d\n", e1, e2,difdef2del1);

    //////////////////////////////////////////////////////////LOOP RESULTADOS////////////////////////////////////////////////////
    for(j=0; j<30; j++){
    a=random();
    b=random();

    if(abs(difovr)<=5 && abs(difovr)>2){
        a%=3;
        b%=3;
    }
    if(abs(difovr)<=2){
        a%=5;
        b=a;
    }
    if((difovr<-5)&&(difovr>=-15)){
        a%=3;
        b= b%6 + 2;
    }
    if((difovr>5)&&(difovr<=15)){
        a = a%6 + 2;
        b%=3;
    }
    if(difovr<=-15){
        a%=2;
        b = b%8 + 3;
    }
    if(difovr>=15){
        a = a%8 + 3;
        b%=2;
    }

    situaciones1=situaciones1+a;
    situaciones2=situaciones2+b;

    printf("Situaciones acumuladas por diferencia de overall %s: %d\n",e1,a);
    printf("Situaciones acumuladas por diferencia de overall %s: %d\n",e2,b);

    a=random();
    b=random();

    if((difmed>=-5)&&(difmed<=5)){
        a%=2;
        b%=2;
    }
    if((difmed<-5)&&(difmed>=-10)){
        a%=2;
        b%=3;
    }
    if((difmed>5)&&(difmed<=10)){
        a%=3;
        b%=2;
    }
    if(difmed<=-10){
        a=0;
        b = b%3 + 1;
    }
    if(difmed>=10){
        a = a%3 + 1;
        b=0;
    }

    situaciones1=situaciones1+a;
    situaciones2=situaciones2+b;
    printf("Situaciones generadas por mediocampo de %s: %d\n",e1,a);
    printf("Situaciones generadas por mediocampo de %s: %d\n",e2,b);


    //printf("Situaciones acumuladas %s: %d\n",e1,situaciones1);
    //printf("Situaciones acumuladas %s: %d\n",e2,situaciones2);
    if(situaciones1 > 0)
        claras1=random()%situaciones1;
    printf("Situaciones claras del %s: %d\n",e1,claras1);
    if(situaciones2 > 0)
        claras2=random()%situaciones2;
    printf("Situaciones claras del %s: %d\n",e2,claras2);
    situaciones1=situaciones1-claras1;
    situaciones2=situaciones2-claras2;
    printf("Situaciones poco claras del %s: %d\n",e1,situaciones1);
    printf("Situaciones poco claras del %s: %d\n",e2,situaciones2);
    getchar();


    for(i=0;i<situaciones1;i++)
    {
        pateador=random()%5+6;
        chancegol=random()%100 - (int) ovreq1[pateador]*0.2;
        //printf("Chance gol equipo 1 (%s): %d\n", neq1+pateador, chancegol);
        if(chancegol<100-ovreq2[0]){
            goles1++;
            printf("GOOOOOOOOOL! Para %s lo hizo %s.\n", neq1+11, neq1+pateador);
        }
        else{
            printf("Oportunidad desperdiciada por %s.\n",neq1+pateador);
        }
    }

    for(i=0;i<claras1;i++)
    {   
        pateador=random()%5+6;
        chancegol=random()%100 - (int) ovreq1[pateador]*0.25;
        //printf("Chance gol clara equipo 1 (%s): %d\n", neq1+pateador, chancegol);
        if(chancegol<125-ovreq2[0]){
            goles1++;
            printf("GOOOOOOOOOL! Para %s lo hizo %s.\n", neq1+11, neq1+pateador);
        }
        else{
            printf("Atajo %s.\n",neq2);
        }
    }

    for(i=0;i<situaciones2;i++)
    {   
        pateador=random()%5+6;
        chancegol=random()%100 - (int) ovreq1[pateador]*0.2;
        //printf("Chance gol equipo 2 (%s): %d\n", neq2+pateador, chancegol);
        if(chancegol<100-ovreq1[0]){
            goles2++;
            printf("GOOOOOOOOOL! Para %s lo hizo %s.\n", neq2+11, neq2+pateador);
        }
        else{
            printf("Oportunidad desperdiciada por %s.\n",neq2+pateador);
        }

    }

    for(i=0;i<claras2;i++)
    {   
        pateador=random()%5+6;
        chancegol=random()%100 - (int) ovreq1[pateador]*0.25;
        //printf("Chance gol clara equipo 2 (%s): %d\n", neq2+pateador, chancegol);
        if(chancegol<125-ovreq1[0]){
            goles2++;
            printf("GOOOOOOOOOL! Para %s lo hizo %s.\n", neq2+11, neq2+pateador);
        }
        else{
            printf("Atajo %s.\n",neq1);
        }
    }

    printf("RESULTADO FINAL: %s %d - %d %s\n\n\n", neq1+11,goles1,goles2,neq2+11);
    if(goles1==goles2)
        emp++;
    if(goles1>goles2)
        vl++;
    if(goles2>goles1)
        vv++;
    volvertodoacero();
    }
    printf("%s gano %d partidos.\n",neq1+11,vl);
    printf("%s gano %d partidos.\n",neq2+11,vv);
    printf("Empataron %d partidos.\n",emp);
    return 0;
}
