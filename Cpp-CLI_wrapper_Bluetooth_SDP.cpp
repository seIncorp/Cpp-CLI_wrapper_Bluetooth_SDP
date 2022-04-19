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
			delete_exported_data_HFP();
		}

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
			delete_exported_data_AVRCP();
		}

		if (dd->services_for_search.Message_Access_Server == 1)
		{
			delete_exported_data_MAP();
		}

		if (dd->services_for_search.Handsfree == 1 || dd->services_for_search.HandsfreeAudioGateway == 1)
		{
			delete_exported_data_HFP();
		}

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
	// Currently all printing are disabled by default
	dd->sdp_settings.debug = 0;
	dd->sdp_settings.print = 0;
	dd->sdp_settings.print_info = 0;
	dd->sdp_settings.print_with_outside_funct = 0;


	dd->sdp_settings.print_service.print_service_record = 0;
	dd->sdp_settings.print_service.print_service_class_id_list = 0;
	dd->sdp_settings.print_service.print_protocol_descriptor_list = 0;
	dd->sdp_settings.print_service.print_service_name = 0;
	dd->sdp_settings.print_service.print_provider_name = 0;
	dd->sdp_settings.print_service.print_bluetooth_profile_descriptor_list = 0;
	dd->sdp_settings.print_service.print_language_base_attribute_id_list = 0;
	dd->sdp_settings.print_service.print_service_description = 0;


	dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info = 0;

	dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 0;
	dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 0;
	dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 0;

	dd->sdp_settings.print_service.print_OBEX_attributes.print_goepl2cappsm = 0;
	dd->sdp_settings.print_service.print_OBEX_attributes.print_supported_formats = 0;
	dd->sdp_settings.print_service.print_OBEX_attributes.print_service_version = 0;

	dd->sdp_settings.print_service.print_NAP_attributes.print_security_description = 0;
	dd->sdp_settings.print_service.print_NAP_attributes.print_max_net_access_rate = 0;
	dd->sdp_settings.print_service.print_NAP_attributes.print_net_access_type = 0;

	dd->sdp_settings.print_service.print_HSP_attributes.print_remote_audio_volume_control = 0;

	dd->sdp_settings.print_service.print_HFP_attributes.print_network = 0;
	dd->sdp_settings.print_service.print_HFP_attributes.print_supported_features = 0;

	dd->sdp_settings.print_service.print_AVRCP_attributes.print_supported_features = 0;

	dd->sdp_settings.print_service.print_A2DP_attributes.print_supported_features = 0;

	dd->sdp_settings.print_service.print_MAP_attributes.print_goepl2cappsm = 0;
	dd->sdp_settings.print_service.print_MAP_attributes.print_supported_message_types = 0;
	dd->sdp_settings.print_service.print_MAP_attributes.print_mas_instance_id = 0;
	dd->sdp_settings.print_service.print_MAP_attributes.print_map_supported_features = 0;

	dd->reset_attr_search_for_service();
	dd->reset_SDP_service_for_search();
}



void CLI_DEFAULT_DATA::CLI_connectToDevice(System::String^ str)
{
	pin_ptr<const wchar_t> convertedValue = PtrToStringChars(str);
	const wchar_t* constValue = convertedValue;

	//if (IOCTL_S::connectToDevice(L"\\\\?\\GLOBALROOT\\Device\\USBPDO-5", dd) == 1)
	if (IOCTL_S::connectToDevice(constValue, dd) == 1)
	{
		if (sdp_settings->debug == 1)
			Console::WriteLine("CONNECTED!!");
	}
	else
		if (sdp_settings->debug == 1)
			Console::WriteLine("FAIL TO CONNECT!!!");
}

void CLI_DEFAULT_DATA::CLI_closeConnectionToDevice(/*IOCTL_S::DEFAULT_DATA* dd*/)
{
	// TODO: ko bo urejeno return naredi izpis
	IOCTL_S::closeConnectionToDevice(dd);
}


