#include <Keypad.h>
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
#include <time.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {16, 17, 18, 19};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
const char alphanum[] = "0123456789ABCD#*";
int string_length = sizeof(alphanum)-1;

int printRandoms(){
      int n=3;
    srand(time(0));
    for(int i = 0; i < n; i++)
    return alphanum[rand() % string_length];

}
int passsword1,passsword2,passsword3,passsword4;

void setup(){
  lcd.begin(16,2);
  pinMode(8,OUTPUT); //relay
}

void loop(){
  lcd.print("1 for lock and 2 to unlock");  delay(3000);
  char keys = keypad.getKey();
  
  if (keys==1)
  {
    
    lcd.print("which drawer you want to close?");  delay(3000);
    char box = keypad.getKey();
    if (box==1){  digitalWrite(8,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 1 locked");  delay(1000);
                  passsword1=printRandoms();
                  lcd.print(passsword1);
                  delay(2000); }

     if (box==2){  digitalWrite(14,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 2 locked");  delay(1000);
                  passsword2=printRandoms();
                  lcd.print(passsword2);
                  delay(2000); }
                  
     if (box==3){  digitalWrite(15,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 3 locked");  delay(1000);
                  passsword3=printRandoms();
                  lcd.print(passsword3);
                  delay(2000); }
    
   if (box==4){  digitalWrite(3,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 4 locked");  delay(1000);
                  passsword4=printRandoms();
                  lcd.print(passsword4);
                  delay(2000); }
   }


   
 
    if (keys==2)
    {
      bool b=false;
      while (b!=true)
      {
      lcd.print("whic box do you want to open?"); delay(2000);

      char box2 = keypad.getKey();
      if (box2==1){ 
             lcd.print("enter passsword"); delay(1000);
             char pwd = keypad.getKey(); //get input passsword
             if (pwd==passsword1){ 
             digitalWrite(8,LOW);  //lock open
             delay(500);
             lcd.print("draws 1 unlocked");  delay(1000);
             b=true;
             }}
             lcd.print("wrong passsword,Try again"); delay(1000);

      if (box2==2){ 
             lcd.print("enter passsword");
             char pwd = keypad.getKey(); //get input passsword
             if (pwd==passsword2){ 
             digitalWrite(14,LOW);  //lock open
             delay(500);
             b=true;
             lcd.print("draws 2 locked");  delay(1000);
             }}
             lcd.print("wrong passsword,Try again"); delay(1000);

      if (box2==3){ 
             lcd.print("enter passsword");
             char pwd = keypad.getKey(); //get input passsword
             if (pwd==passsword3){ 
             digitalWrite(15,LOW);  //lock open
             delay(500);
             b=true;
             lcd.print("draws 3 locked");  delay(1000);
             }}
             lcd.print("wrong passsword,Try again"); delay(1000);

      if (box2==4){ 
             lcd.print("enter passsword");
             char pwd = keypad.getKey(); //get input passsword
             if (pwd==passsword4){ 
             digitalWrite(3,LOW);  //lock open
             delay(500);
             b=true;
             lcd.print("draws 4 locked");  delay(1000);
             }}
             lcd.print("wrong passsword,Try again"); delay(1000);
             
    }
      }
}
