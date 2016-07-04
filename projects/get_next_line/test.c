#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

void toto() 
{
 static int test = 10;

 test++;
printf ("%d\n", test);
}


int main()
{
  toto();
  toto();

  return 0;
}