int STEP = 7;
int DIR = 6;
int StepsPerRot = 1600;

void setup(){
    pinMode(STEP,OUTPUT);
    pinMode(DIR,OUTPUT);
    Serial.begin(9600);
    Serial.setTimeout(10);
}
void loop(){
    while (Serial.available() == 0) {} 
    String input = Serial.readString();
    if(input == "F"){
        MoveStepper(StepsPerRot/2,true);
    }
    else if(input == "B"){
        MoveStepper(StepsPerRot/2,false);
    }
}

void MoveStepper(int TurnAmt, bool Direction){
    for(int i=0;i<TurnAmt;i++){
        getDirection(Direction);
        digitalWrite(STEP,HIGH);
        delayMicroseconds(500);
        digitalWrite(STEP,LOW);
        delayMicroseconds(500); 
    }
}

void getDirection(bool Direction){
    if(Direction){
        digitalWrite(DIR,HIGH);
    }
    else{
        digitalWrite(DIR,LOW);
    }
}
