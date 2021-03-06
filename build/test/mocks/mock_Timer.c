/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_Timer.h"

typedef struct _CMOCK_getTime_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_getTime_CALL_INSTANCE;

static struct mock_TimerInstance
{
  int getTime_IgnoreBool;
  int getTime_FinalReturn;
  CMOCK_getTime_CALLBACK getTime_CallbackFunctionPointer;
  int getTime_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE getTime_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_Timer_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.getTime_IgnoreBool)
    Mock.getTime_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.getTime_CallInstance, cmock_line, "Function 'getTime' called less times than expected.");
  if (Mock.getTime_CallbackFunctionPointer != NULL)
    Mock.getTime_CallInstance = CMOCK_GUTS_NONE;
}

void mock_Timer_Init(void)
{
  mock_Timer_Destroy();
}

void mock_Timer_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.getTime_CallbackFunctionPointer = NULL;
  Mock.getTime_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int getTime(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_getTime_CALL_INSTANCE* cmock_call_instance = (CMOCK_getTime_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.getTime_CallInstance);
  Mock.getTime_CallInstance = CMock_Guts_MemNext(Mock.getTime_CallInstance);
  if (Mock.getTime_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return (int)Mock.getTime_FinalReturn;
    Mock.getTime_FinalReturn = cmock_call_instance->ReturnVal;
    return (int)cmock_call_instance->ReturnVal;
  }
  if (Mock.getTime_CallbackFunctionPointer != NULL)
  {
    return Mock.getTime_CallbackFunctionPointer(Mock.getTime_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'getTime' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'getTime' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'getTime' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void getTime_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getTime_CALL_INSTANCE));
  CMOCK_getTime_CALL_INSTANCE* cmock_call_instance = (CMOCK_getTime_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.getTime_CallInstance = CMock_Guts_MemChain(Mock.getTime_CallInstance, cmock_guts_index);
  Mock.getTime_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.getTime_IgnoreBool = (int)1;
}

void getTime_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getTime_CALL_INSTANCE));
  CMOCK_getTime_CALL_INSTANCE* cmock_call_instance = (CMOCK_getTime_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.getTime_CallInstance = CMock_Guts_MemChain(Mock.getTime_CallInstance, cmock_guts_index);
  Mock.getTime_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void getTime_StubWithCallback(CMOCK_getTime_CALLBACK Callback)
{
  Mock.getTime_CallbackFunctionPointer = Callback;
}

