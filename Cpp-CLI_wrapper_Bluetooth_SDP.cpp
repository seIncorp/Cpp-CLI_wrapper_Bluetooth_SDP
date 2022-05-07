#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()
#include <vector>


using namespace System;

CLI_DEFAULT_DATA::CLI_DEFAULT_DATA()
{
	dd = new IOCTL_S::DEFAULT_DATA();

	setNativeDLLSettingsToFalse();

	sdp_settings = gcnew CLI_SDP_settings();
}

CLI_DEFAULT_DATA::~CLI_DEFAULT_DATA()
{
	if (dd != nullptr)
	{
		if (dd->services_for_search.AudioSource == 1)
		{
			delete_exported_data_A2DP();
		}

		if (dd->services_for_search.A_V_RemoteControl == 1)
		{
			delete_exported_data_AVRCP();
		}

		if (dd->services_for_search.Message_Access_Server == 1)
		{
			delete_exported_data_MAP();
		}

		if (dd->services_for_search.Handsfree == 1 || dd->services_for_search.HandsfreeAudioGateway == 1)
		{
			// TODO: preveri kako je s tem, ker se je spreminjalo
			delete_exported_data_HFP();
		}

		// TODO: preveri kako je s tem, ker se je spreminjalo
		if (dd->services_for_search.Headset == 1 || dd->services_for_search.Headset_Audio_Gateway == 1)
			delete_exported_data_HSP();

		if (dd->services_for_search._NAP == 1)
			delete_exported_data_NAP();

		if (dd->services_for_search.OBEXObjectPush == 1)
			delete_exported_data_OBEX();

		if (dd->services_for_search.Phonebook_Access_PSE == 1)
			delete_exported_data_PBAP();

		if (dd->services_for_search.PnPInformation == 1)
			delete_exported_data_PNPINFO();

		delete sdp_settings;

		delete dd;
		dd = nullptr;
	}
}

CLI_DEFAULT_DATA::!CLI_DEFAULT_DATA()
{
	if (dd != nullptr)
	{
		if (dd->services_for_search.AudioSource == 1)
		{
			delete_exported_data_A2DP();
		}

		if (dd->services_for_search.A_V_RemoteControl == 1)
		{
			// TODO: preveri kako je s tem, ker se je spreminjalo
			delete_exported_data_AVRCP();
		}

		if (dd->services_for_search.Message_Access_Server == 1)
		{
			delete_exported_data_MAP();
		}

		if (dd->services_for_search.Handsfree == 1 || dd->services_for_search.HandsfreeAudioGateway == 1)
		{
			// TODO: preveri kako je s tem, ker se je spreminjalo
			delete_exported_data_HFP();
		}

		// TODO: preveri kako je s tem, ker se je spreminjalo
		if (dd->services_for_search.Headset == 1 || dd->services_for_search.Headset_Audio_Gateway == 1)
			delete_exported_data_HSP();

		if (dd->services_for_search._NAP == 1)
			delete_exported_data_NAP();

		if (dd->services_for_search.OBEXObjectPush == 1)
			delete_exported_data_OBEX();

		if (dd->services_for_search.Phonebook_Access_PSE == 1)
			delete_exported_data_PBAP();

		if (dd->services_for_search.PnPInformation == 1)
			delete_exported_data_PNPINFO();

		delete sdp_settings;

		delete dd;
		dd = nullptr;
	}
}


void CLI_DEFAULT_DATA::setNativeDLLSettingsToFalse()
{
	// PRINTING
	dd->sdp_settings.debug = 0;
	dd->sdp_settings.print = 0;
	dd->sdp_settings.print_info = 0;
	dd->sdp_settings.print_with_outside_funct = 0;
	dd->set_all_default_attr_service_PRINT(0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Headset, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Handsfree, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControl, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::AudioSource, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, 0);
	dd->set_all_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, 0);

	// SEARCHING
	dd->reset_all_SDP_service_for_search();
	dd->reset_all_attr_search_for_service();
}



