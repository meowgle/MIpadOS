/* 
 this is a Operating system

*/
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
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
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B00000
};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
char entryStr[8];
int i=0;
void setup(){
lcd.begin(16, 2);
lcd.createChar(5, MIpad);
lcd.createChar(4, loading);
  lcd.createChar(0, customChar);
  lcd.createChar(1, terminal);
  lcd.createChar(2, sqigle);
  lcd.createChar(3, dollar);
  lcd.home();
  lcd.write((byte)5);
  lcd.print("|MIpad |");
  lcd.setCursor(0, 1);
  lcd.print("--------|");
  Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }


    Serial.println("Lernel loaded");
    delay(1000);
    Serial.println("initializing memory");
    char Memory1 = 0;
    char Memory2 = 0;
    char Memory3 = 0;
    char memory4 = 0;
    Serial.println("Memory initalized");
    delay(1000);
    Serial.println("initalizing cache");
    char cache = 0;
    delay(1000);
    Serial.println("loading boot Splash");
    delay(1000);
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
    delay(1000);
    Serial.println("20% [**   ]");
    delay(1000);
    Serial.println("30% [***  ]");
    delay(1000);
    Serial.println("40% [*****]");
    delay(1000);
    delay(1000);
    Serial.println("Flushing serial");
    delay(1000);
    Serial.flush();
    Serial.println("Serial cleared");
    Serial.println("OS ready");
  lcd.clear();
    lcd.print("       ");
    lcd.write((byte)   0);
  lcd.setCursor(0, 1);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
    lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  delay(5000);
  lcd.write((byte)   4);
  lcd.clear();
  lcd.print("       ");
  lcd.write((byte)   0);
  delay(2000);
  lcd.clear();
lcd.print("Meos");
lcd.write((byte)2);
lcd.write((byte)3);
char type;
}
void loop(){
char Memory1 = customKeypad.getKey();
 
 if (Memory1){
  lcd.print(Memory1);
   if (Memory1 == '*'){
    goto timer;
timer:
 lcd.print(millis() / 1000);
 delay(1000);
 lcd.clear();
 goto timer;
   }
   if (Memory1 == '#'){
lcd.clear();
lcd.print("Meos");
lcd.write((byte)2);
lcd.write((byte)3);
 }
   
 
   }


}
