#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clientDashboard(char usrname[50],Route trips[12],booked_trip booked[1500],Users list[30])
{
  int choice;
  while(1)
  {
    

    //Enimerono ton xristi gia to ti mporei na kanei
    printf("Ti tha thelate na kanete ?\n\n\n");
    printf("View Routes : 1\n");
    printf("Book Trip : 2\n");
    printf("Payment : 3\n");
    printf("Confirmed Trips : 4\n");
    printf("Logout : 5\n ");
    printf("?");
    scanf("%d",&choice);
    //ELegxw to input kai kalw tin analogi sinartisi
    if(choice == 1)
    {
      view_routes(trips);
      continue;
    }

    else if(choice == 2)
    {
      book_trip(booked,usrname, trips,users);
      continue;
    }

    else if(choice == 3)
    {
      for(int i = 0; i < 1500; i ++)
      {
        //elegxw an iparxei toulaxiston ena mi exoflimeno taxidi
        if(booked[i].payment == 0 && strcmp(booked[i].username,usrname) == 0)
        {
          payment(booked,usrname);
          break;
        }
        
      }
      continue;
    }

    else if(choice == 4)
    {

      char answer[5];
      printf("Pliktrologiste :\n");
      printf("HIGH gia na deite tis kratiseis kata auxousa seira imerominias kratisis \n");
      printf("LOW gia na deite tis kratiseis kata fthinousa seira imerominias kratisis \n");
      printf("?");
      scanf("%s",&answer);
      confirmed_trips(usrname,trips,answer);
      continue;
    }

    
    else if(choice == 5)
    {
      return; 
    }
    //An den balei enan apo tous 5 arithmous pou antistoixoun se kathe epilogi ton enimeronon kai tou xanazitao arithmo
    else{
      printf("Mi egkiri epilogi\n");
    }
  }
}

void view_routes(Route trips[12])
{
  // Ektipono tis steiles stis opoies tha ektipothoun oi plirofories kathe proorismou 
  printf("| Nisi/ Limani  | Kodikos | Kostos Thesis | Katastroma | Aeroporikou Typou | Kampina | Aytokinito |\n");
  //Ektipono pavles kai gia omorfia alla kai gia na xero peripou poso xoro prepei na pianei kathe string gia na einai efthigramismena 
  printf("|----------------|---------|--------------|------------|-------------------|---------|------------|\n");

  for (int i = 0; i < 9; i++) 
  {
    //emafnizo stin othoni tis plirofories kathe proorismou 
    printf("| %-15s | %-7s | %-12d | %-10d | %-17d | %-7d | %-10d |\n", 
    trips[i].port, trips[i].port_code, trips[i].deck_cost, trips[i].plane_cost, trips[i].boat_cost, trips[i].car_cost);
  }  
  return;
}


