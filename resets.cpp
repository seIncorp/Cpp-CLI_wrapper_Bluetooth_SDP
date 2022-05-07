#include "pch.h"

#include "Cpp-CLI_wrapper_Bluetooth_SDP.h"

#include <stdio.h> // to printf()
using namespace System;



void CLI_DEFAULT_DATA::CLI_reset_SDP_service_for_search()
{
	// TODO: se je spremenilo
	//dd->reset_SDP_service_for_search();

	if (sdp_settings->debug == 1)
		Console::WriteLine("CLI_DEFAULT_DATA::CLI_reset_SDP_service_for_search()");
}

void CLI_DEFAULT_DATA::CLI_reset_attr_search_for_service()
{
	// TODO: se je spremenilo
	//dd->reset_attr_search_for_service();

	if (sdp_settings->debug == 1)
		Console::WriteLine("CLI_DEFAULT_DATA::CLI_reset_attr_search_for_service()");
}
