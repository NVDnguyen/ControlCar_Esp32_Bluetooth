#include <Arduino.h>

String device_name = "ESP32-NVD";
bool transVMode = false;
bool serialMode = false;
BluetoothSerial SerialBT;

const int EN_A = 13;
const int IN1_A = 14;
const int IN2_A = 12;

const int IN1_B = 27;
const int IN2_B = 26;
const int EN_B = 25;

void bluProcessor();

void setup() {

  Serial.begin(115200);
  SerialBT.begin(device_name);  // Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());

  pinMode(EN_A, OUTPUT);
  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);

  pinMode(IN1_B, OUTPUT);
  pinMode(IN2_B, OUTPUT);
  pinMode(EN_B, OUTPUT);

  analogWrite(EN_A, 0);
  analogWrite(EN_B, 0);
}

void loop() {
  bluProcessor();
  delay(20);
}

void bluProcessor() {
  if (SerialBT.available()) {
    String receivedMessage = SerialBT.readStringUntil(';');

    if (transVMode) {
      SerialBT.println("Your response in transVMode");
      // Process your response for transVMode here
      transVMode = false;
    }
    if (serialMode) {
      // this mode send data to your app
      SerialBT.write(101);
      serialMode = false;
    }

    if (receivedMessage.equals("vmode") && !serialMode && !transVMode) {
      Serial2.flush();
      transVMode = true;
    } else if (receivedMessage.equals("srmode") && !serialMode && !transVMode) {
      serialMode = true;
    } else if (receivedMessage.indexOf(':') >= 0 && !transVMode && !serialMode) {
      String angleStr = receivedMessage.substring(0, receivedMessage.indexOf(':'));
      int angle = angleStr.toInt();

      if (angle == 0) {
        stop();
        Serial.println("stop");
      } else if (angle > 82 && angle < 100) {
        forward();
        Serial.println("forward");
      } else if (angle > 98 || angle < -111) {
        turnRight();
        Serial.println("turn right");

      } else if (angle < 82 && angle > -70) {
        turnLeft();
        Serial.println("turn left");
      } else if (angle > -111 && angle < -70) {
        backward();
        Serial.println("backward");
      }
    }
  }
}

void stop() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, LOW);
  analogWrite(EN_A, 0);

  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, LOW);
  analogWrite(EN_B, 0);
}

void forward() {
  digitalWrite(IN1_A, HIGH);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);

  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
}

void backward() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, HIGH);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);

  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
}

void turnLeft() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, HIGH);
  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);

  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
}

void turnRight() {
  digitalWrite(IN1_A, HIGH);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);

  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
}
