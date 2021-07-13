
bool started = false;

void stop_m()
{
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
}

void forward_m()
{
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
}

void backward_m()
{
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
}


void setup() {
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  stop_m();
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
 if (Serial.available() > 0) {
    String str = Serial.readStringUntil('@');
    if (str.equals("off"))
    {
      stop_m();
      Serial.println("motor_controller off");
      started = false;
      delay(100);
    }
    
    if (str.equals("on"))
    {
      Serial.println("motor_controller on");
      started = true;
      delay(100);
    }
    
    if (started && str.equals("stop") )
    {
      stop_m();
    }
      
    if (started && str.equals("forwards") )
    {
      forward_m();
    }
    
    if (started && str.equals("backwards") )
    {
      backward_m();
    }
  } 
}