void CLI_DEFAULT_DATA::CLI_connectToDevice(System::String^ str)
{
	pin_ptr<const wchar_t> convertedValue = PtrToStringChars(str);
	const wchar_t* constValue = convertedValue;

	if (IOCTL_S::connectToDevice(constValue, *dd) == 1)
	{
		if (sdp_settings->debug == 1)
			Console::WriteLine("CONNECTED!!");
	}
	else
		if (sdp_settings->debug == 1)
			Console::WriteLine("FAIL TO CONNECT!!!");
}

void CLI_DEFAULT_DATA::CLI_closeConnectionToDevice()
{
	if (IOCTL_S::closeConnectionToDevice(*dd) == 1)
		if (sdp_settings->debug == 1)
			Console::WriteLine("CLOSED!!");
		else
			if (sdp_settings->debug == 1)
				Console::WriteLine("FAILED TO CLOSE!!");
}



void CLI_DEFAULT_DATA::CLI_SDPsearch(System::String^ str)
{
	using namespace System::Runtime::InteropServices;
	char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);

	dd->sdp_settings.print_info = 1;
	dd->sdp_settings.debug = 1;
	//dd->sdp_settings.print = 1;
	//dd->sdp_settings.print_service.print_PNPINFO_attributes.SpecificationID = 1;

	if (IOCTL_S::SDPsearch(*dd, str2) == 1)
	{
		if (sdp_settings->debug == 1)
			Console::WriteLine("SEARCHED!!");

		if (dd->services_for_search.AudioSource == 1)
			save_exported_data_A2DP();

		if (dd->services_for_search.Message_Access_Server == 1)
			save_exported_data_MAP();

		if (dd->services_for_search._NAP == 1)
			save_exported_data_NAP();

		if (dd->services_for_search.OBEXObjectPush == 1)
			save_exported_data_OBEX();

		if (dd->services_for_search.Phonebook_Access_PSE == 1)
			save_exported_data_PBAP();

		if (dd->services_for_search.PnPInformation == 1)
			save_exported_data_PNPINFO();

		if (dd->services_for_search.Headset == 1 || dd->services_for_search.Headset_Audio_Gateway == 1)
			save_exported_data_HSP();

		if (dd->services_for_search.Handsfree == 1 || dd->services_for_search.HandsfreeAudioGateway == 1)
			save_exported_data_HFP();

		if (dd->services_for_search.A_V_RemoteControl == 1 ||
			dd->services_for_search.A_V_RemoteControlTarget == 1 ||
			dd->services_for_search.A_V_RemoteControlController == 1
			)
			save_exported_data_AVRCP();
	}
	else
		if (sdp_settings->debug == 1)
			Console::WriteLine("FAILED TO SEARCH!!!");
}

void CLI_DEFAULT_DATA::CLI_getBthDeviceInfo()
{
	if (IOCTL_S::getBthDeviceInfo(*dd, 0) == 1)
	{
		cached_devices = gcnew CLI_SEARCHED_CACHED_DEVICES();

		if (sdp_settings->debug == 1)
			Console::WriteLine("getBthDeviceInfo!!");

		cached_devices->numOfDevices = (UInt32)dd->exported_data.devices->numOfDevices;

		cached_devices->devices = gcnew array<CLI_CACHED_DEVICE^>(cached_devices->numOfDevices);

		for (int i = 0; i < dd->exported_data.devices->devices.size(); i++)
		{
			cached_devices->devices[i] = gcnew CLI_CACHED_DEVICE();
			System::String^ str = System::Runtime::InteropServices::Marshal::PtrToStringAnsi(static_cast<System::IntPtr>(dd->exported_data.devices->devices.at(i).getName()));

			cached_devices->devices[i]->flags = dd->exported_data.devices->devices.at(i).getFlags();
			cached_devices->devices[i]->name = str;
			cached_devices->devices[i]->address = gcnew array< BYTE^ >(6);

			for (int a = 0; a < 6; a++)
				cached_devices->devices[i]->address[a] = dd->exported_data.devices->devices.at(i).getAddress()[a];
		}

		if (sdp_settings->print == 1)
			cached_devices->print();
	}
	else
		if (sdp_settings->debug == 1)
			Console::WriteLine("FAILED TO getBthDeviceInfo!!!");
}

