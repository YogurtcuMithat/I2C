#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  Wire.begin(5);
  Wire.onRequest(istekGeldiginde);
  Wire.onReceive(veriGeldiginde);
}

void loop()
{
  delay(1);
  masterGame();
  delay(150);
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

char gelenKarakter;
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
long randNumber;
void masterGame(){
  Wire.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0)); 
  
  randNumber = random(0, 54);
  lcd.setCursor(1,0);
  lcd.print(dizi[randNumber]);
  Wire.beginTransmission(6);
  Wire.write(randNumber);
  Serial.print(randNumber);
  Serial.print(dizi[randNumber]);
  Serial.println("");
  Wire.endTransmission();
  delay(1000);
}