#define LED1 3
#define LED2 4
#define BUTTON 2
#define DELAY 40

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
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(BUTTON, INPUT);
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
			if(digitalRead(BUTTON)==HIGH){
				currentState=BUTTON_FALLING;
				timeReference=millis();
			}
			break;

		case BUTTON_FALLING:
			if(digitalRead(BUTTON)==HIGH){
				if(millis()-timeReference>=DELAY){
					buttonPressed();
					currentState=BUTTON_DOWN;
				}
				}else{
					currentState=BUTTON_UP;
				}
			break;

		case BUTTON_DOWN:
			if(digitalRead(BUTTON)==LOW){
				currentState=BUTTON_RAISING;
				timeReference=millis();
			}
			break;

		case BUTTON_RAISING:
			if(digitalRead(BUTTON)==LOW){
				if(millis()-timeReference>=DELAY){
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
	digitalWrite(LED1, !digitalRead(LED1));
}

void buttonReleased(){
	digitalWrite(LED2, !digitalRead(LED2));
}