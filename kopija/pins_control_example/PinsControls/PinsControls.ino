


//https://www.instructables.com/Simplest-Arduino-GUI-in-C/
//C# Arduino GUI to Control the LED


//D:\pc_07_1tb_ssd\programming\Arduino\arduino_projektai_002\socket_w5100_client_001
//D:\pc_07_1tb_ssd\programming\c_cpp_csharp\vs2015projects\SendCommandsToArduino
//D:\pc_07_1tb_ssd\programming\c_cpp_csharp\vs2015projects\SendCommandsToArduino\SendCommandsToArduino



//CMD SET ON d5
//CMD SET OFF d5

//CMD SET ON d6
//CMD SET OFF d6

//CMD SET ON d7
//CMD SET OFF d7


//CMD_SET_ON_d5
//CMD_SET_OFF_d5

//CMD_SET_ON_d6
//CMD_SET_OFF_d6

//CMD_SET_ON_d7
//CMD_SET_OFF_d7











String _cmd = "";

void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

  Serial.begin(9600);
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
  }
  
  if (_cmd.indexOf("SET_OFF_d2") >= 0)
  {
    digitalWrite(2, LOW);
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

  /*
    char receiveVal;

    if (Serial.available() > 0)
    {
      receiveVal = Serial.read();

      if (receiveVal == '1')
        digitalWrite(2, HIGH);
      if (receiveVal == '2')
        digitalWrite(2, LOW);

      if (receiveVal == '3')
        digitalWrite(3, HIGH);
      if (receiveVal == '4')
        digitalWrite(3, LOW);

      if (receiveVal == '5')
        digitalWrite(4, HIGH);
      if (receiveVal == '6')
        digitalWrite(4, LOW);

      if (receiveVal == '7')
        digitalWrite(5, HIGH);
      if (receiveVal == '8')
        digitalWrite(5, LOW);
    }

  */

 _cmd = "";

  delay(400);

  
}
