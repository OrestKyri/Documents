#include "structs.h"
#include <string.h>
#include<stdio.h>
#include <stdlib.h>

void adminDashboard(Users list[30])
{
  while(1)
  {
    //Rotao ton admin ti thelei na kanei 
    int choice;
    printf("Ti that thelete na kanete : \n\n\n");
    printf("Register Client : 1\n");
    printf("Change client password : 2\n");
    printf("Epistrofi stin arxiki othoni : 3\n");
    printf("? ");
    scanf("%d",&choice);
    //An epileksei 1 kalo ti sinartisi create_new_client gia na diomiourgisei neo xristi
    if(choice == 1)
    {
      create_new_client(list);
    }
    //An epileksei 2 kalo ti sinartisi changePword gia na allaksei ton kodiko tou xristi pou thelei 
    else if(choice == 2)
    {
      changePword(list);
    }
    //An epileksei 3 bgaino apo to adminDashboard kai epistreofo sthn arxiki othoni
    else if(choice == 3)
    {
      return ;
    }
    //An den dwsei sosti apantisi ton enimerono kai ton xanarotao ti thelei na kanei
    else
    {
      printf("Mi dekti epilogi\n\n\n");
    }

  }

}



void create_new_client(Users list[30])
{
 int choice = 0;
 for(int i = 0; i < 30; i++) 
 {
    //rotao ton admin mexi na dosei sosti apantisi an thelei na dilosei neo user h na epistrepsei sto admin dashboard 
    while(1)
    {

      printf("Dilosi neou user : 1\n");
      printf("Epistrofi sto admin dashboard : 0\n");
      printf("?");
      scanf("%d ",&choice);
      if(choice == 1)
      {
        break;
      }
      else if(choice == 0)
      {
        return ;
      }
      else
      {
        printf("Mi egkiri apantisi\n");
      }

    }
    //elegxo an i thesi stin opoia paw na valo ton user einai keni h piasmni
    if(list[i].empty != 0)
    {
      continue;
    }
    //dilono ta stoixeia tou neou user
    else 
    {
      //orizo metavlites stis opoies tha apothikevo prosorina to onoma,eitheto,username,kodiko prin ta anigrapso sto struct
      char name[50];
      char surname[50];
      char username[50];
      char password[8];

      printf("Neos pelatis :\n\n\n");
      printf("Onoma : ");
      scanf("%s",name);
      strcpy(list[i].name,name); 
      printf("Epitheto : ");
      scanf("%s",surname);
      strcpy(list[i].surname,surname);
      printf("Ilikia : ");
      scanf("%d",list[i].age);
      printf("Arithmos trapezikis kartas : ");
      scanf("%d",list[i].card_num);
      printf("Foititis :");
      scanf("%d",list[i].uni_student);
      printf("Username :");
      scanf("%s",username);
      strcpy(list[i].username,username);
      printf("Kodikos : ");
      scanf("%s",password);
      strcpy(list[i].password,password);
      //orizo thn thesi [i] sth lista list os piasmeni
      list[i].empty = 1;
    }
 }
 return;

}



void changePword(Users list[30])
{
  //prosorini thesi stin opoia tha apothikevo ta passwords prin ta antigrapso sti lista
  char username[50];
  char password[8];
  while(1)
  {

    //Zitao username kai  leo ston admin ti prepei na kanei an thelei na epistrepsei sto Admin Dashboard 
    printf("Sti periptosi pou thelete na epistrepsete sto Admin Dashboard patiste 0");
    printf("Dwste username :");
    scanf("%s",username);
    for(int i = 0; i <30; i ++)
    {
      //elegxo an to username pou dothike yparxei
      if(strcmp(username,list[i].username) == 0)
      {
        printf("Enter new password :");
        scanf("%s",password);
        //anigrafo to neo password sti lista
        strcpy(list[i].password,password);
        return;
      }
      else if(strcmp(username,"0") == 0) 
      { 
        return; 
      }

      else
      {
      continue;
      }
    }
    //an den brethei to username sti lista enimerono ton admin kai xanarotao ek neou na dwsei username
    printf("To username pou eisagate den einai sosto\n\n\n");

  }
}






