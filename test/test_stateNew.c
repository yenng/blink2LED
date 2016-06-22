#include "unity.h"
#include "stateNew.h"
#include "mock_Timer.h"
#include "mock_Button.h"

int * tablePtr = NULL;

int fake_isButtonPressed(){
	int button = *tablePtr;
	tablePtr ++;
	
	return button;
};

void setUp(void){
	isButtonPressed_StubWithCallback(fake_isButtonPressed);
}

void tearDown(void){}

void buttonAndLED(TaskState *self){
	startCoroutine();
	while(1){
		turnOffLED();
		while(isButtonPressed()==FALSE){
			yield();
		}
		turnOnLED();
		while(isButtonPressed()==TRUE){
			yield();
		}
		while(isButtonPressed()==FALSE){
			yield();
		}
		endCoroutine();
	}
}

void test_module_generator_needs_to_be_implemented(void){
	TEST_IGNORE_MESSAGE("Implement me!");
}
