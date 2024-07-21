
#include <Servo.h>

Servo myservo;

String _cmd = "";

void setup() {

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

  Serial.begin(9600);

  myservo.attach(8);
}

void loop()
{
  while (Serial.available() > 0)
  {
    _cmd = _cmd + (char)Serial.read();
  }

  if (_cmd.indexOf("SET_ON_d2") >= 0)
  {
    digitalWrite(2, HIGH);

    myservo.write(120);
  }

  if (_cmd.indexOf("SET_OFF_d2") >= 0)
  {
    digitalWrite(2, LOW);

    myservo.write(30);
  }

  if (_cmd.indexOf("SET_ON_d3") >= 0)
  {
    digitalWrite(3, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d3") >= 0)
  {
    digitalWrite(3, LOW);
  }


  if (_cmd.indexOf("SET_ON_d4") >= 0)
  {
    digitalWrite(4, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d4") >= 0)
  {
    digitalWrite(4, LOW);
  }


  if (_cmd.indexOf("SET_ON_d5") >= 0)
  {
    digitalWrite(5, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d5") >= 0)
  {
    digitalWrite(5, LOW);
  }

  _cmd = "";

  delay(400);
}
