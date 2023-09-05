int STEP = 7;
int DIR = 6;
int StepsPerRot = 200;
int microstep = 8; 
int ActualStepsPerRot = StepsPerRot*microstep;
/*  microstep truth table

    MS1     MS2        Microstep Value
    0       0           8
    1       0           2
    0       1           4
    1       1           16

*/

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
        MoveStepper(ActualStepsPerRot/2,true);
    }
    else if(input == "B"){
        MoveStepper(ActualStepsPerRot/2,false);
    }
    else if(input == "L"){
        MoveStepperUntil(true);
    }
    else if(input == "R"){
        MoveStepperUntil(false);
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
void MoveStepperUntil(bool Direction){
    while(true){
        for(int i=0;i<ActualStepsPerRot;i++){
            getDirection(Direction);
            digitalWrite(STEP,HIGH);
            delayMicroseconds(500);
            digitalWrite(STEP,LOW);
            delayMicroseconds(500); 
        }
        if(Serial.readString() == "S"){
            break;
        }
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
