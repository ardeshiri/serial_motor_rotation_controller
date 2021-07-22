
bool started = false;
uint32_t HB_counter_I = 0;
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
  Serial.begin(57600);
  while (!Serial);
}

void loop() {
 if (Serial.available() > 0) {
    HB_counter_I = 0;
    String str = Serial.readStringUntil('@');
    if (str.equals("query"))
    {
      Serial.println("motor_controller");
      Serial.flush();
    }
    else if (str.equals("off"))
    {
      stop_m();
      started = false;
      Serial.println("off");
      Serial.flush();
    }
    else if (str.equals("on"))
    {
      started = true;
      Serial.println("on");
      Serial.flush();
    }
    else if (started && str.equals("stp") )
    {
      stop_m();
      Serial.println("stp");
      Serial.flush();
    }
    else if (started && str.equals("fwd") )
    {
      forward_m();
      Serial.println("fwd");
      Serial.flush();
    }
    else if (started && str.equals("bwd") )
    {
      backward_m();
      Serial.println("bwd");
      Serial.flush();
    }
  }
  else
  {  
    HB_counter_I++;
    if(HB_counter_I >= 1000000)
    {
      HB_counter_I = 0;
      Serial.println("Heart_broken_stop");
      Serial.flush();
      stop_m();
    }
  }
}
