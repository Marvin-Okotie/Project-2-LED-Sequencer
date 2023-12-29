// Sets pins and Values for potentiometers and LED's
int Leds[] = {9, 8, 7, 6, 5, 4, 3, 2};
int pot1 = A1;
int pot0 = A0;
int pot0value = 0;
int pot1value = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(pot1, INPUT); // Sets potentiometers as input
 pinMode(pot0, INPUT);
 Serial.begin(9600); // Starts serial communication
 for (int i = 0; i < 8; i += 1) { 
   pinMode(Leds[i],OUTPUT); //Sets all the leds as output
}
}

void loop() {
  // put your main code here, to run repeatedly:
  pot0value = analogRead(pot0); //Gets actual potentiometer value
  pot1value = analogRead(pot1);
  Serial.println(pot0value);
  Serial.println(pot1value);
//If statement to let pot 0 be able to choose which sequence to run
  if (pot0value < 341){
    sequence1();
  }
  else if (pot0value >= 341 && pot0value < 682){
    sequence2();
  }
  else if (pot0value > 682){
    sequence3();
  }
}

void sequence1(){ //Code for sequence 1
  pot1value = analogRead(pot1); //redefines pot1value within the sequence(Repeated on all sequences)
  Serial.println(pot1value);
  int range = pot1value/128; // splits the pot1value into 8 seperate ranges and asigns each LED each range respectively(Repeated on all sequences)
  for (int i = 0; i < 8; i++) {
    digitalWrite(Leds[i], i != range); //Turns on all led's that are not in the specified range if the potentiometer
  }
}  

void sequence2() { //Code for sequence 2 
  pot1value = analogRead(pot1);
  Serial.println(pot1value);
  int range = pot1value/128; // splits the pot1value into 8 seperate ranges and asigns each LED each range respectively
  for (int i = 0; i < 8; i++) {
    digitalWrite(Leds[i], i <= range); // Turns on and LEAVES ON all Led's in the set potentiometer range
  }
}
void sequence3() { //Code for sequence 3
  pot1value = analogRead(pot1);
  Serial.println(pot1value);
  int range = pot1value/128;
  for (int i = 0 ; i < 8; i += 1) 
  if (i == range ||  i == range - 2){ 
    digitalWrite ,(Leds[i], HIGH); 
  }
  else {
    digitalWrite(Leds[i], LOW);
  }
}