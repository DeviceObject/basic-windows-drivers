#include <iostream>
#include <memory>
#include <string>
#include <format>
#include <stdexcept>
#include <Windows.h>
#include <fwpmu.h>
#include <Winternl.h>
#include <guiddef.h>
#include "Guids.hpp"

// WFP error codes: https://docs.microsoft.com/en-us/windows/win32/fwp/wfp-error-codes

import wfpcontroller.windowsfilteringplatform;

//struct FilterEngineDeleter
//{
//    void operator()(HANDLE engineHandle)
//    {
//        DWORD status = FwpmCalloutDeleteByKey0(engineHandle, &WFP_PROVIDER_GUID);
//        if (status != ERROR_SUCCESS)
//            std::cout << "FwpmCalloutDeleteByKey0() failed\n";
//    }
//};
//using FilterEngineUniquePtr = std::unique_ptr<std::remove_pointer<HANDLE>::type, FilterEngineDeleter>;

int main(int argc, char* argv[])
{
    HANDLE engineHandle = nullptr;
    try
    {
        WFPController::WindowsFilteringPlatform engine;

        bool execute = true;
        std::string input;
        while (execute)
        {
            std::cout << "Enter input...\n";
            std::cin >> input;

            if (input == "exit")
            {
                return 0;
            }
            else if (input == "open")
            {
                engine.OpenFilterEngine();
            }
            else if (input == "close")
            {
                engine.Close();
            }
            else if (input == "register")
            {
                engine.RegisterProvider();
            }
            else if (input == "callouts")
            {
                engine.AddCallouts();
            }
            else if (input == "sublayer")
            {
                engine.AddSublayer();
            }
            else if (input == "filter")
            {
                engine.AddFilters();
            }
            else if (input == "all")
            {
                engine.OpenFilterEngine();
                engine.RegisterProvider();
                engine.AddSublayer();
                engine.AddCallouts();
                engine.AddFilters();
            }
        }

        return 0;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

