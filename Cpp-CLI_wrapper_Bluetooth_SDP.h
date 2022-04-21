#pragma once

#include <stdio.h> // to printf()
#include <vector>
#include <string>

#include < vcclr.h >

#include <cliext/vector>
#include "SDP.h"

using namespace System;



public enum class CLI_SWITCHES
{
	OFF = 0,
	ON = 1
};

public enum class CLI_SERVICE_CLASS_ID
{
	// DONE
	Headset = 0x1108,
	AudioSource = 0x110A,
	AudioSink = 0x110B,
	Headset_Audio_Gateway = 0x1112,
	Handsfree = 0x111E,
	OBEXObjectPush = 0x1105,
	OBEXFileTransfer = 0x1106,
	A_V_RemoteControl = 0x110E,
	A_V_RemoteControlTarget = 0x110C,
	A_V_RemoteControlController = 0x110F,
	PANU = 0x1115,
	_NAP = 0x1116,
	HandsfreeAudioGateway = 0x111F,
	Phonebook_Access_PSE = 0x112F,
	Phonebook_Access = 0x1130,
	Message_Access_Server = 0x1132,
	Message_Access_Profile = 0x1134,
	PnPInformation = 0x1200,
	GenericAudio = 0x1203,

	// TODO: 
	Phonebook_Access_PCE = 0x112E,
	Message_Notification_Server = 0x1133

};

public enum class CLI_DATA_ELEMENT_TYPE_DESCRIPTOR_VALUE
{
	_Nil = 0,
	_Unsigned_int,
	_Signed_twos_complement_int,
	_UUID,
	_Text_string,
	_Boolean,
	_Data_element_sequence,
	_Data_element_alternative,
	_URL,
	_Reserved

};

public enum class CLI_DATA_ELEMENT_SIZE_DESCRIPTOR_VALUE
{
	_1_byte = 0,
	_2_bytes,
	_4_bytes,
	_8_bytes,
	_16_bytes,
	_additional_8_bits,		//unsigned integer
	_additional_16_bits,	//unsigned integer
	_additional_32_bits		//unsigned integer

};

public enum class CLI_PDU_ID
{
	SDP_ERROR_RSP = 1,
	SDP_SERVICE_SEARCH_REQ,
	SDP_SERVICE_SEARCH_RSP,
	SDP_SERVICE_ATTR_REQ,
	SDP_SERVICE_ATTR_RSP,
	SDP_SERVICE_SEARCH_ATTR_REQ,
	SDP_SERVICE_SEARCH_ATTR_RSP

};

public enum class CLI_PROTOCOL_ID
{
	_SDP = 0x0001,
	_UDP = 0x0002,
	_RFCOMM = 0x0003,
	_TCP = 0x0004,
	_TCS_BIN = 0x0005,
	_TCS_AT = 0x0006,
	_ATT = 0x0007,
	_OBEX = 0x0008,
	_IP = 0x0009,
	_FTP = 0x000a,
	_HTTP = 0x000c,
	_WSP = 0x000e,
	_BNEP = 0x000f,
	_UPNP = 0x0010,
	_HIDP = 0x0011,
	_AVCTP = 0x0017,
	_AVDTP = 0x0019,
	_CMTP = 0x001b,
	_L2CAP = 0x0100

};

public enum class CLI_NETWORK_PACKET_TYPE
{
	IPv4 = 0x0800,
	ARP = 0x0806,
	FRARP = 0x0808,
	IPv6 = 0x86DD
	// https://www.rfc-editor.org/rfc/pdfrfc/rfc7042.txt.pdf


};

public enum class CLI_ATTRIBUTE_ID : Int16
{
	ServiceRecordHandle = 0x0000,
	ServiceClassIDList = 0x0001,
	ServiceRecordState = 0x0002,
	ServiceID = 0x0003,
	ProtocolDescriptorList = 0x0004,
	BrowseGroupList = 0x0005,
	LanguageBaseAttributeIDList = 0x0006,
	ServiceInfoTimeToLive = 0x0007,
	ServiceAvailability = 0x0008,
	BluetoothProfileDescriptorList = 0x0009,
	DocumentationURL = 0x000A,
	ClientExecutableURL = 0x000B,
	IconURL = 0x000C,
	AdditionalProtocolDescriptorList = 0x000D,
	ServiceName = 0x0100,
	ServiceDescription = 0x0101,
	ProviderName = 0x0102

};



namespace CLI_NAP
{
	public enum class CLI_ATTRIBUTE_ID_PAN
	{
		IpSubnet = 0x0200,
		SecurityDescription = 0x030A,
		NetAccessType = 0x030B,
		MaxNetAccessrate = 0x030C,
		IPv4Subnet = 0x030D,		// TODO:
		IPv6Subnet = 0x030E		// TODO:

	};
}

