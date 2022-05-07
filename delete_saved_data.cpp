#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()

// DONE
void CLI_DEFAULT_DATA::delete_exported_data_A2DP()
{
	if (a2dp_export != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_A2DP_EXPORT^>(a2dp_export);

		if (a2dp_export->supported_features_handle_export != nullptr)
		{
			if (a2dp_export->supported_features_handle_export->VALUE != nullptr)
			{
				if (a2dp_export->supported_features_handle_export->VALUE->sfds != nullptr)
					delete a2dp_export->supported_features_handle_export->VALUE->sfds;

				delete_default_data_of_attr<A2DP::CLI_SUPPORTED_FEATURES^>(a2dp_export->supported_features_handle_export);

				delete a2dp_export->supported_features_handle_export->VALUE;
			}

			delete a2dp_export->supported_features_handle_export;
		}

		delete a2dp_export;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_AVRCP()
{
	if (avrcp_export_avrc != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^>(avrcp_export_avrc);

		if (avrcp_export_avrc->supported_features_handle_export != nullptr)
		{
			if (avrcp_export_avrc->supported_features_handle_export->VALUE != nullptr)
			{
				if (avrcp_export_avrc->supported_features_handle_export->VALUE->sfds != nullptr)
					delete avrcp_export_avrc->supported_features_handle_export->VALUE->sfds;

				delete_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^>(avrcp_export_avrc->supported_features_handle_export);

				delete avrcp_export_avrc->supported_features_handle_export->VALUE;
			}

			delete avrcp_export_avrc->supported_features_handle_export;
		}

		delete avrcp_export_avrc;
	}

	if (avrcp_export_avrct != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^>(avrcp_export_avrct);

		if (avrcp_export_avrct->supported_features_handle_export != nullptr)
		{
			if (avrcp_export_avrct->supported_features_handle_export->VALUE != nullptr)
			{
				if (avrcp_export_avrct->supported_features_handle_export->VALUE->sfds != nullptr)
					delete avrcp_export_avrct->supported_features_handle_export->VALUE->sfds;

				delete_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^>(avrcp_export_avrct->supported_features_handle_export);

				delete avrcp_export_avrct->supported_features_handle_export->VALUE;
			}

			delete avrcp_export_avrct->supported_features_handle_export;
		}

		delete avrcp_export_avrct;
	}

	if (avrcp_export_avrcc != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^>(avrcp_export_avrcc);

		if (avrcp_export_avrcc->supported_features_handle_export != nullptr)
		{
			if (avrcp_export_avrcc->supported_features_handle_export->VALUE != nullptr)
			{
				if (avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds != nullptr)
					delete avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds;

				delete_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^>(avrcp_export_avrcc->supported_features_handle_export);

				delete avrcp_export_avrcc->supported_features_handle_export->VALUE;
			}

			delete avrcp_export_avrcc->supported_features_handle_export;
		}

		delete avrcp_export_avrcc;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_MAP()
{
	if (map_export != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_MAP_EXPORT^>(map_export);

		if (map_export->goepl2cappsm_handle_export != nullptr)
		{
			if (map_export->goepl2cappsm_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^>(map_export->goepl2cappsm_handle_export);

				delete map_export->goepl2cappsm_handle_export->VALUE;
			}

			delete map_export->goepl2cappsm_handle_export;
		}

		if (map_export->supported_message_types_handle != nullptr)
		{
			if (map_export->supported_message_types_handle->VALUE != nullptr)
			{
				if (map_export->supported_message_types_handle->VALUE->sfm != nullptr)
					delete map_export->supported_message_types_handle->VALUE->sfm;

				delete_default_data_of_attr<MAP::CLI_SUPPORTED_MESSAGE_TYPES^>(map_export->supported_message_types_handle);

				delete map_export->supported_message_types_handle->VALUE;
			}

			delete map_export->supported_message_types_handle;
		}


		if (map_export->mas_instance_id_handle != nullptr)
		{
			if (map_export->mas_instance_id_handle->VALUE != nullptr)
			{
				delete_default_data_of_attr<MAP::CLI_MAS_INSTANCE_ID^>(map_export->mas_instance_id_handle);

				delete map_export->mas_instance_id_handle->VALUE;
			}

			delete map_export->mas_instance_id_handle;
		}

		if (map_export->map_supported_features_handle != nullptr)
		{
			if (map_export->map_supported_features_handle->VALUE != nullptr)
			{
				if (map_export->map_supported_features_handle->VALUE->sfm != nullptr)
					delete map_export->map_supported_features_handle->VALUE->sfm;

				delete_default_data_of_attr<MAP::CLI_MAP_SUPPORTED_FEATURES^>(map_export->map_supported_features_handle);

				delete map_export->map_supported_features_handle->VALUE;
			}

			delete map_export->map_supported_features_handle;
		}

		delete map_export;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_HFP()
{
	if (hfp_export_Handsfree != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_HFP_EXPORT^>(hfp_export_Handsfree);

		if (hfp_export_Handsfree->network_handle_export != nullptr)
		{
			if (hfp_export_Handsfree->network_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<HFP::CLI_NETWORK^>(hfp_export_Handsfree->network_handle_export);

				delete hfp_export_Handsfree->network_handle_export->VALUE;
			}

			delete hfp_export_Handsfree->network_handle_export;
		}

		if (hfp_export_Handsfree->supported_features_handle_export != nullptr)
		{
			if (hfp_export_Handsfree->supported_features_handle_export->VALUE != nullptr)
			{
				if (hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds != nullptr)
					delete hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds;

				delete_default_data_of_attr<HFP::CLI_SUPPORTED_FEATURES^>(hfp_export_Handsfree->supported_features_handle_export);

				delete hfp_export_Handsfree->supported_features_handle_export->VALUE;
			}

			delete hfp_export_Handsfree->supported_features_handle_export;
		}

		delete hfp_export_Handsfree;
	}

	if (hfp_export_HandsfreeAG != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_HFP_EXPORT^>(hfp_export_HandsfreeAG);

		if (hfp_export_HandsfreeAG->network_handle_export != nullptr)
		{
			if (hfp_export_HandsfreeAG->network_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<HFP::CLI_NETWORK^>(hfp_export_HandsfreeAG->network_handle_export);

				delete hfp_export_HandsfreeAG->network_handle_export->VALUE;
			}

			delete hfp_export_HandsfreeAG->network_handle_export;
		}

		if (hfp_export_HandsfreeAG->supported_features_handle_export != nullptr)
		{
			if (hfp_export_HandsfreeAG->supported_features_handle_export->VALUE != nullptr)
			{
				if (hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds != nullptr)
					delete hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds;

				delete_default_data_of_attr<HFP::CLI_SUPPORTED_FEATURES^>(hfp_export_HandsfreeAG->supported_features_handle_export);

				delete hfp_export_HandsfreeAG->supported_features_handle_export->VALUE;
			}

			delete hfp_export_HandsfreeAG->supported_features_handle_export;
		}

		delete hfp_export_HandsfreeAG;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_HSP()
{
	if (hsp_export_headset != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_HSP_EXPORT^>(hsp_export_headset);

		if (hsp_export_headset->remote_audio_volume_control_handle_export != nullptr)
		{
			if (hsp_export_headset->remote_audio_volume_control_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL^>(hsp_export_headset->remote_audio_volume_control_handle_export);

				delete hsp_export_headset->remote_audio_volume_control_handle_export->VALUE;
			}

			delete hsp_export_headset->remote_audio_volume_control_handle_export;
		}

		delete hsp_export_headset;
	}

	if (hsp_export_headsetAG != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_HSP_EXPORT^>(hsp_export_headsetAG);

		if (hsp_export_headsetAG->remote_audio_volume_control_handle_export != nullptr)
		{
			if (hsp_export_headsetAG->remote_audio_volume_control_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL^>(hsp_export_headsetAG->remote_audio_volume_control_handle_export);

				delete hsp_export_headsetAG->remote_audio_volume_control_handle_export->VALUE;
			}

			delete hsp_export_headsetAG->remote_audio_volume_control_handle_export;
		}

		delete hsp_export_headsetAG;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_NAP()
{
	if (nap_export != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_NAP_EXPORT^>(nap_export);

		if (nap_export->security_description_handle_export != nullptr)
		{
			if (nap_export->security_description_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<NAP::CLI_SECURITY_DESCRIPTION^>(nap_export->security_description_handle_export);

				delete nap_export->security_description_handle_export->VALUE;
			}

			delete nap_export->security_description_handle_export;
		}
		
		if (nap_export->net_access_type_handle_export != nullptr)
		{
			if (nap_export->net_access_type_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<NAP::CLI_NET_ACCESS_TYPE^>(nap_export->net_access_type_handle_export);

				delete nap_export->net_access_type_handle_export->VALUE;
			}

			delete nap_export->net_access_type_handle_export;
		}

		if (nap_export->max_net_access_rate_handle_export != nullptr)
		{
			if (nap_export->max_net_access_rate_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<NAP::CLI_MAX_NET_ACCESS_RATE^>(nap_export->max_net_access_rate_handle_export);
				
				delete nap_export->max_net_access_rate_handle_export->VALUE;
			}

			delete nap_export->max_net_access_rate_handle_export;
		}

		delete nap_export;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_OBEX()
{
	if (obex_export != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_OBEX_EXPORT^>(obex_export);

		if (obex_export->goepl2cappsm_handle_export != nullptr)
		{
			if (obex_export->goepl2cappsm_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^>(obex_export->goepl2cappsm_handle_export);

				delete obex_export->goepl2cappsm_handle_export->VALUE;
			}

			delete obex_export->goepl2cappsm_handle_export;
		}

		if (obex_export->service_version_handle_export != nullptr)
		{
			if (obex_export->service_version_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<OBEX::CLI_SERVICE_VERSION^>(obex_export->service_version_handle_export);

				delete obex_export->service_version_handle_export->VALUE;
			}

			delete obex_export->service_version_handle_export;
		}

		if (obex_export->supported_formats_handle_export != nullptr)
		{
			if (obex_export->supported_formats_handle_export->VALUE != nullptr)
			{
				if (obex_export->supported_formats_handle_export->VALUE->formats != nullptr)
					delete obex_export->supported_formats_handle_export->VALUE->formats;

				delete_default_data_of_attr<OBEX::CLI_SUPPORTED_FORMATS^>(obex_export->supported_formats_handle_export);

				delete obex_export->supported_formats_handle_export->VALUE;
			}

			delete obex_export->supported_formats_handle_export;
		}

		delete obex_export;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_PBAP()
{
	if (pbap_export != nullptr)
	{
		delete_exported_data_DEFAULT<CLI_EXPORTS::CLI_PBAP_EXPORT^>(pbap_export);

		if (pbap_export->goepl2cappsm_handle_export != nullptr)
		{
			if (pbap_export->goepl2cappsm_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^>(pbap_export->goepl2cappsm_handle_export);

				delete pbap_export->goepl2cappsm_handle_export->VALUE;
			}

			delete pbap_export->goepl2cappsm_handle_export;
		}

		if (pbap_export->supported_repositories_handle_export != nullptr)
		{
			if (pbap_export->supported_repositories_handle_export->VALUE != nullptr)
			{
				if (pbap_export->supported_repositories_handle_export->VALUE->srs != nullptr)
					delete pbap_export->supported_repositories_handle_export->VALUE->srs;

				delete_default_data_of_attr<PBAP::CLI_SUPPORTED_REPOSITORIES^>(pbap_export->supported_repositories_handle_export);

				delete pbap_export->supported_repositories_handle_export->VALUE;
			}

			delete pbap_export->supported_repositories_handle_export;
		}

		if (pbap_export->pbap_supported_features_handle_export != nullptr)
		{
			if (pbap_export->pbap_supported_features_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<PBAP::CLI_PBAP_SUPPORTED_FEATURES^>(pbap_export->pbap_supported_features_handle_export);

				delete pbap_export->pbap_supported_features_handle_export->VALUE;
			}

			delete pbap_export->pbap_supported_features_handle_export;
		}

		delete pbap_export;
	}
}
// DONE
void CLI_DEFAULT_DATA::delete_exported_data_PNPINFO()
{
	if (pnpinfo_export != nullptr)
	{
		//delete_exported_data_DEFAULT<CLI_INFO_EXPORT^>(pnpinfo_export);

		if (pnpinfo_export->info_handle_export != nullptr)
		{
			if (pnpinfo_export->info_handle_export->VALUE != nullptr)
			{
				delete_default_data_of_attr<PNPINFO::CLI_INFO^>(pnpinfo_export->info_handle_export);

				delete pnpinfo_export->info_handle_export->VALUE;
			}

			if (pnpinfo_export->info_handle_export->SpecificationID != nullptr)
			{
				delete pnpinfo_export->info_handle_export->SpecificationID;
			}

			if (pnpinfo_export->info_handle_export->Version != nullptr)
			{
				delete pnpinfo_export->info_handle_export->Version;
			}

			delete pnpinfo_export->info_handle_export;
		}

		delete pnpinfo_export;
	}
}






