#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()
using namespace System;

/*******************************************************************************************/
/* PRINT ATTR. SETTINGS */

// DEFAULT ATTRIBUTES
void CLI_DEFAULT_DATA::CLI_set_all_default_attr_print()
{
	sdp_settings->print_service.print_service_record = 1;
	sdp_settings->print_service.print_service_class_id_list = 1;
	sdp_settings->print_service.print_protocol_descriptor_list = 1;
	sdp_settings->print_service.print_service_name = 1;
	sdp_settings->print_service.print_provider_name = 1;
	sdp_settings->print_service.print_bluetooth_profile_descriptor_list = 1;
	sdp_settings->print_service.print_language_base_attribute_id_list = 1;
	sdp_settings->print_service.print_service_description = 1;

	Console::WriteLine("[Print ON] ALL default attributes");
}

void CLI_DEFAULT_DATA::CLI_disable_all_default_attr_print()
{
	sdp_settings->print_service.print_service_record = 0;
	sdp_settings->print_service.print_service_class_id_list = 0;
	sdp_settings->print_service.print_protocol_descriptor_list = 0;
	sdp_settings->print_service.print_service_name = 0;
	sdp_settings->print_service.print_provider_name = 0;
	sdp_settings->print_service.print_bluetooth_profile_descriptor_list = 0;
	sdp_settings->print_service.print_language_base_attribute_id_list = 0;
	sdp_settings->print_service.print_service_description = 0;

	Console::WriteLine("[Print OFF] ALL default attributes");
}

void CLI_DEFAULT_DATA::CLI_set_default_attr_print(Int16 def_attr, int onOff)
{
	switch (def_attr)
	{
		case SDP::ATTRIBUTE_ID::ServiceRecordHandle:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_service_record = 1;
				Console::WriteLine("[Print ON] ServiceRecordHandle");
			}
			else
			{
				sdp_settings->print_service.print_service_record = 0;
				Console::WriteLine("[Print OFF] ServiceRecordHandle");
			}
		break;

		case SDP::ATTRIBUTE_ID::ServiceClassIDList:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_service_class_id_list = 1;
				Console::WriteLine("[Print ON] ServiceClassIDList");
			}
			else
			{
				sdp_settings->print_service.print_service_class_id_list = 0;
				Console::WriteLine("[Print OFF] ServiceClassIDList");
			}
		break;

		case SDP::ATTRIBUTE_ID::ProtocolDescriptorList:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_protocol_descriptor_list = 1;
				Console::WriteLine("[Print ON] ProtocolDescriptorList");
			}
			else
			{
				sdp_settings->print_service.print_protocol_descriptor_list = 0;
				Console::WriteLine("[Print OFF] ProtocolDescriptorList");
			}
		break;

		case SDP::ATTRIBUTE_ID::ServiceName:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_service_name = 1;
				Console::WriteLine("[Print ON] ServiceName");
			}
			else
			{
				sdp_settings->print_service.print_service_name = 0;
				Console::WriteLine("[Print OFF] ServiceName");
			}
		break;

		case SDP::ATTRIBUTE_ID::ProviderName:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_provider_name = 1;
				Console::WriteLine("[Print ON] ProviderName");
			}
			else
			{
				sdp_settings->print_service.print_provider_name = 0;
				Console::WriteLine("[Print OFF] ProviderName");
			}
		break;

		case SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_bluetooth_profile_descriptor_list = 1;
				Console::WriteLine("[Print ON] BluetoothProfileDescriptorList");
			}
			else
			{
				sdp_settings->print_service.print_bluetooth_profile_descriptor_list = 0;
				Console::WriteLine("[Print OFF] BluetoothProfileDescriptorList");
			}
		break;

		case SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_language_base_attribute_id_list = 1;
				Console::WriteLine("[Print ON] LanguageBaseAttributeIDList");
			}
			else
			{
				sdp_settings->print_service.print_language_base_attribute_id_list = 0;
				Console::WriteLine("[Print OFF] LanguageBaseAttributeIDList");
			}
		break;

		case SDP::ATTRIBUTE_ID::ServiceDescription:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_service_description = 1;
				Console::WriteLine("[Print ON] ServiceDescription");
			}
			else
			{
				sdp_settings->print_service.print_service_description = 0;
				Console::WriteLine("[Print OFF] ServiceDescription");
			}
		break;
	}
}


