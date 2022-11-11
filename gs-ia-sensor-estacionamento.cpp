#define triggerg 10
#define echog 11
#define triggerr 12 
#define echor 13

// biblioteca do LCD:
#include <LiquidCrystal.h>


float xVaga1 = 0, yVaga1 = 0;
float xVaga2 = 0, yVaga2 = 0;
int vagasLivres = 2;
int vagasOcupadas = 0;


LiquidCrystal lcd(0,1,2,3,4,5);

void setup()
{
  
  lcd.begin(16, 2);
  
  pinMode(triggerg, OUTPUT);
  pinMode(triggerr, OUTPUT);
  pinMode(echog, INPUT);
  pinMode(echor, INPUT);
  
  
}
void loop() 
{
  
  
  digitalWrite(triggerr, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerr, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerr, LOW);
  float xVaga1 = pulseIn(echor, HIGH);
  yVaga1=(xVaga1*340/20000)/100;
  delayMicroseconds(5);
  
  
  digitalWrite(triggerg, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerg, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerg, LOW);
  float xVaga2 = pulseIn(echog, HIGH);
  yVaga2 = (xVaga2*340/20000)/100;
  delay(90);
  
  if(yVaga1 < 2.00 && yVaga2 < 2.00){

      	vagasLivres = 0;
    vagasOcupadas = 2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0,1);
    lcd.print("Vagas ocupadas " + String(vagasOcupadas));
  }if(yVaga1 < 2.00 && yVaga2 > 2.00) {
    vagasLivres = 1;
    vagasOcupadas = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas "+ String(vagasOcupadas));
  }if (yVaga1 > 2.00 && yVaga2 < 2.00) {
  	vagasLivres = 1;
    vagasOcupadas = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas "+ String(vagasOcupadas));
  }if(yVaga1 > 2.00 && yVaga2 > 2.00){
    vagasLivres = 2;
    vagasOcupadas = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(vagasLivres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas "+ String(vagasOcupadas));
  }
}


  