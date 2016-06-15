/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_Button.h"

typedef struct _CMOCK_getButton_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;
  int Expected_Button;

} CMOCK_getButton_CALL_INSTANCE;

static struct mock_ButtonInstance
{
  int getButton_IgnoreBool;
  int getButton_FinalReturn;
  CMOCK_getButton_CALLBACK getButton_CallbackFunctionPointer;
  int getButton_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE getButton_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_Button_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.getButton_IgnoreBool)
    Mock.getButton_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.getButton_CallInstance, cmock_line, "Function 'getButton' called less times than expected.");
  if (Mock.getButton_CallbackFunctionPointer != NULL)
    Mock.getButton_CallInstance = CMOCK_GUTS_NONE;
}

void mock_Button_Init(void)
{
  mock_Button_Destroy();
}

void mock_Button_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.getButton_CallbackFunctionPointer = NULL;
  Mock.getButton_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int getButton(int Button)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_getButton_CALL_INSTANCE* cmock_call_instance = (CMOCK_getButton_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.getButton_CallInstance);
  Mock.getButton_CallInstance = CMock_Guts_MemNext(Mock.getButton_CallInstance);
  if (Mock.getButton_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return (int)Mock.getButton_FinalReturn;
    Mock.getButton_FinalReturn = cmock_call_instance->ReturnVal;
    return (int)cmock_call_instance->ReturnVal;
  }
  if (Mock.getButton_CallbackFunctionPointer != NULL)
  {
    return Mock.getButton_CallbackFunctionPointer(Button, Mock.getButton_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'getButton' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'getButton' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'getButton' called later than expected.");
  {
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_Button, Button, cmock_line, "Function 'getButton' called with unexpected value for argument 'Button'.");
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_getButton(CMOCK_getButton_CALL_INSTANCE* cmock_call_instance, int Button)
{
  cmock_call_instance->Expected_Button = Button;
}

void getButton_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getButton_CALL_INSTANCE));
  CMOCK_getButton_CALL_INSTANCE* cmock_call_instance = (CMOCK_getButton_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.getButton_CallInstance = CMock_Guts_MemChain(Mock.getButton_CallInstance, cmock_guts_index);
  Mock.getButton_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.getButton_IgnoreBool = (int)1;
}

void getButton_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int Button, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getButton_CALL_INSTANCE));
  CMOCK_getButton_CALL_INSTANCE* cmock_call_instance = (CMOCK_getButton_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.getButton_CallInstance = CMock_Guts_MemChain(Mock.getButton_CallInstance, cmock_guts_index);
  Mock.getButton_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_getButton(cmock_call_instance, Button);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void getButton_StubWithCallback(CMOCK_getButton_CALLBACK Callback)
{
  Mock.getButton_CallbackFunctionPointer = Callback;
}

