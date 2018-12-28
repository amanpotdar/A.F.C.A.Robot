

const int pingPin = 7; 
// Trigger Pin of Ultrasonic Sensor
const int echoPin = 6;
 // Echo Pin of Ultrasonic Sensor
int in1=8;

int in2=9;

int in3=10;

int in4=11;

void setup() {
  pinMode(in1, OUTPUT);
 
 pinMode(in2, OUTPUT);
 
 pinMode(in3, OUTPUT);

  pinMode(in4, OUTPUT);
  
 Serial.begin(9600); 
// Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
 
  pinMode(pingPin, OUTPUT);
  
 digitalWrite(pingPin, LOW);
 
  delayMicroseconds(2);
  
 digitalWrite(pingPin, HIGH);
  
 delayMicroseconds(10);

   digitalWrite(pingPin, LOW);
  
 pinMode(echoPin, INPUT);

   duration = pulseIn(echoPin, HIGH);
  
 inches = microsecondsToInches(duration);

   cm = microsecondsToCentimeters(duration);
  
 Serial.print(inches);
   Serial.print("in, ");
 
  Serial.print(cm);
   Serial.print("cm");
 
  Serial.println();
   delay(100);
 
 if(cm<=15){
  digitalWrite(in1,HIGH);
 
  digitalWrite(in2,LOW);
 
   digitalWrite(in3,HIGH);
 
   digitalWrite(in4,HIGH);
  }
 
 else{
   
 digitalWrite(in1,HIGH);
   
digitalWrite(in2,LOW);
  
  digitalWrite(in3,HIGH);
  
  digitalWrite(in4,LOW);
  }

 
  
}


long microsecondsToInches(long microseconds) {
  
 return microseconds / 74 / 2;
}


long microsecondsToCentimeters(long microseconds) {
  
 return microseconds / 29 / 2;

}
