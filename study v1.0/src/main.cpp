#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <ctime>

#include "../imgui_include_folder/includes.h"
#include "imgui_func.h"
#include "menu.h"
#include "inputs.h"
#include "macro_manager.h"
#include "globals.h"
#include "generalfunctions.h"




bool afk = false;
// Main code
int main()
{
    
    if (IsRunningAsAdmin())
    {
        programstatus.isAdmin = true;
    }
    HWND gtaHwnd = FindWindow(NULL, TEXT("Grand Theft Auto V"));
    if (gtaHwnd == NULL) {
        MessageBox(NULL, TEXT("Game window not found"), TEXT("Emil-Eriks Afk Bot"), MB_OK | MB_ICONERROR);
        return 0;
    }
    
    setup_menu();
    
    macro macro;
    auto start = std::chrono::steady_clock::now();
    
    programstatus.console_output += "   " + printCurTime() + "\n";
    while(true)
    {
        render_menu();
        
        if (programstatus.isRunning)
        {
            
            if (!programstatus.windowPrep == true)
            {
                Sleep(10);
                SetForegroundWindow(gtaHwnd);
                Sleep(10);
                MoveWindow(gtaHwnd, 0, 0, 0, 0, TRUE);
                programstatus.windowPrep = true;
            }
            auto now = std::chrono::steady_clock::now();
            auto duration1 = std::chrono::duration_cast<std::chrono::minutes>(now - start).count();
            if (duration1 >= timings.loop_timer)
            {
                macro.StartMc();
                macro.AccessMasterControlTerminal();

                if(nightclub.NightclubBool)
                    macro.PopularityNightclub();

                if(bunker.BunkerBool)
                    macro.ResupplyGunRunning();

                if (methlockup.MethLockupBool)
                    macro.ResupplyMeth();

                if (cocainelockup.CocaineLockupBool)
                    macro.ResupplyCocaine();

                macro.LeavingMasterControlTerminal();

                if (acidlab.AcidLabBool)
                    macro.ResupplyAcid();

                macro.DisbandMc();
                start = std::chrono::steady_clock::now();

            }
            macro.StandardAfk();
            Sleep(3);
        }
        else
            start = std::chrono::steady_clock::now();
        
        if (programstatus.Stop)
            break;
    }
    destroy_menu();
    return 0;
}




