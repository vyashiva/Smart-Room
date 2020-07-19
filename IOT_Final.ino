#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temp;
int dht_apin=A1;
dht DHT;

//#define fan 9


// defines pins numbers ultrasonic sensor.
const int trigPin = 9;
const int echoPin = 10;

// defines pins numbers motors.
const int motor = 8;

// defines variables
long duration;
int distance;

void setup() {

   
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
       pinMode(echoPin, INPUT); // Sets the echoPin as an Input

       pinMode(motor, OUTPUT); // Sets the Motor as an Output

      Serial.begin(9600); // Starts the serial        communication
      //pinMode (fan, OUTPUT);

  lcd.begin(16,3);

  lcd.setCursor(3,0);
  lcd.print("IOT PROJECT");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("MCA SCIENCE");
  delay(1000);
  lcd.clear();
  lcd.print("Guided By..");
   lcd.setCursor(0,1);
  lcd.print("Dr.C.H.Patil Sir");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("SMART");
  lcd.setCursor(8,1);
  lcd.print("ROOM");
  delay(2000);
  lcd.clear();

  }


void loop()
{
  DHT.read11(dht_apin);
       lcd.setCursor(3,0);
  lcd.print("Recording");
  lcd.setCursor(2,1);
  lcd.print("Temperature...");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,2);
  temp=DHT.temperature;
  Serial.print("Current Humidity = ");
  Serial.print(DHT.humidity);
  
  //temp = analogRead(tempPin);
  //temp = temp * 0.48828125;
  lcd.setCursor(0 ,0);
  lcd.print("Temperature = ");
  lcd.setCursor(5 ,1);
  lcd.print(temp);
  delay(3000);
  lcd.clear();

//Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if(distance < 30 && temp>18){
   digitalWrite(motor, HIGH);
    lcd.print("FAN ON..... ");
    delay(2000);
    lcd.clear();}
  else if(distance<20 && temp<17 ){
     digitalWrite(motor, LOW);   
      lcd.print("FAN OFF...");
             delay(2000);
    lcd.clear();}
    else{
    analogWrite(motor, LOW);  
    lcd.print("FAN OFF...");
    delay(2000);
    lcd.clear();}
    }
  
