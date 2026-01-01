#include <stdio.h>
#include <string.h>
#include "structs.h"

int main(void)
{
  //arxikopoio enan pinaka me olous tous xristous pou mporei na ypostirixei to sistima 
  Users users[30];
  strcpy(users[0].name, "Orestis");
  strcpy(users[0].surname, "Kyriakidis");
  users[0].age = 19;
  users[0].card_num = 1111;
  users[0].uni_student = 1;
  strcpy(users[0].username , "orestkyri");
  strcpy(users[0].password , "pass");
  users[0].empty = 0;


  for(int i = 0 ; i < 30 ; i ++)
  {
    users[i].empty = 1;
  }

  //Orizo ton pinaka kai arxikopoio tis times tou me tis plirofories kathe dromologiou
  Route Routes[12] ={ 
      {"Rodos", "RHO", 80, 100, 140, 100},
      {"Kalymnos", "KAL", 60, 80, 120, 100},
      {"Patmos", "PAT", 55, 75, 115, 100},
      {"Astypalaia", "AST", 50, 70, 110, 100},
      {"Kasos", "KAS", 65, 85, 125, 100},
      {"Kasterlorizo", "KAS", 100, 120, 160, 120},
      {"Leros", "LER", 60, 80, 120, 100},
      {"Karpathos", "KAR", 70, 90, 130, 100},
      {"Symi", "SYM", 80, 100, 140, 120},
      {"Xalki", "XAL", 80, 100, 140, 120},
      {"Tilos","TIL", 75, 95, 135, 100},
      {"Pserimos", "PSE", 60, 80, 120, 100}
  };


  //Lista stin opoia apothikevontai ola ta taxidia pou mporoun na apothikeftoun sti platforma 30 xristes * 50 taxidia o kathenas
  booked_trip trips[1500];


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

  //Orizo kathe thesi kratisis os mi pliromeni
  for(int i = 0 ; i < 1500; i++)
  {
    trips[i].payment = 0;
  }


  while(1)
  {
    printf("---Arxiki Othoni---\n\n\n");
    printf("Ti tha thelate na kanete\n");
    printf("Login\n\n");
    printf("Exit \n\n");
    printf("?");
    scanf("%s",choice);

    //Elegx an o user epilegei na kanei login kai prospatho na to kano case-insensitive
    if(!strcmp(choice,"Login") || !strcmp(choice,"login"))
    {
      printf("Eisagete to username sas :");
      scanf("%s",username);
      printf("Eisagete ton kodiko sas :");
      scanf("%s",password);

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
