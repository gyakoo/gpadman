/*
The MIT License (MIT)

Copyright (c) 2015 Manu / gyakoo@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//
#include "stdafx.h"
#include "GamePad.h"
#include <commdlg.h>
#include <xinput.h>
#include <basetsd.h>

struct CONTROLER_STATE
{
  XINPUT_STATE state;
  bool bConnected;
};
#define MAX_CONTROLLERS 4
#define INPUT_DEADZONE  ( 0.24f * FLOAT(0x7FFF) )  // Default to 24% of the +/- 32767 range.   This is a reasonable default value but can be altered if needed.
CONTROLER_STATE g_Controllers[MAX_CONTROLLERS];
bool    g_bDeadZoneOn = true;

GAMEPAD_API void __stdcall gpInit()
{
  ZeroMemory( g_Controllers, sizeof( CONTROLER_STATE ) * MAX_CONTROLLERS );
  XInputEnable(true);
}
GAMEPAD_API void __stdcall gpDeInit()
{
  XInputEnable(false);
}


GAMEPAD_API int  __stdcall gpMaxControllersCount(void){ return MAX_CONTROLLERS;}
GAMEPAD_API void __stdcall gpSetUseDeadZone(bool status){ g_bDeadZoneOn = status; }
GAMEPAD_API bool __stdcall gpIsUsingDeadZone(){ return g_bDeadZoneOn; }

// This is an example of an exported function.
GAMEPAD_API void __stdcall gpUpdateAllControllers(void)
{

  DWORD dwResult;
  for( DWORD i = 0; i < MAX_CONTROLLERS; i++ )
  {
    // Simply get the state of the controller from XInput.
    dwResult = XInputGetState( i, &g_Controllers[i].state );

    if( dwResult == ERROR_SUCCESS )
      g_Controllers[i].bConnected = true;
    else
      g_Controllers[i].bConnected = false;

    // If using dead zone, put 0 these values if they're in the dead-zone threshold
    XINPUT_GAMEPAD& gp = g_Controllers[i].state.Gamepad;
    if( g_bDeadZoneOn )
    {
      // Zero value if thumbsticks are within the dead zone 
      if( ( gp.sThumbLX < INPUT_DEADZONE && gp.sThumbLX > -INPUT_DEADZONE ) &&
          ( gp.sThumbLY < INPUT_DEADZONE && gp.sThumbLY > -INPUT_DEADZONE ) )
      {
        gp.sThumbLX = 0;
        gp.sThumbLY = 0;
      }

      if( ( gp.sThumbRX < INPUT_DEADZONE && gp.sThumbRX > -INPUT_DEADZONE ) &&
          ( gp.sThumbRY < INPUT_DEADZONE && gp.sThumbRY > -INPUT_DEADZONE ) )
      {
        gp.sThumbRX = 0;
        gp.sThumbRY = 0;
      }
    }
  }
}

GAMEPAD_API bool __stdcall gpIsConnected(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) 
    return false;
  return g_Controllers[index].bConnected;
}

bool gpButton(int index,int but)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) 
    return false;
  return (g_Controllers[index].state.Gamepad.wButtons & but)!=0;
}

GAMEPAD_API bool __stdcall gpIsButton_DPAD_UP(int index)    {return gpButton(index,XINPUT_GAMEPAD_DPAD_UP); }
GAMEPAD_API bool __stdcall gpIsButton_DPAD_DOWN(int index)  {return gpButton(index,XINPUT_GAMEPAD_DPAD_DOWN); }
GAMEPAD_API bool __stdcall gpIsButton_DPAD_LEFT(int index)  {return gpButton(index,XINPUT_GAMEPAD_DPAD_LEFT); }
GAMEPAD_API bool __stdcall gpIsButton_DPAD_RIGHT(int index) {return gpButton(index,XINPUT_GAMEPAD_DPAD_RIGHT); }
GAMEPAD_API bool __stdcall gpIsButton_START(int index)      {return gpButton(index,XINPUT_GAMEPAD_START); }
GAMEPAD_API bool __stdcall gpIsButton_BACK(int index)       {return gpButton(index,XINPUT_GAMEPAD_BACK); }
GAMEPAD_API bool __stdcall gpIsButton_A(int index)          {return gpButton(index,XINPUT_GAMEPAD_A); }
GAMEPAD_API bool __stdcall gpIsButton_B(int index)          {return gpButton(index,XINPUT_GAMEPAD_B); }
GAMEPAD_API bool __stdcall gpIsButton_X(int index)          {return gpButton(index,XINPUT_GAMEPAD_X); }
GAMEPAD_API bool __stdcall gpIsButton_Y(int index)          {return gpButton(index,XINPUT_GAMEPAD_Y); }
GAMEPAD_API bool __stdcall gpIsButton_LEFT_THUMB(int index) {return gpButton(index,XINPUT_GAMEPAD_LEFT_THUMB); }
GAMEPAD_API bool __stdcall gpIsButton_RIGHT_THUMB(int index){return gpButton(index,XINPUT_GAMEPAD_RIGHT_THUMB); }
GAMEPAD_API bool __stdcall gpIsButton_LEFT_SHOULDER(int index){return gpButton(index,XINPUT_GAMEPAD_LEFT_SHOULDER); }
GAMEPAD_API bool __stdcall gpIsButton_RIGHT_SHOULDER(int index){return gpButton(index,XINPUT_GAMEPAD_RIGHT_SHOULDER); }

GAMEPAD_API int __stdcall gpLeftTriggerValue(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) return false;
  return (int)g_Controllers[index].state.Gamepad.bLeftTrigger;
}
GAMEPAD_API int __stdcall gpRightTriggerValue(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) return false;
  return (int)g_Controllers[index].state.Gamepad.bRightTrigger;
}
GAMEPAD_API int __stdcall gpLeftThumbXValue(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) return false;
  return (int)g_Controllers[index].state.Gamepad.sThumbLX;
}
GAMEPAD_API int __stdcall gpLeftThumbYValue(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) return false;
  return (int)g_Controllers[index].state.Gamepad.sThumbLY;
}
GAMEPAD_API int __stdcall gpRightThumbXValue(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) return false;
  return (int)g_Controllers[index].state.Gamepad.sThumbRX;
}
GAMEPAD_API int __stdcall gpRightThumbYValue(int index)
{
  if ( index < 0 || index >= MAX_CONTROLLERS ) return false;
  return (int)g_Controllers[index].state.Gamepad.sThumbRY;
}


