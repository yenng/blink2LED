#include "unity.h"
#include "State.h"
#include "mock_Timer.h"
#include "mock_Button.h"

int * tablePtr = NULL;
int * tablePtr1 = NULL;

int fake_getButton(int Button){
	int button = *tablePtr1;
	tablePtr1 ++;
	
	return button;
}

int fake_getTime(){
	int time = *tablePtr;
	tablePtr ++;
	
	return time;
}

void setUp(void){
	getTime_StubWithCallback(fake_getTime);
	getButton_StubWithCallback(fake_getButton);
}

void tearDown(void)
{
}

void test_RELEASED_to_PRESSED_ON(void){
	int table1[] = {1, 0, 1, 0, 1, 0, 1};
	int table[] = {0, 20, 200, 250, 1, 0, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {RELEASED,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	
	TEST_ASSERT_EQUAL(PRESSED_ON,taskA.state);
}

void test_PRESSED_ON_to_PRESSED_OFF(void){
	int table1[] = {1, 1, 1, 1, 1, 1, 1};
	int table[] = {0, 20, 200, 250, 1, 0, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {PRESSED_ON,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(PRESSED_ON,taskA.state);
	buttonAndLED(&taskA);
	buttonAndLED(&taskA);
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(PRESSED_OFF,taskA.state);	
}

void test_PRESSED_OFF_to_PRESSED_ON(void){
	int table1[] = {1, 1, 1, 1, 1, 1, 1};
	int table[] = {250,500};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {PRESSED_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(PRESSED_ON,taskA.state);
}

void test_PRESSED_OFF_to_RELEASE_OFF(void){
	int table1[] = {1, 0, 1, 1, 1, 1, 1};
	int table[] = {1,0};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {PRESSED_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(RELEASED_OFF,taskA.state);
}

void test_PRESSED_OFF_to_PRESSED_ON_to_PRESSED_OFF(void){
	int table1[] = {1, 1, 1, 1, 1, 1, 1};
	int table[] = {250, 500, 0, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {PRESSED_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(PRESSED_OFF,taskA.state);	
}

void test_PRESSED_ON_to_RELEASE_ON(void){
	int table1[] = {1, 0, 1, 1, 1, 1, 1};
	int table[] = {0, 1, 0, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {PRESSED_ON,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(RELEASED_ON,taskA.state);
}

void test_RELEASED_ON_to_RELEASE_OFF(void){
	int table1[] = {0, 0, 0, 0, 0, 0, 0};
	int table[] = {250, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {RELEASED_ON,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(RELEASED_OFF,taskA.state);
}

void test_RELEASED_OFF_to_RELEASE_ON(void){
	int table1[] = {0, 0, 0, 0, 0, 0, 0};
	int table[] = {250, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {RELEASED_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(RELEASED_ON,taskA.state);
}

void test_RELEASED_OFF_to_RELEASE_ON_to_RELEASED_OFF(void){
	int table1[] = {0, 0, 0, 0, 0, 0, 0};
	int table[] = {250, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {RELEASED_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(RELEASED_OFF,taskA.state);
}

void test_RELEASED_OFF_to_TURNING_OFF(void){
	int table1[] = {1, 0, 0, 0, 0, 0, 0};
	int table[] = {249, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {RELEASED_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(TURNING_OFF,taskA.state);
}

void test_RELEASED_ON_to_TURNING_OFF(void){
	int table1[] = {1, 0, 0, 0, 0, 0, 0};
	int table[] = {249, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {RELEASED_ON,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(TURNING_OFF,taskA.state);
}

void test_TURNING_OFF_to_TURNING_OFF(void){
	int table1[] = {1, 1, 1, 0, 0, 0, 0};
	int table[] = {249, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {TURNING_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(TURNING_OFF,taskA.state);
}

void test_TURNING_OFF_to_RELEASE(void){
	int table1[] = {0, 1, 1, 0, 0, 0, 0};
	int table[] = {249, 500, 750, 1};
	tablePtr1 = table1;
	tablePtr = table;
	
	TaskState taskA = {TURNING_OFF,0,250,RED_LED,BUTTON_A};
	buttonAndLED(&taskA);
	TEST_ASSERT_EQUAL(RELEASED,taskA.state);
}
