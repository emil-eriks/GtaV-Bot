#pragma once
#include "../imgui_include_folder/includes.h"

extern ID3D10Device* g_pd3dDevice;
extern IDXGISwapChain* g_pSwapChain;
extern UINT g_ResizeWidth, g_ResizeHeight;
extern ID3D10RenderTargetView* g_mainRenderTargetView;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
