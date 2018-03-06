
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "llist.h"

node_e *makeList(){ //generates the list
  node_e *employees = (node_e*) malloc(sizeof(node_e));
  employees->next = NULL;
  return employees;
} 

node_e* addName(char *str, node_e* head){ //adds a name to the list 
  node_e* new = (node_e*) malloc(sizeof(node_e));
  new->name = strdup(str); 
  new->next = head;
} 

void printList(node_e* head){
  if((head == NULL)||(head->name == NULL)){
    printf("End of list.");
    return;
  }
    printf("%s \n", head->name);
    printList(head->next);
}

node_e* removeName(char *name, node_e*head){//removes a name, NOTE: It is case sensitive
  if((head == NULL) || (head->name ==NULL)){
    printf("No names found in the list. \n");
    return head;
  }
  if(strcmp(head->name,name) == 0){
    return head->next;
  }
  node_e* temp =(node_e*) malloc(sizeof(node_e));
  temp = head;
  temp->next = removeName(name, head->next);
  return temp;
}

node_e* readFile(char *fileName,node_e* head){ //adds names based on a file, NOTE: case sensitive and must end with .txt for it to work, file must also be on the same directory
  FILE *employees;
  char employee[99][99];
  int i = 0;
  employees = fopen(fileName, "r");
  if (employees ==NULL){
  printf("File not found.");
  return head;
  }
  while(!feof(employees)){
   *fgets(employee[i],99,employees);
    head = addName(employee[i], head);
    i++;
  }
  return head;
}
int userOptions(){ // used to create the menu as a whole
  int num;
  printf("1.Add a new name. \n");
  printf("2.Remove a name. \n");
  printf("3.List names. \n");
  printf("4.Read names from file. \n");
  printf("5.Quit. \n");
  scanf("%d", &num);
  return num;
}

int main(){
  int opt;
  char *str = malloc(sizeof(char)*50);
  node_e* head = makeList();
  
  printf("Welcome, please select an option. \n");
  opt = userOptions();
  printf("\n");
  while(opt != 5){
    if(opt == 1){
      printf("Please type the name \n");
      scanf("%s", str);
      head = addName(str,head);
      printf("\n");
      printf("Select next option \n");
      opt = userOptions();
    }
  
    if(opt == 2){
      printf("Please type the name to delete. \n");
      scanf("%s", str);
      head = removeName(str, head);
      printf("\n");
      printf("Select next option \n");
      opt = userOptions();
    }
    
    if(opt == 3){
      printf("Listing names \n");
      printList(head);
      printf("\n");
      printf("\n");
      printf("Select next option \n");
      opt = userOptions();
    }
    
    if(opt == 4){
      printf("Please type filename. \n");
      scanf("%s", str);
      head = readFile(str, head);     
      printf("\n");
      printf("Select next option \n");
      opt = userOptions();
    }
    if((opt != 1)&&(opt != 2)&&(opt != 3)&&(opt != 4)&&(opt != 5)){
      printf("Invalid,input please try again. \n");
      opt = userOptions();
    }

  }
  if(opt == 5){
    printf("Goodbye. \n");
  }
}
