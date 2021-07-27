#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! 
#endif

BluetoothSerial SerialBT;

int led = 2;           //Conected to pin 2. Output. Built in led

//Mic 1
int sound_digital_1 = 0; //Conected to pin 0. Input
int sound_analog_1 = 4;  //Conected to pin 4. Input

//Mic 2
int sound_digital_2 = 36; //Conected to pin 36. Input
int sound_analog_2 = 39;  //Conected to pin 39. Input

//Mic 3
int sound_digital_3 = 34; //Conected to pin 34. Input
int sound_analog_3 = 35;  //Conected to pin 35. Input

//Mic 4
int sound_digital_4 = 32; //Conected to pin 32. Input
int sound_analog_4 = 33;  //Conected to pin 33. Input


void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(sound_digital_1, INPUT);
  pinMode(sound_digital_2, INPUT);
  pinMode(sound_digital_3, INPUT);
  pinMode(sound_digital_4, INPUT);
  
  delay(3000);
  Serial.println("Starting BT...");
  SerialBT.begin("MyESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");  
}

void loop(){
  
  int val_digital_1 = digitalRead(sound_digital_1);
  int val_analog_1 = analogRead(sound_analog_1);

  int val_digital_2 = digitalRead(sound_digital_2);
  int val_analog_2 = analogRead(sound_analog_2);

  int val_digital_3 = digitalRead(sound_digital_3);
  int val_analog_3 = analogRead(sound_analog_3);

  int val_digital_4 = digitalRead(sound_digital_4);
  int val_analog_4 = analogRead(sound_analog_4);

  //Serial.print(val_analog);
  //Serial.print("\t");
  //Serial.println(val_digital);

  if ( (val_digital_1 == HIGH)||(val_digital_2 == HIGH)||(val_digital_3 == HIGH)||(val_digital_4 == HIGH) )
  { 
    if (Serial.available()) {
      SerialBT.println("Sound Detected"); //Detection message send via bluetooth
    }
    
    digitalWrite (led, HIGH);
    delay(500);
    }
  else
  {
    digitalWrite (led, LOW);
    }

}
