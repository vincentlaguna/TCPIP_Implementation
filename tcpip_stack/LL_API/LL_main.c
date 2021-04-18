#include <stdio.h>
#include <stdlib.h>
#include "LL_API.h"
#include <string.h>

typedef struct person_
{
  char name[32];
  int  age;
  int  weight;
} person_t;

int person_comparison_fn(void *pStruct, void *key)
{
  person_t *person = (person_t *)pStruct;
  if (strncmp(person->name, (char *)key, strlen((char *)key)) == 0 &&
      strlen((char *)key) == strlen(person->name))
    return 1; // We found a match
  return 0; // We did not find a match
}

void print_person_details(person_t *outperson)
{
  printf("outperson->name = %s\n", outperson->name);
  printf("outperson->age = %d\n", outperson->age);
  printf("outperson->name = %d\n", outperson->weight);
}