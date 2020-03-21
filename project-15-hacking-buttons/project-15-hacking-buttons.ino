const int optoPin1 = 2;
const int optoPin2 = 12;

unsigned long seconds = 1000L;
unsigned long minutes = seconds * 60;
unsigned long hours = minutes * 60;

const int pressTime = 1000;

void setup(){
  pinMode(optoPin1, OUTPUT);
  pinMode(optoPin2, OUTPUT);
}

void loop(){
  int randomNumber = random(10, 60);

  if (randomNumber % 2 == 0)
    pressButton(optoPin1, randomNumber);
  else
    pressButton(optoPin2, randomNumber);
}

void pressButton(int pinNumber, int randomNumber){
  digitalWrite(pinNumber, HIGH);
  delay(pressTime);
  digitalWrite(pinNumber, LOW);

  delay(randomNumber * seconds);
}