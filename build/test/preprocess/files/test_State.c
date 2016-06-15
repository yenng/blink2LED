#include "mock_Button.h"
#include "mock_Timer.h"
#include "State.h"
#include "unity.h"


int * tablePtr = ((void *)0);

int * tablePtr1 = ((void *)0);



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



 TaskState taskA = {RELEASED,0,250,0,0};

 buttonAndLED(&taskA);



 UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_PRESSED_ON_to_PRESSED_OFF(void){

 int table1[] = {1, 1, 1, 1, 1, 1, 1};

 int table[] = {0, 20, 200, 250, 1, 0, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {PRESSED_ON,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

 buttonAndLED(&taskA);

 buttonAndLED(&taskA);

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

}



void test_PRESSED_OFF_to_PRESSED_ON(void){

 int table1[] = {1, 1, 1, 1, 1, 1, 1};

 int table[] = {250,500};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {PRESSED_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

}



void test_PRESSED_OFF_to_RELEASE_OFF(void){

 int table1[] = {1, 0, 1, 1, 1, 1, 1};

 int table[] = {1,0};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {PRESSED_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

}



void test_PRESSED_OFF_to_PRESSED_ON_to_PRESSED_OFF(void){

 int table1[] = {1, 1, 1, 1, 1, 1, 1};

 int table[] = {250, 500, 0, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {PRESSED_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

}



void test_PRESSED_ON_to_RELEASE_ON(void){

 int table1[] = {1, 0, 1, 1, 1, 1, 1};

 int table[] = {0, 1, 0, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {PRESSED_ON,0,250,0,0};

 buttonAndLED(&taskA);

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

}



void test_RELEASED_ON_to_RELEASE_OFF(void){

 int table1[] = {0, 0, 0, 0, 0, 0, 0};

 int table[] = {250, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {RELEASED_ON,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

}



void test_RELEASED_OFF_to_RELEASE_ON(void){

 int table1[] = {0, 0, 0, 0, 0, 0, 0};

 int table[] = {250, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {RELEASED_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

}



void test_RELEASED_OFF_to_RELEASE_ON_to_RELEASED_OFF(void){

 int table1[] = {0, 0, 0, 0, 0, 0, 0};

 int table[] = {250, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {RELEASED_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

}



void test_RELEASED_OFF_to_TURNING_OFF(void){

 int table1[] = {1, 0, 0, 0, 0, 0, 0};

 int table[] = {249, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {RELEASED_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

}



void test_RELEASED_ON_to_TURNING_OFF(void){

 int table1[] = {1, 0, 0, 0, 0, 0, 0};

 int table[] = {249, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {RELEASED_ON,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

}



void test_TURNING_OFF_to_TURNING_OFF(void){

 int table1[] = {1, 1, 1, 0, 0, 0, 0};

 int table[] = {249, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {TURNING_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

}



void test_TURNING_OFF_to_RELEASE(void){

 int table1[] = {0, 1, 1, 0, 0, 0, 0};

 int table[] = {249, 500, 750, 1};

 tablePtr1 = table1;

 tablePtr = table;



 TaskState taskA = {TURNING_OFF,0,250,0,0};

 buttonAndLED(&taskA);

 UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((taskA.state)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

}