namespace CLI_MAP
{
	public enum class CLI_ATTRIBUTE_ID_MAP
	{
		GoepL2capPsm = 0x0200,
		MASInstanceID = 0x0315,
		SupportedMessageTypes = 0x0316,
		MapSupportedFeatures = 0x0317

	};
}

namespace CLI_PBAP
{
	public enum class CLI_ATTRIBUTE_ID_PBAP
	{
		GoepL2capPsm = 0x0200,
		SupportedRepositories = 0x0314,
		PbapSupportedFeatures = 0x0317

	};
}

namespace CLI_OBEX
{
	public enum class CLI_ATTRIBUTE_ID_OBEX
	{
		GoepL2capPsm = 0x0200,
		ServiceVersion = 0x0300,
		SupportedFormatsList = 0x0303

	};
}

namespace CLI_HFP
{
	public enum class CLI_ATTRIBUTE_ID_HFP
	{
		Network = 0x0301,
		SupportedFeatures = 0x0311

	};
}

namespace CLI_PNPINFO	// PnPInformation
{
	public enum class CLI_ATTRIBUTE_ID_DEVICE_SDP
	{
		SpecificationID = 0x0200,
		VendorID = 0x0201,
		ProductID = 0x0202,
		Version = 0x0203,
		PrimaryRecord = 0x0204,
		VendorIDSource = 0x0205,
		ClientExecutableURL = 0x000B,
		DocumentationURL = 0x000A

	};
}

namespace CLI_A2DP
{
	public enum class CLI_ATTRIBUTE_ID_DEVICE_A2DP
	{
		SupportedFeatures = 0x0311

	};
}

namespace CLI_AVRCP
{
	public enum class CLI_ATTRIBUTE_ID_DEVICE_AVRCP
	{
		SupportedFeatures = 0x0311

	};
}

namespace CLI_HSP
{
	public enum class CLI_ATTRIBUTE_ID_DEVICE_HSP
	{
		RemoteAudioVolumeControl = 0x0302

	};
}


public ref struct CLI_SDP_settings
{
	int debug;
	int print;
	//int print_info;
	//int print_with_outside_funct;

	//System::String test;

	ref struct SDP_print_service
	{
		/* DEFAULT ATTR. */
		int print_service_record;
		int print_service_class_id_list;
		int print_protocol_descriptor_list;
		int print_service_name;
		int print_provider_name;
		int print_bluetooth_profile_descriptor_list;
		int print_language_base_attribute_id_list;
		int print_service_description;
		//int print_service_availability;

		/***********************************************/
		/* SPECIAL ATTR. */

		/* PNPINFO */
		ref struct print_PNPINFO
		{
			int print_pnp_info;
		};
		print_PNPINFO print_PNPINFO_attributes;

		/* PBAP */
		ref struct print_PBAP
		{
			int print_goepl2cappsm;
			int print_supported_repositories;
			int print_pbap_supported_features;
		};
		print_PBAP print_PBAP_attributes;

		/* OBEX */
		ref struct print_OBEX
		{
			int print_goepl2cappsm;
			int print_supported_formats;
			int print_service_version;
		};
		print_OBEX print_OBEX_attributes;

		/* NAP */
		ref struct print_NAP
		{
			int print_security_description;
			int print_net_access_type;
			int print_max_net_access_rate;
		};
		print_NAP print_NAP_attributes;

		/* HSP */
		ref struct print_HSP
		{
			int print_remote_audio_volume_control;
		};
		print_HSP print_HSP_attributes_Headset;
		print_HSP print_HSP_attributes_Headset_Audio_Gateway;

		/* HFP */
		ref struct print_HFP
		{
			int print_network;
			int print_supported_features;
		};
		print_HFP print_HFP_attributes_Handsfree;
		print_HFP print_HFP_attributes_HandsfreeAudioGateway;

		/* AVRCP */
		ref struct print_AVRCP
		{
			int print_supported_features;
		};
		print_AVRCP print_AVRCP_attributes_A_V_RemoteControl;
		print_AVRCP print_AVRCP_attributes_A_V_RemoteControlTarget;
		print_AVRCP print_AVRCP_attributes_A_V_RemoteControlController;

		/* A2DP */
		ref struct print_A2DP
		{
			int print_supported_features;
		};
		print_A2DP print_A2DP_attributes;

		/* MAP */
		ref struct print_MAP
		{
			int print_goepl2cappsm;
			int print_supported_message_types;
			int print_mas_instance_id;
			int print_map_supported_features;
		};
		print_MAP print_MAP_attributes;

	};

	SDP_print_service print_service;
};









