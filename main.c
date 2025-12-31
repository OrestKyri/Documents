#include <stdio.h>
#include <string.h>
#include "structs.h"

int main(void)
{
  //Sti metavliti choice tha apothikevo tin epilogi tou xristi afou ton rotiso an thelei na kanei login i na bgei apo to programma 
  char choice[10];
  //Prospatho na apotrepso ta problimata me megala usernames arxikopoiontas to string me megethos 30
  char username[50];
  char password[8];

  //Orizo kathe thesi kratisis os keni
  for(int i = 0 ; i < 1500; i++)
  {
    trips[i].empty = 1;
  }

  while(true)
  {
    printf("---Arxiki Othoni---\n\n\n");
    printf("Ti tha thelate na kanete\n");
    printf("Login\n\n");
    printf("Exit \n\n");
    printf("?");
    scanf("%s",&choice);

    //Elegx an o user epilegei na kanei login kai prospatho na to kano case-insensitive
    if(!strcmp(choice,"Login") || !strcmp(choice,"login"))
    {
      printf("Eisagete to username sas :");
      scanf("%s",&username);
      printf("Eisagete ton kodiko sas :");
      scanf("%s",&password);

      //elegxw an to username kai o kwdikos einai auta tou admin, an nai metafero ton xristi sto admin dashboard allios sto client dashboard  
      if(!strcmp(username,"admin") && !strcmp(password,"admin123"))
      {
        adminDashboard(users);
        continue;
      }
      else 
      {
        int login = check_login(username,password,users);
        if(login == 0)
        {
          clientDashboard(username,Routes,trips,users);
          continue;
        }
        else
        {
          printf("Lathos username h lathos kodikos");
          continue;
        }
      }
    }

    //elegxw an epilexei na bgei apo to programam stin opioa periptwsi termatizw to programma
    else if(!strcmp(choice,"Exit"))
    {
      return 1;
    }

    //an den exei eisagei egkiri apantisi ton epistrefo stin arxiki othoni
    else{
      printf("Den eisagate egkiri epilogi \n\n\n");
      continue;
    }

  }

}
