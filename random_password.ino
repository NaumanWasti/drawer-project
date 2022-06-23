#include <Keypad.h>

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
    pinMode(11,OUTPUT); //relay
  Serial.begin(9600);
}
  
void loop(){
  Serial.println("enter 1 for lock and 2 to open lock");
  char key = keypad.getKey();
  
  if (key==1)
  {
    Serial.println("which drawer you want to close?");
    char box = keypad.getKey();
    if (box==1){  digitalWrite(11,HIGH);  //Relay onn,locked
                  delay(500);
                  password1=printRandoms(0, 9, 3);
                  Serial.println("password is ",passsword1);
                  delay(2000); }

     if (box==2){  digitalWrite(10,HIGH);  //Relay onn,locked
                  delay(500);
                  password2=printRandoms(0, 9, 3);
                  Serial.println("password is ",passsword2);
                  delay(2000); }
                  
     if (box==3){  digitalWrite(9,HIGH);  //Relay onn,locked
                  delay(500);
                  password3=printRandoms(0, 9, 3);
                  Serial.println("password is ",passsword3);
                  delay(2000); }
    
   if (box==4){  digitalWrite(8,HIGH);  //Relay onn,locked
                  delay(500);
                  password4=printRandoms(0, 9, 3);
                  Serial.println("password is ",passsword4);
                  delay(2000); }
   }


   
 
    if (key==2)
    {
      bool b=false;
      while (b!=true)
      {
      Serial.println("whic box do you want to open?");
      char box2 = keypad.getKey();
      if (box2==1){ 
             Serial.println("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password1){ 
             digitalWrite(11,LOW);  //lock open
             delay(500);
             b=true;
             }}
             Serial.println("wrong password,Try again");

      if (box2==2){ 
             Serial.println("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password2){ 
             digitalWrite(10,LOW);  //lock open
             delay(500);
             b=true;
             }}
             Serial.println("wrong password,Try again");

      if (box2==3){ 
             Serial.println("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password3){ 
             digitalWrite(9,LOW);  //lock open
             delay(500);
             b=true;
             }}
             Serial.println("wrong password,Try again");

      if (box2==4){ 
             Serial.println("enter password");
             char pwd = keypad.getKey(); //get input password
             if (pwd==password8){ 
             digitalWrite(8,LOW);  //lock open
             delay(500);
             b=true;
             }}
             Serial.println("wrong password,Try again");
             
    }
      }
}
