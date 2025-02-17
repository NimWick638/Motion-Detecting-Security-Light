#define timeSeconds 10

//define gpio pin 12 and 14 for led and button
const int led = 12 ; 
const  int button  = 14 ;

// difning variables to manage time 
unsigned long now = millis() ; 
unsigned long lastTrigger  =  0 ;
boolean timerStatus = false ; //why this (as a good practice i planned to make the intrupt routine as much as smaller to increase the responsive of the button trigger )

ICACHE_RAM_ATTR void buttonPress(){//ICACHE_Ram_ATTR to save function on Ram 

 Serial.println("Buton was pessed..");
 digitalWrite(led, HIGH);
 timerStatus = true ; //acts like flag to trigger the fuction  in main loop
 lastTrigger = millis(); 

}
void setup() {
 Serial.begin(115200);

 pinMode(button, INPUT);//set button pin as output 
 attachInterrupt(digitalPinToInterrupt(14), buttonPress , RISING );
 pinMode(led, OUTPUT);

 //set led pin low

  pinMode(led, OUTPUT);
  digitalWrite(led , LOW); 

}

void loop() {
  now = millis(); 
  if(timerStatus && (now - lastTrigger) > timeSeconds*1000 ){

    
    digitalWrite(led , LOW);
    timerStatus = false;
    Serial.println("light off...");

  }
}