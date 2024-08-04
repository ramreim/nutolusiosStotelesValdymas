
//https://jawhersebai.com/tutorials/how-to-use-the-sg90-servo-motor/

//197
//173

#include "Constants.h"

int timer_cycle_actual = 0;

unsigned int NeedToCheckReceivedDataInSerialPortCycleCounter = 0;

unsigned int NeedToPrintDataToSerialPortForUserCounter = 0;

int _sp = 0;

int CycleCounterAfterLastReceivedCommand = 0;

String _cmd = "";

void setup() {

  _sp = RELEASE;

  pinMode(LED_02_PIN, OUTPUT);

  pinMode(LED_03_PIN, OUTPUT);

  pinMode(LED_04_PIN, OUTPUT);

  pinMode(LED_05_PIN, OUTPUT);

  pinMode(MOTOR_CONTROL_09_PIN, OUTPUT);

  digitalWrite(LED_02_PIN, HIGH);

  digitalWrite(LED_03_PIN, HIGH);

  digitalWrite(LED_04_PIN, LOW);

  digitalWrite(LED_05_PIN, LOW);

  digitalWrite(MOTOR_CONTROL_09_PIN, LOW);

  NeedToCheckReceivedDataInSerialPortCycleCounter = 0;

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

  if (NeedToCheckReceivedDataInSerialPortCycleCounter < 11000)
    NeedToCheckReceivedDataInSerialPortCycleCounter++;

  if (NeedToPrintDataToSerialPortForUserCounter < 100005)
    NeedToPrintDataToSerialPortForUserCounter++;
}

void loop()
{
  if (NeedToCheckReceivedDataInSerialPortCycleCounter > 3000)
  {
    while (Serial.available() > 0)
    {
      _cmd = _cmd + (char)Serial.read();
    }

    if (_cmd.indexOf("SET_ON_d2") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;

      digitalWrite(LED_02_PIN, LOW);

      _sp = PUSH;
    }

    if (_cmd.indexOf("SET_OFF_d2") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;

      digitalWrite(LED_02_PIN, HIGH);

      _sp = RELEASE;
    }

    if (_cmd.indexOf("SET_ON_d3") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;
      
      digitalWrite(LED_03_PIN, LOW);
    }

    if (_cmd.indexOf("SET_OFF_d3") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;
      
      digitalWrite(LED_03_PIN, HIGH);
    }

    if (_cmd.indexOf("SET_ON_d4") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;
      
      //digitalWrite(LED_04_PIN, HIGH);
    }

    if (_cmd.indexOf("SET_OFF_d4") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;
      
      //digitalWrite(LED_04_PIN, LOW);
    }

    if (_cmd.indexOf("SET_ON_d5") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;
      
      digitalWrite(LED_05_PIN, HIGH);
    }

    if (_cmd.indexOf("SET_OFF_d5") >= 0)
    {
      CycleCounterAfterLastReceivedCommand = 0;
      
      digitalWrite(LED_05_PIN, LOW);
    }

    _cmd = "";

    NeedToCheckReceivedDataInSerialPortCycleCounter = 0;

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
  }

  if (NeedToCheckReceivedDataInSerialPortCycleCounter > 200000)
  {
    NeedToCheckReceivedDataInSerialPortCycleCounter = 0;
  }



  if (NeedToPrintDataToSerialPortForUserCounter > 5000)
  {
    Serial.println("CycleCounterAfterLastReceivedCommand = " + String(CycleCounterAfterLastReceivedCommand));

    Serial.println("NeedToCheckReceivedDataInSerialPortCycleCounter = " + String(NeedToCheckReceivedDataInSerialPortCycleCounter));

    Serial.println("NeedToPrintDataToSerialPortForUserCounter = " + String(NeedToPrintDataToSerialPortForUserCounter));

    NeedToPrintDataToSerialPortForUserCounter = 0;
  }



  //delay(400);
}
