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

void printPersonDetails(person_t *outPerson)
{
  printf("outperson->name = %s\n", outPerson->name);
  printf("outperson->age = %d\n", outPerson->age);
  printf("outperson->name = %d\n", outPerson->weight);
}

int main(int argc, char **argv)
{
  linked_list_t *personList = init_single_linked_list();
  // Register comparison function
  personList->comparison_fn = person_comparison_fn;
  
  person_t person1 = {"Dwight", 40, 200};
  person_t person2 = {"Jim", 37, 195};
  person_t person3 = {"Creed", 60, 185};
  
  linked_list_add_node_by_val(personList, &person1);
  linked_list_add_node_by_val(personList, &person2);
  linked_list_add_node_by_val(personList, &person3);
  
  person_t *outPerson = NULL;
  
  printf("\n\nSearching ->->-> ...\n");
  outPerson = (person_t *)linked_list_search_by_key(personList, "Dwight");
  
  printPersonDetails(outPerson);
  printf("\n\nLooping ->->-> ...\n");
  
  linked_list_node_t *listNode = NULL;
  // Using looping macro (still do not fully understand) to iterate
  ITERATE_LIST(personList, listNode)
  {
    outPerson = (person_t *)listNode->data;
    printPersonDetails(outPerson);
  }
  return(0);
}