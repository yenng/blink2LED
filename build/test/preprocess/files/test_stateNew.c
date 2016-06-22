#include "mock_Button.h"
#include "mock_Timer.h"
#include "stateNew.h"
#include "unity.h"


int * tablePtr = ((void *)0);



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

 switch(self->state){ case 0:;

 while(1){

  turnOffLED();

  while(isButtonPressed()==0){

   self->state=26; return; case 26:;

  }

  turnOnLED();

  while(isButtonPressed()==1){

   self->state=30; return; case 30:;

  }

  while(isButtonPressed()==0){

   self->state=33; return; case 33:;

  }

  };

 }

}



void test_module_generator_needs_to_be_implemented(void){

 UnityIgnore( ("Implement me!"), (_U_UINT)40);;

}
