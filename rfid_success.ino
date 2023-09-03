#define SS_PIN  10 //D2
#define RST_PIN 5 //D1
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(SS_PIN, RST_PIN);   
int variable = 0;
void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();  // Initiate  SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522
  Serial.println("Show your card:");
  
void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content = " ";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "A3 E0 1E 02") //change UID of the card that you want to give access
  {
    Serial.println(" unlock ");
    Serial.println(" Welcome ram ");
    Serial.println(" enjoy your day ");
    Serial.println(" thank you ");
    Serial.println();
    delay(1000);
  }
  content.toUpperCase();
  if (content.substring(1) == "49 DC 65 D5") //change UID of the card that you want to give access
  {
    Serial.println(" unlock ");
    Serial.println(" Welcome vIP");    
    Serial.println(" enjoy your day ");
    Serial.println(" thank you ");
    Serial.println();
    delay(1000);
  }
}
