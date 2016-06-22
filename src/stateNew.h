#ifndef stateNew_H
#define stateNew_H

#define startCoroutine()										\
										switch(self->state){		\
										case 0:
#define endCoroutine()											\
										}
#define yield()			self->state=__LINE__;		\
										return;									\
										case __LINE__:

#define TRUE		1										
#define FALSE		0										
										
typedef enum{
	RELEASED, PRESSED_ON, RELEASED_ON, PRESSED_OFF,RELEASED_OFF, TURNING_OFF,
}FsmState;

typedef struct{
	FsmState state;
	unsigned int recordedTime;
	int interval;
	int whichLED;
	int whichButton;
}TaskState;
void turnOnLED();
void turnOffLED();
#endif // stateNew_H
