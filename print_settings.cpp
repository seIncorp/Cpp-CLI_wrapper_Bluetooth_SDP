#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()
using namespace System;

/*******************************************************************************************/
/* PRINT ATTR. SETTINGS */

// DEFAULT ATTRIBUTES
void CLI_DEFAULT_DATA::CLI_set_all_default_attr_print(int onOff)
{
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::ServiceRecordHandle, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::ServiceClassIDList, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::ProtocolDescriptorList, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::ServiceName, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::ProviderName, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList, onOff);
	CLI_set_default_attr_print(SDP::ATTRIBUTE_ID::ServiceDescription, onOff);

	if (sdp_settings->debug == 1)
		if (onOff)
		{
			Console::WriteLine("[Print ON] ALL default attributes");
		}
		else
		{
			Console::WriteLine("[Print OFF] ALL default attributes");
		}
}


void CLI_DEFAULT_DATA::CLI_set_default_attr_print(Int16 def_attr, int onOff)
{
	if (sdp_settings->debug == 1)
		if (onOff == (int)CLI_SWITCHES::ON)
			Console::Write("[Print ON] ");
		else
			Console::Write("[Print OFF] ");

	switch (def_attr)
	{
		case SDP::ATTRIBUTE_ID::ServiceRecordHandle:
			sdp_settings->print_service.print_service_record = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("ServiceRecordHandle");
		break;

		case SDP::ATTRIBUTE_ID::ServiceClassIDList:
			sdp_settings->print_service.print_service_class_id_list = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("ServiceClassIDList");
		break;

		case SDP::ATTRIBUTE_ID::ProtocolDescriptorList:
			sdp_settings->print_service.print_protocol_descriptor_list = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("ProtocolDescriptorList");
		break;

		case SDP::ATTRIBUTE_ID::ServiceName:
			sdp_settings->print_service.print_service_name = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("ServiceName");
		break;

		case SDP::ATTRIBUTE_ID::ProviderName:
			sdp_settings->print_service.print_provider_name = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("ProviderName");
		break;

		case SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList:
			sdp_settings->print_service.print_bluetooth_profile_descriptor_list = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("BluetoothProfileDescriptorList");
		break;

		case SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList:
			sdp_settings->print_service.print_language_base_attribute_id_list = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("LanguageBaseAttributeIDList");
		break;

		case SDP::ATTRIBUTE_ID::ServiceDescription:
			sdp_settings->print_service.print_service_description = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
			if (sdp_settings->debug == 1)
				Console::WriteLine("ServiceDescription");
		break;
	}
}


