#ifndef STRUCTS
#define STRUCTS.H 

//genika kathe char meatbliti exei megethos 50 gia na eimai sigouros oti den tha valei kapoios onoma pou tha dhmiourghisei problhma  
//arxikopio kathe akeraio os 0 gia na mporw na prostheto elefthera 
struct users{
  char name[50];
  char surname[50];
  int age = 0;
  int card_num = 0;
  bool uni_student;
  char username[50];
  //orizo to megethos tou password 8 gia tous 7 xarakthres + ton null character
  char password[8];
  //arxikopoio enan pinaka me olous tous xristous pou mporei na ypostirixei to sistima 
}Users[30];



typedef struct route{
  //to megalitero onoma limaniou exei ligotero apo 15 xaraktheres, kai pali gia na sigouria to megethos orizetai os 15
  char port[15];
  //ta prwta tria gramata kathe limaniou einai o kwdikos ara to mhkow = ta 3 grammata + null character
  char port_code[4];
  //kostos katastromatos
  int deck_cost = 0;
  //kostos aeroporikis 
  int plane_cost = 0;
  //kostos kampinas
  int boat_cost = 0;
  //kostos autokinitou
  int car_cost = 0;
}Route;


//Orizo ton pinaka kai arxikopoio tis times tou me tis plirofories kathe dromologiou
Route Routes[12];

Routes[0].port = "Kos";
Routes[0].port_code = "KOS";
Routes[0].deck_cost = 60;
Routes[0].plane_cost = 80;
Routes[0].boat_cost = 120;
Routes[0].car_cost = 100;

Routes[1].port = "Rodos";
Routes[1].port_code = "RHO";
Routes[1].deck_cost = 80;
Routes[1].plane_cost = 100;
Routes[1].boat_cost = 140; 
Routes[1].car_cost = 100;

Routes[2].port = "Kalymnos";
Routes[2].port_code = "KAL";
Routes[2].deck_cost = 60;
Routes[2].plane_cost = 80;
Routes[2].boat_cost = 120; 
Routes[2].car_cost = 100;

Routes[3].port = "Patmos";
Routes[3].port_code = "PAT";
Routes[3].deck_cost = 55;
Routes[3].plane_cost = 75;
Routes[3].boat_cost = 115; 
Routes[3].car_cost = 100;

Routes[4].port = "Astypalaia";
Routes[4].port_code = "AST";
Routes[4].deck_cost = 50;
Routes[4].plane_cost = 70;
Routes[4].boat_cost = 110; 
Routes[4].car_cost = 100;

Routes[5].port = "Kasos";
Routes[5].port_code = "KAS";
Routes[5].deck_cost = 65;
Routes[5].plane_cost = 85;
Routes[5].boat_cost = 125; 
Routes[5].car_cost = 100;

Routes[6].port = "Kastelorizo";
Routes[6].port_code = "KST";
Routes[6].deck_cost = 100;
Routes[6].plane_cost = 120;
Routes[6].boat_cost = 160; 
Routes[6].car_cost = 100;

Routes[7].port = "Leros";
Routes[7].port_code = "LER";
Routes[7].deck_cost = 60;
Routes[7].plane_cost = 80;
Routes[7].boat_cost = 120; 
Routes[7].car_cost = 100;

Routes[8].port = "Karpathos";
Routes[8].port_code = "KAR";
Routes[8].deck_cost = 70;
Routes[8].plane_cost = 90;
Routes[8].boat_cost = 130; 
Routes[8].car_cost = 100;

Routes[9].port = "Symi";
Routes[9].port_code = "SYM";
Routes[9].deck_cost = 80;
Routes[9].plane_cost = 100;
Routes[9].boat_cost = 140; 
Routes[9].car_cost = 120;

Routes[10].port = "Xalki";
Routes[10].port_code = "XAL";
Routes[10].deck_cost = 70;
Routes[10].plane_cost = 90;
Routes[10].boat_cost = 130; 
Routes[10].car_cost = 100;

Routes[11].port = "Tilos";
Routes[11].port_code = "TIL";
Routes[11].deck_cost = 75;
Routes[11].plane_cost = 95;
Routes[11].boat_cost = 135; 
Routes[11].car_cost = 100;

Routes[12].port = "Pserimos";
Routes[12].port_code = "PSE";
Routes[12].deck_cost = 60;
Routes[12].plane_cost = 80;
Routes[12].boat_cost = 120; 
Routes[12].car_cost = 100;


typedef struct Booked_trip{
  char username[50];
  char unique_string[100];
  int total_cost = 0;
  char date_go[10];
  char date_return[10];
  char trip_type[50];
  //orizo ex arxhs th plhrwmh ws false etsi wste na to allazv mono otan plirountai oi poroypotheseis kai exei plhrwsei o xrhsths
  bool payment = false;
}booked_trip;

//arxikopoio enan pinaka ston opoio tha apothikevontai ola ta kleismena taxidia kathe user
booked_trip Trips[30][50];


struct date{
  int dd;//mera 
  int mm;//minas
  int yyyy;//etos 
}

#endif




