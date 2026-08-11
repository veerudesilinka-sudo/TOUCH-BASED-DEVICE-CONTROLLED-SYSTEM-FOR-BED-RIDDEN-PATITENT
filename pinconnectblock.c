#include<LPC21XX.h>
void cfgportpinfunc(int portno,int pinno,int fn)
{
if(portno==0)
{
if(pinno<16)
{
PINSEL0=(((PINSEL0&~(3<<(pinno*2))))|(fn<<(pinno*2)));
}
else
{
PINSEL1=(((PINSEL1&~(3<<((pinno-16)*2))))|(fn<<((pinno-16)*2)));
}
}
else
{
}
}


