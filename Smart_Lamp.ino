int Buzzer = 10; // choose the pin for the Buzzer
int inputPin = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int ledPin = 13;
 

int buzzer = 9;
int redLed = 13;
void setup() {
  // put your setup code here, to run once:
  BUZZ_setup();
  LED_setup() ;
  PIR_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  BUZZ_loop();
  LED_loop() ;
  PIR_loop();
}

void BUZZ_setup()
{
// initialize digital pin 13 as an output.
pinMode(5,OUTPUT );
pinMode(2, INPUT);
pinMode(redLed, OUTPUT);
}
void BUZZ_loop()
{
if( digitalRead(2)==LOW)
{
digitalWrite(redLed, HIGH);
digitalWrite(5, HIGH);
delay(1000);
}
else
{
digitalWrite(redLed, LOW);   
digitalWrite(5, LOW);
}
}
void LED_setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(11, OUTPUT);//OUTPUT DEVICE THAT AT POT 11

}
void LED_loop() {
  // put your main code here, to run repeatedly:
  float sensorValue= analogRead(A0);

    Serial.println
    (sensorValue);
  if (sensorValue>= 400){
    digitalWrite(11, HIGH);
  }
  else {
    digitalWrite(11 , LOW);
  }
}

void PIR_setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(Buzzer, OUTPUT); // declare Buzzer as output
  pinMode(inputPin, INPUT); // declare sensor as input
   
  Serial.begin(9600);
}

void PIR_loop(){
  val = digitalRead(inputPin); // read input value
  
  if (val == HIGH) { // check if the input is HIGH
    digitalWrite(ledPin, HIGH); // turn LED ON
    digitalWrite(Buzzer, 1); // turn Buzzer ON
    delay(100);
    digitalWrite(Buzzer, 0);
    delay(50);
    digitalWrite(Buzzer, 1); // turn Buzzer ON
    delay(100);
    digitalWrite(Buzzer, 0);
    delay(100);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    digitalWrite(Buzzer, 0); // turn Buzzer OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
