#pragma once
#include "imgui_func.h"
#include "generalfunctions.h"
#include "globals.h"

int windowWidth = 400;
int windowHeight = 400;
int currentPage = 1;
// window stuff
WNDCLASSEXW wc;


bool show_demo_window;
bool show_another_window;
ImVec4 clear_color;

void setup_menu()
{
    wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&wc);
    hwnd = CreateWindowExW(
    NULL,              // Extended window style.
    wc.lpszClassName,           // Window class name.
    L"Emil-Eriks's GTA V Bot",     // Window title.
    WS_BORDER & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // Window style.
    100, 100, 414, 410,         // Window position and size.
    nullptr, nullptr,           // Parent window and menus.
    wc.hInstance, nullptr       // Instance and param.
);

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return;
    }

    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX10_Init(g_pd3dDevice);

    show_demo_window = true;
    show_another_window = false;
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void destroy_menu()
{
    ImGui_ImplDX10_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
}

void render_menu()
{
    // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
    MSG msg;
    while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    // Handle window resize (we don't resize directly in the WM_SIZE handler)
    if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
    {
        CleanupRenderTarget();
        g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
        g_ResizeWidth = g_ResizeHeight = 0;
        CreateRenderTarget();
    }

    // Start the Dear ImGui frame
    ImGui_ImplDX10_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    {
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight));

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));
        ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

        if (1 == 1) // Menu page
        {
            ImVec2 buttonSize = ImVec2(90.0f, 20.0f);

            if (ImGui::Button("BOT", buttonSize))
                currentPage = 1;
            ImGui::SameLine();
            if(ImGui::Button("SETTINGS", buttonSize))
                currentPage = 2;
            ImGui::SameLine();
            if (ImGui::Button("TIMINGS", buttonSize))
                currentPage = 3;
            ImGui::SameLine();
            if (ImGui::Button("INFORMATION", buttonSize))
                currentPage = 4;
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.7f, 0.0f, 0.0f, 1.0f));
            if (ImGui::Button("Exit", ImVec2(40, 20.0f)))
                programstatus.Stop = true;
            ImGui::PopStyleColor();
        }
        ImGui::PopStyleVar(3);

        if (currentPage == 1)
        {
            ImGui::SetCursorPos(ImVec2(135.0f, 35.0f));
            ImGui::Text("Demil27 Gta V Bot");
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            draw_list->AddLine(ImVec2(50, ImGui::GetCursorScreenPos().y), ImVec2(350, ImGui::GetCursorScreenPos().y), ImColor(255, 255, 255), 1.0f);

            ImGui::SetCursorPos(ImVec2(10.0f, 75.0f));
            ImGui::Text("Admin Status: ");
            ImGui::SameLine();
            if (programstatus.isAdmin)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
                ImGui::Text("Active");
                ImGui::PopStyleColor();
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
                ImGui::Text("In-Active");
                ImGui::PopStyleColor();
            }
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));
            ImGui::Text("(not necessary for all pc's)");
            ImGui::PopStyleColor();

            ImGui::SetCursorPos(ImVec2(10.0f, ImGui::GetCursorScreenPos().y));
            ImGui::Text("Bot   Status: ");
            ImGui::SameLine();
            if (programstatus.isRunning)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
                ImGui::Text("Active");
                ImGui::PopStyleColor();
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
                ImGui::Text("In-Active");
                ImGui::PopStyleColor();
            }

            ImGui::SetCursorPos(ImVec2(10.0f, ImGui::GetCursorScreenPos().y + 25.0f));
            if (ImGui::Button("START BOT", ImVec2(180, 35)))
            {
                programstatus.isRunning = true;
                programstatus.console_output += "Bot started at " + printCurTime() + "\n";
            }
            ImGui::SameLine();
            if (ImGui::Button("STOP BOT", ImVec2(180, 35)))
            {
                programstatus.isRunning = false;
                programstatus.windowPrep = false;
                programstatus.console_output += "Bot stopped at " + printCurTime() + "\n";
            }
            //ImGui::SetCursorPos(ImVec2(10.0f, ImGui::GetCursorScreenPos().y + 5.0f));
            //ImGui::Checkbox("Menu overlap Gta V on Start?", &programstatus.overlapOnStart);
            
            // Output display
            ImGui::SetCursorPos(ImVec2(10.0f, 205.0f));
            ImGui::Text("Output Log");
            ImGui::SetCursorPos(ImVec2(10.0f, 225.0f));
            ImGui::BeginChild("ScrollingRegion", ImVec2(380, 140.0f), true, ImGuiWindowFlags_ChildWindow);
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.5f, 0.5f, 0.5f, 1.0f)); // Change the color to red
            ImGui::TextWrapped("%s", programstatus.console_output.c_str());
            ImGui::PopStyleColor();
            ImGui::EndChild();


        }
        if (currentPage == 2)
        {
            ImGui::SetCursorPos(ImVec2(155.0f, 35.0f));
            ImGui::Text("BUSINESSES");

            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            draw_list->AddLine(ImVec2(50, ImGui::GetCursorScreenPos().y), ImVec2(350, ImGui::GetCursorScreenPos().y), ImColor(255, 255, 255), 1.0f);

            ImGui::SetCursorPos(ImVec2(10.0f, 75.0f));
            ImGui::Checkbox("Nightclub Popularity", &nightclub.NightclubBool);
            ImGui::SetCursorPos(ImVec2(50.0f, 95.0f));
            ImGui::Checkbox("Is second dj the resident?", &nightclub.second_dj_resident);
            ImGui::SetCursorPos(ImVec2(50.0f, 115.0f));
            ImGui::Checkbox("Loot the nightclub safe? (coming soon)", &nightclub.NightClubLoot);

            ImGui::SetCursorPos(ImVec2(10.0f, 155.0f));
            ImGui::Checkbox("Bunker", &bunker.BunkerBool);

            ImGui::SetCursorPos(ImVec2(10.0f, 195.0f));
            ImGui::Checkbox("Cocaine Lockup", &cocainelockup.CocaineLockupBool);

            ImGui::SetCursorPos(ImVec2(10.0f, 235.0f));
            ImGui::Checkbox("Meth Lockup", &methlockup.MethLockupBool);

            ImGui::SetCursorPos(ImVec2(10.0f, 275.0f));
            ImGui::Checkbox("Acid Lab", &acidlab.AcidLabBool);
            ImGui::SetCursorPos(ImVec2(50.0f, 295.0f));
            ImGui::PushItemWidth(100);
            ImGui::SliderInt("How far down is Mutt's number?", &acidlab.MuttNumber, 1, 30);
            ImGui::PopItemWidth();


        }
        if (currentPage == 3)
        {
            ImGui::SetCursorPos(ImVec2(155.0f, 35.0f));
            ImGui::Text("TIMINGS");
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            draw_list->AddLine(ImVec2(50, ImGui::GetCursorScreenPos().y), ImVec2(350, ImGui::GetCursorScreenPos().y), ImColor(255, 255, 255), 1.0f);

            ImGui::SetCursorPos(ImVec2(10.0f, 75.0f));
            ImGui::PushItemWidth(100);
            ImGui::SliderInt("Time between resupplies (in minutes) ", &timings.loop_timer, 1, 180);
            ImGui::PopItemWidth();
        }
        if (currentPage == 4)
        {
            ImGui::SetCursorPos(ImVec2(155.0f, 35.0f));

            ImGui::Text("INFORMATION");
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            draw_list->AddLine(ImVec2(50, ImGui::GetCursorScreenPos().y), ImVec2(350, ImGui::GetCursorScreenPos().y), ImColor(255, 255, 255), 1.0f);
            ImGui::SetCursorPos(ImVec2(10.0f, 75.0f));
            ImGui::PushTextWrapPos();

            ImGui::Text("This is a small project I decided to make in order for legit players to be able to afk in more efficiently. All credits go to Emil-Eriks, below is some information if you wish to make this type of project yourself. I will potentially be making updates to this project if people deem it useful enough :)");
            ImGui::SetCursorPos(ImVec2(10.0f, 175.0f));
            ImGui::Bullet(); ImGui::Text("Entirely coded in C++");
            ImGui::SetCursorPos(ImVec2(10.0f, 195.0f));
            ImGui::Bullet(); ImGui::Text("Using keyb_event / mousevent ");
            ImGui::SetCursorPos(ImVec2(10.0f, 215.0f));
            ImGui::Bullet(); ImGui::Text("Gui made using ImGui Dx10 ");

            ImGui::SetCursorPos(ImVec2(10.0f, 255.0f));
            ImGui::Text("For more information (and source code) add");
            ImGui::SetCursorPos(ImVec2(310.0f, 253.0f));
            char str[] = "e006";
            ImGui::PushItemWidth(40);
            ImGui::InputText("on", str, IM_ARRAYSIZE(str), ImGuiInputTextFlags_ReadOnly);
            ImGui::PopItemWidth();
            ImGui::SetCursorPos(ImVec2(10.0f, 270.0f));
            ImGui::Text("discord.");
            ImGui::PopTextWrapPos();
        }

        ImGui::End();
    }

    // Rendering
    ImGui::Render();
    const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
    g_pd3dDevice->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
    g_pd3dDevice->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
    ImGui_ImplDX10_RenderDrawData(ImGui::GetDrawData());

    g_pSwapChain->Present(1, 0);
}