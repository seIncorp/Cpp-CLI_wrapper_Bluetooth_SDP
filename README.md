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
> With this function you will connect to local bluetooth radio
> input parameter: System::String^ str (for example: "\\\\?\\GLOBALROOT\\Device\\USBPDO-4") (you need physical device object name of Generic Bluetooth Radio)
- void CLI_closeConnectionToDevice()
> with this function you will close connection to local bluetooth radio (YOU MUST CALL THIS before app is closed!!!)

#### Search and retriving data functions
- void CLI_SDPsearch(System::String^ str)
> Here you can search for service data of remote bluetooth device
> input parameter: System::String^ str (you need bluetooth address of remote bluetooth device) (for example: "A8:B8:6E:E7:5A:B6")
- void CLI_getBthDeviceInfo()
> Here you will get list of all remote devices from previous search
- void CLI_getLocalBthInfo()
> here you will get data of local bluetooth radio

#### Reset functions
- void CLI_reset_SDP_service_for_search()
> Here you will set all service to false for search
- void CLI_reset_attr_search_for_service()
> Here you will set all attributes to false for search

#### Set/Dsiable functions
- void CLI_set_all_SDP_service_for_search()
> Here you set all services to TRUE for search
- void CLI_set_SDP_service_for_search(Int16 service)
> Here you set specific service to TRUE for search
- void CLI_disable_SDP_service_for_search(Int16 service)
> Here you set specific service to FALSE for search
- void CLI_set_all_attr_of_SDP_service_for_search()
> Here you can set all atrributes for search
- void CLI_set_default_attr_of_SDP_service_for_search(Int16 attr)
> Here you can set only default attribute to TRUE for search
- void CLI_set_service_specific_attr_of_SDP_service_for_search(Int16 service, Int16 attr)
> Here you can set only service specific attribute to TRUE for search
- void CLI_set_all_default_attr_print()
> Here you can set all default atrributes to TRUE for print in console
- void CLI_disable_all_default_attr_print()
> Here you can set all default atrributes to FALSE for print in console
- void CLI_set_default_attr_print(Int16 def_attr, int onOff)
> Here you can set default attribute to TRUE or FALSE for print in console
- void CLI_set_all_specific_attrs_service_print(Int16 service, int onOff)
> Here you can set all service specific atrributes to TRUE or FALSE for print in console
- void CLI_set_specific_attr_service_print(Int16 service, Int16 attr, int onOff)
> Here you can set service specific attribute to TRUE or FALSE for print in console

#### Show functions
- void CLI_show_print_service()
> IN PROGRESS...
- void CLI_show_SDP_service_search()
> IN PROGRESS...


## Structures (Details in progress...)
- CLI_SDP_settings^ sdp_settings;
> Look at Settings of dll
- CLI_SEARCHED_CACHED_DEVICES^ cached_devices;
> Here you get list of devices
- CLI_LOCAL_RADIO_DEVICE_DATA^ local_device_radio;
> Here you get all data of local bluetooth radio
- CLI_A2DP_EXPORT^ a2dp_export
> Exported data for AudioSource service
- CLI_AVRCP_EXPORT^ avrcp_export
> Exported data for A_V_RemoteControl, A_V_RemoteControlTarget and A_V_RemoteControlController services
- CLI_MAP_EXPORT^ map_export
> Exported data for Message_Access_Server service
- CLI_HFP_EXPORT^ hfp_export
> Exported data for Handsfree and HandsfreeAudioGateway services
- CLI_HSP_EXPORT^ hsp_export
> Exported data for Headset and Headset_Audio_Gateway service
- CLI_NAP_EXPORT^ nap_export
> Exported data for Android Network Access Point and PANU(in progress...) service
- CLI_OBEX_EXPORT^ obex_export
> Exported data for OBEXObjectPush service
- CLI_PBAP_EXPORT^ pbap_export
> Exported data for Phonebook_Access_PSE service
- CLI_INFO_EXPORT^ pnpinfo_export
> Exported data for PnPInformation service


## Settings of dll
#### Printing
- Debug
- print
- print_service
#### Attributes Searching
> Through void CLI_set_all_attr_of_SDP_service_for_search(), void CLI_set_default_attr_of_SDP_service_for_search(Int16 attr) and void CLI_set_service_specific_attr_of_SDP_service_for_search(Int16 service, Int16 attr)
> you can set TRUE or false
#### Service Searching
> Through void CLI_set_all_SDP_service_for_search(), void CLI_set_SDP_service_for_search(Int16 service) and void CLI_disable_SDP_service_for_search(Int16 service)
> you can set TRUE or false

# How to use it on client app
You have more options:
1. in project add as new reference for "Cpp-CLI_wrapper_Bluetooth_SDP.dll"
2. copy&paste "Cpp-CLI_wrapper_Bluetooth_SDP.dll" and "SDP_data.dll" to your app project

