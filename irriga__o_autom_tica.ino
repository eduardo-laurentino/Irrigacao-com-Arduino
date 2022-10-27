#include <virtuabotixRTC.h> 
#define clk 6
#define dat 7
#define rst 8
#define seg 0
#define mnt 12
#define hor 28
#define d_sem 1
#define d_mes 9
#define mes 10
#define ano 2022

const int Valv = 10;
const int Bomba = 11;

//Determina os pinos ligados ao modulo

virtuabotixRTC meuRTC(clk, dat, rst);

// Converte o dia da semana na escrita dia da semana
void DS1302();
void week (int dayW);
void setup()  {
  pinMode(Valv, OUTPUT); 
  //pinMode(Bomba, OUTPUT);     
  Serial.begin(9600);
  //Informacoes iniciais de data e hora
  //Apos setar as informacoes, comente a linha abaixo
  //(segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
 //meuRTC.setDS1302Time(seg, mnt, hor, d_sem, d_mes, mes, ano);
}
void loop(){
  DS1302();
}

void DS1302(){
  meuRTC.updateTime();

  // Imprime informações
  Serial.print(" -> ");
  week(meuRTC.dayofweek);
  Serial.print(" ! ");
  Serial.print(meuRTC.dayofmonth);
  Serial.print("/");
  Serial.print(meuRTC.month);
  Serial.print("/");
  Serial.print(meuRTC.year);
  Serial.print("|");
  if(meuRTC.hours < 10) Serial.print("0");
  Serial.print(meuRTC.hours);
  Serial.print(":");
  if(meuRTC.minutes < 10) Serial.print("0");
  Serial.print(meuRTC.minutes);
  Serial.print(":");
  if(meuRTC.seconds < 10) Serial.print("0");
  Serial.println(meuRTC.seconds);
  delay(1000);

  
  if(meuRTC.hours==19 && meuRTC.minutes==49){
    digitalWrite(Valv, HIGH);
    delay(1000);
    digitalWrite(Bomba, HIGH);
  }
  if(meuRTC.hours==19 && meuRTC.minutes==50){
    digitalWrite(Bomba, LOW);
    delay(1000);
    digitalWrite(Valv, LOW);
  }
  
}
void week(int dayW){
  switch(dayW){
  case 1 : Serial.print("DOMINGO"); 
  break;
  case 2 : Serial.print("SEGUNDA"); 
  break;
  case 3 : Serial.print("TERÇA"); 
  break;
  case 4 : Serial.print("QUARTA"); 
  break;
  case 5 : Serial.print("QUINTA"); 
  break;
  case 6 : Serial.print("SEXTA"); 
  break;
  case 7 : Serial.print("SÁBADO"); 
  break;
}
}
