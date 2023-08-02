#pragma once
#include <iostream>
#include <Windows.h>

class Key
{
public:
    static constexpr uint8_t A = 0x41;
    static constexpr uint8_t E = 0x45;
    static constexpr uint8_t D = 0x44;
    static constexpr uint8_t S = 0x53;
    static constexpr uint8_t W = 0x57;
    static constexpr uint8_t M = 0x4D;
    static constexpr uint8_t P = 0x50;
    static constexpr uint8_t O = 0x4F;
    static constexpr uint8_t I = 0x49;
    static constexpr uint8_t ENTER = 0x0D;
    static constexpr uint8_t ESCAPE = 0x1B;
    static constexpr uint8_t ARROW_UP = 0x26;
    static constexpr uint8_t ARROW_DOWN = 0x28;
    static constexpr uint8_t ARROW_LEFT = 0x25;
    static constexpr uint8_t ARROW_RIGHT = 0x27;
    
    // You can add other keys similarly...
};
void HoldDownWKey(uint8_t key) {
    BYTE scanCode = MapVirtualKeyW(key, MAPVK_VK_TO_VSC);
    keybd_event(key, scanCode, 0, 0);
}

void ReleaseWKey(uint8_t key) {
    BYTE scanCode = MapVirtualKeyW(key, MAPVK_VK_TO_VSC);
    keybd_event(key, scanCode, KEYEVENTF_KEYUP, 0);
}

void PressKey(uint8_t key) {
    BYTE scanCode = MapVirtualKeyW(key, MAPVK_VK_TO_VSC);
    keybd_event(key, scanCode, 0, 0);
    Sleep(100);
    keybd_event(key, scanCode, KEYEVENTF_KEYUP, 0);
}
void SetMousePos(int x, int y)
{
    SetCursorPos(x, y);
}

void LeftClick()
{
    // MOUSEEVENTF_LEFTDOWN simulates pressing the left mouse button
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

    // Sleep to simulate holding the button down
    Sleep(10);

    // MOUSEEVENTF_LEFTUP simulates releasing the left mouse button
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void RightClick() {
    // MOUSEEVENTF_RIGHTDOWN simulates pressing the right mouse button
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);

    // Sleep to simulate holding the button down
    Sleep(10);

    // MOUSEEVENTF_RIGHTUP simulates releasing the right mouse button
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}

void MiddleClick()
{
    // MOUSEEVENTF_MIDDLEDOWN simulates pressing the middle mouse button
    mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);

    // Sleep to simulate holding the button down
    Sleep(10);

    // MOUSEEVENTF_MIDDLEUP simulates releasing the middle mouse button
    mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
}