// SPECIFIC ATTRIBUTES
void CLI_DEFAULT_DATA::CLI_set_all_specific_attrs_service_print(Int16 service, int onOff)
{
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::PnPInformation:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_PNPINFO_attributes.print_pnp_info = 1;
				Console::WriteLine("[Print ON] PnPInformation attr.");
			}
			else
			{
				sdp_settings->print_service.print_PNPINFO_attributes.print_pnp_info = 0;
				Console::WriteLine("[Print OFF] PnPInformation attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_PBAP_attributes.print_goepl2cappsm = 1;
				sdp_settings->print_service.print_PBAP_attributes.print_supported_repositories = 1;
				sdp_settings->print_service.print_PBAP_attributes.print_pbap_supported_features = 1;
				Console::WriteLine("[Print ON] Phonebook_Access_PSE attr.");
			}
			else
			{
				sdp_settings->print_service.print_PBAP_attributes.print_goepl2cappsm = 0;
				sdp_settings->print_service.print_PBAP_attributes.print_supported_repositories = 0;
				sdp_settings->print_service.print_PBAP_attributes.print_pbap_supported_features = 0;
				Console::WriteLine("[Print OFF] Phonebook_Access_PSE attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_OBEX_attributes.print_goepl2cappsm = 1;
				sdp_settings->print_service.print_OBEX_attributes.print_supported_formats = 1;
				sdp_settings->print_service.print_OBEX_attributes.print_service_version = 1;
				Console::WriteLine("[Print ON] OBEXObjectPush attr.");
			}
			else
			{
				sdp_settings->print_service.print_OBEX_attributes.print_goepl2cappsm = 0;
				sdp_settings->print_service.print_OBEX_attributes.print_supported_formats = 0;
				sdp_settings->print_service.print_OBEX_attributes.print_service_version = 0;
				Console::WriteLine("[Print OFF] OBEXObjectPush attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_NAP_attributes.print_security_description = 1;
				sdp_settings->print_service.print_NAP_attributes.print_net_access_type = 1;
				sdp_settings->print_service.print_NAP_attributes.print_max_net_access_rate = 1;
				Console::WriteLine("[Print ON] _NAP attr.");
			}
			else
			{
				sdp_settings->print_service.print_NAP_attributes.print_security_description = 0;
				sdp_settings->print_service.print_NAP_attributes.print_net_access_type = 0;
				sdp_settings->print_service.print_NAP_attributes.print_max_net_access_rate = 0;
				Console::WriteLine("[Print OFF] _NAP attr.");
			}
		break;

		case (SDP::SERVICE_CLASS_ID::Headset):
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_HSP_attributes_Headset.print_remote_audio_volume_control = 1;
				Console::WriteLine("[Print ON] Headset attr.");
			}
			else
			{
				sdp_settings->print_service.print_HSP_attributes_Headset.print_remote_audio_volume_control = 0;
				Console::WriteLine("[Print OFF] Headset attr.");
			}
		break;

		case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_HSP_attributes_Headset_Audio_Gateway.print_remote_audio_volume_control = 1;
				Console::WriteLine("[Print ON] Headset_Audio_Gateway attr.");
			}
			else
			{
				sdp_settings->print_service.print_HSP_attributes_Headset_Audio_Gateway.print_remote_audio_volume_control = 0;
				Console::WriteLine("[Print OFF] Headset_Audio_Gateway attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_HFP_attributes_Handsfree.print_network = 1;
				sdp_settings->print_service.print_HFP_attributes_Handsfree.print_supported_features = 1;
				Console::WriteLine("[Print ON] Handsfree attr.");
			}
			else
			{
				sdp_settings->print_service.print_HFP_attributes_Handsfree.print_network = 0;
				sdp_settings->print_service.print_HFP_attributes_Handsfree.print_supported_features = 0;
				Console::WriteLine("[Print OFF] Handsfree attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_network = 1;
				sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_supported_features = 1;
				Console::WriteLine("[Print ON] HandsfreeAudioGateway attr.");
			}
			else
			{
				sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_network = 0;
				sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_supported_features = 0;
				Console::WriteLine("[Print OFF] HandsfreeAudioGateway attr.");
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControl.print_supported_features = 1;
				Console::WriteLine("[Print ON] A_V_RemoteControl attr.");
			}
			else
			{
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControl.print_supported_features = 0;
				Console::WriteLine("[Print OFF] A_V_RemoteControl attr.");
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlTarget.print_supported_features = 1;
				Console::WriteLine("[Print ON] A_V_RemoteControlTarget attr.");
			}
			else
			{
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlTarget.print_supported_features = 0;
				Console::WriteLine("[Print OFF] A_V_RemoteControlTarget attr.");
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlController.print_supported_features = 1;
				Console::WriteLine("[Print ON] A_V_RemoteControlController attr.");
			}
			else
			{
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlController.print_supported_features = 0;
				Console::WriteLine("[Print OFF] A_V_RemoteControlController attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::AudioSource:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_A2DP_attributes.print_supported_features = 1;
				Console::WriteLine("[Print ON] AudioSource attr.");
			}
			else
			{
				sdp_settings->print_service.print_A2DP_attributes.print_supported_features = 0;
				Console::WriteLine("[Print OFF] AudioSource attr.");
			}
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			if (onOff == (int)CLI_SWITCHES::ON)
			{
				sdp_settings->print_service.print_MAP_attributes.print_goepl2cappsm = 1;
				sdp_settings->print_service.print_MAP_attributes.print_supported_message_types = 1;
				sdp_settings->print_service.print_MAP_attributes.print_mas_instance_id = 1;
				sdp_settings->print_service.print_MAP_attributes.print_map_supported_features = 1;

				Console::WriteLine("[Print ON] Message_Access_Server attr.");
			}
			else
			{
				sdp_settings->print_service.print_MAP_attributes.print_goepl2cappsm = 0;
				sdp_settings->print_service.print_MAP_attributes.print_supported_message_types = 0;
				sdp_settings->print_service.print_MAP_attributes.print_mas_instance_id = 0;
				sdp_settings->print_service.print_MAP_attributes.print_map_supported_features = 0;

				Console::WriteLine("[Print OFF] Message_Access_Server attr.");
			}
		break;
	}
}

void CLI_DEFAULT_DATA::CLI_set_specific_attr_service_print(Int16 service, Int16 attr, int onOff)
{
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::PnPInformation:
			// TODO: ko bo mozno za vsak posebej search in printanje
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			switch (attr)
			{
				case SDP::PBAP::GoepL2capPsm:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_PBAP_attributes.print_goepl2cappsm = 1;
					else
						sdp_settings->print_service.print_PBAP_attributes.print_goepl2cappsm = 0;
				break;

				case SDP::PBAP::SupportedRepositories:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_PBAP_attributes.print_supported_repositories = 1;
					else
						sdp_settings->print_service.print_PBAP_attributes.print_supported_repositories = 0;
				break;

				case SDP::PBAP::PbapSupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_PBAP_attributes.print_pbap_supported_features = 1;
					else
						sdp_settings->print_service.print_PBAP_attributes.print_pbap_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			switch (attr)
			{
				case SDP::OBEX::GoepL2capPsm:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_OBEX_attributes.print_goepl2cappsm = 1;
					else
						sdp_settings->print_service.print_OBEX_attributes.print_goepl2cappsm = 0;
				break;

				case SDP::OBEX::ServiceVersion:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_OBEX_attributes.print_service_version = 1;
					else
						sdp_settings->print_service.print_OBEX_attributes.print_service_version = 0;
				break;

				case SDP::OBEX::SupportedFormatsList:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_OBEX_attributes.print_supported_formats = 1;
					else
						sdp_settings->print_service.print_OBEX_attributes.print_supported_formats = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			switch (attr)
			{
				case SDP::NAP::SecurityDescription:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_NAP_attributes.print_security_description = 1;
					else
						sdp_settings->print_service.print_NAP_attributes.print_security_description = 0;
				break;

				case SDP::NAP::NetAccessType:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_NAP_attributes.print_net_access_type = 1;
					else
						sdp_settings->print_service.print_NAP_attributes.print_net_access_type = 0;
				break;

				case SDP::NAP::MaxNetAccessrate:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_NAP_attributes.print_max_net_access_rate = 1;
					else
						sdp_settings->print_service.print_NAP_attributes.print_max_net_access_rate = 0;
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::Headset):
			switch (attr)
			{
				case SDP::HSP::RemoteAudioVolumeControl:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_HSP_attributes_Headset.print_remote_audio_volume_control = 1;
					else
						sdp_settings->print_service.print_HSP_attributes_Headset.print_remote_audio_volume_control = 0;
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway):
			switch (attr)
			{
				case SDP::HSP::RemoteAudioVolumeControl:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_HSP_attributes_Headset_Audio_Gateway.print_remote_audio_volume_control = 1;
					else
						sdp_settings->print_service.print_HSP_attributes_Headset_Audio_Gateway.print_remote_audio_volume_control = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			switch (attr)
			{
				case SDP::HFP::Network:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_HFP_attributes_Handsfree.print_network = 1;
					else
						sdp_settings->print_service.print_HFP_attributes_Handsfree.print_network = 0;
				break;

				case SDP::HFP::SupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_HFP_attributes_Handsfree.print_supported_features = 1;
					else
						sdp_settings->print_service.print_HFP_attributes_Handsfree.print_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			switch (attr)
			{
				case SDP::HFP::Network:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_network = 1;
					else
						sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_network = 0;
				break;

				case SDP::HFP::SupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_supported_features = 1;
					else
						sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_supported_features = 0;
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl):
			switch (attr)
			{
				case SDP::AVRCP::SupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControl.print_supported_features = 1;
					else
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControl.print_supported_features = 0;
				break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget):
			switch (attr)
			{
				case SDP::AVRCP::SupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlTarget.print_supported_features = 1;
					else
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlTarget.print_supported_features = 0;
					break;
			}
		break;

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControlController):
			switch (attr)
			{
				case SDP::AVRCP::SupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlController.print_supported_features = 1;
					else
						sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlController.print_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::AudioSource:
			switch (attr)
			{
				case SDP::A2DP::SupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_A2DP_attributes.print_supported_features = 1;
					else
						sdp_settings->print_service.print_A2DP_attributes.print_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			switch (attr)
			{
				case SDP::MAP::GoepL2capPsm:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_MAP_attributes.print_goepl2cappsm = 1;
					else
						sdp_settings->print_service.print_MAP_attributes.print_goepl2cappsm = 0;
				break;

				case SDP::MAP::MASInstanceID:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_MAP_attributes.print_mas_instance_id = 1;
					else
						sdp_settings->print_service.print_MAP_attributes.print_mas_instance_id = 0;
				break;

				case SDP::MAP::SupportedMessageTypes:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_MAP_attributes.print_supported_message_types = 1;
					else
						sdp_settings->print_service.print_MAP_attributes.print_supported_message_types = 0;
				break;

				case SDP::MAP::MapSupportedFeatures:
					if (onOff == (int)CLI_SWITCHES::ON)
						sdp_settings->print_service.print_MAP_attributes.print_map_supported_features = 1;
					else
						sdp_settings->print_service.print_MAP_attributes.print_map_supported_features = 0;
				break;
			}
		break;
	}
}

void CLI_DEFAULT_DATA::CLI_show_print_service()
{
	
}

/*******************************************************************************************/

/* PRINT ATTR. SETTINGS [NATIVE!!!!] */

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
	switch (service)
	{
	case SDP::SERVICE_CLASS_ID::PnPInformation:
		if (dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info == 0)
		{
			dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info = 1;
			Console::WriteLine("[Print ON] PnPInformation->print_pnp_info");
		}
		else
		{
			dd->sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info = 0;
			Console::WriteLine("[Print OFF] PnPInformation->print_pnp_info");
		}

		Console::WriteLine("");
		break;

	case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
		if (dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm == 0)
		{
			dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 1;
			Console::WriteLine("[Print ON] Phonebook_Access_PSE->print_goepl2cappsm");
		}
		else
		{
			dd->sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 0;
			Console::WriteLine("[Print OFF] Phonebook_Access_PSE->print_goepl2cappsm");
		}

		if (dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories == 0)
		{
			dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 1;
			Console::WriteLine("[Print ON] Phonebook_Access_PSE->print_supported_repositories");
		}
		else
		{
			dd->sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 0;
			Console::WriteLine("[Print OFF] Phonebook_Access_PSE->print_supported_repositories");
		}

		if (dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features == 0)
		{
			dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 1;
			Console::WriteLine("[Print ON] Phonebook_Access_PSE->print_pbap_supported_features");
		}
		else
		{
			dd->sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 0;
			Console::WriteLine("[Print OFF] Phonebook_Access_PSE->print_pbap_supported_features");
		}

		Console::WriteLine("");
		break;

	case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
		break;

	case SDP::SERVICE_CLASS_ID::_NAP:
		break;


		// TODO: find solution for other services with the same print object
	case (SDP::SERVICE_CLASS_ID::Headset /*|| SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway*/):
		break;

	case SDP::SERVICE_CLASS_ID::Handsfree:

		/*if (hfp_flag_called == 0)
		{

		}*/
		break;

		/*case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			if (hfp_flag_called == 0)
			{

			}
			break;*/

		case (SDP::SERVICE_CLASS_ID::A_V_RemoteControl /*||
			SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget ||
			SDP::SERVICE_CLASS_ID::A_V_RemoteControlController*/
		):
			break;

		case SDP::SERVICE_CLASS_ID::AudioSource:
			break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			break;
	}
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