# Examples 
### Connection and disconnection from local radio
#### Code
```
// 1. you must create class instance
CLI_DEFAULT_DATA data = new CLI_DEFAULT_DATA();
// 2. call CLI_connectToDevice to connect to local bluetooth radio
data.CLI_connectToDevice("\\\\?\\GLOBALROOT\\Device\\USBPDO-4");
// 3. close the connection
data.CLI_closeConnectionToDevice();
```

### Getting list of previously searched devices and export/print data
#### Code
```
// 1. you must create class instance
CLI_DEFAULT_DATA data = new CLI_DEFAULT_DATA();

// 2. call CLI_connectToDevice to connect to local bluetooth radio
data.CLI_connectToDevice("\\\\?\\GLOBALROOT\\Device\\USBPDO-4");

// 3.1 if you want to print it in console you must set
data.sdp_settings.print = 1;

// 3.2 calling driver to return list of devices
data.CLI_getBthDeviceInfo();

// 3.1.1 or if you have disabled data.sdp_settings.print you can use
// data.cached_devices.print();

// 3.3 exporting data
Console.WriteLine("{0}",data.cached_devices.devices[0].name);

// 4. close the connection
data.CLI_closeConnectionToDevice();
```
#### Response
```
*********** DEVICES *************
NUM: 8
************************
NAME: Nexus 6
FLAGS: 18335
ADDRESS: 44:80:EB:EF:D2:CE
.
.
.
```

### Getting all data of local bluetooth radio
#### Code
```
// 1. you must create class instance
CLI_DEFAULT_DATA data = new CLI_DEFAULT_DATA();

// 2. call CLI_connectToDevice to connect to local bluetooth radio
data.CLI_connectToDevice("\\\\?\\GLOBALROOT\\Device\\USBPDO-4");

// 3.1 if you want to print it in console you must set
data.sdp_settings.print = 1;

// 3.2 calling local radio driver
data.CLI_getLocalBthInfo();

// 3.1.1 or if you have disabled data.sdp_settings.print you can use
// data.local_device_radio.print();

// 3.3 exporting data
Console.WriteLine("{0}",data.local_device_radio.radio.LMP_major_version);

// 4. close the connection
data.CLI_closeConnectionToDevice();
```
#### Response
```
LOCAL DEVICE and RADIO DATA:
        Flags: 2
        Version: 6.8891 (Major.Minor version HCI)
        Name: DESKTOP-HJ6NMIA
ADDRESS: XX:XX:XX:XX:XX:XX
FLAGS: 7
        DEVICE COD data:
                Major service class:
                        Networking (LAN, Ad hoc, ...)
                        Capturing (Scanner, Microphone, ...)
                        Audio (Speaker, Microphone, Headset service, ...)
                Major device class:
                        Computer (desktop,notebook, PDA, organizers, .... )
                Minor device class:
                        Desktop workstation

        RADIO DATA:
                LMP version: 6.8891
                LMP Supported Features: 875BFFDBFE8FFFFF
                ID of the manufacturer: 10
```

### Getting one SDP service data (searching, printing and exporting)
#### Code
```
// 1. you must create class instance
CLI_DEFAULT_DATA data = new CLI_DEFAULT_DATA();

// 2.1 if you want to print it in console you must set
data.sdp_settings.print = 1;

// 3.1 good practice (reseting to FALSE all settings)
data.CLI_reset_SDP_service_for_search();      
data.CLI_reset_attr_search_for_service();

// 3.2 enabling AudioSource service for searching on device and enabling all attributes to search
data.CLI_set_SDP_service_for_search((short)CLI_SERVICE_CLASS_ID.AudioSource);
data.CLI_set_all_attr_of_SDP_service_for_search();

// 4. call CLI_connectToDevice to connect to local bluetooth radio
data.CLI_connectToDevice("\\\\?\\GLOBALROOT\\Device\\USBPDO-4");

// 5. calling CLI_SDPsearch() function with device bluetooth address
data.CLI_SDPsearch("XX:XX:XX:XX:XX:XX");

// 6. exporting data


// 7. close the connection
data.CLI_closeConnectionToDevice();
```

#### Response
```
************************************************
RECORD HANDLE:
ATTRIBUTE ID:
Type: [1]
Size: 2 Bytes [2]
Value: 0x0000
VALUE ELEMENT:
Type:  [1]
Size: 4 Bytes [4]
Value: 0x00010006
Record handle: 0x00010006

************************************************
CLASS ID:
ATTRIBUTE ID:
Type: [1]
Size: 2 Bytes [2]
Value: 0x0001
VALUE ELEMENT:
Type:  [6]
Additional size: 1
Data size: 3
Value:
0x19 0x11 0x0A
Class ID [0]: 0x110A
.
.
.
```