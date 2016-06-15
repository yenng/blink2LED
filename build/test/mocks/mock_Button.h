/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_BUTTON_H
#define _MOCK_BUTTON_H

#include "Button.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC)
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_Button_Init(void);
void mock_Button_Destroy(void);
void mock_Button_Verify(void);




#define getButton_IgnoreAndReturn(cmock_retval) getButton_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void getButton_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define getButton_ExpectAndReturn(Button, cmock_retval) getButton_CMockExpectAndReturn(__LINE__, Button, cmock_retval)
void getButton_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int Button, int cmock_to_return);
typedef int (* CMOCK_getButton_CALLBACK)(int Button, int cmock_num_calls);
void getButton_StubWithCallback(CMOCK_getButton_CALLBACK Callback);

#endif