// SPECIFIC ATTRIBUTES
void CLI_DEFAULT_DATA::CLI_set_all_specific_attrs_service_print(Int16 service, int onOff)
{
	if (sdp_settings->debug == 1)
		if (onOff == (int)CLI_SWITCHES::ON)
			Console::Write("[Print ON] ");
		else
			Console::Write("[Print OFF] ");

	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::PnPInformation:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_PNPINFO_attributes.PnpInfo = 1;
				
				if(sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation attr.");
			}
			else
			{
				sdp_settings->print_service.print_PNPINFO_attributes.PnpInfo = 0;
				
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			if (sdp_settings->debug == 1)
				Console::WriteLine("Phonebook_Access_PSE attr.");
				
			CLI_set_specific_attr_service_print(service, SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm, onOff);
			CLI_set_specific_attr_service_print(service, SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories, onOff);
			CLI_set_specific_attr_service_print(service, SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures, onOff);
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			if (sdp_settings->debug == 1)
				Console::WriteLine("OBEXObjectPush attr.");

			CLI_set_specific_attr_service_print(service, SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm, onOff);
			CLI_set_specific_attr_service_print(service, SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList, onOff);
			CLI_set_specific_attr_service_print(service, SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion, onOff);
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			if (sdp_settings->debug == 1)
				Console::WriteLine("_NAP attr.");

			CLI_set_specific_attr_service_print(service, SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription, onOff);
			CLI_set_specific_attr_service_print(service, SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType, onOff);
			CLI_set_specific_attr_service_print(service, SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate, onOff);
		break;

		case (SDP::SERVICE_CLASS_ID::Headset):
			if (sdp_settings->debug == 1)
				Console::WriteLine("Headset attr.");

			CLI_set_specific_attr_service_print(service, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, onOff);
		break;

		case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
			if (sdp_settings->debug == 1)
				Console::WriteLine("Headset_Audio_Gateway attr.");

			CLI_set_specific_attr_service_print(service, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, onOff);
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			if (sdp_settings->debug == 1)
				Console::WriteLine("Handsfree attr.");

			CLI_set_specific_attr_service_print(service, SDP::HFP::ATTRIBUTE_ID_HFP::Network, onOff);
			CLI_set_specific_attr_service_print(service, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, onOff);
		break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			if (sdp_settings->debug == 1)
				Console::WriteLine("HandsfreeAudioGateway attr.");

			CLI_set_specific_attr_service_print(service, SDP::HFP::ATTRIBUTE_ID_HFP::Network, onOff);
			CLI_set_specific_attr_service_print(service, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, onOff);
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
			if (sdp_settings->debug == 1)
				Console::WriteLine("A_V_RemoteControl attr.");

			CLI_set_specific_attr_service_print(service, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, onOff);
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
			if (sdp_settings->debug == 1)
				Console::WriteLine("A_V_RemoteControlTarget attr.");

			CLI_set_specific_attr_service_print(service, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, onOff);
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
			if (sdp_settings->debug == 1)
				Console::WriteLine("A_V_RemoteControlController attr.");

			CLI_set_specific_attr_service_print(service, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, onOff);
		break;

		case SDP::SERVICE_CLASS_ID::AudioSource:
			if (sdp_settings->debug == 1)
				Console::WriteLine("AudioSource attr.");

			CLI_set_specific_attr_service_print(service, SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures, onOff);
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			if (sdp_settings->debug == 1)
				Console::WriteLine("Message_Access_Server attr.");

			CLI_set_specific_attr_service_print(service, SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm, onOff);
			CLI_set_specific_attr_service_print(service, SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes, onOff);
			CLI_set_specific_attr_service_print(service, SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID, onOff);
			CLI_set_specific_attr_service_print(service, SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures, onOff);
		break;
	}
}

