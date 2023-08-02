#pragma once
#include "inputs.h"
#include "globals.h"

class macro
{
public:
    void StartMc()
    {
        PressKey(Key::M);
        Sleep(100);
        PressKey(Key::P);
        Sleep(100);
        PressKey(Key::P);
        Sleep(100);
        PressKey(Key::ENTER);
        Sleep(100);
        PressKey(Key::P);
        Sleep(100);
        PressKey(Key::ENTER);
        Sleep(100);
        PressKey(Key::ENTER);
        Sleep(5000);
    }
    void DisbandMc()
    {
        PressKey(Key::M);
        Sleep(100);
        PressKey(Key::ENTER);
        Sleep(100);
        PressKey(Key::O);
        Sleep(100);
        PressKey(Key::ENTER);
        Sleep(5000);
    }
    void StandardAfk()
    {
        HoldDownWKey(Key::A);
        Sleep(5000);
        ReleaseWKey(Key::A);
        Sleep(5000);
    }
    void AccessMasterControlTerminal()
    {
        PressKey(Key::E);
        Sleep(10000);
        PressKey(Key::ENTER);
        Sleep(5000);
        programstatus.console_output += "Accessed Master Control Terminal at " + printCurTime() + "\n";
    }
    void LeavingMasterControlTerminal()
    {
        RightClick();
        Sleep(7500);
        RightClick();
        programstatus.console_output += "Left Master Control Terminal at " + printCurTime() + "\n";
    }
    void PopularityNightclub()
    {
        SetMousePos(217, 304); // clicking on nightclub from arcade
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(202, 427); // going onto resident dj
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        if (nightclub.second_dj_resident == true)
        {
            SetMousePos(395, 337); // booking first dj
            Sleep(15);
            PressKey(Key::ENTER);
            Sleep(100);
        }
        else
        {
            SetMousePos(620, 335); // booking second dj for 1 full bar
            Sleep(15);
            PressKey(Key::ENTER);
            Sleep(100);
        }
        nightclub.second_dj_resident = !nightclub.second_dj_resident;

        SetMousePos(480, 360); // confirming 
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(1000);
        
        PressKey(Key::ESCAPE); // going back to main menu
        Sleep(100);
        PressKey(Key::ESCAPE);
        Sleep(5000);
        programstatus.console_output += "Refilled Nightclub Popularity At " + printCurTime() + "\n";
    }
    void ResupplyGunRunning()
    {
        SetMousePos(400, 304); // clicking on gunrunning from arcade
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(402,365); // clicking on login
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);


        SetMousePos(181,284); // clicking on resupply
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(409,455); // clicking on buy supplies
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(445,357); // clicking on confirm
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        PressKey(Key::ESCAPE); // going back to main menu
        Sleep(100);
        PressKey(Key::ESCAPE);
        Sleep(100);
        programstatus.console_output += "Resupplied Gunrunning Supplies at " + printCurTime() + "\n";
        Sleep(5000);
    }
    void ResupplyCocaine()
    {
        SetMousePos(520, 304); // clicking on cocaine from arcade
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(3000);

        SetMousePos(410,413); // login key
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(177,232); // resupply tab
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(479,298); // resupply button
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(461,393); // confirm button
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        PressKey(Key::ESCAPE); // going back to main menu
        Sleep(100);
        PressKey(Key::ESCAPE);
        Sleep(5000);
        programstatus.console_output += "Resupplied Cocaine Supplies at " + printCurTime() + "\n";
    }
    void ResupplyMeth()
    {
        SetMousePos(215, 517); // clicking on cocaine from arcade
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(3000);

        SetMousePos(410, 413); // login key
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(177, 232); // resupply tab
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(479, 298); // resupply button
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        SetMousePos(461, 393); // confirm button
        Sleep(15);
        PressKey(Key::ENTER);
        Sleep(100);

        PressKey(Key::ESCAPE); // going back to main menu
        Sleep(100);
        PressKey(Key::ESCAPE);
        Sleep(5000);
        programstatus.console_output += "Resupplied Meth Supplies at " + printCurTime() + "\n";
    }
    void ResupplyAcid()
    {
        MiddleClick();
        Sleep(1000);
        PressKey(Key::I);
        Sleep(1000);
        PressKey(Key::O);
        Sleep(1000);
        PressKey(Key::ENTER);
        Sleep(100);
        for (int i = 0; i < acidlab.MuttNumber; i++)
        {
            PressKey(Key::P);
            Sleep(100);
        }
        PressKey(Key::ENTER);
        Sleep(10000);
        PressKey(Key::ENTER);
        Sleep(10000);
    }
};