// DONE!!
void CLI_DEFAULT_DATA::CLI_SDPsearch(System::String^ str)
{
	using namespace System::Runtime::InteropServices;
	char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	printf(str2);

	//if (IOCTL_S::SDPsearch(dd, "44:80:EB:EF:D2:CE") == 1)
	//if (IOCTL_S::SDPsearch(dd, "A8:B8:6E:E7:5A:B6") == 1)
	if (IOCTL_S::SDPsearch(dd, str2) == 1)
	{
		if (sdp_settings->debug == 1)
			Console::WriteLine("SEARCHED!!");

		if (dd->services_for_search.AudioSource == 1)
			save_exported_data_A2DP();

		if (dd->services_for_search.A_V_RemoteControl == 1 ||
			dd->services_for_search.A_V_RemoteControlTarget == 1 ||
			dd->services_for_search.A_V_RemoteControlController == 1
			)
			save_exported_data_AVRCP();

		if (dd->services_for_search.Message_Access_Server == 1)
			save_exported_data_MAP();

		if (dd->services_for_search.Handsfree == 1 || dd->services_for_search.HandsfreeAudioGateway == 1)
			save_exported_data_HFP();

		if (dd->services_for_search.Headset == 1 || dd->services_for_search.Headset_Audio_Gateway == 1)
			save_exported_data_HSP();

		if (dd->services_for_search._NAP == 1)
			save_exported_data_NAP();

		if (dd->services_for_search.OBEXObjectPush == 1)
			save_exported_data_OBEX();

		if (dd->services_for_search.Phonebook_Access_PSE == 1)
			save_exported_data_PBAP();

		if (dd->services_for_search.PnPInformation == 1)
			save_exported_data_PNPINFO();
	}
	else
		if (sdp_settings->debug == 1)
			Console::WriteLine("FAIL TO SEARCH!!!");

	//Marshal::FreeHGlobal(str2);
}

// DONE!!
void CLI_DEFAULT_DATA::CLI_getBthDeviceInfo()
{
	if (IOCTL_S::getBthDeviceInfo(dd, 0) == 1)
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

			//cached_devices->devices.push_back(gcnew CLI_CACHED_DEVICE());
			cached_devices->devices[i]->flags = dd->exported_data.devices->devices.at(i).getFlags();
			cached_devices->devices[i]->name = str;
			cached_devices->devices[i]->address = gcnew array< BYTE^ >(6);

			for (int i = 0; i < 6; i++)
				cached_devices->devices[i]->address[i] = dd->exported_data.devices->devices.at(i).getAddress()[i];
		}

		if (sdp_settings->print == 1)
			cached_devices->print();
	}
	else
		if (sdp_settings->debug == 1)
			Console::WriteLine("FAIL TO getBthDeviceInfo!!!");
}

// DONE!!
void CLI_DEFAULT_DATA::CLI_getLocalBthInfo()
{
	IOCTL_S::getLocalBthInfo(dd, 0);

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
		Console::WriteLine("CLI_DEFAULT_DATA::CLI_set_all_SDP_service_for_search()");
}

void CLI_DEFAULT_DATA::CLI_set_SDP_service_for_search(Int16 service)
{
	// TODO: daj izpis pod print ali debug
	switch (service)
	{
	case SDP::SERVICE_CLASS_ID::PnPInformation:
		dd->services_for_search.PnPInformation = 1;
		Console::WriteLine("[Service search ON] PnPInformation");
		break;

	case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
		dd->services_for_search.Phonebook_Access_PSE = 1;
		Console::WriteLine("[Service search ON] Phonebook_Access_PSE");
		break;

	case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
		dd->services_for_search.OBEXObjectPush = 1;
		Console::WriteLine("[Service search ON] OBEXObjectPush");
		break;

	case SDP::SERVICE_CLASS_ID::_NAP:
		dd->services_for_search._NAP = 1;
		Console::WriteLine("[Service search ON] _NAP");
		break;

	case (SDP::SERVICE_CLASS_ID::Headset):
		dd->services_for_search.Headset = 1;
		Console::WriteLine("[Service search ON] Headset");
		break;

	case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
		dd->services_for_search.Headset_Audio_Gateway = 1;
		Console::WriteLine("[Service search ON] Headset_Audio_Gateway");
		break;

	case SDP::SERVICE_CLASS_ID::Handsfree:
		dd->services_for_search.Handsfree = 1;
		Console::WriteLine("[Service search ON] Handsfree");
		break;

	case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
		dd->services_for_search.HandsfreeAudioGateway = 1;
		Console::WriteLine("[Service search ON] HandsfreeAudioGateway");
		break;

	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
		dd->services_for_search.A_V_RemoteControl = 1;
		Console::WriteLine("[Service search ON] A_V_RemoteControl");
		break;

	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
		dd->services_for_search.A_V_RemoteControlTarget = 1;
		Console::WriteLine("[Service search ON] A_V_RemoteControlTarget");
		break;

	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
		dd->services_for_search.A_V_RemoteControlController = 1;
		Console::WriteLine("[Service search ON] A_V_RemoteControlController");
		break;

	case SDP::SERVICE_CLASS_ID::AudioSource:
		dd->services_for_search.AudioSource = 1;
		Console::WriteLine("[Service search ON] AudioSource");
		break;

	case SDP::SERVICE_CLASS_ID::Message_Access_Server:
		dd->services_for_search.Message_Access_Server = 1;
		Console::WriteLine("[Service search ON] Message_Access_Server");
		break;

	case SDP::SERVICE_CLASS_ID::GenericAudio:
		dd->services_for_search.GenericAudio = 1;
		Console::WriteLine("[Service search ON] GenericAudio");
		break;
	}

	Console::WriteLine("");
}

