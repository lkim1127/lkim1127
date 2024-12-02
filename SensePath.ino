
// Source of PN532 example code : https://how2electronics.com/interfacing-pn532-nfc-rfid-module-with-arduino/


#include "Keyboard.h" // The Arduino Leonardo board is an Arduino board capable of keyboard input. It includes a library for keyboard input
//Library: A collection of pre-made “recipes” created by other developers to help users easily implement code
// It allows ordinary people to cook (code) using recipes (libraries) created by professional chefs (other developers). 

#include <SoftwareSerial.h> //Library for using the PN532 NFC tag reader.
#include <PN532_SWHSU.h>    //Library for using the PN532 NFC tag reader.
#include <PN532.h>          //Library for using the PN532 NFC tag reader.
SoftwareSerial SWSerial( 9, 8 ); // RX, TX
//https://docs.arduino.cc/learn/built-in-libraries/software-serial/
//  the following can be used for RX: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
PN532_SWHSU pn532swhsu( SWSerial );
PN532 nfc( pn532swhsu );
String tagId = "None", dispTag = "None"; // A string variable to store card data when the PN532 card tag reader reads a card
byte nuidPICC[4];                        // A byte array to store card data when the PN532 card tag reader reads a card


const char CARD_ID_1[]  = "4.148.173.169";
const char CARD_ID_2[]  = "67.180.228.28";
const char CARD_ID_3[]  = "35.140.31.41";
const char CARD_ID_4[]  = "147.93.44.40";
const char CARD_ID_5[]  = "3.247.11.43";
const char CARD_ID_6[]  = "51.24.203.28";
const char CARD_ID_7[]  = "4.61.215.169";
const char CARD_ID_8[]  = "3.165.110.29";
const char CARD_ID_9[]  = "83.125.105.29";
const char CARD_ID_10[] = "75.70.210.25";
const char CARD_ID_11[] = "61.26.105.107";
const char CARD_ID_12[] = "68.70.88.182";
const char CARD_ID_13[] = "96.102.50.59";
const char CARD_ID_14[] = "52.14.121.254";
const char CARD_ID_15[] = "32.141.199.59";
const char CARD_ID_16[] = "173.10.181.107";
const char CARD_ID_17[] = "107.28.222.25";
const char CARD_ID_18[] = "3.102.143.29";
const char CARD_ID_19[] = "77.92.254.107";
const char CARD_ID_20[] = "77.195.145.107";
const char CARD_ID_21[] = "93.145.121.60";
const char CARD_ID_22[] = "100.108.67.169";
const char CARD_ID_23[] = "3.205.240.28";
const char CARD_ID_24[] = "115.54.39.29";
const char CARD_ID_25[] = "160.243.197.59";
const char CARD_ID_26[] = "100.65.87.254";
const char CARD_ID_27[] = "52.50.207.169";
const char CARD_ID_28[] = "13.220.198.60";
const char CARD_ID_29[] = "164.109.206.89";
const char CARD_ID_30[] = "116.180.245.169";
const char CARD_ID_31[] = "93.147.244.60";
const char CARD_ID_32[] = "3.115.217.29";
const char CARD_ID_33[] = "91.142.221.25";
const char CARD_ID_34[] = "116.76.197.206";
const char CARD_ID_35[] = "71.97.164.180";
const char CARD_ID_36[] = "93.3.143.60";
const char CARD_ID_37[] = "51.23.82.29";
const char CARD_ID_38[] = "83.105.199.29";
const char CARD_ID_39[] = "148.172.252.169";
const char CARD_ID_40[] = "116.175.154.182";
const char CARD_ID_41[] = "52.3.220.182";
const char CARD_ID_42[] = "3.72.142.21";
const char CARD_ID_43[] = "61.91.172.107";
const char CARD_ID_44[] = "100.163.12.176";
const char CARD_ID_45[] = "51.27.85.29";
const char CARD_ID_46[] = "38.8.56.169";
const char CARD_ID_47[] = "29.241.249.107";
const char CARD_ID_48[] = "109.250.199.60";
const char CARD_ID_49[] = "176.178.36.59";
const char CARD_ID_50[] = "155.238.19.26";
const char CARD_ID_51[] = "29.169.246.107";
const char CARD_ID_52[] = "43.92.242.25";
const char CARD_ID_53[] = "45.185.207.107";
const char CARD_ID_54[] = "61.106.136.107";
const char CARD_ID_55[] = "36.122.225.206";
const char CARD_ID_56[] = "4.113.211.169";
const char CARD_ID_57[] = "32.183.189.59";
const char CARD_ID_58[] = "36.115.255.182";
const char CARD_ID_59[] = "115.207.239.28";
const char CARD_ID_60[] = "3.254.253.28";
const char CARD_ID_61[] = "77.203.34.60";
const char CARD_ID_62[] = "3.225.42.29";
const char CARD_ID_63[] = "80.204.62.59";
const char CARD_ID_64[] = "107.17.25.26";
const char CARD_ID_65[] = "36.188.115.169";
const char CARD_ID_66[] = "37.175.115.252";
const char CARD_ID_67[] = "37.254.203.171";
const char CARD_ID_68[] = "29.20.146.107";
const char CARD_ID_69[] = "67.166.241.28";
const char CARD_ID_70[] = "61.29.135.107";


