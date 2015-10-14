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
#ifdef GAMEPAD_EXPORTS
#define GAMEPAD_API __declspec(dllexport)
#else
#define GAMEPAD_API __declspec(dllimport)
#endif

// external for DLL
extern "C" GAMEPAD_API void __stdcall gpInit(void);
extern "C" GAMEPAD_API void __stdcall gpDeInit(void);
extern "C" GAMEPAD_API void __stdcall gpUpdateAllControllers(void);
extern "C" GAMEPAD_API int  __stdcall gpMaxControllersCount(void);
extern "C" GAMEPAD_API void __stdcall gpSetUseDeadZone(bool status);
extern "C" GAMEPAD_API bool __stdcall gpIsUsingDeadZone(void);

extern "C" GAMEPAD_API bool __stdcall gpIsConnected(int index);

extern "C" GAMEPAD_API bool __stdcall gpIsButton_DPAD_UP(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_DPAD_DOWN(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_DPAD_LEFT(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_DPAD_RIGHT(int index);


extern "C" GAMEPAD_API bool __stdcall gpIsButton_START(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_BACK(int index);

extern "C" GAMEPAD_API bool __stdcall gpIsButton_A(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_B(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_X(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_Y(int index);

extern "C" GAMEPAD_API bool __stdcall gpIsButton_LEFT_THUMB(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_RIGHT_THUMB(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_LEFT_SHOULDER(int index);
extern "C" GAMEPAD_API bool __stdcall gpIsButton_RIGHT_SHOULDER(int index);

extern "C" GAMEPAD_API int __stdcall gpLeftTriggerValue(int index);
extern "C" GAMEPAD_API int __stdcall gpRightTriggerValue(int index);
extern "C" GAMEPAD_API int __stdcall gpLeftThumbXValue(int index);
extern "C" GAMEPAD_API int __stdcall gpLeftThumbYValue(int index);
extern "C" GAMEPAD_API int __stdcall gpRightThumbXValue(int index);
extern "C" GAMEPAD_API int __stdcall gpRightThumbYValue(int index);


