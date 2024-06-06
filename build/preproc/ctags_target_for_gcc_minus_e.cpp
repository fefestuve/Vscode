# 1 "C:\\Users\\fstuve\\Documents\\Vscode\\Arduino\\MaquinaDeEstados\\MaquinaDeEstados.ino"





void debounceFSM_init();
void debounceFSM_update();
void buttonPressed();
void buttonReleased();

typedef enum{
 BUTTON_UP,
 BUTTON_FALLING,
 BUTTON_DOWN,
 BUTTON_RAISING,
}debounceState_t;

debounceState_t currentState;
unsigned long int timeReference;

void setup(){
 debounceFSM_init();
 pinMode(3, 0x1);
 pinMode(4, 0x1);
 pinMode(2, 0x0);
}

void loop(){
 debounceFSM_update();
}

void debounceFSM_init(){
 currentState=BUTTON_UP;
}

void debounceFSM_update(){
 switch(currentState){
  case BUTTON_UP:
   if(digitalRead(2)==0x1){
    currentState=BUTTON_FALLING;
    timeReference=millis();
   }
   break;

  case BUTTON_FALLING:
   if(digitalRead(2)==0x1){
    if(millis()-timeReference>=40){
     buttonPressed();
     currentState=BUTTON_DOWN;
    }
    }else{
     currentState=BUTTON_UP;
    }
   break;

  case BUTTON_DOWN:
   if(digitalRead(2)==0x0){
    currentState=BUTTON_RAISING;
    timeReference=millis();
   }
   break;

  case BUTTON_RAISING:
   if(digitalRead(2)==0x0){
    if(millis()-timeReference>=40){
     buttonReleased();
     currentState=BUTTON_UP;
    }
   }else{
    currentState=BUTTON_DOWN;
   }
   break;

 }
}

void buttonPressed(){
 digitalWrite(3, !digitalRead(3));
}

void buttonReleased(){
 digitalWrite(4, !digitalRead(4));
}
