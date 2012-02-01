
#include <stdio.h>
#include <stdlib.h>

enum states
{
  GREEN, YELLOW, RED, RED_AND_YELLOW
};

enum events
{
  TICK
};

int light1 = GREEN;
int light2 = RED;

void
lightcurve1(int event);
void
Do(int State);

//------------------------------

int tickcount;

int
main()
{
  lightcurve1(TICK);

  for (tickcount = 0; tickcount < 2; tickcount++)
    lightcurve1(TICK);

  return 0;
}

void
lightcurve1(int event)
{
  int NextState = light1;

  switch (light1)
    {
  case GREEN:
    switch (event)
      {
    case TICK:
      NextState = YELLOW;
      break;
      }
    break;

  case YELLOW:

    switch (event)
      {
    case TICK:
      NextState = RED;
      break;
      }
    case RED:

      switch (event)
        {
      case TICK:
        NextState = RED;
        break;
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

  Do(light1);
}

void
Do(int State)
{
  switch (State)
    {
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

