#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clientDashboard(char usrname[50],Route trip[12],booked_trip booked[1500],Users list[30])
{
  int choice;
  while(1)
  {
    

    //Enimerono ton xristi gia to ti mporei na kanei
    printf("Ti tha thelate na kanete ? (epilegete arithmo)\n\n\n");
    printf("View Routes : 1\n");
    printf("Book Trip : 2\n");
    printf("Payment : 3\n");
    printf("Confirmed trip : 4\n");
    printf("Logout : 5\n ");
    printf("?");
    scanf("%d",&choice);
    printf("\n\n");

    //ELegxw to input kai kalw tin analogi sinartisi
    if(choice == 1)
    {
      view_routes(trip);
    }

    else if(choice == 2)
    {
      book_trip(booked,usrname, trip, list);
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
    }

    else if(choice == 4)
    {

      char answer[5];
      printf("Pliktrologiste :\n");
      printf("HIGH gia na deite tis kratiseis kata auxousa seira imerominias kratisis \n");
      printf("LOW gia na deite tis kratiseis kata fthinousa seira imerominias kratisis \n");
      printf("?");
      scanf("%s",answer);
      confirmed_trips(usrname,booked,answer);
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
  printf("|  Nisi/ Limani  | Kodikos |               Kostos Thesis                   |       Epipleon Kostos       |\n"
         "|                          |  Katastroma  |  Aeroporikou Typou  | Kampina  |       Aytokinito            |\n");
  //Ektipono pavles kai gia omorfia alla kai gia na xero peripou poso xoro prepei na pianei kathe string gia na einai efthigramismena 
  printf("|----------------|---------|--------------|---------------------|----------|-----------------------------|\n");

  for (int i = 0; i < 9; i++) 
  {
    //emafnizo stin othoni tis plirofories kathe proorismou 
    printf("| %-14s | %-7s | %-12d | %-19d | %-8d | %-27d |\n", 
    trips[i].port, trips[i].port_code, trips[i].deck_cost, trips[i].plane_cost, trips[i].boat_cost, trips[i].car_cost);
  }  
  printf("\n");
  return;
}


void book_trip(booked_trip booked[1500],char usrname[50],Route Trips[12],Users list[30])
{
  //metavliti stin opoia tha apothikevetai o kodikos limaniou prin apothikeftei
  char desti[4];
  //metavliti stin opoia tha apothikevetai i epilogi thesis
  int seat;
  //metavliti stin opoia tha apothikevtai to sinoliko kostos tou taxidiou
  int cost;
  //metavliti stin opoia tha apothikevetai i epilogi taxidiou me h xoris amaksi
  int car;

  Date date_go;
  Date return_date;
  printf("pote tha thelate na taxidepsete : ");
  scanf("%d %d %d",&date_go.dd,&date_go.mm,&date_go.yyyy);

  printf("pou tha thelate na taksidepsete : ");
  scanf("%s",desti);
  for(int i = 0 ; i < 1500; i++ )
  {
    if(strcmp(desti,Trips[i].port_code) == 0);   
    {
      //infinite loop etsi oste na rotaei sinexeia ton xristi mexri na parei egkiri apantisi
      while(1)
      {
        printf("se ti thesi tha thelate na taxidepsete : \n");
        printf("aeriporikou tipou : 1\n");
        printf("kampina : 2\n");
        printf("katastroma : 3 \n");
        printf("?");
        scanf("%d",&seat);
        if(seat == 1)
        {
          cost = Trips[i].plane_cost;
          break;
        }
        else if(seat == 2)
        {
          cost = Trips[i].boat_cost;
          break;
        }
        else if(seat == 3)
        {
          cost = Trips[i].deck_cost;
          break;
        }
        else
        {
          printf("mi egkiri epilogi\n\n");
        }
      }
      //infinite loop gia na rotaei sinexeia ton xristi mexri na dosei egkiri apantisi 
      while(1)
      {
        printf("epithimite na taxidepsete me autokinito :\n");
        printf("nai : 1\n");
        printf("oxi : 2\n");
        printf("?");
        scanf("%i",&car);
        printf("\n");
        if(car == 1)
        {
          cost += Trips[i].car_cost;
          break;
        }
        else if(car == 2)
        {
          break;
        }
        else
        {
          printf("mi egkiri epilogi \n");  
        }
      }

      //i metavliti retour tha pairnei h 0 h 1 an to taxidi einai monis diadromis h met'epistrofis antistoixa
      int retour;
      while(1)
      {
        int epistrofi;
        printf("epithimite to taxidi sas na einai monis diadromis h met'epistrofis\n");
        printf("monis diadromis : 1\n");
        printf("met'epistrofis : 2\n ");
        scanf("%d",&epistrofi);

        if(epistrofi == 1)
        {
          retour = 0;
          break;
        }
        else if(epistrofi == 2)
        {
          //an epilexei na taxidepsei me'epstroifi prostheto to kostos tou ela sto kostos tou pigaine, ta opioa theoro pos eina isa
          cost = cost * 2;
          retour = 1;
          printf("pote tha thelate na epistrepsete : ");
          scanf("%d %d %d",&return_date.dd, &return_date.mm, &return_date.yyyy);
          break;
          
        }
        else
        {
          printf("mi egkiri epilogi \n");
        }
      }
      
      //elegxw an o user einai foititis kai analoga diamorfono to kostos
      for(int i = 0 ; i < 30; i ++)
      {
        if(strcmp(usrname,list[i].username) == 0)
        {
          if(list[i].uni_student == 1)
          {
            cost = cost / 2;
            break;
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
      char travelid[100];  
      generate_travel_ID(date_go,usrname,desti,travelid);


      //ta apothikevo ola ston pinaka booked se opoia thesi einai keni
      for(int i = 0; i < 1500; i++)
      {
        if(booked[i].empty == 1)
        {
          //apothikevo sta antistoixa meri tou struct booked_trip kai orizo to payment = 0 ( diladi oti den exei plirothei) kai to empty = 0(diladi i thesi einia piasmeni) 
          
          strcpy(booked[i].username,usrname);               
          strcpy(booked[i].unique_string,travelid);
          booked[i].total_cost = cost;

          //pernao tin imeronia anaxorisis sti kratisi
          booked[i].date_go->dd = date_go.dd;
          booked[i].date_go->mm = date_go.mm;
          booked[i].date_go->yyyy = date_go.yyyy;
          
          //pernao tin imeronia epistrofis sti kratisi(an den iparxei tha midenistei)
          booked[i].date_return->dd = return_date.dd;
          booked[i].date_return->mm = return_date.mm;
          booked[i].date_return->yyyy = return_date.yyyy;

          booked[i].trip_type = retour;
          booked[i].payment = 0;  
          booked[i].empty = 0;  
          break;
        }
      }

      return;

    }
  }
  printf("O kodikos den iparxei\n\n\n");
  return;

  

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
  for(int i = 0 ; i < 1500 ; i++ )
  {
    if(strcmp(booked[i].username,usrname) == 0)
    {
      //elegxw an i kratisi den exei plirothei
      if(booked[i].payment == 0)
      {
        //an den exei plirothei ektipono tis plirofories tis kratisis
        printf("Plirofories taxidiou :\n Monadiko anagnoristiko taxidiou : %s \n Sinoliko kostos : %d \n Imerominia anaxorisis : %d/%d/%d \n",booked[i].unique_string,booked[i].total_cost,booked[i].date_go->dd,booked[i].date_go->mm,booked[i].date_go->yyyy);
        //an to taxidi exei kai epistrofi ektipono tin imerominia epistrofis 
        if(booked[i].trip_type == 1)
        {
          printf(" Imerominia epistrofis : %d/%d/%d\n",booked[i].date_return->dd,booked[i].date_return->mm,booked[i].date_return->yyyy);
        }

      }
    }
  }

  char tripID[100];
  printf("An thelete na plirosete mia kratisi pliktrologiste to Monadiko Anagnoristiko Taxidiou tis kratisis sas \n");
  printf("?");
  scanf("%s",tripID);

  //elegxw an to monadiko anagnoristiko taxidiou einai sosto kai analoga theto tin kratisi pliromeni h na einai pliromeni ektipono to analogo minima
  //ayto to for-loop tha mporoyse na einai mesa sto if sti grmami 287 gia na min ksanatsekaro to username
  for(int j = 0 ; j < 1500 ; j++)
  {
    if(strcmp( booked[j].username, usrname) == 0 && strcmp( booked[j].unique_string, tripID) == 0 && booked[j].payment == 0)
    {
      booked[j].payment = 1;
      return;
      
    }
    else if(strcmp(booked[j].username,usrname) == 0 && strcmp(booked[j].unique_string,tripID) == 0 && booked[j].payment == 1)
    {
      printf("To sigkekrimeno taxidi exei idi exoflithei\n\n\n");
      return;
    }
  }
  printf("To Monadiko Anagnoristiko Taxidiou einai lathos\n\n\n");
  return;

}


int compare_trip(booked_trip a,booked_trip b)
{
  //Sigkrino arxika tin xronia, meta ton mina kai telos thn imera tis kratisis kathe taxidiou kai analoga epistrefo to taxidi pou exei kratithei teleftaio
  if(a.date_go->yyyy > b.date_go->yyyy)
  {
    return 1;
  }
  else if(a.date_go->mm > b.date_go->mm)
  {
    return 1;
  }
  else if(a.date_go->dd > b.date_go->dd)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}



void confirmed_trips(char usrname[50],booked_trip trips[1500],char ans[5])
{
  booked_trip userTrips[30];

  //Orizo kathe thesi kratisis os keni
  for(int i = 0 ; i < 30; i++)
  {
    userTrips[i].empty = 1;
  }

  for(int i = 0; i < 1500; i++)
  {
    //elegxw poia taxidia tou xristi einai pliromena kai ta antigrafo ston pinaka userTrips stin proti keni thesi
    if(strcmp(usrname,trips[i].username) == 0 && trips[i].payment == 1)
    {
      for(int j = 0 ; j < 30 ; j++)
      {
        if(userTrips[j].empty == 1)
        {
          strcpy(userTrips[j].username,trips[i].username);
          strcpy(userTrips[j].unique_string,trips[i].unique_string);
          userTrips[j].total_cost = trips[i].total_cost;

          userTrips[j].date_go->dd = trips[i].date_go->dd;
          userTrips[j].date_go->mm = trips[i].date_go->mm;
          userTrips[j].date_go->yyyy = trips[i].date_go->yyyy;

          userTrips[j].date_return->dd = trips[i].date_return->dd;
          userTrips[j].date_return->mm = trips[i].date_return->mm;
          userTrips[j].date_return->yyyy = trips[i].date_return->yyyy;

          userTrips[j].trip_type = trips[i].trip_type;
          userTrips[j].empty = 0;
          break;
        }
      }
      

    }
  }

  //Kano sort ton pinaka userTrips kata auxousa seira
  booked_trip temp;
  int n;
  int swapped = 0;
  for(int i = 0; i <30 ; i ++)
  {
    for(int j = 0 ; j < 28 ; j++)
    {
      n = compare_trip(userTrips[j],userTrips[j+1]);
      if(n == 1)
      {
        temp = userTrips[j];
        userTrips[j] = userTrips[j+1];
        userTrips[j+1] = temp;
        //Enimeronno thn metavliti swapped kathe fora pou allazw dio arithmous metaxi tous
        swapped++;
      }
      else
      {
        continue;
      }
    }
    //elegxw an den exei ginei kamia allagi etsi oste na termatizei i for-loop molis ginei sort o pinakas
    if(swapped == 0)
    {
      break;
    }
    swapped = 0;
  }

  //An o xristis pliktrologisei "HIGH" ektipono ti lista me tis kratiseis tou opos einai  
  if(strcmp(ans,"HIGH") == 0)
  {
    //gia aisthitikous skopous ektiopno mia keni grammi
    printf("\n");
    for(int i = 0; i < 30 ; i++)
    {
      if(userTrips[i].empty == 0)
      {
        printf("Monadiko Anagnoristiko Taxidiou : %s \n ",userTrips[i].unique_string);
        printf("Sinoliko Kostos : %d \n",userTrips[i].total_cost);
        printf("Imerominia Anaxorisis : %02d/%02d/%d\n",userTrips[i].date_go->dd,userTrips[i].date_go->mm,userTrips[i].date_go->yyyy);
        if(userTrips[i].trip_type == 1)
        {
          printf("Imerominia epistrofis %02d/%02d/%d  \n",userTrips[i].date_return->dd,userTrips[i].date_return->mm,userTrips[i].date_return->yyyy);
        }
        printf("\n");
      }
    }
  }
  //An o xristis pliktrologisei "LOW" ektipono ti lista anapoda etsi oste na oi kratiseis na einai kata fthinousa seira 
  else if(strcmp(ans,"LOW") == 0)
  {
    //gia aisthitikous skopous ektiopno mia keni grammi
    printf("\n");
    for(int j = 29 ; j >= 0 ; j--)
    {
      printf("Monadiko Anagnoristiko Taxidiou : %s \n ",userTrips[j].unique_string);
      printf("Sinoliko Kostos : %d \n",userTrips[j].total_cost);
      printf("Imerominia Anaxorisis : %02d/%02d/%d\n",userTrips[j].date_go->dd,userTrips[j].date_go->mm,userTrips[j].date_go->yyyy);
      if(userTrips[j].trip_type == 1)
      {
        printf("Imerominia epistrofis %02d/%02d/%d\n",userTrips[j].date_return->dd,userTrips[j].date_return->mm,userTrips[j].date_return->yyyy);
      }
      printf("\n");
    }
  }

}