const char CARD_ID_RESET1[] = "211.130.36.45";
const char CARD_ID_RESET2[] = "115.63.173.29";

void setup(void)
{
  Serial.begin(115200); // The function to start Serial communication in order to check the variables and status inside the Arduino through the Serial Monitor.
  delay(1000);          // 1 second delay 
  Serial.println("ASD EDU SYSTEM KIT 2024");
  delay(1000);

  // Initializing the PN532 card reader (Initialization process). 
  SWSerial.begin(9600); // Initialization command for using the PN532 module.
  nfc.begin();          // Command to initiate communication between the PN532 module and Arduino.
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata){
    Serial.print("Didn't Find PN53x Module");
    while (1); // Halt
  }
  // Got valid data, print it out!
  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); 
  Serial.println((versiondata >> 8) & 0xFF, DEC);
  // Configure board to read RFID tags
  nfc.SAMConfig(); 

  Keyboard.begin(); // 아두이노 레오나르도가 키보드처럼 작동하기 위해서 관련 시작함수 실행

  pinMode(3, OUTPUT); //카드 태그 시 삑 거리는 수동부저(Passive Buzzer)를 아두이노 디지털 3 번에 연결

  for( int i = 0; i<3; i++){
    tone(3, 800); //수동부저(Passive Buzzer)를 800 Hz 로 소리를 발생함. 
    delay(200);
    noTone(3);    //수동부저(Passive Buzzer)의 소리를 끔
    delay(200);
  }
}
 
 
void loop()
{
  readNFC(); //  PN532 리더기를 통해서 실시간 태그 되는 카드의 여부 확인 / 카드가 태그 되면 내부 UID 를 읽어 처리하도록 반복 함수 수행
}
 
 
void readNFC()
{
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                       // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
  if (success) //만약 PN532 카드 리더기가 카드를 인식한 경우에 실행되는 조건문
  {
    Serial.print("UID Length: ");
    Serial.print(uidLength, DEC);
    Serial.println(" bytes");
    Serial.print("UID Value: ");
    
    for (uint8_t i = 0; i < 4; i++)
    {
      nuidPICC[i] = uid[i];
      Serial.print(" "); Serial.print(nuidPICC[i], DEC);
    }
    Serial.println();

    tagId = "";
    tagId = String(nuidPICC[0]);  tagId += '.';
    tagId += String(nuidPICC[1]); tagId += '.';
    tagId += String(nuidPICC[2]); tagId += '.';
    tagId += String(nuidPICC[3]);
    Serial.print(F("tagId is : "));
    Serial.println(tagId); //PN532 를 통해서 카드 내부의 UID 가 읽어지면 xxx.xxx.xxx.xxxx 형태로 tagId라는 변수에 데이터 저장
    Serial.println("");
    
    // 리더기가 수신한 카드 고유값(UID) 와 사전에 Mapping 된 UID 의 일치 여부를 검사함.
    // 일치하게 되면 ( equals 가 -1 이 아니게 되면 ) 특정 카드의 번호 및 키보드 출력 이벤트를 발생
    // 예) 리더기가 리딩한 카드의 번호가 51 번 이라고 하면, 아두이노 레오나르도는 " 5 1 Enter " 를 키보드 출력함. 
    //      해당 키보드 입력을 통해 파워포인트의 특정 슬라이드로 이동할 수 있도록 함. 
     
    tone(3, 800); //수동부저(Passive Buzzer)를 800 Hz 로 소리를 발생함. 
    delay(200);
    noTone(3);    //수동부저(Passive Buzzer)의 소리를 끔
    if(  tagId.equals( String(CARD_ID_1 ))){
      Serial.println("CARD1");
      Keyboard.print("2");          //키보드 숫자 2 입력 후 (표지장 때문에 카드 UID 보다 1 큰 숫자 입력)
      Keyboard.write(KEY_RETURN);   //키보드 엔터 입력
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_2 ))){
      Serial.println("CARD2");
      Keyboard.print("3");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_3 ))){
      Serial.println("CARD3");
      Keyboard.print("4");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_4 ))){
      Serial.println("CARD4");
      Keyboard.print("5");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_5 ))){
      Serial.println("CARD5");
      Keyboard.print("6");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_6 ))){
      Serial.println("CARD6");
      Keyboard.print("7");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_7 ))){
      Serial.println("CARD7");
      Keyboard.print("8");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_8 ))){
      Serial.println("CARD8");
      Keyboard.print("9");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_9 ))){
      Serial.println("CARD9");
      Keyboard.print("10");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_10 ))){
      Serial.println("CARD10");
      Keyboard.print("11");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_11 ))){
      Serial.println("CARD11");
      Keyboard.print("12");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_12 ))){
      Serial.println("CARD12");
      Keyboard.print("13");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_13 ))){
      Serial.println("CARD13");
      Keyboard.print("14");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_14 ))){
      Serial.println("CARD14");
      Keyboard.print("15");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_15 ))){
      Serial.println("CARD15");
      Keyboard.print("16");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_16 ))){
      Serial.println("CARD16");
      Keyboard.print("17");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll();       
    }
    else if( tagId.equals( String(CARD_ID_17 ))){
      Serial.println("CARD17");
      Keyboard.print("18");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_18 ))){
      Serial.println("CARD18");
      Keyboard.print("19");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_19 ))){
      Serial.println("CARD19");
      Keyboard.print("20");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_20 ))){
      Serial.println("CARD20");
      Keyboard.print("21");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_21 ))){
      Serial.println("CARD21");
      Keyboard.print("22");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_22 ))){
      Serial.println("CARD22");
      Keyboard.print("23");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_23 ))){
      Serial.println("CARD23");
      Keyboard.print("24");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_24 ))){
      Serial.println("CARD24");
      Keyboard.print("25");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_25 ))){
      Serial.println("CARD25");
      Keyboard.print("26");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_26 ))){
      Serial.println("CARD26");
      Keyboard.print("27");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_27 ))){
      Serial.println("CARD27");
      Keyboard.print("28");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_28 ))){
      Serial.println("CARD28");
      Keyboard.print("29");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_29 ))){
      Serial.println("CARD29");
      Keyboard.print("30");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_30 ))){
      Serial.println("CARD30");
      Keyboard.print("31");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_31 ))){
      Serial.println("CARD31");
      Keyboard.print("32");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_32 ))){
      Serial.println("CARD32");
      Keyboard.print("33");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_33 ))){
      Serial.println("CARD33");
      Keyboard.print("34");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_34 ))){
      Serial.println("CARD34");
      Keyboard.print("35");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_35 ))){
      Serial.println("CARD35");
      Keyboard.print("36");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_36 ))){
      Serial.println("CARD36");
      Keyboard.print("37");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_37 ))){
      Serial.println("CARD37");
      Keyboard.print("38");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_38 ))){
      Serial.println("CARD38");
      Keyboard.print("39");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_39 ))){
      Serial.println("CARD39");
      Keyboard.print("40");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_40 ))){
      Serial.println("CARD40");
      Keyboard.print("41");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_41 ))){
      Serial.println("CARD41");
      Keyboard.print("42");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_42 ))){
      Serial.println("CARD42");
      Keyboard.print("43");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_43 ))){
      Serial.println("CARD43");
      Keyboard.print("44");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_44 ))){
      Serial.println("CARD44");
      Keyboard.print("45");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_45 ))){
      Serial.println("CARD45");
      Keyboard.print("46");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_46 ))){
      Serial.println("CARD46");
      Keyboard.print("47");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_47  ))){
      Serial.println("CARD47");
      Keyboard.print("48");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_48 ))){
      Serial.println("CARD48");
      Keyboard.print("49");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_49 ))){
      Serial.println("CARD49");
      Keyboard.print("50");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_50 ))){
      Serial.println("CARD50");
      Keyboard.print("51");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_51 ))){
      Serial.println("CARD51");
      Keyboard.print("52");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_52 ))){
      Serial.println("CARD52");
      Keyboard.print("53");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_53 ))){
      Serial.println("CARD53");
      Keyboard.print("54");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_54 ))){
      Serial.println("CARD54");
      Keyboard.print("55");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_55 ))){
      Serial.println("CARD55");
      Keyboard.print("56");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_56 ))){
      Serial.println("CARD56");
      Keyboard.print("57");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_57 ))){
      Serial.println("CARD57");
      Keyboard.print("58");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_58 ))){
      Serial.println("CARD58");
      Keyboard.print("59");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_59 ))){
      Serial.println("CARD59");
      Keyboard.print("60");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_60 ))){
      Serial.println("CARD60");
      Keyboard.print("61");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_61 ))){
      Serial.println("CARD61");
      Keyboard.print("62");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_62 ))){
      Serial.println("CARD62");
      Keyboard.print("63");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_63 ))){
      Serial.println("CARD63");
      Keyboard.print("64");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_64 ))){
      Serial.println("CARD64");
      Keyboard.print("65");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_65 ))){
      Serial.println("CARD65");
      Keyboard.print("66");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_66 ))){
      Serial.println("CARD66");
      Keyboard.print("67");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_67 ))){
      Serial.println("CARD67");
      Keyboard.print("68");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_68 ))){
      Serial.println("CARD68");
      Keyboard.print("69");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_69 ))){
      Serial.println("CARD69");
      Keyboard.print("70");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_70 ))){
      Serial.println("CARD70");
      Keyboard.print("71");
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_RESET1 ))){
      Serial.println("CARD7_RESET");
      Keyboard.print("1"); // 교육을 초기 상태로 설정하는 카드
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    }
    else if( tagId.equals( String(CARD_ID_RESET2 ))){
      Serial.println("CARD7_RESET");
      Keyboard.print("1"); // 교육을 초기 상태로 설정하는 카드
      Keyboard.write(KEY_RETURN);  
      delay(1);
      Keyboard.releaseAll(); 
    } 
    
    delay(1000);
  }
  
  {
    Serial.println("Timed out! Waiting for a card...");
  }
} 
