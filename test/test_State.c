#include "unity.h"
#include "State.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_RELEASED_to_PRESSED_ON(void){
	TaskState taskA = {RELEASED,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	
	TEST_ASSERT_EQUAL(taskA.state,PRESSED_ON);
}

void test_PRESSED_ON_to_PRESSED_OFF(void){
	TaskState taskA = {PRESSED_ON,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	
	TEST_ASSERT_EQUAL(taskA.state,PRESSED_OFF);
}
