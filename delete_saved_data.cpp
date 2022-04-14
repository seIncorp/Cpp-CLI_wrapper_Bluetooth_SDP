#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()


void CLI_DEFAULT_DATA::delete_exported_data_A2DP()
{
	delete_exported_data_DEFAULT<CLI_A2DP_EXPORT^>(a2dp_export);

	if (a2dp_export->supported_features_handle_export->VALUE.sfds != nullptr)
		delete a2dp_export->supported_features_handle_export->VALUE.sfds;

	delete_default_data_of_attr<A2DP::CLI_SUPPORTED_FEATURES^>(a2dp_export->supported_features_handle_export);
	if (a2dp_export->supported_features_handle_export != nullptr)
		delete a2dp_export->supported_features_handle_export;

	if (a2dp_export != nullptr)
		delete a2dp_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_AVRCP()
{
	delete_exported_data_DEFAULT<CLI_AVRCP_EXPORT^>(avrcp_export);

	if (avrcp_export->supported_features_handle_export->VALUE.sfds != nullptr)
		delete avrcp_export->supported_features_handle_export->VALUE.sfds;

	delete_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^>(avrcp_export->supported_features_handle_export);
	if(avrcp_export->supported_features_handle_export != nullptr)
		delete avrcp_export->supported_features_handle_export;

	if (avrcp_export != nullptr)
		delete avrcp_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_MAP()
{
	delete_exported_data_DEFAULT<CLI_MAP_EXPORT^>(map_export);

	delete_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^>(map_export->goepl2cappsm_handle_export);
	if (map_export->goepl2cappsm_handle_export != nullptr)
		delete map_export->goepl2cappsm_handle_export;

	if (map_export->supported_message_types_handle->VALUE.sfm != nullptr)
		delete map_export->supported_message_types_handle->VALUE.sfm;

	delete_default_data_of_attr<MAP::CLI_SUPPORTED_MESSAGE_TYPES^>(map_export->supported_message_types_handle);
	if (map_export->supported_message_types_handle != nullptr)
		delete map_export->supported_message_types_handle;

	delete_default_data_of_attr<MAP::CLI_MAS_INSTANCE_ID^>(map_export->mas_instance_id_handle);
	if (map_export->mas_instance_id_handle != nullptr)
		delete map_export->mas_instance_id_handle;

	if (map_export->map_supported_features_handle->VALUE.sfm != nullptr)
		delete map_export->map_supported_features_handle->VALUE.sfm;

	delete_default_data_of_attr<MAP::CLI_MAP_SUPPORTED_FEATURES^>(map_export->map_supported_features_handle);
	if (map_export->map_supported_features_handle != nullptr)
		delete map_export->map_supported_features_handle;

	if (map_export != nullptr)
		delete map_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_HFP()
{
	delete_exported_data_DEFAULT<CLI_HFP_EXPORT^>(hfp_export);

	delete_default_data_of_attr<HFP::CLI_NETWORK^>(hfp_export->network_handle_export);
	if (hfp_export->network_handle_export != nullptr)
		delete hfp_export->network_handle_export;

	if (hfp_export->supported_features_handle_export->VALUE.sfds != nullptr)
		delete hfp_export->supported_features_handle_export->VALUE.sfds;

	delete_default_data_of_attr<HFP::CLI_SUPPORTED_FEATURES^>(hfp_export->supported_features_handle_export);
	if (hfp_export->supported_features_handle_export != nullptr)
		delete hfp_export->supported_features_handle_export;

	if (hfp_export != nullptr)
		delete hfp_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_HSP()
{
	delete_exported_data_DEFAULT<CLI_HSP_EXPORT^>(hsp_export);

	delete_default_data_of_attr<HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL^>(hsp_export->remote_audio_volume_control_handle_export);
	if (hsp_export->remote_audio_volume_control_handle_export != nullptr)
		delete hsp_export->remote_audio_volume_control_handle_export;

	if (hsp_export != nullptr)
		delete hsp_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_NAP()
{
	delete_exported_data_DEFAULT<CLI_NAP_EXPORT^>(nap_export);

	delete_default_data_of_attr<NAP::CLI_SECURITY_DESCRIPTION^>(nap_export->security_description_handle_export);
	if (nap_export->security_description_handle_export != nullptr)
		delete nap_export->security_description_handle_export;

	delete_default_data_of_attr<NAP::CLI_NET_ACCESS_TYPE^>(nap_export->net_access_type_handle_export);
	if (nap_export->net_access_type_handle_export != nullptr)
		delete nap_export->net_access_type_handle_export;

	delete_default_data_of_attr<NAP::CLI_MAX_NET_ACCESS_RATE^>(nap_export->max_net_access_rate_handle_export);
	if (nap_export->max_net_access_rate_handle_export != nullptr)
		delete nap_export->max_net_access_rate_handle_export;

	if (nap_export != nullptr)
		delete nap_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_OBEX()
{
	delete_exported_data_DEFAULT<CLI_OBEX_EXPORT^>(obex_export);

	delete_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^>(obex_export->goepl2cappsm_handle_export);
	if (obex_export->goepl2cappsm_handle_export != nullptr)
		delete obex_export->goepl2cappsm_handle_export;

	delete_default_data_of_attr<OBEX::CLI_SERVICE_VERSION^>(obex_export->service_version_handle_export);
	if (obex_export->service_version_handle_export != nullptr)
		delete obex_export->service_version_handle_export;

	if (obex_export->supported_formats_handle_export->VALUE.formats != nullptr)
		delete obex_export->supported_formats_handle_export->VALUE.formats;

	delete_default_data_of_attr<OBEX::CLI_SUPPORTED_FORMATS^>(obex_export->supported_formats_handle_export);
	if (obex_export->supported_formats_handle_export != nullptr)
		delete obex_export->supported_formats_handle_export;

	if (obex_export != nullptr)
		delete obex_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_PBAP()
{
	delete_exported_data_DEFAULT<CLI_PBAP_EXPORT^>(pbap_export);

	delete_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^>(pbap_export->goepl2cappsm_handle_export);
	if (pbap_export->goepl2cappsm_handle_export != nullptr)
		delete pbap_export->goepl2cappsm_handle_export;

	if (pbap_export->supported_repositories_handle_export->VALUE.srs != nullptr)
		delete pbap_export->supported_repositories_handle_export->VALUE.srs;

	delete_default_data_of_attr<PBAP::CLI_SUPPORTED_REPOSITORIES^>(pbap_export->supported_repositories_handle_export);
	if (pbap_export->supported_repositories_handle_export != nullptr)
		delete pbap_export->supported_repositories_handle_export;

	delete_default_data_of_attr<PBAP::CLI_PBAP_SUPPORTED_FEATURES^>(pbap_export->pbap_supported_features_handle_export);
	if (pbap_export->pbap_supported_features_handle_export != nullptr)
		delete pbap_export->pbap_supported_features_handle_export;

	if (pbap_export != nullptr)
		delete pbap_export;
}

void CLI_DEFAULT_DATA::delete_exported_data_PNPINFO()
{
	//delete_exported_data_DEFAULT<CLI_INFO_EXPORT^>(pnpinfo_export);

	delete_default_data_of_attr<PNPINFO::CLI_INFO^>(pnpinfo_export->info_handle_export);
	if (pnpinfo_export->info_handle_export != nullptr)
		delete pnpinfo_export->info_handle_export;

	if (pnpinfo_export != nullptr)
		delete pnpinfo_export;
}






