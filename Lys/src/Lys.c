

#include <stdio.h>
#include <stdlib.h>


enum states { GREEN, YELLOW, RED, RED_AND_YELLOW };

enum events { TICK };

int light1 = GREEN;
int light2 = RED;

void lightcurve1(int event);
void Do( int State );

//------------------------------

int tickcount=0;

int main()
{
    lightcurve1(TICK);


    //int i;
    //for(i=0;i<2;i++) lightcurve1( TICK );

    return 0;
}



void lightcurve1( int event )
{
    int NextState = light1;

    switch( light1 )
    {
        case GREEN:
            switch (event )
            {
                    NextState = YELLOW;
            }
            break;
            default:
            break;
            // The program should never get here !
    }

    if (NextState != light1)
     {
        light1 = NextState;
    }

    Do( light1 );
}



void Do( int State)
{
    switch (State) {
        case GREEN:
            printf("The light is green\n");
            break;
        case YELLOW:
            printf("The light is yellow.\n");
            break;
        case RED:
            printf("The light is red\n");
            break;
        case RED_AND_YELLOW:
            printf("The light is red and yellow\n");
            break;
    }
}