void book_trip(booked_trip booked[1500],char usrname[50],Route trips[12],Users list[30])
{
  //metavliti stin opoia tha apothikevetai o kodikos limaniou prin apothikeftei
  char desti[4];
  //metavliti stin opoia tha apothikevetai i epilogi thesis
  int seat;
  //metavliti stin opoia tha apothikevtai to sinoliko kostos tou taxidiou
  int cost;
  //metavliti stin opoia tha apothikevetai i epilogi taxidiou me amaksi
  int car;

  while(1)
  {
    Date date_go[11];
    Date return_date[11];
    printf("Pote tha thelate na taxidepsete : ");
    scanf("%d %d %d",date_go->dd,date_go->mm,date_go->yyyy);

    printf("Pou that helate na taxidepsete : ");
    scanf("%s",&desti);
    for(int i = 0 ; i < 1500; i++ )
    {
      if(strcmp(desti,trips[i].port_code) == 0);   
      {
        //Infinite loop etsi oste na rotaei sinexeia ton xristi mexri na parei egkiri apantisi
        while(1)
        {
          printf("Se ti thesi tha thelate na taxidepsete : ");
          printf("Aeriporikou Tipou : 1\n");
          printf("Kampina : 2\n");
          printf("Katastroma : 3 \n");
          printf("?");
          scanf("%d",&seat);
          if(seat == 1)
          {
            cost = trips[i].plane_cost;
            break;
          }
          else if(seat == 2)
          {
            cost = trips[i].plane_cost;
            break;
          }
          else if(seat == 3)
          {
            cost = trips[i].boat_cost;
            break;
          }
          else
          {
            printf("Mi egkiri epilogi\n\n");
          }
        }
        //Infinite loop gia na rotaei sinexeia ton xristi mexri na dosei egkiri apantisi 
        while(1)
        {
          printf("Epithimite na taxidepsete me autokinito :\n");
          printf("Nai : 1\n");
          printf("Oxi : 2\n");
          scanf("%i",&car);
          if(car == 1)
          {
            cost += trips[i].car_cost;
            break;
          }
          else if(car == 2)
          {
            break;
          }
          else
          {
            printf("Mi egkiri epilogi \n");  
          }
        }

        //I metavliti retour tha pairnei h 0 h 1 an to taxidi einai monis diadromis h met'epistrofis antistoixa
        int retour;
        while(1)
        {
          int epistrofi;
          printf("Epithimite to taxidi sas na einai monis diadromis h met'epistrofis");
          printf("Monis diadromis : 1\n");
          printf("Met'epistrofis : 2\n ");
          scanf("%d",epistrofi);

          if(epistrofi == 1)
          {
            retour = 0;
            break;
          }
          else if(epistrofi == 2)
          {
            //An epilexei na taxidepsei me'epstroifi prostheto to kostos tou ela sto kostos tou pigaine, ta opioa theoro pos eina isa
            cost += cost;
            retour = 1;
            printf("Pote tha thelate na epistrepsete : ");
            scanf("%d %d %d",&return_date->dd, &return_date->mm, &return_date->yyyy);
            break;
            
          }
          else
          {
            printf("Mi egkiri epilogi \n");
          }
        }
        
        //elegxw an o user einai foititis kai analoga diamorfono to kostos
        for(int i = 0 ; i < 30; i ++)
        {
          if(strcmp(usrname,list[i].username) == 0)
          {
            if(list[i].uni_student == 1)
            {
              cost /= 2;
            }
            else
            {
              continue;
            }
          }
          else
          {
            continue;
          }
        }
        //dimiourgo to monadiko anagnoristiko taxidiou
        char travelID[100];
        generate_travel_ID(date_go,usrname,desti,travelID);

        //ta apothikevo ola ston pinaka booked se opoia thesi einai keni
        for(int i = 0; i < 1500; i++)
        {
          if(booked[i].empty == 1)
          {
            //apothikevo sta antistoixa meri tou struct Booked_trip kai orizo to payment = 0 ( diladi oti den exei plirothei) kai to empty = 0(diladi i thesi einia piasmeni) 
           
            strcpy(booked[i].username,usrname);               
            strcpy(booked[i].unique_string,travelID);
            booked[i].total_cost = cost;

            //Pernao tin imeronia anaxorisis sti kratisi
            booked[i].date_go->dd = date_go->dd;
            booked[i].date_go->mm = date_go->mm;
            booked[i].date_go->yyyy = date_go->yyyy;
            
            //Pernao tin imeronia epistrofis sti kratisi(an den iparxei tha midenistei)
            booked[i].date_return->dd = return_date->dd;
            booked[i].date_return->mm = return_date->mm;
            booked[i].date_return->yyyy = return_date->yyyy;

            booked[i].trip_type = retour;
            booked[i].payment = 0;  
            booked[i].empty = 0;  
            break;
          }
        }

        break;

      }
    }

  }

}


int check_login(char usrname[50],char pword[8],Users user[30])
{
  for(int i = 0; i < 30; i++)
  {
    if(strcmp(usrname,user[i].username) == 0 && strcmp(pword,user[i].password) == 0)
    {
      return 0;
    }
  }

  return 1;

}



void generate_travel_ID(Date date_go,char usrname[50],char destination[4],char *travelID)
{
  for(int i = 0 ; i < 2 ; i++)
  {
  sprintf(travelID, "%02d%02d%d%s-%s",date_go.dd,date_go.mm,date_go.yyyy,destination,usrname);
  return;
  }
}


void payment(booked_trip booked[1500],char usrname[50])
{
  //elegxw oles tis kratiseis tou xristi 
  for(int i = 0 ; i < 1500 ; )
  {
    if(strcmp(booked[i].username,usrname) == 0)
    {
      //elegxw an i kratisi den exei plirothei
      if(booked[i].payment == 0)
      {
        //an den exei plirothei ektipono tis plirofories tis kratisis
        printf("Plirofories taxidiou : Monadiko anagnoristiko taxidiou : %s \n Sinoliko kostos : %d \n Imerominia anaxorisis : %s \n",booked[i].unique_string,booked[i].total_cost,booked[i].date_go);
        //an to taxidi exei kai epistrofi ektipono tin imerominia epistrofis 
        if(booked[i].trip_type == 1)
        {
          printf("Imerominia epistrofis : %s\n",booked[i].date_return);
        }

      }
    }
  }

  char tripID[100];
  printf("An thelete na plirosete mia kratisi plhktrologiste to Monadiko Anagnoristiko Taxidiou tis kratisis sas \n");
  printf("?");
  scanf("%s",&tripID);

  //elegxw an to monadiko anagnoristiko taxidiou einai sosto kai analoga theto tin kratisi pliromeni h na einai pliromeni ektipono to analogo minima
  for(int j = 0 ; j < 1500 ; j++)
  {
    if(strcmp( booked[j].username, usrname) == 0 && strcmp( booked[j].unique_string, tripID) == 0 && booked[j].payment == 0)
    {
      booked[j].payment = 1;
      return;
      
    }
    else if(strcmp(booked[j].username,usrname) == 0 && strcmp(booked[j].unique_string,tripID) == 0 && booked[j].payment == 0)
    {
      printf("To sigkekrimeno taxidi exei idi exoflithei\n\n\n");
      return;
    }
  }
  printf("To Monadiko Anagnoristiko Taxidiou einai lathos\n\n\n");
  return;

}