/*
	TODO:
	- UREDI: da je v tem wrapperju by default shranjevanje errorja v struct (id in text)
	- UREDI: da se bo pnpinfo searchalo po vsakem podatku in ne po vseh naenkrat
	- POPRAVI: ce dam search samo po service name, dobim error
	- PREVERI: preveri vsak attr posebej pri searchenju
	- DODAJ: preveri ali je kaksen attr. enabled za search drugace se ne sme izvesti SDP  in isto za service, ker drugace je error
	- DODAJ: se za PANU service
	

	- PREVERI/DODAJ/POPRAVI: app javi da ni kompatibilno VALUE ko se exporta iz objekta (resitev: kreiranje instance objekta in potem dodajanje podatkov, uredi tudi brisanje tega)
	(resitev: glej SERVICE_NAME exportanje in naredi na vseh ostalih takole)	<-- DONE !!
	- POPRAVI: vrstni red brisanja pointerjev (example: glej delete_exported_data_A2DP)	<-- DONE !!
	- PREVERI: A_V_RemoteControlTarget in A_V_RemoteControlController <-- zakaj ne vrne, kje tezava v native ali tukaj <-- DONE !!
	- UREDI: da se pri shranjevanju exported tudi preveri ali sploh obstajajo podatki	<-- DONE !!
	- UREDI: glede printanja od native C++ (najbolje posebej kar se dobi data od native) (najbolje da se naredi nov struct) <-- DONE !!
	- UREDI: preglej in dodaj remove (delete) na vse kjer se uporabi gcnew	<-- DONE !!


	TODO za NATIVE DLL:
	- UREDI: da IOCTL_S::closeConnectionToDevice vraca 1 ali 0, odvisno ali je ok ali failed
	- UREDI: da SDP::FUNCTIONS::SDP_INIT_CONNECT::init_for_IOCTL_BTH_SDP_CONNECT vraca 1 ali 0, odvisno ali je ok ali failed
	- UREDI: da SDP::FUNCTIONS::SDP_INIT_DISCONNECT::init_for_IOCTL_BTH_SDP_DISCONNECT vraca 1 ali 0, odvisno ali je ok ali failed
	- UREDI: da ce je error, da se shrani v temp id in text in poslje na CLI->.NET
	- UREDI: da IOCTL_S::getLocalBthInfo vraca 1 ali 0, odvisno ali je ok ali failed
	- UREDI: da se lahko za pnpinfo searcha za vsak podatek posebej, ker trenutno se vse searcha
	- DODAJ: da se v DEFAULT struct shrani tudi string od attr_element value, trenutno se samo klice v printATTR_ELEMENT -> getElementTypeString, tako da trenutno ni mozno exportat ta podatek
	- POPRAVI: glede search all services, da se res vsi poiscejo ali pa pac odstrani to
	- POPRAVI: izpis vseh praznih vrstic
	- DODAJ: shranjevanje text-a iz razlicnih servicov, ker trenutno se samo izpise
	- DODAJ: ERROR_BAD_NETPATH --> 0x35
	- DODAJ: ERROR_INVALID_HANDLE --> 0x6
	- POPRAVI: v native popravi text izpis za A_V_RemoteControlController
	- DODAJ: se za PANU service



*/


public ref struct CLI_CACHED_DEVICE
{
	UInt32 flags;
	System::String^ name;
	array< BYTE^ >^ address;

	void print()
	{
		Console::WriteLine("************************");
		Console::WriteLine("NAME: {0}", name);
		Console::WriteLine("FLAGS: {0}", flags);
		Console::WriteLine("ADDRESS: {5:X2}:{4:X}:{3:X}:{2:X}:{1:X}:{0:X}", address[0], address[1], address[2], address[3], address[4], address[5]);
		Console::WriteLine("************************");
	}
};

public ref struct CLI_SEARCHED_CACHED_DEVICES
{
	UInt32 numOfDevices;
	//cliext::vector<CLI_CACHED_DEVICE^> devices;
	array<CLI_CACHED_DEVICE^>^ devices;

	void print()
	{
		Console::WriteLine("*********** DEVICES *************");
		Console::WriteLine("NUM: {0}", numOfDevices);

		for (int i = 0; i < numOfDevices; i++)
			devices[i]->print();
	}
};









public ref struct CLI_DEVICE_PARSED_COD_DATA
{
	cliext::vector<System::String^> major_service_class;
	cliext::vector<System::String^> major_device_class;
	cliext::vector<System::String^> minor_device_class;

	void print()
	{
		Console::WriteLine("\tDEVICE COD data: ");

		Console::WriteLine("\t\tMajor service class:");
		for (int a = 0; a < major_service_class.size(); a++)
			Console::WriteLine("\t\t\t{0}", major_service_class.at(a));

		Console::WriteLine("\t\tMajor device class:");
		for (int a = 0; a < major_device_class.size(); a++)
			Console::WriteLine("\t\t\t{0}", major_device_class.at(a));

		Console::WriteLine("\t\tMinor device class:");
		for (int a = 0; a < minor_device_class.size(); a++)
			Console::WriteLine("\t\t\t{0}", minor_device_class.at(a));
		Console::WriteLine("");
	}
};

