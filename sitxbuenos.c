#include "sitxbuenos.h"

int sitxovr (int ovr)
{
	int a;
	gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
	if (ovr>=85)
    {
        a=rand()%6+2;
    }
    if((ovr>=70)&&(ovr<85))
    {
    	a=rand()%4+1;
    }
    if(ovr<70){
        a=rand()%2;
    }
	return a;
}
