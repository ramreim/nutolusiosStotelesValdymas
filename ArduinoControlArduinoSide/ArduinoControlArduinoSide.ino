
//https://jawhersebai.com/tutorials/how-to-use-the-sg90-servo-motor/

//197
//173

#include "Constants.h"

int timer_cycle_actual = 0;

int _sp = 0;

int CycleCounterAfterLastReceivedCommand = 0;

int _printedToSerialPort = 0;

String _cmd = "";

void setup() {

  _sp = RELEASE;

  pinMode(LED_02_PIN, OUTPUT);

  pinMode(LED_03_PIN, OUTPUT);

  pinMode(LED_04_PIN, OUTPUT);

  pinMode(LED_05_PIN, OUTPUT);

  pinMode(MOTOR_CONTROL_09_PIN, OUTPUT);

  digitalWrite(LED_02_PIN, LOW);

  digitalWrite(LED_03_PIN, LOW);

  digitalWrite(LED_04_PIN, LOW);

  digitalWrite(LED_05_PIN, LOW);

  digitalWrite(MOTOR_CONTROL_09_PIN, LOW);

  Serial.begin(9600);

  cli();

  TCCR1A = 0;

  TCCR1B = 0;

  TCNT1 = 0;

  OCR1A = 24;

  TCCR1B |= (1 << WGM12);

  TCCR1B |= (1 << CS11) | (1 << CS10);

  TIMSK1 |= (1 << OCIE1A);

  sei();
}

ISR(TIMER1_COMPA_vect)
{
  timer_cycle_actual++;

  if (timer_cycle_actual == _sp && CycleCounterAfterLastReceivedCommand < 9)
  {
    digitalWrite(MOTOR_CONTROL_09_PIN, HIGH);
  }

  if (timer_cycle_actual >= 200)
  {
    digitalWrite(MOTOR_CONTROL_09_PIN, LOW);

    timer_cycle_actual = 0;
  }
}

void loop()
{
  while (Serial.available() > 0)
  {
    _cmd = _cmd + (char)Serial.read();
  }

  if (_cmd.indexOf("SET_ON_d2") >= 0)
  {
    CycleCounterAfterLastReceivedCommand = 0;

    digitalWrite(LED_02_PIN, HIGH);

    _sp = PUSH;
  }

  if (_cmd.indexOf("SET_OFF_d2") >= 0)
  {
    CycleCounterAfterLastReceivedCommand = 0;

    digitalWrite(LED_02_PIN, LOW);

    _sp = RELEASE;
  }

  if (_cmd.indexOf("SET_ON_d3") >= 0)
  {
    digitalWrite(LED_03_PIN, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d3") >= 0)
  {
    digitalWrite(LED_03_PIN, LOW);
  }

  if (_cmd.indexOf("SET_ON_d4") >= 0)
  {
    //digitalWrite(LED_04_PIN, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d4") >= 0)
  {
    //digitalWrite(LED_04_PIN, LOW);
  }

  if (_cmd.indexOf("SET_ON_d5") >= 0)
  {
    digitalWrite(LED_05_PIN, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d5") >= 0)
  {
    digitalWrite(LED_05_PIN, LOW);
  }

  _cmd = "";

  if (_printedToSerialPort < 300)
  {
    Serial.println(_printedToSerialPort);

    _printedToSerialPort++;
  }

  Serial.println(CycleCounterAfterLastReceivedCommand);

  if (CycleCounterAfterLastReceivedCommand < 15)
  {
    CycleCounterAfterLastReceivedCommand++;
  }

  if (CycleCounterAfterLastReceivedCommand > 9)
  {
    digitalWrite(LED_04_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_04_PIN, LOW);
  }

  delay(400);
}
