
//https://jawhersebai.com/tutorials/how-to-use-the-sg90-servo-motor/

int timer_cycle_actual = 0;

const int _release = 185;

const int _push = 190;

int _sp = 0;

int CycleCounterAfterLastReceivedCommand = 0;

int _printedToSerialPort = 0;

String _cmd = "";

void setup() {

  _sp = _release;

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

  pinMode(9, OUTPUT);

  digitalWrite(9, LOW);

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

  /*
    if (timer_cycle_actual >= 10000)
    {
    Serial.println("safd");

    timer_cycle_actual = 0;

    }
  */
  //197
  //173
  if (timer_cycle_actual == _sp && CycleCounterAfterLastReceivedCommand < 9)
  {
    digitalWrite(9, HIGH);
  }

  //if (timer_cycle_actual == 19)
  //{
  //digitalWrite(9, LOW);
  //}

  if (timer_cycle_actual >= 200)
  {
    digitalWrite(9, LOW);

    timer_cycle_actual = 0;

    //Serial.println("safd");
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

    digitalWrite(2, HIGH);

    _sp = _push;
  }

  if (_cmd.indexOf("SET_OFF_d2") >= 0)
  {
    CycleCounterAfterLastReceivedCommand = 0;

    digitalWrite(2, LOW);

    _sp = _release;
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
    //digitalWrite(4, HIGH);
  }

  if (_cmd.indexOf("SET_OFF_d4") >= 0)
  {
    //digitalWrite(4, LOW);
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
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(4, LOW);
  }

  delay(400);
}
