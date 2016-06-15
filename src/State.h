#ifndef State_H
#define State_H

typedef enum{
	RELEASED, PRESSED_ON, RELEASED_ON, PRESSED_OFF,RELEASED_OFF, TURNING_OFF,
}FsmState;

#define IS_RELEASED	0
#define IS_PRESSED 	1

#define LED_ON 	1
#define LED_OFF 0

#define RED_LED	 	0
#define GREEN_LED 1

#define BUTTON_A 0
#define BUTTON_B 1

typedef struct{
	FsmState state;
	unsigned int recordedTime;
	int interval;
	int whichLED;
	int whichButton;
}TaskState;

void buttonAndLED(TaskState *ts);
void Main();

#endif // State_H
