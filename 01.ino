// RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
int count = 0;
//const int Tejas = 3, Om = 2, Sai = 1;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);          // Create MFRC522 instance.
Servo myServo;          // define servo name

void setup()
{
  Serial.begin(9600);          // Initiate a serial communication
  SPI.begin();          // Initiate SPI bus
  mfrc522.PCD_Init();          // Initiate MFRC522 
  myServo.attach(3);          // servo pin 
  myServo.write(0);          // servo start position
  Serial.println("CLEARDATA");//clear excel sheet
 Serial.println("RFID UID,name");//label for ms-excel
 delay(1000);
    
}


void loop()
{
  if( ! mfrc522.PICC_IsNewCardPresent())          // Look for a new cards
  {
    return 0;
  }
  if( ! mfrc522.PICC_ReadCardSerial())          // Select one of the cards
  {
    return 0;
  }
  //Serial.println("UID TAGS:");          // Show UID on Serial monitor
  String content = "";
  byte letter;
  for ( byte i=0;i<mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  //Serial.print("Message : Welcome To School " );
  Serial.println(  "RFID UID,name" +content);
  content.toUpperCase();
  if ( content.substring(1) == "B9 2C D0 B8")          // Enter here the UID of the cards
  {
//    Serial.println( (String) "RFID UID,name" + content.substring(1));
    Serial.println("Rakesh");
    Serial.println();
    delay(500);
    count++;
    Serial.println("Tejas is present");
    Serial.print(count);
    delay(400);
  }
  else if( content.substring(1) == "76 9F A6 23")          // Enter here the UID of the cards
  {
    Serial.println("Tejas ");
    Serial.println();
    delay(500);
    count++;
    Serial.println("Tejas is present");
    Serial.print(count);
    delay(400);
  }
  else if( content.substring(1) == "44 69 6D 25")          // Enter here the UID of the cards
  {
    Serial.println("Om");
    Serial.println();
    delay(500);
    count++;
    Serial.println("Om is present");
    Serial.print(count);
    delay(400);
  }
  else if( content.substring(1) == "C3 7A C9 73")          // Enter here the UID of the cards
  {
    Serial.println("Sai");
    Serial.println();
    delay(500);
    count++;
    Serial.println("Sai is present");
    Serial.print(count);
    delay(400);
  }
}