void CLI_DEFAULT_DATA::CLI_getLocalBthInfo()
{
	IOCTL_S::getLocalBthInfo(*dd, 0);

	if (sdp_settings->debug == 1)
		Console::WriteLine("getLocalBthInfo!!");

	local_device_radio = gcnew CLI_LOCAL_RADIO_DEVICE_DATA();

	local_device_radio->flags = dd->exported_data.local_device_radio->flags;
	local_device_radio->HCI_major_version = dd->exported_data.local_device_radio->HCI_major_version;
	local_device_radio->HCI_minor_version = dd->exported_data.local_device_radio->HCI_minor_version;


	local_device_radio->device = gcnew CLI_DEVICE_DATA();
	System::String^ str = System::Runtime::InteropServices::Marshal::PtrToStringAnsi(static_cast<System::IntPtr>(dd->exported_data.local_device_radio->device->name));
	local_device_radio->device->name = str;

	// ADDRESS
	local_device_radio->device->address = gcnew array< BYTE^ >(6);

	for (int i = 0; i < 6; i++)
		local_device_radio->device->address[i] = dd->exported_data.local_device_radio->device->address[i];

	// FLAGS
	local_device_radio->device->flags = dd->exported_data.local_device_radio->device->flags;

	// COD
	local_device_radio->device->cod = gcnew CLI_DEVICE_PARSED_COD_DATA();

	for (int i = 0; i < dd->exported_data.local_device_radio->device->cod->major_service_class.size(); i++)
	{
		str = System::Runtime::InteropServices::Marshal::PtrToStringAnsi(static_cast<System::IntPtr>(dd->exported_data.local_device_radio->device->cod->major_service_class.at(i)));
		local_device_radio->device->cod->major_service_class.push_back(gcnew System::String(str));
	}

	for (int i = 0; i < dd->exported_data.local_device_radio->device->cod->major_device_class.size(); i++)
	{
		str = System::Runtime::InteropServices::Marshal::PtrToStringAnsi(static_cast<System::IntPtr>(dd->exported_data.local_device_radio->device->cod->major_device_class.at(i)));
		local_device_radio->device->cod->major_device_class.push_back(gcnew System::String(str));
	}

	for (int i = 0; i < dd->exported_data.local_device_radio->device->cod->minor_device_class.size(); i++)
	{
		str = System::Runtime::InteropServices::Marshal::PtrToStringAnsi(static_cast<System::IntPtr>(dd->exported_data.local_device_radio->device->cod->minor_device_class.at(i)));
		local_device_radio->device->cod->minor_device_class.push_back(gcnew System::String(str));
	}

	// RADIO DATA
	local_device_radio->radio = gcnew CLI_RADIO_DATA();

	local_device_radio->radio->LMP_SupportedFeatures = dd->exported_data.local_device_radio->radio->LMP_SupportedFeatures;
	local_device_radio->radio->mfg = dd->exported_data.local_device_radio->radio->mfg;
	local_device_radio->radio->LMP_minor_version = dd->exported_data.local_device_radio->radio->LMP_minor_version;
	local_device_radio->radio->LMP_major_version = dd->exported_data.local_device_radio->radio->LMP_major_version;

	if (sdp_settings->print == 1)
		local_device_radio->print();
}





void CLI_DEFAULT_DATA::CLI_set_all_SDP_service_for_search()
{
	dd->set_all_SDP_service_for_search();

	if (sdp_settings->debug == 1)
		Console::WriteLine("[DEBUG] CLI_set_all_SDP_service_for_search()");
}

