const int ledVermelho = 8, ledVerde = 9, sensor = 12, aspersor = 7, cooler = 5;
int x=0;

int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(aspersor, OUTPUT);
  pinMode(cooler, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(aspersor, LOW);
  digitalWrite(cooler, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);
  Serial.begin(9600);
  Serial.println("aguardando ");
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(sensor);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        if(x==0){
          digitalWrite(aspersor, HIGH);
          digitalWrite(ledVerde, LOW);
          digitalWrite(ledVermelho, HIGH);
          Serial.println("aspersor ativado");
          delay(1000);
          digitalWrite(aspersor, LOW);
          digitalWrite(cooler, HIGH);
          Serial.println("cooler ativado");
          delay(3000);
          digitalWrite(ledVermelho, LOW);
          digitalWrite(cooler, LOW);
          digitalWrite(ledVerde, HIGH);
          Serial.println("processo concluido");
        }
        x=1;
      }
      else{
        Serial.println("sensor desativado");
        x=0;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
