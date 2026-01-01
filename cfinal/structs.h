#ifndef STRUCTS_H
#define STRUCTS_H 

//genika kathe char meatbliti exei megethos 50 gia na eimai sigouros oti den tha valei kapoios onoma pou tha dhmiourghisei problhma  
//arxikopio kathe akeraio os 0 gia na mporw na prostheto elefthera 
typedef struct people{
  char name[50];
  char surname[50];
  int age;
  int card_num;
  int uni_student;
  char username[50];
  //orizo to megethos tou password 8 gia tous 7 xarakthres + ton null character
  char password[8];
  int empty;
}Users;



typedef struct route{
  //to megalitero onoma limaniou exei ligotero apo 15 xaraktheres, kai pali gia na sigouria to megethos orizetai os 15
  char port[15];
  //ta prwta tria gramata kathe limaniou einai o kwdikos ara to mhkow = ta 3 grammata + null character
  char port_code[4];
  //kostos katastromatos
  int deck_cost;
  //kostos aeroporikis 
  int plane_cost;
  //kostos kampinas
  int boat_cost;
  //kostos autokinitou
  int car_cost;
}Route;



typedef struct date{
  int dd;//mera 
  int mm;//minas
  int yyyy;//etos 
}Date;


typedef struct Booked_trip{
  char username[50];
  char unique_string[100];
  int total_cost;
  //Orizo tis meatvlites pou apothikevoun tis imeronies os structs tipou Date
  Date date_go[10];
  Date date_return[10];
  int trip_type;
  int payment;
  //Metavliti pou deixnei an to struct einai keno i oxi (1 = keno | 0 = piasmeno)
  int empty;
}booked_trip;






//oriso ta prototipa ton sinartiseon pou tha ilopoioso

void clientDashboard(char usrname[50],Route trip[12],booked_trip booked[1500],Users list[30]);
void view_routes(Route trips[12]);
void book_trip(booked_trip booked[1500],char usrname[50],Route Trips[12],Users list[30]);
int check_login(char usrname[50],char pword[8],Users user [30]);
void generate_travel_ID(Date date_go,char usrname[50],char destination[4],char *travelID);
void payment(booked_trip booked[1500],char usrname[50]);
booked_trip compare_trips(booked_trip a, booked_trip b);
void confirmed_trips(char usrname[50],booked_trip Booked[1500],char ans[5]);


void adminDashboard(Users list[30]);
void create_new_client(Users list[30]);
void changePword(Users list[30]);
int username_exists(char usrname[50],Users list[30]);

#endif





