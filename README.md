# Cpp-CLI_wrapper_Bluetooth_SDP
 C++/CLI wrapper of Bluetooth_SDP_data_DLL for C# and .NET.

 Here you have managed code (APIs) from native C++ unmanaged code (APIs).

 # How to use it
 ## Included headers and libraries for using dll
 - stdio.h
- vector
- iostream
- winsock2.h
- bthdef.h
- bthioctl.h
- functional

## DLL, lib and header
Before you can use this dll file, you must add to your project:

1. header:

copy ioctl_data.h from Bluetooth_SDP_data_DLL to this project
> #include "ioctl_data.h"

2. .lib file:

copy .lib from Bluetooth_SDP_data_DLL to this project
> #pragma comment(lib, "SDP_data.lib")

3. .dll file:

> Add SDP_data.dll into folder where .dll of this project will be with the same type of system (example: x64 Debug)

## Functions
DLL wrapper have next functions:
#### Connection and disconnection functions
- void CLI_connectToDevice(System::String^ str)
- void CLI_closeConnectionToDevice()

#### Search and retriving data functions
- void CLI_SDPsearch(System::String^ str)
- void CLI_getBthDeviceInfo()
- void CLI_getLocalBthInfo()

#### Reset functions
- void CLI_reset_SDP_service_for_search()
- void CLI_reset_attr_search_for_service()

#### Set/Dsiable functions
- void CLI_set_all_SDP_service_for_search()
- void CLI_set_SDP_service_for_search(Int16 service)
- void CLI_set_all_attr_of_SDP_service_for_search()
- void CLI_set_default_attr_of_SDP_service_for_search(Int16 attr)
- void CLI_set_service_specific_attr_of_SDP_service_for_search(Int16 service, Int16 attr)
- void CLI_set_all_default_attr_print()
- void CLI_disable_all_default_attr_print()
- void CLI_set_default_attr_print(Int16 def_attr, int onOff)
- void CLI_set_all_specific_attrs_service_print(Int16 service, int onOff)
- void CLI_set_specific_attr_service_print(Int16 service, Int16 attr, int onOff)

#### Show functions
- void CLI_show_print_service()
- void CLI_show_SDP_service_search()


## Structures
- CLI_SDP_settings^ sdp_settings;
- CLI_SEARCHED_CACHED_DEVICES^ cached_devices;
- CLI_LOCAL_RADIO_DEVICE_DATA^ local_device_radio;
- CLI_A2DP_EXPORT^ a2dp_export;
- CLI_AVRCP_EXPORT^ avrcp_export;
- CLI_MAP_EXPORT^ map_export;
- CLI_HFP_EXPORT^ hfp_export;
- CLI_HSP_EXPORT^ hsp_export;
- CLI_NAP_EXPORT^ nap_export;
- CLI_OBEX_EXPORT^ obex_export;
- CLI_PBAP_EXPORT^ pbap_export;
- CLI_INFO_EXPORT^ pnpinfo_export;


## Settings of dll
#### Printing

#### Attributes Searching

#### Service Searching

## Main structures

# Examples 

