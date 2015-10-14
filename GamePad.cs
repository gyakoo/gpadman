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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;


namespace App
{
  public static class GamePad
  {
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern void gpInit();

    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern void gpDeInit();

    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern void gpUpdateAllControllers();

    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpMaxControllersCount();
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern void gpSetUseDeadZone(bool status);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsUsingDeadZone();
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsConnected(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_DPAD_UP(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_DPAD_DOWN(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_DPAD_LEFT(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_DPAD_RIGHT(int index);
        
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_START(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_BACK(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_A(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_B(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_X(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_Y(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_LEFT_THUMB(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_RIGHT_THUMB(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_LEFT_SHOULDER(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern bool gpIsButton_RIGHT_SHOULDER(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpLeftTriggerValue(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpRightTriggerValue(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpLeftThumbXValue(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpLeftThumbYValue(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpRightThumbXValue(int index);
    
    [DllImport("GamePad.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
    public static extern int gpRightThumbYValue(int index);
  }
}