#include <stdio.h>
#include <stdlib.h>

 void clean_string(char*);

void main()
{
  char a[] = " quEst4 e' 1 sTr1n#ga ";
  clean_string(a);
  printf("%s\n"  , a);
}

void clean_string(char *a ){
  int next_pos=0;
  int current_pos=0;
  while (a[current_pos] != '\0') {
    if ( a[current_pos] >= 'a' && a[current_pos] <= 'z' ){
      a[next_pos] = a[current_pos];
      next_pos++;
    } else if ( a[current_pos] >= 'A' && a[current_pos] <= 'Z' ){
      a[next_pos]= 'a' + a[current_pos] - 'A';
      next_pos++;
    }
    current_pos++;
  }
  a[next_pos] = '\0';
}