booked_trip compare_trip(booked_trip a,booked_trip b)
{
  //Sigkrino arxika tin xronia, meta ton mina kai telos thn imera tis kratisis kathe taxidiou kai analoga epistrefo to taxidi pou exei kratithei teleftaio
  if(a.date_go->yyyy > b.date_go->yyyy)
  {
    return a;
  }
  else if(a.date_go->mm > b.date_go->mm)
  {
    return a;
  }
  else if(a.date_go->dd > b.date_go->dd)
  {
    return a;
  }
  else{
    return b;
  }

}



void confirmed_trips(char usrname[50],booked_trip trips[1500],char ans[5])
{
  booked_trip userTrips[30];

  for(int i = 0; i < 1500; i++)
  {
    //elegxw poia taxidia tou xristi einai pliromena 
    if(strcmp(usrname,trips[i].username) == 0 && trips[i].payment == 1)
    {
      strcpy(userTrips[i].username,trips[i].username);
      strcpy(userTrips[i].unique_string,trips[i].unique_string);
      userTrips[i].total_cost = trips[i].total_cost;

      userTrips[i].date_go->dd = trips[i].date_go->dd;
      userTrips[i].date_go->mm = trips[i].date_go->mm;
      userTrips[i].date_go->yyyy = trips[i].date_go->yyyy;

      userTrips[i].date_return->dd = trips[i].date_return->dd;
      userTrips[i].date_return->mm = trips[i].date_return->mm;
      userTrips[i].date_return->yyyy = trips[i].date_return->yyyy;

      userTrips[i].trip_type = trips[i].trip_type;

    }
  }

  //Kano sort ton pinaka userTrips kata auxousa seira
  for(int i = 0; i < 30; i ++)
  {
    for(int j = 0 ; j < 30 ; j++)
    {
      userTrips[j] = compare_trip(userTrips[j],userTrips[j+1]);
    }
  }

  //An o xristis pliktrologisei "HIGH" ektipono ti lista me tis kratiseis tou opos einai  
  if(strcmp(ans,"HIGH") == 0)
  {
    for(int i = 0; i < 30 ; i++)
    {
      printf("Monadiko Anagnoristiko Taxidiou : %s \n ",userTrips[i].unique_string);
      printf("Sinoliko Kostos : %d \n",userTrips[i].total_cost);
      printf("Imerominia Anaxorisis : %02s/%02s/%s",userTrips[i].date_go->dd,userTrips[i].date_go->mm,userTrips[i].date_go->yyyy);
      if(userTrips[i].trip_type == 1)
      {
        printf("Imerominia epistrofis %02s/%02s/%s",userTrips[i].date_return->dd,userTrips[i].date_return->mm,userTrips[i].date_return->yyyy);
      }
    }
  }
  //An o xristis pliktrologisei "LOW" ektipono ti lista anapoda etsi oste na oi kratiseis na einai kata fthinousa seira 
  else if(strcmp(ans,"LOW") == 0)
  {
    for(int j = 30 ; j > 0 ; j--)
    {
      printf("Monadiko Anagnoristiko Taxidiou : %s \n ",userTrips[j].unique_string);
      printf("Sinoliko Kostos : %d \n",userTrips[j].total_cost);
      printf("Imerominia Anaxorisis : %02s/%02s/%s",userTrips[j].date_go->dd,userTrips[j].date_go->mm,userTrips[j].date_go->yyyy);
      if(userTrips[j].trip_type == 1)
      {
        printf("Imerominia epistrofis %02s/%02s/%s",userTrips[j].date_return->dd,userTrips[j].date_return->mm,userTrips[j].date_return->yyyy);
      }
    }
  }

}






