#include "State.h"
#include "Timer.h"
#include "Button.h"

void turnLED(int LED, int on_off){
	
}

void buttonAndLED(TaskState *ts){
	switch(ts->state){
		case RELEASED:
			if(getButton(ts->whichButton)==IS_PRESSED){
					turnLED(ts->whichLED, LED_ON);
					ts->recordedTime = getTime();
					ts->state = PRESSED_ON;
			}
		break;
		case PRESSED_ON:
			if(getButton(ts->whichButton)==IS_RELEASED)
				ts->state = RELEASED_ON;
			if(getTime()-ts->recordedTime >= ts->interval){
				turnLED(ts->whichLED, LED_OFF);
				ts->recordedTime = getTime();
				ts->state = PRESSED_OFF;
			}
		break;
		case PRESSED_OFF:
			if(getButton(ts->whichButton)==IS_RELEASED)
				ts->state = RELEASED_OFF;
			if(getTime()-ts->recordedTime >= ts->interval){
				turnLED(ts->whichLED, LED_ON);
				ts->recordedTime = getTime();
				ts->state = PRESSED_ON;
			}
		break;
		case RELEASED_OFF:
			if(getButton(ts->whichButton)==IS_PRESSED)
				ts->state = TURNING_OFF;
			if(getTime()-ts->recordedTime >= ts->interval){
				turnLED(ts->whichLED, LED_ON);
				ts->recordedTime = getTime();
				ts->state = RELEASED_ON;
			}
		break;
		case RELEASED_ON:
			if(getButton(ts->whichButton)==IS_PRESSED){
				turnLED(ts->whichLED, LED_OFF);
				ts->state = TURNING_OFF;
			}
			if(getTime()-ts->recordedTime >= ts->interval){
				turnLED(ts->whichLED, LED_OFF);
				ts->recordedTime = getTime();
				ts->state = RELEASED_OFF;
			}
		break;
		case TURNING_OFF:
			if(getButton(ts->whichButton)==IS_RELEASED)
				ts->state = RELEASED;
		break;
			
	}
}

void Main(){
	TaskState taskA = {RELEASED,0,250,RED_LED,BUTTON_A};
	TaskState taskB = {RELEASED,0,500,GREEN_LED,BUTTON_B};
	
	while(1){
		buttonAndLED(&taskA);
		buttonAndLED(&taskB);
	}
}