void CLI_DEFAULT_DATA::CLI_set_SDP_service_for_search(Int16 service, int OnOff)
{
	if (OnOff)
	{
		// TODO: ko se bo vracalo 1 ali 0 potem tudi napis prilagodi
		dd->set_SDP_service_for_search(service, 1);
		if (sdp_settings->debug == 1)
			Console::Write("[DEBUG] [Service search ON] ");
	}
	else
	{
		dd->set_SDP_service_for_search(service, 0);
		if (sdp_settings->debug == 1)
			Console::Write("[DEBUG] [Service search OFF] ");
	}

	if (sdp_settings->debug == 1)
		switch (service)
		{
		case SDP::SERVICE_CLASS_ID::PnPInformation:
			Console::Write("PnPInformation");
			break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			Console::Write("Phonebook_Access_PSE");
			break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			Console::Write("OBEXObjectPush");
			break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			Console::Write("_NAP");
			break;

		case (SDP::SERVICE_CLASS_ID::Headset):
			Console::Write("Headset");
			break;

		case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
			Console::Write("Headset_Audio_Gateway");
			break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			Console::Write("Handsfree");
			break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			Console::Write("HandsfreeAudioGateway");
			break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
			Console::Write("A_V_RemoteControl");
			break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
			Console::Write("A_V_RemoteControlTarget");
			break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
			Console::Write("A_V_RemoteControlController");
			break;

		case SDP::SERVICE_CLASS_ID::AudioSource:
			Console::Write("AudioSource");
			break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			Console::Write("Message_Access_Server");
			break;

		case SDP::SERVICE_CLASS_ID::GenericAudio:
			Console::Write("GenericAudio");
			break;

		default:
			Console::Write("Unknown service");
			break;
		}

	if (sdp_settings->debug == 1)
		Console::WriteLine("");
}


void CLI_DEFAULT_DATA::CLI_set_all_attr_of_SDP_service_for_search()
{
	dd->set_all_attr_search_for_service();

	if (sdp_settings->debug == 1)
		Console::WriteLine("[DEBUG] CLI_set_all_attr_of_SDP_service_for_search()");
}


void CLI_DEFAULT_DATA::CLI_set_default_attr_of_SDP_service_for_search(Int16 attr, int OnOff)
{
	if (OnOff)
	{
		dd->set_default_attr_search_for_service(attr, 1);
		if (sdp_settings->debug == 1)
			Console::Write("[DEBUG] [Default attribute ON] ");
	}
	else
	{
		dd->set_default_attr_search_for_service(attr, 0);
		if (sdp_settings->debug == 1)
			Console::Write("[DEBUG] [Default attribute OFF] ");
	}

	if (sdp_settings->debug == 1)
		switch (attr)
		{
		case (short)CLI_ATTRIBUTE_ID::ServiceRecordHandle:
			Console::Write("ServiceRecordHandle");
			break;

		case (short)CLI_ATTRIBUTE_ID::ServiceClassIDList:
			Console::Write("ServiceClassIDList");
			break;

		case (short)CLI_ATTRIBUTE_ID::ProtocolDescriptorList:
			Console::Write("ProtocolDescriptorList");
			break;

		case (short)CLI_ATTRIBUTE_ID::ServiceName:
			Console::Write("ServiceName");
			break;

		case (short)CLI_ATTRIBUTE_ID::BluetoothProfileDescriptorList:
			Console::Write("BluetoothProfileDescriptorList");
			break;

		case (short)CLI_ATTRIBUTE_ID::ProviderName:
			Console::Write("ProviderName");
			break;

		case (short)CLI_ATTRIBUTE_ID::LanguageBaseAttributeIDList:
			Console::Write("LanguageBaseAttributeIDList");
			break;

		case (short)CLI_ATTRIBUTE_ID::ServiceDescription:
			Console::Write("ServiceDescription");
			break;

		default:
			Console::WriteLine("Unknown attribute");
			break;
		}

	if (sdp_settings->debug == 1)
		Console::WriteLine("");
}