public ref struct CLI_DEVICE_DATA
{
	System::String^ name;
	array< BYTE^ >^ address;
	UInt32 flags;
	CLI_DEVICE_PARSED_COD_DATA^ cod;

	void print()
	{
		Console::WriteLine("\tName: {0:X}", name);
		Console::WriteLine("ADDRESS: {5:X2}:{4:X}:{3:X}:{2:X}:{1:X}:{0:X}", address[0], address[1], address[2], address[3], address[4], address[5]);
		Console::WriteLine("FLAGS: {0}", flags);

		cod->print();
	}
};

public ref struct CLI_RADIO_DATA
{
	ULONGLONG LMP_SupportedFeatures;
	USHORT mfg;
	USHORT LMP_minor_version;
	UCHAR LMP_major_version;

	void print()
	{
		Console::WriteLine("\tRADIO DATA:");
		Console::WriteLine("\t\tLMP version: {0}.{1}", LMP_major_version, LMP_minor_version);
		Console::WriteLine("\t\tLMP Supported Features: {0:X}", LMP_SupportedFeatures);
		Console::WriteLine("\t\tID of the manufacturer: {0}", mfg);
	}
};

public ref struct CLI_LOCAL_RADIO_DEVICE_DATA
{
	UInt32 flags;
	USHORT HCI_minor_version;
	UCHAR HCI_major_version;

	CLI_DEVICE_DATA^ device;
	CLI_RADIO_DATA^ radio;

	void print()
	{
		Console::WriteLine("LOCAL DEVICE and RADIO DATA:");
		Console::WriteLine("\tFlags: {0:X}", flags);
		Console::WriteLine("\tVersion: {0}.{1} (Major.Minor version HCI)",
			HCI_major_version,
			HCI_minor_version
		);

		device->print();
		radio->print();
	}
};