void CLI_DEFAULT_DATA::CLI_disable_SDP_service_for_search(Int16 service)
{
	// TODO: daj izpis pod print ali debug
	
	switch (service)
	{
	case SDP::SERVICE_CLASS_ID::PnPInformation:
		dd->services_for_search.PnPInformation = 0;
		Console::WriteLine("[Service search OFF] PnPInformation");
		break;

	case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
		dd->services_for_search.Phonebook_Access_PSE = 0;
		Console::WriteLine("[Service search OFF] Phonebook_Access_PSE");
		break;

	case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
		dd->services_for_search.OBEXObjectPush = 0;
		Console::WriteLine("[Service search OFF] OBEXObjectPush");
		break;

	case SDP::SERVICE_CLASS_ID::_NAP:
		dd->services_for_search._NAP = 0;
		Console::WriteLine("[Service search OFF] _NAP");
		break;

	case (SDP::SERVICE_CLASS_ID::Headset):
		dd->services_for_search.Headset = 0;
		Console::WriteLine("[Service search OFF] Headset");
		break;

	case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
		dd->services_for_search.Headset_Audio_Gateway = 0;
		Console::WriteLine("[Service search ONOFF Headset_Audio_Gateway");
		break;

	case SDP::SERVICE_CLASS_ID::Handsfree:
		dd->services_for_search.Handsfree = 0;
		Console::WriteLine("[Service search OFF] Handsfree");
		break;

	case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
		dd->services_for_search.HandsfreeAudioGateway = 0;
		Console::WriteLine("[Service search OFF] HandsfreeAudioGateway");
		break;

	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
		dd->services_for_search.A_V_RemoteControl = 0;
		Console::WriteLine("[Service search OFF] A_V_RemoteControl");
		break;

	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
		dd->services_for_search.A_V_RemoteControlTarget = 0;
		Console::WriteLine("[Service search OFF] A_V_RemoteControlTarget");
		break;

	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
		dd->services_for_search.A_V_RemoteControlController = 0;
		Console::WriteLine("[Service search OFF] A_V_RemoteControlController");
		break;

	case SDP::SERVICE_CLASS_ID::AudioSource:
		dd->services_for_search.AudioSource = 0;
		Console::WriteLine("[Service search OFF] AudioSource");
		break;

	case SDP::SERVICE_CLASS_ID::Message_Access_Server:
		dd->services_for_search.Message_Access_Server = 0;
		Console::WriteLine("[Service search OFF] Message_Access_Server");
		break;

	case SDP::SERVICE_CLASS_ID::GenericAudio:
		dd->services_for_search.GenericAudio = 0;
		Console::WriteLine("[Service search OFF] GenericAudio");
		break;
	}

	Console::WriteLine("");
}

void CLI_DEFAULT_DATA::CLI_set_all_attr_of_SDP_service_for_search()
{
	dd->attr_search_for_service.all = 1;
}


