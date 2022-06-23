#include <Keypad.h>
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void printRandoms(int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %(upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}

void setup(){
  lcd.begin(16,2);
  pinMode(11,OUTPUT); //relay
  Serial.begin(9600);
}
  
void loop(){
  lcd.print("1 for lock and 2 to unlock");  delay(3000);
  char key = keypad.getKey();
  
  if (key==1)
  {
    lcd.print("which drawer you want to close?");  delay(3000);
    char box = keypad.getKey();
    if (box==1){  digitalWrite(11,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 1 locked");  delay(1000);
                  password1=printRandoms(0, 9, 3);
                  lcd.print("password is ",passsword1);
                  delay(2000); }

     if (box==2){  digitalWrite(10,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 2 locked");  delay(1000);
                  password2=printRandoms(0, 9, 3);
                  lcd.print("password is ",passsword2);
                  delay(2000); }
                  
     if (box==3){  digitalWrite(9,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 3 locked");  delay(1000);
                  password3=printRandoms(0, 9, 3);
                  lcd.print("password is ",passsword3);
                  delay(2000); }
    
   if (box==4){  digitalWrite(8,HIGH);  //Relay onn,locked
                  delay(500);
                  lcd.print("draws 4 locked");  delay(1000);
                  password4=printRandoms(0, 9, 3);
                  lcd.print("password is ",passsword4);
                  delay(2000); }
   }


   
 
    if (key==2)
    {
      bool b=false;
      while (b!=true)
      {
      lcd.print("whic box do you want to open?"); delay(2000);

      char box2 = keypad.getKey();
      if (box2==1){ 
             lcd.print("enter password"); delay(1000);
             char pwd = keypad.getKey(); //get input password
             if (pwd==password1){ 
             digitalWrite(11,LOW);  //lock open
             delay(500);
             lcd.print("draws 1 unlocked");  delay(1000);
             b=true;
             }}
             lcd.print("wrong password,Try again"); delay(1000);

      if (box2==2){ 
             lcd.print("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password2){ 
             digitalWrite(10,LOW);  //lock open
             delay(500);
             b=true;
             lcd.print("draws 2 locked");  delay(1000);
             }}
             lcd.print("wrong password,Try again"); delay(1000);

      if (box2==3){ 
             lcd.print("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password3){ 
             digitalWrite(9,LOW);  //lock open
             delay(500);
             b=true;
             lcd.print("draws 3 locked");  delay(1000);
             }}
             lcd.print("wrong password,Try again"); delay(1000);

      if (box2==4){ 
             lcd.print("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password8){ 
             digitalWrite(8,LOW);  //lock open
             delay(500);
             b=true;
             lcd.print("draws 4 locked");  delay(1000);
             }}
             lcd.print("wrong password,Try again"); delay(1000);
             
    }
      }
}