public ref struct CLI_DEFAULT_DATA
{
public:
	CLI_DEFAULT_DATA();

	~CLI_DEFAULT_DATA();
	!CLI_DEFAULT_DATA();


	void CLI_connectToDevice(System::String^ str);
	void CLI_closeConnectionToDevice();

	// reset to false all service and attr. 
	void CLI_reset_SDP_service_for_search();
	void CLI_reset_attr_search_for_service();

	// set all, specific service for search
	void CLI_set_all_SDP_service_for_search();
	void CLI_set_SDP_service_for_search(Int16 service);
	void CLI_disable_SDP_service_for_search(Int16 service);

	// set all, default and specific attr. for search
	void CLI_set_all_attr_of_SDP_service_for_search();
	void CLI_set_default_attr_of_SDP_service_for_search(Int16 attr);
	void CLI_set_service_specific_attr_of_SDP_service_for_search(Int16 service, Int16 attr);


	// functions for different data
	void CLI_SDPsearch(System::String^ str);
	void CLI_getBthDeviceInfo();
	void CLI_getLocalBthInfo();



	void CLI_set_all_default_attr_print();
	void CLI_disable_all_default_attr_print();
	void CLI_set_default_attr_print(Int16 def_attr, int onOff);
	void CLI_set_all_specific_attrs_service_print(Int16 service, int onOff);
	void CLI_set_specific_attr_service_print(Int16 service, Int16 attr, int onOff);



	// to show settings of service and attributes
	void CLI_show_print_service();
	void CLI_show_SDP_service_search();


	CLI_SDP_settings^ sdp_settings;

	CLI_SEARCHED_CACHED_DEVICES^ cached_devices;
	CLI_LOCAL_RADIO_DEVICE_DATA^ local_device_radio;

	CLI_EXPORTS::CLI_A2DP_EXPORT^ a2dp_export;
	CLI_EXPORTS::CLI_AVRCP_EXPORT^ avrcp_export;
	CLI_EXPORTS::CLI_MAP_EXPORT^ map_export;
	CLI_EXPORTS::CLI_HFP_EXPORT^ hfp_export;
	CLI_EXPORTS::CLI_HSP_EXPORT^ hsp_export;
	CLI_EXPORTS::CLI_NAP_EXPORT^ nap_export;
	CLI_EXPORTS::CLI_OBEX_EXPORT^ obex_export;
	CLI_EXPORTS::CLI_PBAP_EXPORT^ pbap_export;
	CLI_EXPORTS::CLI_INFO_EXPORT^ pnpinfo_export;


private:
	IOCTL_S::DEFAULT_DATA* dd;
	void setNativeDLLSettingsToFalse();
	void CLI_show_print_service_NATIVE();
	void CLI_set_default_print_service_NATIVE(Int16 def_attr);
	void CLI_set_specific_print_service_NATIVE(Int16 service);


	template<class A, class B>
	void save_exported_data_DEFAULT(A main, BYTE* submain)
	{
		main->default_export = gcnew CLI_DEFAULT_EXPORT();

		// SERVICE_RECORD
		if (((B)submain)->default_export->record_handle_export != NULL)
		{
			main->default_export->record_handle_export = gcnew CLI_DEFAULT::CLI_SERVICE_RECORD();

			main->default_export->record_handle_export->VALUE = gcnew CLI_DEFAULT::CLI_SERVICE_RECORD::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_RECORD^, SDP::SERVICE_RECORD*>(
				main->default_export->record_handle_export,
				dd,
				((B)submain)->default_export->record_handle_export
				);

			DWORD temp = 0x00;
			temp |= ((B)submain)->default_export->record_handle_export->VALUE.value[0];
			temp <<= 8;
			temp |= ((B)submain)->default_export->record_handle_export->VALUE.value[1];
			temp <<= 8;
			temp |= ((B)submain)->default_export->record_handle_export->VALUE.value[2];
			temp <<= 8;
			temp |= ((B)submain)->default_export->record_handle_export->VALUE.value[3];
			main->default_export->record_handle_export->VALUE->handle = temp;
		}

		//  SERVICE_CLASS_ID_LIST
		if (((B)submain)->default_export->class_id_handle_export != NULL)
		{
			main->default_export->class_id_handle_export = gcnew CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST();

			main->default_export->class_id_handle_export->VALUE = gcnew CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST^, SDP::SERVICE_CLASS_ID_LIST*>(
				main->default_export->class_id_handle_export,
				dd,
				((B)submain)->default_export->class_id_handle_export
				);

			main->default_export->class_id_handle_export->VALUE->num_classes = ((B)submain)->default_export->class_id_handle_export->VALUE.num_classes;

			main->default_export->class_id_handle_export->VALUE->classes = gcnew array<CLI_SERVICE_CLASS^>(main->default_export->class_id_handle_export->VALUE->num_classes);
			// TODO: preveri za element v classes ce se sploh uporablja
			for (int a = 0; a < main->default_export->class_id_handle_export->VALUE->num_classes; a++)
			{
				main->default_export->class_id_handle_export->VALUE->classes[a] = gcnew CLI_SERVICE_CLASS();
				main->default_export->class_id_handle_export->VALUE->classes[a]->element = gcnew CLI_ATTRIBUTE_ID_ELEMENT();
				main->default_export->class_id_handle_export->VALUE->classes[a]->additional_bits_flag = ((B)submain)->default_export->class_id_handle_export->VALUE.classes[a].additional_bits_flag;
				main->default_export->class_id_handle_export->VALUE->classes[a]->value = ((B)submain)->default_export->class_id_handle_export->VALUE.classes[a].value;
			}
		}

		//  PROTOCOL_DESCRIPTOR_LIST
		if (((B)submain)->default_export->protocol_descriptor_list_handle_export != NULL)
		{
			main->default_export->protocol_descriptor_list_handle_export = gcnew CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST();

			main->default_export->protocol_descriptor_list_handle_export->VALUE = gcnew CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST^, SDP::PROTOCOL_DESCRIPTOR_LIST*>(
				main->default_export->protocol_descriptor_list_handle_export,
				dd,
				((B)submain)->default_export->protocol_descriptor_list_handle_export
				);


			main->default_export->protocol_descriptor_list_handle_export->VALUE->num_protocols = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.num_protocols;
			main->default_export->protocol_descriptor_list_handle_export->VALUE->_BNEP_flag = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE._BNEP_flag;

			main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols = gcnew array<CLI_PROTOCOL_DESCRIPTOR^>(((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.num_protocols);

			for (int i = 0; i < ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.num_protocols; i++)
			{
				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i] = gcnew CLI_PROTOCOL_DESCRIPTOR();

				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->size_bytes = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].size_bytes;
				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->additional_bits_flag = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].additional_bits_flag;
				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->additional_bits_for_size = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].additional_bits_for_size;

				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->value = gcnew array< BYTE >(((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].additional_bits_for_size);
				for (int a = 0; a < ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].additional_bits_for_size; a++)
				{
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->value[a] = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].value[a];
				}

				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->protocol_id = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].protocol_id;
				main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->additional_parameters_flag = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].additional_parameters_flag;

				if (((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp != NULL)
				{
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp = gcnew CLI_PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER();
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->server_channel_num = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->server_channel_num;
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->PSM = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->PSM;
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->Version = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->Version;

					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->additional_bits_flag_PANU = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->additional_bits_flag_PANU;
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->additional_bits_for_size_PANU = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->additional_bits_for_size_PANU;
					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->num_of_Supported_Network_Packet_Type_List_PANU = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->num_of_Supported_Network_Packet_Type_List_PANU;

					main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->Supported_Network_Packet_Type_List = gcnew array<SHORT^>(((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->num_of_Supported_Network_Packet_Type_List_PANU);
					for (int aaa = 0; aaa < ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->num_of_Supported_Network_Packet_Type_List_PANU; aaa++)
						main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->Supported_Network_Packet_Type_List[aaa] = ((B)submain)->default_export->protocol_descriptor_list_handle_export->VALUE.protocols[i].pdsp->Supported_Network_Packet_Type_List[aaa];
				}
			}
		}

		//  SERVICE_NAME
		if (((B)submain)->default_export->service_name_handle_export != NULL)
		{
			main->default_export->service_name_handle_export = gcnew CLI_DEFAULT::CLI_SERVICE_NAME();

			main->default_export->service_name_handle_export->VALUE = gcnew CLI_DEFAULT::CLI_SERVICE_NAME::VV();
			//main->default_export->service_name_handle_export->VALUE->service_name = gcnew System::String("DELA TOLE!!!");

			save_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_NAME^, SDP::SERVICE_NAME*>(
				main->default_export->service_name_handle_export,
				dd,
				((B)submain)->default_export->service_name_handle_export
				);
			

			

			main->default_export->service_name_handle_export->VALUE->service_name = gcnew System::String(((B)submain)->default_export->service_name_handle_export->VALUE.service_name);
		}

		//  BLUETOOTH_PROFILE_DESCRIPTOR_LIST
		if (((B)submain)->default_export->bluetooth_profile_descriptor_list_handle_export != NULL)
		{
			main->default_export->bluetooth_profile_descriptor_list_handle_export = gcnew CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST();

			main->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE = gcnew CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST^, SDP::BLUETOOTH_PROFILE_DESCRIPTOR_LIST*>(
				main->default_export->bluetooth_profile_descriptor_list_handle_export,
				dd,
				((B)submain)->default_export->bluetooth_profile_descriptor_list_handle_export
				);


			main->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE->profile_UUID = ((B)submain)->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE.profile_UUID;
			main->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE->profile_version = ((B)submain)->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE.profile_version;
		}

		//  PROVIDER_NAME
		if (((B)submain)->default_export->provider_name_export != NULL)
		{
			main->default_export->provider_name_export = gcnew CLI_DEFAULT::CLI_PROVIDER_NAME();

			main->default_export->provider_name_export->VALUE = gcnew CLI_DEFAULT::CLI_PROVIDER_NAME::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_PROVIDER_NAME^, SDP::PROVIDER_NAME*>(
				main->default_export->provider_name_export,
				dd,
				((B)submain)->default_export->provider_name_export
				);

			main->default_export->provider_name_export->VALUE->provider_name = gcnew System::String(((B)submain)->default_export->provider_name_export->VALUE.provider_name);
		}

		//  LANGUAGE_BASE_ATTRIBUTE_ID_LIST
		if (((B)submain)->default_export->language_base_attribute_id_list_export != NULL)
		{
			main->default_export->language_base_attribute_id_list_export = gcnew CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST();

			main->default_export->language_base_attribute_id_list_export->VALUE = gcnew CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST^, SDP::LANGUAGE_BASE_ATTRIBUTE_ID_LIST*>(
				main->default_export->language_base_attribute_id_list_export,
				dd,
				((B)submain)->default_export->language_base_attribute_id_list_export
				);

			main->default_export->language_base_attribute_id_list_export->VALUE->triplet_id_natural_lang = ((B)submain)->default_export->language_base_attribute_id_list_export->VALUE.triplet_id_natural_lang;
			main->default_export->language_base_attribute_id_list_export->VALUE->triplet_id_char_encoding = ((B)submain)->default_export->language_base_attribute_id_list_export->VALUE.triplet_id_char_encoding;
			main->default_export->language_base_attribute_id_list_export->VALUE->triplet_attribute_id = ((B)submain)->default_export->language_base_attribute_id_list_export->VALUE.triplet_attribute_id;
		}

		//  SERVICE_DESCRIPTION
		if (((B)submain)->default_export->service_description_export != NULL)
		{
			main->default_export->service_description_export = gcnew CLI_DEFAULT::CLI_SERVICE_DESCRIPTION();

			main->default_export->service_description_export->VALUE = gcnew CLI_DEFAULT::CLI_SERVICE_DESCRIPTION::VV();

			save_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_DESCRIPTION^, SDP::SERVICE_DESCRIPTION*>(
				main->default_export->service_description_export,
				dd,
				((B)submain)->default_export->service_description_export
				);

			main->default_export->service_description_export->VALUE->description = gcnew System::String(((B)submain)->default_export->service_description_export->VALUE.description);
		}

	}

	void save_exported_data_A2DP();
	void save_exported_data_AVRCP();
	void save_exported_data_MAP();
	void save_exported_data_HFP();
	void save_exported_data_HSP();
	void save_exported_data_NAP();
	void save_exported_data_OBEX();
	void save_exported_data_PBAP();
	void save_exported_data_PNPINFO();

	// printing functions
	template<class A, class C>
	void print_data_DEFAULT(A main, BYTE* submain)
	{
		if (((C)submain)->default_export->record_handle_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_service_record == 1)
				main->default_export->record_handle_export->print<SDP::SERVICE_RECORD_S::VV>(((C)submain)->default_export->record_handle_export->VALUE, *dd);

		if (((C)submain)->default_export->class_id_handle_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_service_class_id_list == 1)
				main->default_export->class_id_handle_export->print<SDP::SERVICE_CLASS_ID_LIST_S::VV>(((C)submain)->default_export->class_id_handle_export->VALUE, *dd);

		if (((C)submain)->default_export->protocol_descriptor_list_handle_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_protocol_descriptor_list == 1)
				main->default_export->protocol_descriptor_list_handle_export->print<SDP::PROTOCOL_DESCRIPTOR_LIST_S::VV>(((C)submain)->default_export->protocol_descriptor_list_handle_export->VALUE, *dd);

		if (((C)submain)->default_export->service_name_handle_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_service_name == 1)
				main->default_export->service_name_handle_export->print<SDP::SERVICE_NAME_S::VV>(((C)submain)->default_export->service_name_handle_export->VALUE, *dd);

		if (((C)submain)->default_export->bluetooth_profile_descriptor_list_handle_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_bluetooth_profile_descriptor_list == 1)
				main->default_export->bluetooth_profile_descriptor_list_handle_export->print<SDP::BLUETOOTH_PROFILE_DESCRIPTOR_LIST_S::VV>(((C)submain)->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE, *dd);

		if (((C)submain)->default_export->provider_name_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_provider_name == 1)
				main->default_export->provider_name_export->print<SDP::PROVIDER_NAME_S::VV>(((C)submain)->default_export->provider_name_export->VALUE, *dd);

		if (((C)submain)->default_export->language_base_attribute_id_list_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_language_base_attribute_id_list == 1)
				main->default_export->language_base_attribute_id_list_export->print<SDP::LANGUAGE_BASE_ATTRIBUTE_ID_LIST_S::VV>(((C)submain)->default_export->language_base_attribute_id_list_export->VALUE, *dd);

		if (((C)submain)->default_export->service_description_export != NULL)
			if (sdp_settings->print == 1 || sdp_settings->print_service.print_service_description == 1)
				main->default_export->service_description_export->print<SDP::SERVICE_DESCRIPTION_S::VV>(((C)submain)->default_export->service_description_export->VALUE, *dd);

	}

	void print_data_A2DP();
	void print_data_AVRCP();
	void print_data_MAP();
	void print_data_HFP();
	void print_data_HSP();
	void print_data_NAP();
	void print_data_OBEX();
	void print_data_PBAP();
	void print_data_PNPINFO();

	// deleting structures
	// delete function for default data of attribute
	template<class A>
	void delete_default_data_of_attr(A main)
	{
		if (main->VALUE->value != nullptr)
			delete main->VALUE->value;

		if (main->VALUE->element != nullptr)
			delete main->VALUE->element;

		if (main->attr_id->value != nullptr)
			delete main->attr_id->value;

		if (main->attr_id->element != nullptr)
			delete main->attr_id->element;

		if (main->attr_id != nullptr)
			delete main->attr_id;
	}

	template<class A>
	void delete_exported_data_DEFAULT(A main)
	{
		if (main->default_export->record_handle_export != nullptr)
		{
			delete_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_RECORD^>(main->default_export->record_handle_export);

			delete main->default_export->record_handle_export->VALUE;

			delete main->default_export->record_handle_export;
		}

		if (main->default_export->class_id_handle_export != nullptr)
		{
			if (main->default_export->class_id_handle_export->VALUE != nullptr)
			{
				for (int a = 0; a < main->default_export->class_id_handle_export->VALUE->num_classes; a++)
				{
					if (main->default_export->class_id_handle_export->VALUE->classes[a]->element != nullptr)
						delete main->default_export->class_id_handle_export->VALUE->classes[a]->element;

					if (main->default_export->class_id_handle_export->VALUE->classes[a] != nullptr)
						delete main->default_export->class_id_handle_export->VALUE->classes[a];
				}

				if (main->default_export->class_id_handle_export->VALUE->classes != nullptr)
					delete main->default_export->class_id_handle_export->VALUE->classes;

				delete_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST^>(main->default_export->class_id_handle_export);


				delete main->default_export->class_id_handle_export->VALUE;
			}

			delete main->default_export->class_id_handle_export;
		}

		if (main->default_export->protocol_descriptor_list_handle_export != nullptr)
		{
			if (main->default_export->class_id_handle_export->VALUE != nullptr)
			{
				for (int i = 0; i < main->default_export->protocol_descriptor_list_handle_export->VALUE->num_protocols; i++)
					if (main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i] != nullptr)
					{
						delete main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->value;

						if (main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp != nullptr)
						{
							if (main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->Supported_Network_Packet_Type_List != nullptr)
								delete main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp->Supported_Network_Packet_Type_List;

							delete main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i]->pdsp;
						}

						delete main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols[i];
					}

				delete main->default_export->protocol_descriptor_list_handle_export->VALUE->protocols;

				delete_default_data_of_attr<CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST^>(main->default_export->protocol_descriptor_list_handle_export);

				delete main->default_export->protocol_descriptor_list_handle_export->VALUE;
			}

			delete main->default_export->protocol_descriptor_list_handle_export;
		}

		if (main->default_export->service_name_handle_export != nullptr)
		{
			if (main->default_export->service_name_handle_export->VALUE != nullptr)
			{
				if (main->default_export->service_name_handle_export->VALUE->service_name != nullptr)
					delete main->default_export->service_name_handle_export->VALUE->service_name;

				delete_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_NAME^>(main->default_export->service_name_handle_export);


				delete main->default_export->service_name_handle_export->VALUE;
			}

			delete main->default_export->service_name_handle_export;
		}

		if (main->default_export->bluetooth_profile_descriptor_list_handle_export != nullptr)
		{
			if (main->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST^>(main->default_export->bluetooth_profile_descriptor_list_handle_export);
				
				delete main->default_export->bluetooth_profile_descriptor_list_handle_export->VALUE;
			}

			delete main->default_export->bluetooth_profile_descriptor_list_handle_export;
		}

		if (main->default_export->provider_name_export != nullptr)
		{
			if (main->default_export->provider_name_export->VALUE != nullptr)
			{
				if (main->default_export->provider_name_export->VALUE->provider_name != nullptr)
					delete main->default_export->provider_name_export->VALUE->provider_name;

				delete_default_data_of_attr<CLI_DEFAULT::CLI_PROVIDER_NAME^>(main->default_export->provider_name_export);

				delete main->default_export->provider_name_export->VALUE;
			}

			delete main->default_export->provider_name_export;
		}

		if (main->default_export->language_base_attribute_id_list_export != nullptr)
		{
			if (main->default_export->language_base_attribute_id_list_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST^>(main->default_export->language_base_attribute_id_list_export);
				delete main->default_export->language_base_attribute_id_list_export->VALUE;
			}

			delete main->default_export->language_base_attribute_id_list_export;
		}

		if (main->default_export->service_description_export != nullptr)
		{
			if (main->default_export->service_description_export->VALUE != nullptr)
			{
				if (main->default_export->service_description_export->VALUE->description != nullptr)
					delete main->default_export->service_description_export->VALUE->description;

				delete_default_data_of_attr<CLI_DEFAULT::CLI_SERVICE_DESCRIPTION^>(main->default_export->service_description_export);
				delete main->default_export->service_description_export->VALUE;
			}

			delete main->default_export->service_description_export;
		}
	}

	void delete_exported_data_A2DP();
	void delete_exported_data_AVRCP();
	void delete_exported_data_MAP();
	void delete_exported_data_HFP();
	void delete_exported_data_HSP();
	void delete_exported_data_NAP();
	void delete_exported_data_OBEX();
	void delete_exported_data_PBAP();
	void delete_exported_data_PNPINFO();

	
	// ni samo za default attributes
	template<class A, class B>
	void save_default_data_of_attr(A main, IOCTL_S::DEFAULT_DATA* dd, B locale)
	{
		main->attr_id = gcnew CLI_ATTR_ID();

		main->attr_id->size_bytes = locale->attr_id->size_bytes;
		main->attr_id->additional_bits_flag = locale->attr_id->additional_bits_flag;
		main->attr_id->additional_bits_for_size = locale->attr_id->additional_bits_for_size;

		main->attr_id->element = gcnew CLI_ATTRIBUTE_ID_ELEMENT();
		main->attr_id->element->element.size = locale->attr_id->element->element.size;
		main->attr_id->element->element.type = locale->attr_id->element->element.type;

		main->attr_id->value = gcnew array< BYTE^ >(locale->attr_id->size_bytes);

		for (int i = 0; i < locale->attr_id->size_bytes; i++)
			main->attr_id->value[i] = locale->attr_id->value[i];

		main->VALUE->element = gcnew CLI_ATTRIBUTE_ID_ELEMENT();
		main->VALUE->element->element.size = locale->VALUE.element->element.size;
		main->VALUE->element->element.type = locale->VALUE.element->element.type;

		main->VALUE->size_bytes = locale->VALUE.size_bytes;
		main->VALUE->additional_bits_flag = locale->VALUE.additional_bits_flag;
		main->VALUE->additional_bits_for_size = locale->VALUE.additional_bits_for_size;
		main->VALUE->size_bytes_additional = locale->VALUE.size_bytes_additional;

		main->VALUE->value = gcnew array< BYTE^ >(locale->VALUE.size_bytes);

		for (int i = 0; i < locale->VALUE.size_bytes; i++)
			main->VALUE->value[i] = locale->VALUE.value[i];
	}


};