// default and specific attr of service
void CLI_DEFAULT_DATA::CLI_set_default_attr_of_SDP_service_for_search(Int16 attr)
{
	/* DEFAULT ATTR. */
	switch (attr)
	{
	case (short)CLI_ATTRIBUTE_ID::ServiceRecordHandle:
		dd->attr_search_for_service.ServiceRecord = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::ServiceClassIDList:
		dd->attr_search_for_service.ServiceClassIDList = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::ProtocolDescriptorList:
		dd->attr_search_for_service.ProtocolDescriptorList = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::ServiceName:
		dd->attr_search_for_service.ServiceName = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::BluetoothProfileDescriptorList:
		dd->attr_search_for_service.BluetoothProfileDescriptorList = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::ProviderName:
		dd->attr_search_for_service.ProviderName = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::LanguageBaseAttributeIDList:
		dd->attr_search_for_service.LanguageBaseAttributeIdList = 1;
		break;

	case (short)CLI_ATTRIBUTE_ID::ServiceDescription:
		dd->attr_search_for_service.ServiceDescription = 1;
		break;

	default:
		Console::WriteLine("Unknown attribute");
		break;
	}
}

void CLI_DEFAULT_DATA::CLI_set_service_specific_attr_of_SDP_service_for_search(Int16 service, Int16 attr)
{
	switch (service)
	{
	case (short)CLI_SERVICE_CLASS_ID::Headset:
		switch (attr)
		{
		case (short)CLI_HSP::CLI_ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl:
			dd->attr_search_for_service.att_HSP.RemoteAudioVolumeControl = 1;
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
			dd->attr_search_for_service.att_A2DP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_HSP.RemoteAudioVolumeControl = 1;
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
			dd->attr_search_for_service.att_HFP.Network = 1;
			break;

		case (short)CLI_HFP::CLI_ATTRIBUTE_ID_HFP::SupportedFeatures:
			dd->attr_search_for_service.att_HFP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_OBEX.Goepl2cappsm = 1;
			break;

		case (short)CLI_OBEX::CLI_ATTRIBUTE_ID_OBEX::ServiceVersion:
			dd->attr_search_for_service.att_OBEX.ServiceVersion = 1;
			break;

		case (short)CLI_OBEX::CLI_ATTRIBUTE_ID_OBEX::SupportedFormatsList:
			dd->attr_search_for_service.att_OBEX.SupportedFormats = 1;
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
			dd->attr_search_for_service.att_AVRCP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_AVRCP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_AVRCP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_NAP.SecurityDescription = 1;
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
			dd->attr_search_for_service.att_NAP.SecurityDescription = 1;
			break;

		case (short)CLI_NAP::CLI_ATTRIBUTE_ID_PAN::NetAccessType:
			dd->attr_search_for_service.att_NAP.NetAccessType = 1;
			break;

		case (short)CLI_NAP::CLI_ATTRIBUTE_ID_PAN::MaxNetAccessrate:
			dd->attr_search_for_service.att_NAP.MaxNetAccessRate = 1;
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
			dd->attr_search_for_service.att_HFP.Network = 1;
			break;

		case (short)CLI_HFP::CLI_ATTRIBUTE_ID_HFP::SupportedFeatures:
			dd->attr_search_for_service.att_HFP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_PBAP.Goepl2cappsm = 1;
			break;

		case (short)CLI_PBAP::CLI_ATTRIBUTE_ID_PBAP::SupportedRepositories:
			dd->attr_search_for_service.att_PBAP.SupportedRepositories = 1;
			break;

		case (short)CLI_PBAP::CLI_ATTRIBUTE_ID_PBAP::PbapSupportedFeatures:
			dd->attr_search_for_service.att_PBAP.SupportedFeatures = 1;
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
			dd->attr_search_for_service.att_MAP.Goepl2cappsm = 1;
			break;

		case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::MASInstanceID:
			dd->attr_search_for_service.att_MAP.MasInstanceId = 1;
			break;

		case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::SupportedMessageTypes:
			dd->attr_search_for_service.att_MAP.SupportedMessageTypes = 1;
			break;

		case (short)CLI_MAP::CLI_ATTRIBUTE_ID_MAP::MapSupportedFeatures:
			dd->attr_search_for_service.att_MAP.MapSupportedFeatures = 1;
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
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::VendorID:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::ProductID:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::Version:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
			break;

		case (short)CLI_PNPINFO::CLI_ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL:
			dd->attr_search_for_service.att_PNPINFO.PnpInfo = 1;
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
}



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