void CLI_DEFAULT_DATA::CLI_set_specific_attr_service_print(Int16 service, Int16 attr, int onOff)
{
	if (sdp_settings->debug == 1)
		if (onOff == (int)CLI_SWITCHES::ON)
			Console::Write("[Print ON] ");
		else
			Console::Write("[Print OFF] ");

	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::PnPInformation:
			switch (attr)
			{
			case SDP::PNPINFO::SpecificationID:
				sdp_settings->print_service.print_PNPINFO_attributes.SpecificationID = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::VendorID:
				sdp_settings->print_service.print_PNPINFO_attributes.VendorID = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::ProductID:
				sdp_settings->print_service.print_PNPINFO_attributes.ProductID = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::Version:
				sdp_settings->print_service.print_PNPINFO_attributes.Version = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::PrimaryRecord:
				sdp_settings->print_service.print_PNPINFO_attributes.PrimaryRecord = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::VendorIDSource:
				sdp_settings->print_service.print_PNPINFO_attributes.VendorIDSource = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::ClientExecutableURL:
				sdp_settings->print_service.print_PNPINFO_attributes.ClientExecutableURL = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;

			case SDP::PNPINFO::DocumentationURL:
				sdp_settings->print_service.print_PNPINFO_attributes.DocumentationURL = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
				if (sdp_settings->debug == 1)
					Console::WriteLine("PnPInformation -> SpecificationID");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			switch (attr)
			{
				case SDP::PBAP::GoepL2capPsm:
					sdp_settings->print_service.print_PBAP_attributes.print_goepl2cappsm = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Phonebook_Access_PSE -> GoepL2capPsm");
				break;

				case SDP::PBAP::SupportedRepositories:
					sdp_settings->print_service.print_PBAP_attributes.print_supported_repositories = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Phonebook_Access_PSE -> SupportedRepositories");
				break;

				case SDP::PBAP::PbapSupportedFeatures:
					sdp_settings->print_service.print_PBAP_attributes.print_pbap_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Phonebook_Access_PSE -> PbapSupportedFeatures");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			switch (attr)
			{
				case SDP::OBEX::GoepL2capPsm:
					sdp_settings->print_service.print_OBEX_attributes.print_goepl2cappsm = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("OBEXObjectPush -> GoepL2capPsm");
				break;

				case SDP::OBEX::ServiceVersion:
					sdp_settings->print_service.print_OBEX_attributes.print_service_version = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("OBEXObjectPush -> ServiceVersion");
				break;

				case SDP::OBEX::SupportedFormatsList:
					sdp_settings->print_service.print_OBEX_attributes.print_supported_formats = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("OBEXObjectPush -> SupportedFormatsList");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			switch (attr)
			{
				case SDP::NAP::SecurityDescription:
					sdp_settings->print_service.print_NAP_attributes.print_security_description = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("_NAP -> SecurityDescription");
				break;

				case SDP::NAP::NetAccessType:
					sdp_settings->print_service.print_NAP_attributes.print_net_access_type = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("_NAP -> NetAccessType");
				break;

				case SDP::NAP::MaxNetAccessrate:
					sdp_settings->print_service.print_NAP_attributes.print_max_net_access_rate = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("_NAP -> MaxNetAccessrate");
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::Headset):
			switch (attr)
			{
				case SDP::HSP::RemoteAudioVolumeControl:
					sdp_settings->print_service.print_HSP_attributes_Headset.print_remote_audio_volume_control = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Headset -> RemoteAudioVolumeControl");
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
			switch (attr)
			{
				case SDP::HSP::RemoteAudioVolumeControl:
					sdp_settings->print_service.print_HSP_attributes_Headset_Audio_Gateway.print_remote_audio_volume_control = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Headset_Audio_Gateway -> RemoteAudioVolumeControl");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			switch (attr)
			{
				case SDP::HFP::Network:
					sdp_settings->print_service.print_HFP_attributes_Handsfree.print_network = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Handsfree -> Network");
				break;

				case SDP::HFP::SupportedFeatures:
					sdp_settings->print_service.print_HFP_attributes_Handsfree.print_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Handsfree -> SupportedFeatures");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			switch (attr)
			{
				case SDP::HFP::Network:
					sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_network = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("HandsfreeAudioGateway -> Network");
				break;

				case SDP::HFP::SupportedFeatures:
					sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("HandsfreeAudioGateway -> SupportedFeatures");
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
			switch (attr)
			{
				case SDP::AVRCP::SupportedFeatures:
					sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControl.print_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("A_V_RemoteControl -> SupportedFeatures");
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
			switch (attr)
			{
					case SDP::AVRCP::SupportedFeatures:
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlTarget.print_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
						if (sdp_settings->debug == 1)
							Console::WriteLine("A_V_RemoteControlTarget -> SupportedFeatures");
					break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
			switch (attr)
			{
				case SDP::AVRCP::SupportedFeatures:
					sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlController.print_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("A_V_RemoteControlController -> SupportedFeatures");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::AudioSource:
			switch (attr)
			{
				case SDP::A2DP::SupportedFeatures:
					sdp_settings->print_service.print_A2DP_attributes.print_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("AudioSource -> SupportedFeatures");
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			switch (attr)
			{
				case SDP::MAP::GoepL2capPsm:
					sdp_settings->print_service.print_MAP_attributes.print_goepl2cappsm = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Message_Access_Server -> GoepL2capPsm");
				break;

				case SDP::MAP::MASInstanceID:
					sdp_settings->print_service.print_MAP_attributes.print_mas_instance_id = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Message_Access_Server -> MASInstanceID");
				break;

				case SDP::MAP::SupportedMessageTypes:
					sdp_settings->print_service.print_MAP_attributes.print_supported_message_types = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Message_Access_Server -> SupportedMessageTypes");
				break;

				case SDP::MAP::MapSupportedFeatures:
					sdp_settings->print_service.print_MAP_attributes.print_map_supported_features = onOff == (int)CLI_SWITCHES::ON ? 1 : 0;
					if (sdp_settings->debug == 1)
						Console::WriteLine("Message_Access_Server -> MapSupportedFeatures");
				break;
			}
		break;
	}
}

void CLI_DEFAULT_DATA::CLI_show_print_service()
{
	// TODO: dodaj se za printanje glede sdp_settingov
}

/*******************************************************************************************/

/* PRINT ATTR. SETTINGS [NATIVE!!!!] */
// TODO: naredi se za native

void CLI_DEFAULT_DATA::CLI_set_default_print_service_NATIVE(Int16 def_attr)
{
	// default attributes
	switch (def_attr)
	{
	case SDP::ATTRIBUTE_ID::ServiceRecordHandle:
		if (dd->sdp_settings.print_service.print_service_record == 0)
		{
			dd->sdp_settings.print_service.print_service_record = 1;
			Console::WriteLine("[Print ON] ServiceRecordHandle");
		}
		else
		{
			dd->sdp_settings.print_service.print_service_record = 0;
			Console::WriteLine("[Print OFF] ServiceRecordHandle");
		}
		break;

	case SDP::ATTRIBUTE_ID::ServiceClassIDList:
		if (dd->sdp_settings.print_service.print_service_class_id_list == 0)
		{
			dd->sdp_settings.print_service.print_service_class_id_list = 1;
			Console::WriteLine("[Print ON] ServiceClassIDList");
		}
		else
		{
			dd->sdp_settings.print_service.print_service_class_id_list = 0;
			Console::WriteLine("[Print OFF] ServiceClassIDList");
		}
		break;

	case SDP::ATTRIBUTE_ID::ProtocolDescriptorList:
		if (dd->sdp_settings.print_service.print_protocol_descriptor_list == 0)
		{
			dd->sdp_settings.print_service.print_protocol_descriptor_list = 1;
			Console::WriteLine("[Print ON] ProtocolDescriptorList");
		}
		else
		{
			dd->sdp_settings.print_service.print_protocol_descriptor_list = 0;
			Console::WriteLine("[Print OFF] ProtocolDescriptorList");
		}
		break;

	case SDP::ATTRIBUTE_ID::ServiceName:
		if (dd->sdp_settings.print_service.print_service_name == 0)
		{
			dd->sdp_settings.print_service.print_service_name = 1;
			Console::WriteLine("[Print ON] ServiceName");
		}
		else
		{
			dd->sdp_settings.print_service.print_service_name = 0;
			Console::WriteLine("[Print OFF] ServiceName");
		}
		break;

	case SDP::ATTRIBUTE_ID::ProviderName:
		if (dd->sdp_settings.print_service.print_provider_name == 0)
		{
			dd->sdp_settings.print_service.print_provider_name = 1;
			Console::WriteLine("[Print ON] ProviderName");
		}
		else
		{
			dd->sdp_settings.print_service.print_provider_name = 0;
			Console::WriteLine("[Print OFF] ProviderName");
		}
		break;

	case SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList:
		if (dd->sdp_settings.print_service.print_bluetooth_profile_descriptor_list == 0)
		{
			dd->sdp_settings.print_service.print_bluetooth_profile_descriptor_list = 1;
			Console::WriteLine("[Print ON] BluetoothProfileDescriptorList");
		}
		else
		{
			dd->sdp_settings.print_service.print_bluetooth_profile_descriptor_list = 0;
			Console::WriteLine("[Print OFF] BluetoothProfileDescriptorList");
		}
		break;

	case SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList:
		if (dd->sdp_settings.print_service.print_language_base_attribute_id_list == 0)
		{
			dd->sdp_settings.print_service.print_language_base_attribute_id_list = 1;
			Console::WriteLine("[Print ON] LanguageBaseAttributeIDList");
		}
		else
		{
			dd->sdp_settings.print_service.print_language_base_attribute_id_list = 0;
			Console::WriteLine("[Print OFF] LanguageBaseAttributeIDList");
		}
		break;

	case SDP::ATTRIBUTE_ID::ServiceDescription:
		if (dd->sdp_settings.print_service.print_service_description == 0)
		{
			dd->sdp_settings.print_service.print_service_description = 1;
			Console::WriteLine("[Print ON] ServiceDescription");
		}
		else
		{
			dd->sdp_settings.print_service.print_service_description = 0;
			Console::WriteLine("[Print OFF] ServiceDescription");
		}
		break;
	}
}

void CLI_DEFAULT_DATA::CLI_set_specific_print_service_NATIVE(Int16 service)
{
	/* SPECIAL ATTR. */
	//switch (service)
	//{
	//case SDP::SERVICE_CLASS_ID::PnPInformation:
	//	if (dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info == 0)
	//	{
	//		dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info = 1;
	//		Console::WriteLine("[Print ON] PnPInformation->print_pnp_info");
	//	}
	//	else
	//	{
	//		dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info = 0;
	//		Console::WriteLine("[Print OFF] PnPInformation->print_pnp_info");
	//	}

	//	Console::WriteLine("");
	//	break;

	//case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
	//	if (dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm == 0)
	//	{
	//		dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 1;
	//		Console::WriteLine("[Print ON] Phonebook_Access_PSE->print_goepl2cappsm");
	//	}
	//	else
	//	{
	//		dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 0;
	//		Console::WriteLine("[Print OFF] Phonebook_Access_PSE->print_goepl2cappsm");
	//	}

	//	if (dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories == 0)
	//	{
	//		dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 1;
	//		Console::WriteLine("[Print ON] Phonebook_Access_PSE->print_supported_repositories");
	//	}
	//	else
	//	{
	//		dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 0;
	//		Console::WriteLine("[Print OFF] Phonebook_Access_PSE->print_supported_repositories");
	//	}

	//	if (dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features == 0)
	//	{
	//		dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 1;
	//		Console::WriteLine("[Print ON] Phonebook_Access_PSE->print_pbap_supported_features");
	//	}
	//	else
	//	{
	//		dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 0;
	//		Console::WriteLine("[Print OFF] Phonebook_Access_PSE->print_pbap_supported_features");
	//	}

	//	Console::WriteLine("");
	//	break;

	//case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
	//	break;

	//case SDP::SERVICE_CLASS_ID::_NAP:
	//	break;


	//	// TODO: find solution for other services with the same print object
	//case (SDP::SERVICE_CLASS_ID::Headset /*|| SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway*/):
	//	break;

	//case SDP::SERVICE_CLASS_ID::Handsfree:

	//	/*if (hfp_flag_called == 0)
	//	{

	//	}*/
	//	break;

	//	/*case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
	//		if (hfp_flag_called == 0)
	//		{

	//		}
	//		break;*/

	//	case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl /*||
	//		SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget ||
	//		SDP::SERVICE_CLASS_ID::A_V_RemoteControlController*/
	//	):
	//		break;

	//	case SDP::SERVICE_CLASS_ID::AudioSource:
	//		break;

	//	case SDP::SERVICE_CLASS_ID::Message_Access_Server:
	//		break;
	//}
}

void CLI_DEFAULT_DATA::CLI_show_print_service_NATIVE()
{
	if (dd->sdp_settings.print_service.print_service_record == 1)
		Console::WriteLine("[Print ON] ServiceRecordHandle");
	else
		Console::WriteLine("[Print OFF] ServiceRecordHandle");

	if (dd->sdp_settings.print_service.print_service_class_id_list == 1)
		Console::WriteLine("[Print ON] ServiceClassIDList");
	else
		Console::WriteLine("[Print OFF] ServiceClassIDList");

	if (dd->sdp_settings.print_service.print_protocol_descriptor_list == 1)
		Console::WriteLine("[Print ON] ProtocolDescriptorList");
	else
		Console::WriteLine("[Print OFF] ProtocolDescriptorList");

	if (dd->sdp_settings.print_service.print_service_name == 1)
		Console::WriteLine("[Print ON] ServiceName");
	else
		Console::WriteLine("[Print OFF] ServiceName");

	if (dd->sdp_settings.print_service.print_provider_name == 1)
		Console::WriteLine("[Print ON] ProviderName");
	else
		Console::WriteLine("[Print OFF] ProviderName");

	if (dd->sdp_settings.print_service.print_bluetooth_profile_descriptor_list == 1)
		Console::WriteLine("[Print ON] BluetoothProfileDescriptorList");
	else
		Console::WriteLine("[Print OFF] BluetoothProfileDescriptorList");

	if (dd->sdp_settings.print_service.print_language_base_attribute_id_list == 1)
		Console::WriteLine("[Print ON] LanguageBaseAttributeIDList");
	else
		Console::WriteLine("[Print OFF] LanguageBaseAttributeIDList");

	if (dd->sdp_settings.print_service.print_service_description == 1)
		Console::WriteLine("[Print ON] ServiceDescription");
	else
		Console::WriteLine("[Print OFF] ServiceDescription");

	Console::WriteLine("");
}










