//MASTER 
#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0)); 
}

char *dizi[]={"Jenerator","Portmanto","Yagmurluk","Kalorifer","Bukalemun","Kirlangic"
               ,"Sarikanat","Kilkuyruk","Dikkuyruk","Hipopotam","Orangutan","Bildircin"
               ,"Flamingo","Muteaffin","Muteessir","Ayiplanan","Mustehcen","Mustekreh"
                 
               ,"Mustahkem","Salatalik","Mandalina","Muhallebi","Hamburger","Ebegumeci"
               ,"Karabiber","Kuskonmaz","Yenibahar","Yakalamak","Algilamak","Susturmak"
               ,"Yinelemek","Gerilemek","Kakalamak","Kalkinmak","Ufalanmak","Azimsamak"
                 
               ,"Yeltenmek","Kaptirmak","Saptirmak","Yalvarmak","Seslenmek","Patlatmak"
               ,"Karalamak","Bastirmak","Yazdirmak","Deplasman","Defalarca","Milimetre"
               ,"Alaycilik","Yoksulluk","Sersemlik","Yamyamlik","Kabakulak","Dertlenme"
               };
long randNumber;
void loop()
{
  master();
  delay(100);
  slaveGame();
}
void master(){
  randNumber = random(0, 54);
  lcd.setCursor(1,0);
  lcd.print(dizi[randNumber]);
  Wire.beginTransmission(5);
  Wire.write(randNumber);
  Serial.print(randNumber);
  Serial.print(dizi[randNumber]);
  Serial.println("");
  Wire.endTransmission();
  delay(1000);
}

char gelenKarakter;
void slaveGame(){
  Wire.begin(6);
  Wire.onRequest(istekGeldiginde);
  Wire.onReceive(veriGeldiginde);
}
void veriGeldiginde(int veri)
{
  while(Wire.available()){
    gelenKarakter = Wire.read();
  }
  Serial.print(gelenKarakter);
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.print(dizi[gelenKarakter]);
  Serial.print(dizi[gelenKarakter]);
  delay(1000);
}
void istekGeldiginde()
{
}