#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! 
#endif

BluetoothSerial SerialBT;

int led = 2;           //Conected to pin 2. Output. Built in led
int sound_digital = 0; //Conected to pin 0. Input
int sound_analog = 4;  //Conected to pin 4. Input

void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(sound_digital, INPUT);
  delay(3000);
  Serial.println("Starting BT...");
  SerialBT.begin("MyESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");  
}

void loop(){
  
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  Serial.print(val_analog);
  Serial.print("\t");
  Serial.println(val_digital);

  if (val_digital == HIGH)
  { 
    if (Serial.available()) {
      SerialBT.println("Sound Detected");;
    }
    
    digitalWrite (led, HIGH);
    delay(500);
    }
  else
  {
    digitalWrite (led, LOW);
    }

}
