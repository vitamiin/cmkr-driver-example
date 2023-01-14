#include <ntddk.h>
#include "kstd.hpp"

void unload_routine(PDRIVER_OBJECT driver_object) {
    UNREFERENCED_PARAMETER(driver_object);

    DbgPrint("- ZwSchool driver unloaded -\n");
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = unload_routine;

    return STATUS_SUCCESS;
}