#include "State.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_RELEASED_to_PRESSED_ON(void){

 TaskState taskA = {RELEASED,0,250,0,0};

 buttonAndLED(&taskA);



 UnityAssertEqualNumber((_U_SINT)((taskA.state)), (_U_SINT)((PRESSED_ON)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

}



void test_PRESSED_ON_to_PRESSED_OFF(void){

 TaskState taskA = {PRESSED_ON,0,250,0,0};

 buttonAndLED(&taskA);



 UnityAssertEqualNumber((_U_SINT)((taskA.state)), (_U_SINT)((PRESSED_OFF)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

}
