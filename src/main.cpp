#include <ntddk.h>
#include "kstd.hpp"

void unload_routine(PDRIVER_OBJECT driver_object) {
    UNREFERENCED_PARAMETER(driver_object);

    DbgPrint("- Cmkr driver unloaded -\n");
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = unload_routine;

    DbgPrint("Hello from a cmkr kernel driver!");

    return STATUS_SUCCESS;
}