#pragma once
#include <Windows.h>
#include <chrono>
#include <thread>
#include <ctime>

bool IsRunningAsAdmin() {
    BOOL isRunAsAdmin = FALSE;
    PSID adminGroupSid = NULL;

    // Allocate and initialize a SID of the administrators group.
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    if (!AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroupSid)) {
        goto Cleanup;
    }

    // Determine whether the SID of administrators group is enabled in 
    // the primary access token of the process.
    if (!CheckTokenMembership(NULL, adminGroupSid, &isRunAsAdmin)) {
        goto Cleanup;
    }

Cleanup:
    // Centralized cleanup for all allocated resources.
    if (adminGroupSid)
    {
        FreeSid(adminGroupSid);
        adminGroupSid = NULL;
    }

    return isRunAsAdmin;
}

std::string printCurTime()
{
    auto now_local = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now_local);
    std::tm local_time;
    localtime_s(&local_time, &current_time);
    char time_str[9];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", &local_time);
    return std::string(time_str);
}
