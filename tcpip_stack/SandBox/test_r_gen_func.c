#include <stdio.h>

// static unsigned int hash_code(void *ptr, unsigned int size)
// {
//   unsigned int value = 0, i = 0;
//   char *str = (char *)ptr;
  
//   while(i < size)
//   {
//     value += *str;
//     value *= 97;
//     str++;
//     i++;
//   }
//   return value;
// }

int main(void)
{
  // char *str = "Random";
  // unsigned int size = 28;
  
  printf("Testing Random Number Generator Function\n\n");
  for(int i = 0; i < 10; i++)
  {
    printf("%d", hash_code(str, size));
  }
  
  return(0);
}