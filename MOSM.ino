/* 
 this is a Operating system

*/
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;
boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {A0,A1,A2,A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A4,A5,3,2};   //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
byte MIpad[] = {
  B01110,
  B00100,
  B01110,
  B10001,
  B11011,
  B10101,
  B10001,
  B10001
};

byte customChar[] = {
  B10000,
  B10000,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
byte terminal[] = {
  B10000,
  B10000,
  B11000,
  B10100,
  B11010,
  B10100,
  B11000,
  B10000
};
byte sqigle[] = {
  B00000,
  B00000,
  B00000,
  B00101,
  B01010,
  B00000,
  B00000,
  B00000
};

byte dollar[] = {
  B00000,
  B00100,
  B01110,
  B01100,
  B01110,
  B00110,
  B01110,
  B00100
};
byte loading[] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte littleclock[] = {
  B00000,
  B01010,
  B11111,
  B11001,
  B10101,
  B11001,
  B11111,
  B00000
};
byte reboot[] = {
  B01111,
  B01001,
  B11101,
  B01001,
  B00001,
  B01001,
  B01111,
  B00000
};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int i=0;
void setup(){
lcd.begin(16, 2);
startup();
}
void startup(){
clock.begin();
dt = clock.getDateTime();
lcd.createChar(7, reboot);
lcd.createChar(6, littleclock);
lcd.createChar(5, MIpad);
lcd.createChar(4, loading);
  lcd.createChar(0, customChar);
  lcd.createChar(1, terminal);
  lcd.createChar(2, sqigle);
  lcd.createChar(3, dollar);
  lcd.home();
  lcd.write((byte)0);
  lcd.print("|MOSM|");
  lcd.setCursor(0, 1);
  lcd.print("       ");
  delay(2000);
  Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }


    
  lcd.clear();
  Serial.println("Lernel loaded");
    Serial.println("initializing memory");
    char Memory1 = 0;
    char Memory2 = 0;
    char Memory3 = 0;
    char memory4 = 0;
    Serial.println("Memory initalized");
    Serial.println("initalizing cache");
    char cache = 0;
    Serial.println("loading boot Splash");
    Serial.println("                 ");
    Serial.println("                 ");
    Serial.println("                 ");
    Serial.println("      |\___/|    ");
    Serial.println("      | * * |    ");
    Serial.println("      |- ~ -|    ");
    Serial.println("      *******    ");
    Serial.println("                 ");
    Serial.println("Lernel");
    Serial.println("1% [*    ]");
    Serial.println("20% [**   ]");
    Serial.println("30% [***  ]");
    Serial.println("40% [*****]");
    Serial.println("Flushing serial");
    Serial.flush();
    Serial.println("Serial cleared");
    Serial.println("OS ready");
    lcd.print("       ");
    lcd.write((byte)   0);
  lcd.setCursor(0, 1);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
    lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  delay(1000);
  lcd.write((byte)   4);
  lcd.clear();
  lcd.print("       ");
  lcd.write((byte)   0);
  delay(2000);
  lcd.clear();
  goto home;
home:
lcd.clear();
lcd.setCursor(0, 1);
lcd.write((byte)0);
lcd.print(" < *    ");
lcd.write((byte)7);
lcd.print(" < # ");
lcd.setCursor(0, 0);
lcd.write((byte)1);
homescreen();
}
void homescreen(){
char Memory1 = customKeypad.getKey();
 if (Memory1 == '#'){
  lcd.clear();
  delay(5000);
char Memory1 = 0;
setup();
 }
 if (Memory1){
  lcd.print(Memory1);
   if (Memory1 == '*'){
    delay(1000);
    menu();
   }
   
 }
 homescreen();
}










 
void datetime(){
dt = clock.getDateTime();
delay(1000);
lcd.clear();
lcd.print(dt.month);  lcd.print("/");
lcd.print(dt.day);    lcd.print("/");
lcd.print(dt.year);   lcd.print(" ");
lcd.setCursor(0, 1);
lcd.print(dt.hour);   lcd.print(":");
lcd.print(dt.minute); lcd.print(":");
lcd.print(dt.second); lcd.print(" ");
datetime();
 }

 void menu(){
 delay(900);
 char Memory1 = customKeypad.getKey();
 lcd.clear();
 lcd.print("A = clock");
 lcd.setCursor(0,  1);
 lcd.print("B = counter");
 if (Memory1 == '1'){
    datetime();
    delay(900);
   }
  if (Memory1 == 'A'){
    lcd.clear();
    counter();
   }
   delay(1000);
 menu();
 }

 void counter(){
  char Memory1 = customKeypad.getKey();
 if (Memory1 == '*'){
  lcd.print("|");
   }
   if (Memory1 == '#'){
  lcd.setCursor(0, 1);
  counter();
   }
   if (Memory1 == 'D'){
  lcd.scrollDisplayLeft();
  counter();
   }
   if (Memory1 == 'C'){
  lcd.scrollDisplayRight();
  counter();
   }
   
   counter();
 }
   

 
 
