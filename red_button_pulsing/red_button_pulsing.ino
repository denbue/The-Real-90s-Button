// constants won't change. They're used here to set pin numbers & delay countern:
const int buttonPin = 2;           // the number of the pushbutton pin
const int ledPin =  13;            // the number of the LED pin
const int deactivatedTime = 10000; // time in ms to deacticate the pushbutton

// variables will change:
int buttonState = 0;               // variable for reading the pushbutton status
boolean activated = true;          // booklean for deactivating pushbutton

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // initialize the keyboard mode
  Keyboard.begin();  
}

void loop(){
  
  // var for pulse
  float in, out;

  if (activated) {
    
    for (in = 0; in < 6.283; in = in + 0.001) {
    
      // read the state of the pushbutton value:
      buttonState = digitalRead(buttonPin);
  
      // check if the pushbutton is pressed.
      // if it is, the buttonState is HIGH:
      if (activated && buttonState == HIGH) {
      
        // send hotkey to PC
        Keyboard.press("N");
        delay(100);
        Keyboard.releaseAll();   
        
        // BLINK for optical feedback
        for( int i = 0; i < 10; i++ ) {
            digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(50);                    // wait
            digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
            delay(50);                    // wait
        }
        
        // deactivate pushbutton
        activated = false;
        
      } else {
        
        if (activated) {
          out = sin(in) * 127.5 + 127.5;  // "pulse" var while listening for button (see "for" loop for counter)
          analogWrite(ledPin,out);        // do the pulse
        }
        
        if (!activated) {
          digitalWrite(ledPin, LOW);      // turn off LEDs
          delay(deactivatedTime);         // wait          
          activated = true;               // reactivate the pushbutton
        }      
      }      
    }    
  }
}
