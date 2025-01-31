 #include <Keyboard.h>


int forceThreshold =150;

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  pinMode(A1, INPUT);
 
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  int forceValue = analogRead(A1);


  Serial.print(" force: ");
  Serial.println(forceValue);

 

  if(forceValue > forceThreshold){
    digitalWrite(LED_BUILTIN, HIGH);
    Keyboard.press(' ');
    delay(200);  
    digitalWrite(LED_BUILTIN, LOW);
  }

  Keyboard.releaseAll();
}
