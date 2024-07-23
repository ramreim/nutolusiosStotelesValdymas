
//https://jawhersebai.com/tutorials/how-to-use-the-sg90-servo-motor/


int timer_cycle_actual = 0;

int analog_val = 0;

int perskaiciuota = 190;

int pasikeitimo_taimeris = 0;

int isvesta = 0;


bool mygtukas_dabar = false;
bool mygtukas_prev = false;



String _cmd = "";

void setup() {

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
  if (timer_cycle_actual == perskaiciuota && pasikeitimo_taimeris < 9)
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

    pasikeitimo_taimeris = 0;


    digitalWrite(2, HIGH);

    perskaiciuota = 180;


  }

  if (_cmd.indexOf("SET_OFF_d2") >= 0)
  {

    pasikeitimo_taimeris = 0;

    digitalWrite(2, LOW);

    perskaiciuota = 190;


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

  if (isvesta < 300)
  {
    //Serial.println(isvesta);

    isvesta++;

  }


  Serial.println(pasikeitimo_taimeris);

  if (pasikeitimo_taimeris < 15)
  {
    pasikeitimo_taimeris++;
  }


  if (pasikeitimo_taimeris > 9)
  {
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(4, LOW);

  }



  delay(400);

}
