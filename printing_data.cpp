#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"


#include <stdio.h> // to printf()





// DONE
void CLI_DEFAULT_DATA::print_data_A2DP()
{
	print_data_DEFAULT<CLI_EXPORTS::CLI_A2DP_EXPORT^,  SDP::A2DP::A2DP_EXPORT_S*>(a2dp_export, dd->exported_data.a2dp_export);
	
	if (((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_A2DP_attributes.print_supported_features == 1)
			a2dp_export->supported_features_handle_export->print<SDP::A2DP::SUPPORTED_FEATURES_S::VV>(((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export->VALUE, *dd);

}
// DONE
void CLI_DEFAULT_DATA::print_data_AVRCP()
{
	if (dd->services_for_search.A_V_RemoteControl == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^, SDP::AVRCP::AVRCP_EXPORT_S*>(avrcp_export_avrc, dd->exported_data.avrcp_export_avrc);

		if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControl.print_supported_features == 1
				)
				avrcp_export_avrc->supported_features_handle_export->print<SDP::AVRCP::SUPPORTED_FEATURES_S::VV>(((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE, *dd);
	}

	if (dd->services_for_search.A_V_RemoteControlController == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^, SDP::AVRCP::AVRCP_EXPORT_S*>(avrcp_export_avrcc, dd->exported_data.avrcp_export_avrcc);

		if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlController.print_supported_features == 1
				)
				avrcp_export_avrcc->supported_features_handle_export->print<SDP::AVRCP::SUPPORTED_FEATURES_S::VV>(((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE, *dd);
	}

	if (dd->services_for_search.A_V_RemoteControlTarget == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^, SDP::AVRCP::AVRCP_EXPORT_S*>(avrcp_export_avrct, dd->exported_data.avrcp_export_avrct);

		if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_AVRCP_attributes_A_V_RemoteControlTarget.print_supported_features == 1 
				)
				avrcp_export_avrct->supported_features_handle_export->print<SDP::AVRCP::SUPPORTED_FEATURES_S::VV>(((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE, *dd);
	}
}
// DONE
void CLI_DEFAULT_DATA::print_data_MAP()
{
	print_data_DEFAULT<CLI_EXPORTS::CLI_MAP_EXPORT^, SDP::MAP::MAP_EXPORT_S*>(map_export, dd->exported_data.map_export);

	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->goepl2cappsm_handle_export != nullptr)
		if(sdp_settings->print == 1 || sdp_settings->print_service.print_MAP_attributes.print_goepl2cappsm == 1)
			map_export->goepl2cappsm_handle_export->print<SDP::MAP::GOEPL2CAPPSM_S::VV>(((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->goepl2cappsm_handle_export->VALUE, *dd);

	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->mas_instance_id_handle != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_MAP_attributes.print_mas_instance_id == 1)
			map_export->mas_instance_id_handle->print<SDP::MAP::MAS_INSTANCE_ID_S::VV>(((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->mas_instance_id_handle->VALUE, *dd);

	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_MAP_attributes.print_supported_message_types == 1)
			map_export->supported_message_types_handle->print<SDP::MAP::SUPPORTED_MESSAGE_TYPES_S::VV>(((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE, *dd);

	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_MAP_attributes.print_map_supported_features == 1)
			map_export->map_supported_features_handle->print<SDP::MAP::MAP_SUPPORTED_FEATURES_S::VV>(((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE, *dd);
}
// DONE
void CLI_DEFAULT_DATA::print_data_HFP()
{
	// TODO: test it
	if (dd->services_for_search.Handsfree == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_HFP_EXPORT^, SDP::HFP::HFP_EXPORT_S*>(hfp_export_Handsfree, dd->exported_data.hfp_export_Handsfree);

		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->network_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_HFP_attributes_Handsfree.print_network == 1
				)
				hfp_export_Handsfree->network_handle_export->print<SDP::HFP::NETWORK_S::VV>(((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->network_handle_export->VALUE, *dd);

		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_HFP_attributes_Handsfree.print_supported_features == 1
				)
				hfp_export_Handsfree->supported_features_handle_export->print<SDP::HFP::SUPPORTED_FEATURES_S::VV>(((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE, *dd);
	}

	if (dd->services_for_search.HandsfreeAudioGateway == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_HFP_EXPORT^, SDP::HFP::HFP_EXPORT_S*>(hfp_export_HandsfreeAG, dd->exported_data.hfp_export_HandsfreeAG);

		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->network_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_network == 1
				)
				hfp_export_HandsfreeAG->network_handle_export->print<SDP::HFP::NETWORK_S::VV>(((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->network_handle_export->VALUE, *dd);

		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export != NULL)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_HFP_attributes_HandsfreeAudioGateway.print_supported_features == 1
				)
				hfp_export_HandsfreeAG->supported_features_handle_export->print<SDP::HFP::SUPPORTED_FEATURES_S::VV>(((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE, *dd);
	}
}
// DONE
void CLI_DEFAULT_DATA::print_data_HSP()
{
	if (dd->services_for_search.Headset == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_HSP_EXPORT^, SDP::HSP::HSP_EXPORT_S*>(hsp_export_headset, dd->exported_data.hsp_export_headset);

		if (((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headset)->remote_audio_volume_control_handle_export != nullptr)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_HSP_attributes_Headset.print_remote_audio_volume_control == 1 
				)
				hsp_export_headset->remote_audio_volume_control_handle_export->print<SDP::HSP::REMOTE_AUDIO_VOLUME_CONTROL_S::VV>(((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headset)->remote_audio_volume_control_handle_export->VALUE, *dd);
	}

	if (dd->services_for_search.Headset_Audio_Gateway == 1)
	{
		print_data_DEFAULT<CLI_EXPORTS::CLI_HSP_EXPORT^, SDP::HSP::HSP_EXPORT_S*>(hsp_export_headsetAG, dd->exported_data.hsp_export_headsetAG);

		if (((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headsetAG)->remote_audio_volume_control_handle_export != nullptr)
			if (sdp_settings->print == 1 ||
				sdp_settings->print_service.print_HSP_attributes_Headset_Audio_Gateway.print_remote_audio_volume_control == 1
				)
				hsp_export_headsetAG->remote_audio_volume_control_handle_export->print<SDP::HSP::REMOTE_AUDIO_VOLUME_CONTROL_S::VV>(((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headsetAG)->remote_audio_volume_control_handle_export->VALUE, *dd);
	}
}
// DONE
void CLI_DEFAULT_DATA::print_data_NAP()
{
	print_data_DEFAULT<CLI_EXPORTS::CLI_NAP_EXPORT^, SDP::NAP::NAP_EXPORT_S*>(nap_export, dd->exported_data.nap_export);

	if (((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->security_description_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_NAP_attributes.print_security_description == 1)
			nap_export->security_description_handle_export->print<SDP::NAP::SECURITY_DESCRIPTION_S::VV>(((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->security_description_handle_export->VALUE, *dd);

	if (((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->net_access_type_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_NAP_attributes.print_net_access_type == 1)
			nap_export->net_access_type_handle_export->print<SDP::NAP::NET_ACCESS_TYPE_S::VV>(((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->net_access_type_handle_export->VALUE, *dd);

	if (((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->max_net_access_rate_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_NAP_attributes.print_max_net_access_rate == 1)
			nap_export->max_net_access_rate_handle_export->print<SDP::NAP::MAX_NET_ACCESS_RATE_S::VV>(((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->max_net_access_rate_handle_export->VALUE, *dd);
}
// DONE
void CLI_DEFAULT_DATA::print_data_OBEX()
{
	print_data_DEFAULT<CLI_EXPORTS::CLI_OBEX_EXPORT^, SDP::OBEX::OBEX_EXPORT_S*>(obex_export, dd->exported_data.obex_export);

	if (((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->service_version_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_OBEX_attributes.print_service_version == 1)
			obex_export->service_version_handle_export->print<SDP::OBEX::SERVICE_VERSION_S::VV>(((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->service_version_handle_export->VALUE, *dd);

	if (((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->supported_formats_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_OBEX_attributes.print_supported_formats == 1)
			obex_export->supported_formats_handle_export->print<SDP::OBEX::SUPPORTED_FORMATS_S::VV>(((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->supported_formats_handle_export->VALUE, *dd);

	if (((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->goepl2cappsm_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_OBEX_attributes.print_goepl2cappsm == 1)
			obex_export->goepl2cappsm_handle_export->print<SDP::MAP::GOEPL2CAPPSM_S::VV>(((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->goepl2cappsm_handle_export->VALUE, *dd);
}
// DONE
void CLI_DEFAULT_DATA::print_data_PBAP()
{
	print_data_DEFAULT<CLI_EXPORTS::CLI_PBAP_EXPORT^, SDP::PBAP::PBAP_EXPORT_S*>(pbap_export, dd->exported_data.pbap_export);

	if (((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_PBAP_attributes.print_supported_repositories == 1)
			pbap_export->supported_repositories_handle_export->print<SDP::PBAP::SUPPORTED_REPOSITORIES_S::VV>(((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export->VALUE, *dd);

	if (((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->pbap_supported_features_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_PBAP_attributes.print_pbap_supported_features == 1)
			pbap_export->pbap_supported_features_handle_export->print<SDP::PBAP::PBAP_SUPPORTED_FEATURES_S::VV>(((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->pbap_supported_features_handle_export->VALUE, *dd);

	if (((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->goepl2cappsm_handle_export != nullptr)
		if (sdp_settings->print == 1 || sdp_settings->print_service.print_PBAP_attributes.print_goepl2cappsm == 1)
			pbap_export->goepl2cappsm_handle_export->print<SDP::MAP::GOEPL2CAPPSM_S::VV>(((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->goepl2cappsm_handle_export->VALUE, *dd);
}

void CLI_DEFAULT_DATA::print_data_PNPINFO()
{
	if (((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export != nullptr)
	{
		
		//if (sdp_settings->print == 1 || sdp_settings->print_service.print_PNPINFO_attributes.print_pnp_info == 1)
			pnpinfo_export->info_handle_export->print<SDP::PNPINFO::INFO_S::VV>(((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->VALUE, *dd, sdp_settings);
	}
}








