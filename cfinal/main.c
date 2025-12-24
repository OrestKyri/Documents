#include <stdio.h>
#include <string.h>

int main(void)
{
  char choice[10];
  //Kai pali prospatho na apotrepso ta problimata me megala usernames arxikopoiontas to string me megethos 30
  char username[30];
  char password[8];
  while(true)
  {
    printf("---Arxiki Othoni---\n\n\n");
    printf("Login\n\n");
    printf("Exit \n\n");
    printf("Epilexte mia apo tis dio epiloges :");
    scanf("%s",&choice);

    //Elegx an o user epilegei na kanei login
    if(!strcmp(choice,"Login"))
    {
      printf("Eisagete to username sas :");
      scanf("%s",&username);
      printf("Eisagete ton kodiko sas :");
      scanf("%s",&password);

      //elegxw an to username kai o kwdikos einai auta tou admin, an nai metafero ton xristi sto admin dashboard allios sto client dashboard  
      if(!strcmp(username,"admin") && !strcmp(password,"admin123"))
      {
        adminDashboard();
        continue;
        
      }
      else 
      {
        clientDashboard();
        continue;
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
