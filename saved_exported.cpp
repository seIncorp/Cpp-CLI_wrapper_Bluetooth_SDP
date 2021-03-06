#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()



// DONE
void CLI_DEFAULT_DATA::save_exported_data_A2DP()
{
	a2dp_export = gcnew CLI_EXPORTS::CLI_A2DP_EXPORT();

	// DEFAULT ATTR.
	save_exported_data_DEFAULT<CLI_EXPORTS::CLI_A2DP_EXPORT^, SDP::A2DP::A2DP_EXPORT_S*>(a2dp_export, dd->exported_data.a2dp_export);

	//  SUPPORTED_FEATURES
	if (((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export != NULL)
	{
		
		a2dp_export->supported_features_handle_export = gcnew A2DP::CLI_SUPPORTED_FEATURES();

		a2dp_export->supported_features_handle_export->VALUE = gcnew A2DP::CLI_SUPPORTED_FEATURES::VV();

		save_default_data_of_attr<A2DP::CLI_SUPPORTED_FEATURES^, SDP::A2DP::SUPPORTED_FEATURES*>(
			a2dp_export->supported_features_handle_export, 
			dd, 
			((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export
		);

		a2dp_export->supported_features_handle_export->VALUE->supported_features_value = ((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export->VALUE.supported_features_value;
	
		a2dp_export->supported_features_handle_export->VALUE->sfds = gcnew A2DP::CLI_SUPPORTED_FEATURES_DATA();
		a2dp_export->supported_features_handle_export->VALUE->sfds->a0 = ((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export->VALUE.sfds->repo->a0;
		a2dp_export->supported_features_handle_export->VALUE->sfds->a1 = ((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export->VALUE.sfds->repo->a1;
		a2dp_export->supported_features_handle_export->VALUE->sfds->a2 = ((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export->VALUE.sfds->repo->a2;
		a2dp_export->supported_features_handle_export->VALUE->sfds->a3 = ((SDP::A2DP::A2DP_EXPORT_S*)dd->exported_data.a2dp_export)->supported_features_handle_export->VALUE.sfds->repo->a3;
	}

	print_data_A2DP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_AVRCP()
{
	if (dd->services_for_search.A_V_RemoteControl == 1)
	{
		avrcp_export_avrc = gcnew CLI_EXPORTS::CLI_AVRCP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^, SDP::AVRCP::AVRCP_EXPORT_S*>(avrcp_export_avrc, dd->exported_data.avrcp_export_avrc);

		//SUPPORTED_FEATURES
		if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export != NULL)
		{
			avrcp_export_avrc->supported_features_handle_export = gcnew AVRCP::CLI_SUPPORTED_FEATURES();

			avrcp_export_avrc->supported_features_handle_export->VALUE = gcnew AVRCP::CLI_SUPPORTED_FEATURES::VV();

			save_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^, SDP::AVRCP::SUPPORTED_FEATURES*>(
				avrcp_export_avrc->supported_features_handle_export,
				dd,
				((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export
				);

			avrcp_export_avrc->supported_features_handle_export->VALUE->supported_features_value = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.supported_features_value;

			avrcp_export_avrc->supported_features_handle_export->VALUE->sfds = gcnew AVRCP::CLI_SUPPORTED_FEATURES_DATA();

			if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc != nullptr)
			{
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a0 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a0;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a1 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a1;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a2 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a2;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a3 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a3;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a6 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a6;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a7 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a7;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a8 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a8;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a9 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a9;
			}

			if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct != nullptr)
			{
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a0 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a0;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a1 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a1;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a2 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a2;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a3 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a3;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a4 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a4;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a5 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a5;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a6 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a6;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a7 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a7;
				avrcp_export_avrc->supported_features_handle_export->VALUE->sfds->avrct.a8 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrc)->supported_features_handle_export->VALUE.sfds->avrct->a8;
			}
		}
	}

	if (dd->services_for_search.A_V_RemoteControlTarget == 1)
	{
		avrcp_export_avrct = gcnew CLI_EXPORTS::CLI_AVRCP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^, SDP::AVRCP::AVRCP_EXPORT_S*>(avrcp_export_avrct, dd->exported_data.avrcp_export_avrct);

		//SUPPORTED_FEATURES
		if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export != NULL)
		{
			avrcp_export_avrct->supported_features_handle_export = gcnew AVRCP::CLI_SUPPORTED_FEATURES();

			avrcp_export_avrct->supported_features_handle_export->VALUE = gcnew AVRCP::CLI_SUPPORTED_FEATURES::VV();

			save_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^, SDP::AVRCP::SUPPORTED_FEATURES*>(
				avrcp_export_avrct->supported_features_handle_export,
				dd,
				((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export
				);

			avrcp_export_avrct->supported_features_handle_export->VALUE->supported_features_value = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.supported_features_value;

			avrcp_export_avrct->supported_features_handle_export->VALUE->sfds = gcnew AVRCP::CLI_SUPPORTED_FEATURES_DATA();

			if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc != nullptr)
			{
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a0 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a0;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a1 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a1;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a2 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a2;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a3 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a3;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a6 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a6;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a7 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a7;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a8 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a8;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a9 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a9;
			}

			if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct != nullptr)
			{
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a0 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a0;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a1 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a1;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a2 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a2;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a3 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a3;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a4 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a4;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a5 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a5;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a6 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a6;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a7 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a7;
				avrcp_export_avrct->supported_features_handle_export->VALUE->sfds->avrct.a8 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrct)->supported_features_handle_export->VALUE.sfds->avrct->a8;
			}
		}
	}

	if (dd->services_for_search.A_V_RemoteControlController == 1)
	{
		avrcp_export_avrcc = gcnew CLI_EXPORTS::CLI_AVRCP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_AVRCP_EXPORT^, SDP::AVRCP::AVRCP_EXPORT_S*>(avrcp_export_avrcc, dd->exported_data.avrcp_export_avrcc);

		//SUPPORTED_FEATURES
		if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export != NULL)
		{
			avrcp_export_avrcc->supported_features_handle_export = gcnew AVRCP::CLI_SUPPORTED_FEATURES();

			avrcp_export_avrcc->supported_features_handle_export->VALUE = gcnew AVRCP::CLI_SUPPORTED_FEATURES::VV();

			save_default_data_of_attr<AVRCP::CLI_SUPPORTED_FEATURES^, SDP::AVRCP::SUPPORTED_FEATURES*>(
				avrcp_export_avrcc->supported_features_handle_export,
				dd,
				((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export
				);

			avrcp_export_avrcc->supported_features_handle_export->VALUE->supported_features_value = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.supported_features_value;

			avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds = gcnew AVRCP::CLI_SUPPORTED_FEATURES_DATA();

			if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc != nullptr)
			{
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a0 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a0;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a1 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a1;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a2 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a2;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a3 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a3;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a6 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a6;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a7 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a7;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a8 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a8;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrc_avrcc.a9 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrc_avrcc->a9;
			}

			if (((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct != nullptr)
			{
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a0 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a0;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a1 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a1;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a2 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a2;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a3 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a3;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a4 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a4;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a5 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a5;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a6 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a6;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a7 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a7;
				avrcp_export_avrcc->supported_features_handle_export->VALUE->sfds->avrct.a8 = ((SDP::AVRCP::AVRCP_EXPORT_S*)dd->exported_data.avrcp_export_avrcc)->supported_features_handle_export->VALUE.sfds->avrct->a8;
			}
		}
	}

	print_data_AVRCP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_MAP()
{
	map_export = gcnew CLI_EXPORTS::CLI_MAP_EXPORT();

	save_exported_data_DEFAULT<CLI_EXPORTS::CLI_MAP_EXPORT^, SDP::MAP::MAP_EXPORT_S*>(map_export, dd->exported_data.map_export);

	//GOEPL2CAPPSM
	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->goepl2cappsm_handle_export != nullptr)
	{
		map_export->goepl2cappsm_handle_export = gcnew MAP::CLI_GOEPL2CAPPSM();

		map_export->goepl2cappsm_handle_export->VALUE = gcnew MAP::CLI_GOEPL2CAPPSM::VV();

		save_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^, SDP::MAP::GOEPL2CAPPSM*>(
			map_export->goepl2cappsm_handle_export,
			dd,
			((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->goepl2cappsm_handle_export
		);

		map_export->goepl2cappsm_handle_export->VALUE->GoepL2CapPsm_value = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->goepl2cappsm_handle_export->VALUE.GoepL2CapPsm_value;
	}

	//SUPPORTED_MESSAGE_TYPES
	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle != nullptr)
	{
		map_export->supported_message_types_handle = gcnew MAP::CLI_SUPPORTED_MESSAGE_TYPES();

		map_export->supported_message_types_handle->VALUE = gcnew MAP::CLI_SUPPORTED_MESSAGE_TYPES::VV();

		save_default_data_of_attr<MAP::CLI_SUPPORTED_MESSAGE_TYPES^, SDP::MAP::SUPPORTED_MESSAGE_TYPES*>(
			map_export->supported_message_types_handle,
			dd,
			((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle
		);

		map_export->supported_message_types_handle->VALUE->sfm = gcnew MAP::CLI_SUPPORTED_FEATURES_MESSAGES();

		if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE.sfm->ttt != NULL)
		{
			map_export->supported_message_types_handle->VALUE->sfm->ttt.a0 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE.sfm->ttt->a0;
			map_export->supported_message_types_handle->VALUE->sfm->ttt.a1 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE.sfm->ttt->a1;
			map_export->supported_message_types_handle->VALUE->sfm->ttt.a2 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE.sfm->ttt->a2;
			map_export->supported_message_types_handle->VALUE->sfm->ttt.a3 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE.sfm->ttt->a3;
			map_export->supported_message_types_handle->VALUE->sfm->ttt.a4 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->supported_message_types_handle->VALUE.sfm->ttt->a4;
		}
	}

	//MAS_INSTANCE_ID
	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->mas_instance_id_handle != nullptr)
	{
		map_export->mas_instance_id_handle = gcnew MAP::CLI_MAS_INSTANCE_ID();

		map_export->mas_instance_id_handle->VALUE = gcnew MAP::CLI_MAS_INSTANCE_ID::VV();

		save_default_data_of_attr<MAP::CLI_MAS_INSTANCE_ID^, SDP::MAP::MAS_INSTANCE_ID*>(
			map_export->mas_instance_id_handle,
			dd,
			((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->mas_instance_id_handle
		);

		map_export->mas_instance_id_handle->VALUE->instance_ID = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->mas_instance_id_handle->VALUE.instance_ID;
	}

	//MAP_SUPPORTED_FEATURES
	if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle != nullptr)
	{
		map_export->map_supported_features_handle = gcnew MAP::CLI_MAP_SUPPORTED_FEATURES();

		map_export->map_supported_features_handle->VALUE = gcnew MAP::CLI_MAP_SUPPORTED_FEATURES::VV();

		save_default_data_of_attr<MAP::CLI_MAP_SUPPORTED_FEATURES^, SDP::MAP::MAP_SUPPORTED_FEATURES*>(
			map_export->map_supported_features_handle,
			dd,
			((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle
		);

		map_export->map_supported_features_handle->VALUE->sfm = gcnew MAP::CLI_SUPPORTED_FEATURES_MESSAGES();

		if (((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa != nullptr)
		{
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a0 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a0;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a1 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a1;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a2 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a2;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a3 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a3;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a4 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a4;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a5 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a5;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a6 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a6;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a7 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a7;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a8 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a8;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a9 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a9;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a10 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a10;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a11 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a11;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a12 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a12;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a13 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a13;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a14 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a14;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a15 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a15;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a16 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a16;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a17 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a17;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a18 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a18;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a19 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a19;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a20 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a20;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a21 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a21;
			map_export->map_supported_features_handle->VALUE->sfm->aaa.a22 = ((SDP::MAP::MAP_EXPORT_S*)dd->exported_data.map_export)->map_supported_features_handle->VALUE.sfm->aaa->a22;
		}
	}

	print_data_MAP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_HFP()
{
	if (dd->services_for_search.Handsfree == 1)
	{
		hfp_export_Handsfree = gcnew CLI_EXPORTS::CLI_HFP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_HFP_EXPORT^, SDP::HFP::HFP_EXPORT_S*>(hfp_export_Handsfree, dd->exported_data.hfp_export_Handsfree);

		// NETWORK
		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->network_handle_export != nullptr)
		{
			hfp_export_Handsfree->network_handle_export = gcnew HFP::CLI_NETWORK();

			hfp_export_Handsfree->network_handle_export->VALUE = gcnew HFP::CLI_NETWORK::VV();

			save_default_data_of_attr<HFP::CLI_NETWORK^, SDP::HFP::NETWORK*>(
				hfp_export_Handsfree->network_handle_export,
				dd,
				((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->network_handle_export
				);
		}

		// SUPPORTED_FEATURES
		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export != nullptr)
		{
			hfp_export_Handsfree->supported_features_handle_export = gcnew HFP::CLI_SUPPORTED_FEATURES();

			hfp_export_Handsfree->supported_features_handle_export->VALUE = gcnew HFP::CLI_SUPPORTED_FEATURES::VV();

			save_default_data_of_attr<HFP::CLI_SUPPORTED_FEATURES^, SDP::HFP::SUPPORTED_FEATURES*>(
				hfp_export_Handsfree->supported_features_handle_export,
				dd,
				((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export
				);

			hfp_export_Handsfree->supported_features_handle_export->VALUE->supported_features_value = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.supported_features_value;

			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds = gcnew HFP::CLI_SUPPORTED_FEATURES_DATA();

			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a0 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a0;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a1 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a1;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a2 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a2;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a3 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a3;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a4 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a4;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a5 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a5;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a6 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a6;
			hfp_export_Handsfree->supported_features_handle_export->VALUE->sfds->repo.a7 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_Handsfree)->supported_features_handle_export->VALUE.sfds->repo->a7;
		}
	}

	if (dd->services_for_search.HandsfreeAudioGateway == 1)
	{
		hfp_export_HandsfreeAG = gcnew CLI_EXPORTS::CLI_HFP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_HFP_EXPORT^, SDP::HFP::HFP_EXPORT_S*>(hfp_export_HandsfreeAG, dd->exported_data.hfp_export_HandsfreeAG);

		// NETWORK
		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->network_handle_export != NULL)
		{
			hfp_export_HandsfreeAG->network_handle_export = gcnew HFP::CLI_NETWORK();

			hfp_export_HandsfreeAG->network_handle_export->VALUE = gcnew HFP::CLI_NETWORK::VV();

			save_default_data_of_attr<HFP::CLI_NETWORK^, SDP::HFP::NETWORK*>(
				hfp_export_HandsfreeAG->network_handle_export,
				dd,
				((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->network_handle_export
				);
		}

		// SUPPORTED_FEATURES
		if (((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export != NULL)
		{
			hfp_export_HandsfreeAG->supported_features_handle_export = gcnew HFP::CLI_SUPPORTED_FEATURES();

			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE = gcnew HFP::CLI_SUPPORTED_FEATURES::VV();

			save_default_data_of_attr<HFP::CLI_SUPPORTED_FEATURES^, SDP::HFP::SUPPORTED_FEATURES*>(
				hfp_export_HandsfreeAG->supported_features_handle_export,
				dd,
				((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export
				);

			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->supported_features_value = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.supported_features_value;

			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds = gcnew HFP::CLI_SUPPORTED_FEATURES_DATA();

			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a0 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a0;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a1 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a1;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a2 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a2;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a3 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a3;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a4 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a4;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a5 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a5;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a6 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a6;
			hfp_export_HandsfreeAG->supported_features_handle_export->VALUE->sfds->repo.a7 = ((SDP::HFP::HFP_EXPORT_S*)dd->exported_data.hfp_export_HandsfreeAG)->supported_features_handle_export->VALUE.sfds->repo->a7;
		}
	}

	print_data_HFP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_HSP()
{
	if (dd->services_for_search.Headset == 1)
	{
		hsp_export_headset = gcnew CLI_EXPORTS::CLI_HSP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_HSP_EXPORT^, SDP::HSP::HSP_EXPORT_S*>(hsp_export_headset, dd->exported_data.hsp_export_headset);

		// REMOTE_AUDIO_VOLUME_CONTROL
		if (((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headset)->remote_audio_volume_control_handle_export != nullptr)
		{
			hsp_export_headset->remote_audio_volume_control_handle_export = gcnew HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL();

			hsp_export_headset->remote_audio_volume_control_handle_export->VALUE = gcnew HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL::VV();

			save_default_data_of_attr<HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL^, SDP::HSP::REMOTE_AUDIO_VOLUME_CONTROL*>(
				hsp_export_headset->remote_audio_volume_control_handle_export,
				dd,
				((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headset)->remote_audio_volume_control_handle_export
				);
		}

		//print_data_HSP();
	}

	if (dd->services_for_search.Headset_Audio_Gateway == 1)
	{
		hsp_export_headsetAG = gcnew CLI_EXPORTS::CLI_HSP_EXPORT();

		save_exported_data_DEFAULT<CLI_EXPORTS::CLI_HSP_EXPORT^, SDP::HSP::HSP_EXPORT_S*>(hsp_export_headsetAG, dd->exported_data.hsp_export_headsetAG);

		// REMOTE_AUDIO_VOLUME_CONTROL
		if (((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headsetAG)->remote_audio_volume_control_handle_export != nullptr)
		{
			hsp_export_headsetAG->remote_audio_volume_control_handle_export = gcnew HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL();

			hsp_export_headsetAG->remote_audio_volume_control_handle_export->VALUE = gcnew HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL::VV();

			save_default_data_of_attr<HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL^, SDP::HSP::REMOTE_AUDIO_VOLUME_CONTROL*>(
				hsp_export_headsetAG->remote_audio_volume_control_handle_export,
				dd,
				((SDP::HSP::HSP_EXPORT_S*)dd->exported_data.hsp_export_headsetAG)->remote_audio_volume_control_handle_export
				);
		}

		
	}

	print_data_HSP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_NAP()
{
	nap_export = gcnew CLI_EXPORTS::CLI_NAP_EXPORT();

	save_exported_data_DEFAULT<CLI_EXPORTS::CLI_NAP_EXPORT^, SDP::NAP::NAP_EXPORT_S*>(nap_export, dd->exported_data.nap_export);

	// SECURITY_DESCRIPTION
	if (((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->security_description_handle_export != nullptr)
	{
		nap_export->security_description_handle_export = gcnew NAP::CLI_SECURITY_DESCRIPTION();

		nap_export->security_description_handle_export->VALUE = gcnew NAP::CLI_SECURITY_DESCRIPTION::VV();

		save_default_data_of_attr<NAP::CLI_SECURITY_DESCRIPTION^, SDP::NAP::SECURITY_DESCRIPTION*>(
			nap_export->security_description_handle_export,
			dd,
			((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->security_description_handle_export
		);

		nap_export->security_description_handle_export->VALUE->security_value = ((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->security_description_handle_export->VALUE.security_value;
	}

	// NET_ACCESS_TYPE
	if (((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->net_access_type_handle_export != nullptr)
	{
		nap_export->net_access_type_handle_export = gcnew NAP::CLI_NET_ACCESS_TYPE();

		nap_export->net_access_type_handle_export->VALUE = gcnew NAP::CLI_NET_ACCESS_TYPE::VV();

		save_default_data_of_attr<NAP::CLI_NET_ACCESS_TYPE^, SDP::NAP::NET_ACCESS_TYPE*>(
			nap_export->net_access_type_handle_export,
			dd,
			((SDP::NAP::NAP_EXPORT*)dd->exported_data.nap_export)->net_access_type_handle_export
		);

		nap_export->net_access_type_handle_export->VALUE->NetAccessType = ((SDP::NAP::NAP_EXPORT*)dd->exported_data.nap_export)->net_access_type_handle_export->VALUE.NetAccessType;
	}

	// MAX_NET_ACCESS_RATE
	if (((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->max_net_access_rate_handle_export != nullptr)
	{
		nap_export->max_net_access_rate_handle_export = gcnew NAP::CLI_MAX_NET_ACCESS_RATE();

		nap_export->max_net_access_rate_handle_export->VALUE = gcnew NAP::CLI_MAX_NET_ACCESS_RATE::VV();

		save_default_data_of_attr<NAP::CLI_MAX_NET_ACCESS_RATE^, SDP::NAP::MAX_NET_ACCESS_RATE*>(
			nap_export->max_net_access_rate_handle_export,
			dd,
			((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->max_net_access_rate_handle_export
		);

		nap_export->max_net_access_rate_handle_export->VALUE->Maximum_possible_Network_Access_Data_Rate = ((SDP::NAP::NAP_EXPORT_S*)dd->exported_data.nap_export)->max_net_access_rate_handle_export->VALUE.Maximum_possible_Network_Access_Data_Rate;
	}

	print_data_NAP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_OBEX()
{
	obex_export = gcnew CLI_EXPORTS::CLI_OBEX_EXPORT();

	save_exported_data_DEFAULT<CLI_EXPORTS::CLI_OBEX_EXPORT^, SDP::OBEX::OBEX_EXPORT_S*>(obex_export, dd->exported_data.obex_export);

	// SERVICE_VERSION
	if (((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->service_version_handle_export != nullptr)
	{
		obex_export->service_version_handle_export = gcnew OBEX::CLI_SERVICE_VERSION();

		obex_export->service_version_handle_export->VALUE = gcnew OBEX::CLI_SERVICE_VERSION::VV();

		save_default_data_of_attr<OBEX::CLI_SERVICE_VERSION^, SDP::OBEX::SERVICE_VERSION_S*>(
			obex_export->service_version_handle_export,
			dd,
			((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->service_version_handle_export
		);
	}

	// SUPPORTED_FORMATS
	if (((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->supported_formats_handle_export != nullptr)
	{
		obex_export->supported_formats_handle_export = gcnew OBEX::CLI_SUPPORTED_FORMATS();

		obex_export->supported_formats_handle_export->VALUE = gcnew OBEX::CLI_SUPPORTED_FORMATS::VV();

		save_default_data_of_attr<OBEX::CLI_SUPPORTED_FORMATS^, SDP::OBEX::SUPPORTED_FORMATS_S*>(
			obex_export->supported_formats_handle_export,
			dd,
			((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->supported_formats_handle_export
		);

		obex_export->supported_formats_handle_export->VALUE->num_of_formats = ((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->supported_formats_handle_export->VALUE.num_of_formats;

		obex_export->supported_formats_handle_export->VALUE->formats = gcnew array<System::Byte^>(obex_export->supported_formats_handle_export->VALUE->num_of_formats);

		for (int aa = 0; aa < obex_export->supported_formats_handle_export->VALUE->num_of_formats; aa++)
			obex_export->supported_formats_handle_export->VALUE->formats[aa] = ((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->supported_formats_handle_export->VALUE.formats[aa];
	}

	//GOEPL2CAPPSM
	if (((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->goepl2cappsm_handle_export != nullptr)
	{
		obex_export->goepl2cappsm_handle_export = gcnew MAP::CLI_GOEPL2CAPPSM();

		obex_export->goepl2cappsm_handle_export->VALUE = gcnew MAP::CLI_GOEPL2CAPPSM::VV();

		save_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^, SDP::MAP::GOEPL2CAPPSM*>(
			obex_export->goepl2cappsm_handle_export,
			dd,
			((SDP::OBEX::OBEX_EXPORT*)dd->exported_data.obex_export)->goepl2cappsm_handle_export
			);

		obex_export->goepl2cappsm_handle_export->VALUE->GoepL2CapPsm_value = ((SDP::OBEX::OBEX_EXPORT_S*)dd->exported_data.obex_export)->goepl2cappsm_handle_export->VALUE.GoepL2CapPsm_value;
	}

	print_data_OBEX();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_PBAP()
{
	pbap_export = gcnew CLI_EXPORTS::CLI_PBAP_EXPORT();

	save_exported_data_DEFAULT<CLI_EXPORTS::CLI_PBAP_EXPORT^, SDP::PBAP::PBAP_EXPORT_S*>(pbap_export, dd->exported_data.pbap_export);

	//SUPPORTED_REPOSITORIES
	if (((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export != nullptr)
	{
		pbap_export->supported_repositories_handle_export = gcnew PBAP::CLI_SUPPORTED_REPOSITORIES();

		pbap_export->supported_repositories_handle_export->VALUE = gcnew PBAP::CLI_SUPPORTED_REPOSITORIES::VV();

		save_default_data_of_attr<PBAP::CLI_SUPPORTED_REPOSITORIES^, SDP::PBAP::SUPPORTED_REPOSITORIES*>(
			pbap_export->supported_repositories_handle_export,
			dd,
			((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export
		);

		pbap_export->supported_repositories_handle_export->VALUE->srs = gcnew PBAP::CLI_SUPPORTED_REPOSITORIES_DATA();
		pbap_export->supported_repositories_handle_export->VALUE->srs->repo.a0 = ((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export->VALUE.srs->repo->a0;
		pbap_export->supported_repositories_handle_export->VALUE->srs->repo.a1 = ((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export->VALUE.srs->repo->a1;
		pbap_export->supported_repositories_handle_export->VALUE->srs->repo.a2 = ((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export->VALUE.srs->repo->a2;
		pbap_export->supported_repositories_handle_export->VALUE->srs->repo.a3 = ((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->supported_repositories_handle_export->VALUE.srs->repo->a3;

	}

	//PBAP_SUPPORTED_FEATURES
	if (((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->pbap_supported_features_handle_export != nullptr)
	{
		pbap_export->pbap_supported_features_handle_export = gcnew PBAP::CLI_PBAP_SUPPORTED_FEATURES();

		pbap_export->pbap_supported_features_handle_export->VALUE = gcnew PBAP::CLI_PBAP_SUPPORTED_FEATURES::VV();

		save_default_data_of_attr<PBAP::CLI_PBAP_SUPPORTED_FEATURES^, SDP::PBAP::PBAP_SUPPORTED_FEATURES*>(
			pbap_export->pbap_supported_features_handle_export,
			dd,
			((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->pbap_supported_features_handle_export
		);
	}

	//GOEPL2CAPPSM
	if (((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->goepl2cappsm_handle_export != nullptr)
	{
		pbap_export->goepl2cappsm_handle_export = gcnew MAP::CLI_GOEPL2CAPPSM();

		pbap_export->goepl2cappsm_handle_export->VALUE = gcnew MAP::CLI_GOEPL2CAPPSM::VV();

		save_default_data_of_attr<MAP::CLI_GOEPL2CAPPSM^, SDP::MAP::GOEPL2CAPPSM*>(
			pbap_export->goepl2cappsm_handle_export,
			dd,
			((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->goepl2cappsm_handle_export
			);

		pbap_export->goepl2cappsm_handle_export->VALUE->GoepL2CapPsm_value = ((SDP::PBAP::PBAP_EXPORT_S*)dd->exported_data.pbap_export)->goepl2cappsm_handle_export->VALUE.GoepL2CapPsm_value;
	}

	print_data_PBAP();
}
// DONE
void CLI_DEFAULT_DATA::save_exported_data_PNPINFO()
{
	pnpinfo_export = gcnew CLI_EXPORTS::CLI_INFO_EXPORT();

	if (((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export != nullptr)
	{
		pnpinfo_export->info_handle_export = gcnew PNPINFO::CLI_INFO();

		pnpinfo_export->info_handle_export->VALUE = gcnew PNPINFO::CLI_INFO::VV();

		save_default_data_of_attr<PNPINFO::CLI_INFO^, SDP::PNPINFO::INFO*>(
			pnpinfo_export->info_handle_export,
			dd,
			((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export
		);

		pnpinfo_export->info_handle_export->SpecificationID = gcnew PNPINFO::Specification_ID();
		pnpinfo_export->info_handle_export->SpecificationID->value = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->SpecificationID.value;
		pnpinfo_export->info_handle_export->SpecificationID->major_number = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->SpecificationID.major_number;
		pnpinfo_export->info_handle_export->SpecificationID->minor_number = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->SpecificationID.minor_number;


		pnpinfo_export->info_handle_export->VendorID_vector_location = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->VendorID_vector_location;
		pnpinfo_export->info_handle_export->ProductID = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->ProductID;

		pnpinfo_export->info_handle_export->Version = gcnew PNPINFO::Version_data();
		pnpinfo_export->info_handle_export->Version->major_version = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->Version.major_version;
		pnpinfo_export->info_handle_export->Version->minor_version = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->Version.minor_version;
		pnpinfo_export->info_handle_export->Version->sub_minor_version = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->Version.sub_minor_version;

		pnpinfo_export->info_handle_export->PrimaryRecord = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->PrimaryRecord;
		pnpinfo_export->info_handle_export->VendorIDSource = ((SDP::PNPINFO::INFO_EXPORT_S*)dd->exported_data.pnpinfo_export)->info_handle_export->VendorIDSource;
	}

	print_data_PNPINFO();
}


