int trigPinIn=4;
int echoPinIn=3;
int trigPinOut=10;
int echoPinOut=9;
int sensor=2;
int val=0;
int count=0;

void setup()
{
  pinMode(trigPinIn, OUTPUT);
  pinMode(echoPinIn, INPUT);
  pinMode(trigPinOut, OUTPUT);
  pinMode(echoPinOut, INPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(sensor);
  
  if(val==HIGH)
  {
    delay(2000);
    
    float DurationIn, DistanceIn;
  	digitalWrite(trigPinIn, LOW);
  	delayMicroseconds(2);
  	
    digitalWrite(trigPinIn, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPinIn, LOW);
  
  	DurationIn = pulseIn(echoPinIn, HIGH);
  
  	DistanceIn =0.0034*(DurationIn/2);
  
  	float DurationOut, DistanceOut;
  	digitalWrite(trigPinOut, LOW);
  	delayMicroseconds(2);
  
  	digitalWrite(trigPinOut, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPinOut, LOW);
  
  	DurationOut = pulseIn(echoPinOut, HIGH);
  
  	DistanceOut =0.0034*(DurationOut/2);
    
    if(DistanceIn>20)
    {
      count += 1;
      Serial.print("No. of Sheeps: ");
      Serial.println(count);
    }
    
    else if(DistanceOut>20)
    {
      count -= 1;
      Serial.print("No. of Sheeps: ");
      Serial.println(count);
    }
  }
}