void CLI_DEFAULT_DATA::CLI_set_service_specific_attr_of_SDP_service_for_search(Int16 service, Int16 attr, int OnOff)
{
	if (OnOff)
	{
		// TODO: naredi ko se bo vracalo ok ali false
		dd->set_special_attr_search_for_service(service, attr, 1);
		if (sdp_settings->debug == 1)
			Console::Write("[DEBUG] [Specific attribute ON] ");
	}
	else
	{
		dd->set_special_attr_search_for_service(service, attr, 0);
		if (sdp_settings->debug == 1)
			Console::Write("[DEBUG] [Specific attribute OFF] ");
	}

	if (sdp_settings->debug == 1)
		switch (service)
		{
		case (short)CLI_SERVICE_CLASS_ID::Headset:
			switch (attr)
			{
			case (short)CLI_HSP::CLI_ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl:
				Console::Write("Headset -> RemoteAudioVolumeControl");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::AudioSource:
			switch (attr)
			{
			case (short)CLI_A2DP::CLI_ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures:
				Console::Write("AudioSource -> SupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::Headset_Audio_Gateway:
			switch (attr)
			{
			case (short)CLI_HSP::CLI_ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl:
				Console::Write("Headset_Audio_Gateway -> RemoteAudioVolumeControl");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::Handsfree:
			switch (attr)
			{
			case (short)CLI_HFP::CLI_ATTRIBUTE_ID_HFP::Network:
				Console::Write("Handsfree -> Network");
				break;

			case (short)CLI_HFP::CLI_ATTRIBUTE_ID_HFP::SupportedFeatures:
				Console::Write("Handsfree -> SupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::OBEXObjectPush:
			switch (attr)
			{
			case (short)CLI_OBEX::CLI_ATTRIBUTE_ID_OBEX::GoepL2capPsm:
				Console::Write("OBEXObjectPush -> GoepL2capPsm");
				break;

			case (short)CLI_OBEX::CLI_ATTRIBUTE_ID_OBEX::ServiceVersion:
				Console::Write("OBEXObjectPush -> ServiceVersion");
				break;

			case (short)CLI_OBEX::CLI_ATTRIBUTE_ID_OBEX::SupportedFormatsList:
				Console::Write("OBEXObjectPush -> SupportedFormatsList");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::A_V_RemoteControl:
			switch (attr)
			{
			case (short)CLI_AVRCP::CLI_ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures:
				Console::Write("A_V_RemoteControl -> SupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::A_V_RemoteControlTarget:
			switch (attr)
			{
			case (short)CLI_AVRCP::CLI_ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures:
				Console::Write("A_V_RemoteControlTarget -> SupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::A_V_RemoteControlController:
			switch (attr)
			{
			case (short)CLI_AVRCP::CLI_ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures:
				Console::Write("A_V_RemoteControlController -> SupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::PANU:
			switch (attr)
			{
			case (short)CLI_NAP::CLI_ATTRIBUTE_ID_PAN::SecurityDescription:
				Console::Write("PANU -> SecurityDescription");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::_NAP:
			switch (attr)
			{
			case (short)CLI_NAP::CLI_ATTRIBUTE_ID_PAN::SecurityDescription:
				Console::Write("_NAP -> SecurityDescription");
				break;

			case (short)CLI_NAP::CLI_ATTRIBUTE_ID_PAN::NetAccessType:
				Console::Write("_NAP -> NetAccessType");
				break;

			case (short)CLI_NAP::CLI_ATTRIBUTE_ID_PAN::MaxNetAccessrate:
				Console::Write("_NAP -> MaxNetAccessrate");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::HandsfreeAudioGateway:
			switch (attr)
			{
			case (short)CLI_HFP::CLI_ATTRIBUTE_ID_HFP::Network:
				Console::Write("HandsfreeAudioGateway -> Network");
				break;

			case (short)CLI_HFP::CLI_ATTRIBUTE_ID_HFP::SupportedFeatures:
				Console::Write("HandsfreeAudioGateway -> SupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::Phonebook_Access_PSE:
			switch (attr)
			{
			case (short)CLI_PBAP::CLI_ATTRIBUTE_ID_PBAP::GoepL2capPsm:
				Console::Write("Phonebook_Access_PSE -> GoepL2capPsm");
				break;

			case (short)CLI_PBAP::CLI_ATTRIBUTE_ID_PBAP::SupportedRepositories:
				Console::Write("Phonebook_Access_PSE -> SupportedRepositories");
				break;

			case (short)CLI_PBAP::CLI_ATTRIBUTE_ID_PBAP::PbapSupportedFeatures:
				Console::Write("Phonebook_Access_PSE -> PbapSupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::Message_Access_Server:
			switch (attr)
			{
			case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::GoepL2capPsm:
				Console::Write("Message_Access_Server -> GoepL2capPsm");
				break;

			case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::MASInstanceID:
				Console::Write("Message_Access_Server -> MASInstanceID");
				break;

			case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::SupportedMessageTypes:
				Console::Write("Message_Access_Server -> SupportedMessageTypes");
				break;

			case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::MapSupportedFeatures:
				Console::Write("Message_Access_Server -> MapSupportedFeatures");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		case (short)CLI_SERVICE_CLASS_ID::PnPInformation:
			switch (attr)
			{
			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::SpecificationID:
				Console::Write("PnPInformation -> SpecificationID");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::VendorID:
				Console::Write("PnPInformation -> VendorID");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::ProductID:
				Console::Write("PnPInformation -> ProductID");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::Version:
				Console::Write("PnPInformation -> Version");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord:
				Console::Write("PnPInformation -> PrimaryRecord");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource:
				Console::Write("PnPInformation -> VendorIDSource");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL:
				Console::Write("PnPInformation -> ClientExecutableURL");
				break;

			case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL:
				Console::Write("PnPInformation -> DocumentationURL");
				break;

			default:
				Console::WriteLine("Unknown attribute");
				break;
			}
			break;

		default:
			Console::WriteLine("Unknown Service");
			break;
		}

	if (sdp_settings->debug == 1)
		Console::WriteLine("");
}


// TODO: razmisli ce se to sploh rabi, mogoce za debug
void CLI_DEFAULT_DATA::CLI_show_SDP_service_search()
{
	// TODO: dodaj se za druge service npr. GenericAudio
	if (dd->services_for_search.PnPInformation == 1)
		Console::WriteLine("[Service search ON] PnPInformation");
	else
		Console::WriteLine("[Service search OFF] PnPInformation");

	if (dd->services_for_search.Phonebook_Access_PSE == 1)
		Console::WriteLine("[Service search ON] Phonebook_Access_PSE");
	else
		Console::WriteLine("[Service search OFF] Phonebook_Access_PSE");


	if (dd->services_for_search.OBEXObjectPush == 1)
		Console::WriteLine("[Service search ON] OBEXObjectPush");
	else
		Console::WriteLine("[Service search OFF] OBEXObjectPush");


	if (dd->services_for_search._NAP == 1)
		Console::WriteLine("[Service search ON] _NAP");
	else
		Console::WriteLine("[Service search OFF] _NAP");


	if (dd->services_for_search.Headset == 1)
		Console::WriteLine("[Service search ON] Headset");
	else
		Console::WriteLine("[Service search OFF] Headset");


	if (dd->services_for_search.Handsfree == 1)
		Console::WriteLine("[Service search ON] Handsfree");
	else
		Console::WriteLine("[Service search OFF] Handsfree");


	if (dd->services_for_search.A_V_RemoteControl == 1)
		Console::WriteLine("[Service search ON] A_V_RemoteControl");
	else
		Console::WriteLine("[Service search OFF] A_V_RemoteControl");


	if (dd->services_for_search.AudioSource == 1)
		Console::WriteLine("[Service search ON] AudioSource");
	else
		Console::WriteLine("[Service search OFF] AudioSource");


	if (dd->services_for_search.Message_Access_Server == 1)
		Console::WriteLine("[Service search ON] Message_Access_Server");
	else
		Console::WriteLine("[Service search OFF] Message_Access_Server");

	Console::WriteLine("");
}
