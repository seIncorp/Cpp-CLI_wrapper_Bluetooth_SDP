#pragma once

public ref struct CLI_ATTRIBUTE_ID_ELEMENT
{
	ref struct CLI_ELEMENT {
		BYTE size;		// ID for enum
		BYTE type;		// ID for enum
	};

	CLI_ELEMENT element;
};


public ref struct CLI_ATTR_ID
{
	CLI_ATTRIBUTE_ID_ELEMENT^ element;

	int size_bytes;						// size value for element value
	int additional_bits_flag;
	int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)

	array< BYTE^ >^ value;
};

public ref struct CLI_VALUE
{
	CLI_ATTRIBUTE_ID_ELEMENT^ element;

	int size_bytes;						// size value for element value
	int additional_bits_flag;
	int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)
	ULONG size_bytes_additional;

	array< BYTE^ >^ value;
};



public ref struct CLI_SERVICE_CLASS
{
	CLI_ATTRIBUTE_ID_ELEMENT^ element;			// pointer to ATTRIBUTE_ID_ELEMENT
	int additional_bits_flag;				// depricated
	SHORT value;
};


public ref struct CLI_PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER
{
	CLI_ATTRIBUTE_ID_ELEMENT^ element;

	int server_channel_num;						// for Handsfree, Headset
	SHORT PSM;									// for AudioSource
	SHORT Version;								// for AudioSource

	/* for PANU */
	CLI_ATTRIBUTE_ID_ELEMENT^ element_PANU;
	int additional_bits_flag_PANU;
	int additional_bits_for_size_PANU;
	int num_of_Supported_Network_Packet_Type_List_PANU;
	array<SHORT^>^ Supported_Network_Packet_Type_List;

} ;

public ref struct CLI_PROTOCOL_DESCRIPTOR
{
	// TODO: preveri ce se sploh rabi tale elemenet
	CLI_ATTRIBUTE_ID_ELEMENT^ element;

	int size_bytes;						// size value for element value
	int additional_bits_flag;
	int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)

	array< BYTE >^ value;

	// TODO: preveri ce se sploh rabi tale element_protocol
	CLI_ATTRIBUTE_ID_ELEMENT^ element_protocol;
	SHORT protocol_id;

	int additional_parameters_flag;
	CLI_PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER^ pdsp;

} ;











namespace CLI_DEFAULT
{
	public ref struct CLI_DEFAULT_OBJECT
	{
		CLI_ATTR_ID^ attr_id;

		ref struct VV : CLI_VALUE
		{


		} VALUE;

		void printATTR_ELEMENT(IOCTL_S::DEFAULT_DATA* dd)
		{
			System::Console::Write(VALUE_2);

			System::Console::WriteLine("{0} [{1}]", VALUE_3/*, SDP::SUB_FUNCTIONS::getElementTypeString(attr_id->element->element.type).c_str()*/, attr_id->element->element.type);

			if (attr_id->additional_bits_flag)
			{
				System::Console::WriteLine("{0} {1}", VALUE_6, attr_id->additional_bits_for_size);
			}
			else
			{
				System::Console::WriteLine("{0} {1} Bytes [{2}]", VALUE_4, attr_id->size_bytes, attr_id->size_bytes);

				System::Console::Write("{0} 0x", VALUE_5);
				for (int a = 0; a < attr_id->size_bytes; a++)
					System::Console::Write("{0:X2}", attr_id->value[a]);
				System::Console::WriteLine("");
			}

		}

		template<class T>
		void printVALUE_ELEMENT(T v, IOCTL_S::DEFAULT_DATA dd)
		{

			System::Console::Write(VALUE_1);
			System::Console::WriteLine("{0}  [{1}]", VALUE_3/*, SDP::SUB_FUNCTIONS::getElementTypeString(v.element->element.type).c_str()*/, v.element->element.type);

			if (v.additional_bits_flag)
			{
				System::Console::WriteLine("{0} {1}", VALUE_6, v.additional_bits_for_size);
				if (v.additional_bits_for_size == 1)
				{
					System::Console::WriteLine("Data size: {0}", v.size_bytes);

					System::Console::WriteLine("{0} ", VALUE_5);
					for (int a = 0; a < v.size_bytes; a++)
						System::Console::Write("0x{0:X2} ", v.value[a]);
					System::Console::WriteLine("");
				}
			}
			else
			{
				System::Console::Write("{0} {1} Bytes [{2}]\n", VALUE_4, v.size_bytes, v.size_bytes);

				System::Console::Write("{0} 0x", VALUE_5);
				for (int a = 0; a < v.size_bytes; a++)
					System::Console::Write("{0:X2}", v.value[a]);
				System::Console::WriteLine("");
			}


		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			System::Console::WriteLine(DELIMITER_PRINT);
			System::Console::WriteLine(ATTR_NAME_22);
			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);
		}

	};

	public ref struct CLI_SERVICE_RECORD : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			unsigned int handle;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_0);
			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Record handle: 0x{0:X8}\n", VALUE.handle);
		}
	};

	public ref struct CLI_SERVICE_CLASS_ID_LIST : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{

			int num_classes;
			array<CLI_SERVICE_CLASS^>^ classes;				// pointer to array of SERVICE_CLASS objects
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{


			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_1);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			for (int a = 0; a < VALUE.num_classes; a++)
				Console::Write("Class ID [{0}]: 0x{1:X4}\n", a, VALUE.classes[a]->value);

			Console::WriteLine("\n");
		}

	};

	public ref struct CLI_PROTOCOL_DESCRIPTOR_LIST : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			int num_protocols;

			array<CLI_PROTOCOL_DESCRIPTOR^>^ protocols;

			int _BNEP_flag;

		} VALUE;

		System::String^ getProtocolTypeString(SHORT type)
		{
			System::String^ temp;

			switch (type)
			{
			case SDP::_SDP:
				temp = "SDP";
				break;

			case SDP::_UDP:
				temp = "UDP";
				break;

			case SDP::_RFCOMM:
				temp = "RFCOMM";
				break;

			case SDP::_TCP:
				temp = "TCP";
				break;

			case SDP::_TCS_BIN:
				temp = "TCS‐BIN";
				break;

			case SDP::_TCS_AT:
				temp = "TCS‐AT";
				break;

			case SDP::_ATT:
				temp = "ATT";
				break;

			case SDP::_OBEX:
				temp = "OBEX";
				break;

			case SDP::_IP:
				temp = "IP";
				break;

			case SDP::_FTP:
				temp = "FTP";
				break;

			case SDP::_HTTP:
				temp = "HTTP";
				break;

			case SDP::_WSP:
				temp = "WSP";
				break;

			case SDP::_BNEP:
				temp = "BNEP";
				break;

			case SDP::_UPNP:
				temp = "UPNP";
				break;

			case SDP::_HIDP:
				temp = "HIDP";
				break;

			case SDP::_AVCTP:
				temp = "AVCTP";
				break;

			case SDP::_AVDTP:
				temp = "AVDTP";
				break;

			case SDP::_CMTP:
				temp = "CMTP";
				break;

			case SDP::_L2CAP:
				temp = "L2CAP";
				break;

			default:
				temp = "Unknown type";
				break;
			}

			return temp;
		}

		System::String^ getNetworkPacketTypeString(SHORT type)
		{
			System::String^ temp;

			switch (type)
			{
			case SDP::IPv4:
				temp = "Internet Protocol Version 4 (IPv4)";
				break;

			case SDP::ARP:
				temp = "Address Resolution Protocol (ARP)";
				break;

			case SDP::FRARP:
				temp = "Frame Relay ARP";
				break;

			case SDP::IPv6:
				temp = "Internet Protocol Version 6 (IPv6)";
				break;
			}

			return temp;
		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_2);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);


			for (int c = 0; c < VALUE.num_protocols; c++)
			{
				if (VALUE._BNEP_flag == 1 && c < (VALUE.num_protocols - 1))
				{
					/* za vse protokole ki so BNEP  */
					Console::WriteLine("Protocol [{0}]:", c);

					Console::Write("\tValue: ");
					for (int d = 0; d < VALUE.protocols[c]->additional_bits_for_size; d++)
						Console::WriteLine("0x{0} ", VALUE.protocols[c]->value[d]);
					Console::WriteLine("");
					
					Console::WriteLine("\tID [0x{0:X4}][{1}]", VALUE.protocols[c]->protocol_id, getProtocolTypeString(VALUE.protocols[c]->protocol_id));
					if (VALUE.protocols[c]->additional_parameters_flag)
					{
						if (dd.service_class_id_in_use == SDP::Handsfree ||
							dd.service_class_id_in_use == SDP::Headset ||
							dd.service_class_id_in_use == SDP::Headset_Audio_Gateway ||
							dd.service_class_id_in_use == SDP::OBEXObjectPush ||
							dd.service_class_id_in_use == SDP::OBEXFileTransfer ||
							dd.service_class_id_in_use == SDP::HandsfreeAudioGateway ||
							dd.service_class_id_in_use == SDP::Phonebook_Access_PSE ||
							dd.service_class_id_in_use == SDP::Phonebook_Access ||
							dd.service_class_id_in_use == SDP::Message_Access_Server ||
							dd.service_class_id_in_use == SDP::Message_Access_Profile ||
							dd.service_class_id_in_use == SDP::GenericAudio
							)
							Console::WriteLine("\tChannel number: {0}", VALUE.protocols[c]->pdsp->server_channel_num);

						if (dd.service_class_id_in_use == SDP::AudioSource ||
							dd.service_class_id_in_use == SDP::AudioSink ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlTarget ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControl ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlController ||
							dd.service_class_id_in_use == SDP::PANU ||
							dd.service_class_id_in_use == SDP::_NAP
							)
						{
							if (VALUE.protocols[c]->protocol_id == SDP::_L2CAP)
								Console::WriteLine("\tPSM: 0x{0:X4}", VALUE.protocols[c]->pdsp->PSM);

							if (VALUE.protocols[c]->protocol_id == SDP::_AVDTP ||
								VALUE.protocols[c]->protocol_id == SDP::_AVCTP ||
								VALUE.protocols[c]->protocol_id == SDP::_BNEP
								)
								Console::WriteLine("\tVersion: 0x{0:X4}", VALUE.protocols[c]->pdsp->Version);

							if (VALUE.protocols[c]->protocol_id == SDP::_BNEP)
							{
								Console::WriteLine("\tNumber of supported network packet type: {0}", VALUE.protocols[c]->pdsp->num_of_Supported_Network_Packet_Type_List_PANU);

								for (int aaa = 0; aaa < VALUE.protocols[c]->pdsp->num_of_Supported_Network_Packet_Type_List_PANU; aaa++)
								{
									Console::WriteLine("\tnetwork packet type [0x{0:X4}][{1}]\n", VALUE.protocols[c]->pdsp->Supported_Network_Packet_Type_List[aaa], getNetworkPacketTypeString((short)VALUE.protocols[c]->pdsp->Supported_Network_Packet_Type_List[aaa]));
								}
							}
						}
					}
				}
				else if (VALUE._BNEP_flag != 1)
				{
					/* za vse protokole ki niso BNEP */

					Console::WriteLine("Protocol [{0}]:", c);

					Console::Write("\tValue: ");
					for (int d = 0; d < VALUE.protocols[c]->additional_bits_for_size; d++)
						Console::Write("0x{0:X} ", VALUE.protocols[c]->value[d]);
					Console::WriteLine("");

					Console::WriteLine("\tID [0x{0:X4}][{1}]", VALUE.protocols[c]->protocol_id, getProtocolTypeString(VALUE.protocols[c]->protocol_id));
					if (VALUE.protocols[c]->additional_parameters_flag)
					{
						if (dd.service_class_id_in_use == SDP::Handsfree ||
							dd.service_class_id_in_use == SDP::Headset ||
							dd.service_class_id_in_use == SDP::Headset_Audio_Gateway ||
							dd.service_class_id_in_use == SDP::OBEXObjectPush ||
							dd.service_class_id_in_use == SDP::OBEXFileTransfer ||
							dd.service_class_id_in_use == SDP::HandsfreeAudioGateway ||
							dd.service_class_id_in_use == SDP::Phonebook_Access_PSE ||
							dd.service_class_id_in_use == SDP::Phonebook_Access ||
							dd.service_class_id_in_use == SDP::Message_Access_Server ||
							dd.service_class_id_in_use == SDP::Message_Access_Profile ||
							dd.service_class_id_in_use == SDP::GenericAudio
							)
							Console::WriteLine("\tChannel number: {0}", VALUE.protocols[c]->pdsp->server_channel_num);

						if (dd.service_class_id_in_use == SDP::AudioSource ||
							dd.service_class_id_in_use == SDP::AudioSink ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlTarget ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControl ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlController ||
							dd.service_class_id_in_use == SDP::PANU ||
							dd.service_class_id_in_use == SDP::_NAP
							)
						{
							if (VALUE.protocols[c]->protocol_id == SDP::_L2CAP)
								Console::WriteLine("\tPSM: 0x{0:X4}", VALUE.protocols[c]->pdsp->PSM);

							if (VALUE.protocols[c]->protocol_id == SDP::_AVDTP ||
								VALUE.protocols[c]->protocol_id == SDP::_AVCTP ||
								VALUE.protocols[c]->protocol_id == SDP::_BNEP
								)
								Console::WriteLine("\tVersion: 0x{0:X4}", VALUE.protocols[c]->pdsp->Version);
						}
					}
				}
			}
			Console::WriteLine("");
		}
	};

	public ref struct CLI_SERVICE_NAME : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			System::String^ service_name;


		} ;
		//} VALUE;

		VV^ VALUE;
		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_3);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::Write("Service name: ");
			Console::Write(VALUE->service_name);
			Console::WriteLine("");
		}
	};

	public ref struct CLI_PROVIDER_NAME : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			System::String^ provider_name;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_4);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::Write("Provider name: ");
			Console::Write(VALUE.provider_name);
			Console::WriteLine("");
		}
	};

	public ref struct CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			/* PROFILES */

			SHORT profile_UUID;
			SHORT profile_version;

			// samo za vec profilov
			//int num_Profiles_list;
			//BLUETOOTH_PROFILE* pProfile_list;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_5);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Profile UUID: 0x{0:X4}", VALUE.profile_UUID);
			Console::WriteLine("Profile version: 0x{0:X4}", VALUE.profile_version);
			Console::WriteLine("");
		}
	};

	public ref struct CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			// TODO: naredi ce je teh tripletov vec kot eden (trenutno je narejeno samo za enega)

			SHORT triplet_id_natural_lang;
			SHORT triplet_id_char_encoding;
			SHORT triplet_attribute_id;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_6);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Natural language ID: 0x{0:X4}", VALUE.triplet_id_natural_lang);
			Console::WriteLine("Character encoding ID: 0x{0:X4}", VALUE.triplet_id_char_encoding);
			Console::WriteLine("Attribute ID: 0x{0:X4}", VALUE.triplet_attribute_id);
			Console::WriteLine("");
		}
	};

	public ref struct CLI_SERVICE_DESCRIPTION : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			System::String^ description;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_7);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::Write("Description: ");
			Console::Write(VALUE.description);
			Console::WriteLine("");
		}
	};

};




public ref struct CLI_DEFAULT_EXPORT
{
	CLI_DEFAULT::CLI_SERVICE_RECORD^ record_handle_export;
	CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST^ class_id_handle_export;
	CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST^ protocol_descriptor_list_handle_export;
	CLI_DEFAULT::CLI_SERVICE_NAME^ service_name_handle_export;
	CLI_DEFAULT::CLI_PROVIDER_NAME^ provider_name_export;
	CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST^ bluetooth_profile_descriptor_list_handle_export;
	CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST^ language_base_attribute_id_list_export;
	CLI_DEFAULT::CLI_SERVICE_DESCRIPTION^ service_description_export;

};


namespace A2DP
{
	public ref struct CLI_SUPPORTED_FEATURES_DATA
	{
		BYTE a0;
		BYTE a1;
		BYTE a2;
		BYTE a3;

		array<System::String^>^ Test()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(4);

			local[0] = "Player\n";
			local[1] = "Microphone\n";
			local[2] = "Tuner\n";
			local[3] = "Mixer\n";
			
			return local;
		}

		System::String^ getSupportedFeaturesString()
		{
			array<System::String^>^ text = Test();

			System::String^ temp = "";

			if (a0)
			{
				temp += text[0];
			}

			if (a1)
			{
				temp += text[1];
			}

			if (a2)
			{
				temp += text[2];
			}

			if (a3)
			{
				temp += text[3];
			}

			return temp;
		}
	};
	
	public ref struct CLI_SUPPORTED_FEATURES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT supported_features_value;

			CLI_SUPPORTED_FEATURES_DATA^ sfds;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_9);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("{0} 0x{1:X4}", VALUE_7, VALUE.supported_features_value);
			Console::WriteLine("{0}", VALUE.sfds->getSupportedFeaturesString());
		}

	};

}

namespace AVRCP
{
	public ref struct CLI_SUPPORTED_FEATURES_DATA
	{
		ref struct CLI_AVRCT
		{
			BYTE a0;
			BYTE a1;
			BYTE a2;
			BYTE a3;
			BYTE a4;
			BYTE a5;
			BYTE a6;
			BYTE a7;
			BYTE a8;
		};

		ref struct CLI_AVRC_AVRCC
		{
			BYTE a0;
			BYTE a1;
			BYTE a2;
			BYTE a3;
			BYTE a6;
			BYTE a7;
			BYTE a8;
			BYTE a9;
		};

		CLI_AVRCT avrct;
		CLI_AVRC_AVRCC avrc_avrcc;

		array<System::String^>^ Test1_AVRC_AVRCC()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(8);

			local[0] = "Category 1\n";
			local[1] = "Category 2\n";
			local[2] = "Category 3\n";
			local[3] = "Category 4\n";
			local[4] = "Supports browsing\n";
			local[5] = "Supports Cover Art GetImageProperties feature\n";
			local[6] = "Supports Cover Art GetImage feature\n";
			local[7] = "Supports Cover Art GetLinkedThumbnail feature\n";

			return local;
		}

		array<System::String^>^ Test1_AVRCT()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(9);

			local[0] = "Category 1\n";
			local[1] = "Category 2\n";
			local[2] = "Category 3\n";
			local[3] = "Category 4\n";
			local[4] = "Player Application Settings\n";
			local[5] = "Group Navigation\n";
			local[6] = "Supports browsing\n";
			local[7] = "Supports multiple media player applications\n";
			local[8] = "Supports Cover Art\n";
			
			return local;
		}

		System::String^ getSupportedFeaturesString_AVRC_AVRCC()
		{
			array<System::String^>^ text_AVRC_AVRCC = Test1_AVRC_AVRCC();

			System::String^ temp = "";

			if (avrc_avrcc.a0)
			{
				temp += text_AVRC_AVRCC[0];
			}

			if (avrc_avrcc.a1)
			{
				temp += text_AVRC_AVRCC[1];
			}

			if (avrc_avrcc.a2)
			{
				temp += text_AVRC_AVRCC[2];
			}

			if (avrc_avrcc.a3)
			{
				temp += text_AVRC_AVRCC[3];
			}

			if (avrc_avrcc.a6)
			{
				temp += text_AVRC_AVRCC[4];
			}

			if (avrc_avrcc.a7)
			{
				temp += text_AVRC_AVRCC[5];
			}

			if (avrc_avrcc.a8)
			{
				temp += text_AVRC_AVRCC[6];
			}

			if (avrc_avrcc.a9)
			{
				temp += text_AVRC_AVRCC[7];
			}

			return temp;
		}

		System::String^ getSupportedFeaturesString_AVRCT()
		{
			array<System::String^>^ text_AVRCT = Test1_AVRCT();

			System::String^ temp = "";
	
			if (avrct.a0)
			{
				temp += text_AVRCT[0];
			}

			if (avrct.a1)
			{
				temp += text_AVRCT[1];
			}

			if (avrct.a2)
			{
				temp += text_AVRCT[2];
			}

			if (avrct.a3)
			{
				temp += text_AVRCT[3];
			}

			if (avrct.a4)
			{
				temp += text_AVRCT[4];
			}

			if (avrct.a5)
			{
				temp += text_AVRCT[5];
			}

			if (avrct.a6)
			{
				temp += text_AVRCT[6];
			}

			if (avrct.a7)
			{
				temp += text_AVRCT[7];
			}

			if (avrct.a8)
			{
				temp += text_AVRCT[8];
			}

			return temp;
		}
	};

	public ref struct CLI_SUPPORTED_FEATURES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT supported_features_value;

			CLI_SUPPORTED_FEATURES_DATA^ sfds;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_9);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("{0} 0x{1:X4}", VALUE_7, VALUE.supported_features_value);

			if (dd.temp_class_id == SDP::A_V_RemoteControlTarget)
			{
				Console::WriteLine("{0}", VALUE.sfds->getSupportedFeaturesString_AVRCT());
			}

			if (dd.temp_class_id == SDP::A_V_RemoteControl ||
				dd.temp_class_id == SDP::A_V_RemoteControlController
				)
				Console::WriteLine("{0}", VALUE.sfds->getSupportedFeaturesString_AVRC_AVRCC());

		};
	};
}

namespace MAP
{
	public ref struct CLI_SUPPORTED_FEATURES_MESSAGES
	{
		ref struct SMT_S
		{
			BYTE a0;
			BYTE a1;
			BYTE a2;
			BYTE a3;
			BYTE a4;
		};

		SMT_S ttt;

		ref struct SF_S
		{
			BYTE a0;
			BYTE a1;
			BYTE a2;
			BYTE a3;
			BYTE a4;
			BYTE a5;
			BYTE a6;
			BYTE a7;
			BYTE a8;
			BYTE a9;
			BYTE a10;
			BYTE a11;
			BYTE a12;
			BYTE a13;
			BYTE a14;
			BYTE a15;
			BYTE a16;
			BYTE a17;
			BYTE a18;
			BYTE a19;
			BYTE a20;
			BYTE a21;
			BYTE a22;
		};

		SF_S aaa;

		array<System::String^>^ Test1_MessageTypes()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(5);

			local[0] = "EMAIL\n";
			local[1] = "SMS_GSM\n";
			local[2] = "SMS_CDMA\n";
			local[3] = "MMS\n";
			local[4] = "IM\n";

			return local;
		}

		array<System::String^>^ Test1_SupportedFeatures()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(23);

			local[0] = "Notification Registration Feature\n";
			local[1] = "Notification Feature\n";
			local[2] = "Browsing Feature\n";
			local[3] = "Uploading Feature\n";
			local[4] = "Delete Feature\n";
			local[5] = "Instance Information Feature\n";
			local[6] = "Extended Event Report 1.1\n";
			local[7] = "Event Report Version 1.2\n";
			local[8] = "Message Format Version 1.1\n";
			local[9] = "MessagesListing Format Version 1.1\n";
			local[10] = "Persistent Message Handles\n";
			local[11] = "Database Identifier\n";
			local[12] = "Folder Version Counter\n";
			local[13] = "Conversation Version Counters\n";
			local[14] = "Participant Presence Change Notification\n";
			local[15] = "Participant Chat State Change Notification\n";
			local[16] = "PBAP Contact Cross Reference\n";
			local[17] = "Notification Filtering\n";
			local[18] = "UTC Offset Timestamp Format\n";
			local[19] = "MapSupportedFeatures in Connect Request\n";
			local[20] = "Conversation listing\n";
			local[21] = "Owner Status\n";
			local[22] = "Message Forwarding\n";
			

			return local;
		}

		System::String^ getMessageTypesString()
		{
			array<System::String^>^ text = Test1_MessageTypes();

			System::String^ temp = "";
			
			if (ttt.a0)
			{
				temp += text[0];
			}

			if (ttt.a1)
			{
				temp += text[1];
			}

			if (ttt.a2)
			{
				temp += text[2];
			}

			if (ttt.a3)
			{
				temp += text[3];
			}

			if (ttt.a4)
			{
				temp += text[4];
			}

			return temp;
		}

		System::String^ getSupportedFeaturesString()
		{
			array<System::String^>^ text = Test1_SupportedFeatures();

			System::String^ temp = "";

			if (aaa.a0)
			{
				temp += text[0];
			}

			if (aaa.a1)
			{
				temp += text[1];
			}

			if (aaa.a2)
			{
				temp += text[2];
			}

			if (aaa.a3)
			{
				temp += text[3];
			}

			if (aaa.a4)
			{
				temp += text[4];
			}

			if (aaa.a5)
			{
				temp += text[5];
			}

			if (aaa.a6)
			{
				temp += text[6];
			}

			if (aaa.a7)
			{
				temp += text[7];
			}

			if (aaa.a8)
			{
				temp += text[8];
			}

			if (aaa.a9)
			{
				temp += text[9];
			}

			if (aaa.a10)
			{
				temp += text[10];
			}

			if (aaa.a11)
			{
				temp += text[11];
			}

			if (aaa.a12)
			{
				temp += text[12];
			}

			if (aaa.a13)
			{
				temp += text[13];
			}

			if (aaa.a14)
			{
				temp += text[14];
			}

			if (aaa.a15)
			{
				temp += text[15];
			}

			if (aaa.a16)
			{
				temp += text[16];
			}

			if (aaa.a17)
			{
				temp += text[17];
			}

			if (aaa.a18)
			{
				temp += text[18];
			}

			if (aaa.a19)
			{
				temp += text[19];
			}

			if (aaa.a20)
			{
				temp += text[20];
			}

			if (aaa.a21)
			{
				temp += text[21];
			}

			if (aaa.a22)
			{
				temp += text[22];
			}

			return temp;
		}
	};

	public ref struct CLI_GOEPL2CAPPSM : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT GoepL2CapPsm_value;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_8);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("GoepL2CapPsm value: 0x{0:X4}", VALUE.GoepL2CapPsm_value);
			Console::WriteLine("");
		};
	};

	public ref struct CLI_SUPPORTED_MESSAGE_TYPES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			CLI_SUPPORTED_FEATURES_MESSAGES^ sfm;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_10);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Message types: \n{0}\n", VALUE.sfm->getMessageTypesString());
		}
	};

	public ref struct CLI_MAS_INSTANCE_ID : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			BYTE instance_ID;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_11);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("MAS instance ID: 0x{0:X2}", VALUE.instance_ID);
			Console::WriteLine("");
		}
	};

	public ref struct CLI_MAP_SUPPORTED_FEATURES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			CLI_SUPPORTED_FEATURES_MESSAGES^ sfm;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_12);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Features: \n{0}\n", VALUE.sfm->getSupportedFeaturesString());
		}
	};
}

namespace HFP
{
	public ref struct CLI_SUPPORTED_FEATURES_DATA
	{
		ref struct SR_S
		{
			BYTE a0;
			BYTE a1;
			BYTE a2;
			BYTE a3;
			BYTE a4;
			BYTE a5;
			BYTE a6;
			BYTE a7;
		};

		SR_S repo;

		array<System::String^>^ Test1_SupportedFeatures_AG()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(8);

			local[0] = "Three-way calling\n";
			local[1] = "EC and/or NR function\n";
			local[2] = "Voice recognition function\n";
			local[3] = "In-band ring tone capability\n";
			local[4] = "Attach a phone number to a voice tag\n";
			local[5] = "Wide band speech\n";
			local[6] = "Enhanced Voice Recognition Status \n";
			local[7] = "Voice Recognition Text\n";
		
			return local;
		}

		array<System::String^>^ Test1_SupportedFeatures()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(8);

			local[0] = "EC and/or NR function\n";
			local[1] = "Call waiting or three-way calling\n";
			local[2] = "CLI presentation capability\n";
			local[3] = "Voice recognition activation\n";
			local[4] = "Remote volume control\n";
			local[5] = "Wide band speech\n";
			local[6] = "Enhanced Voice Recognition Status\n";
			local[7] = "Voice Recognition Text\n";
			


			return local;
		}

		System::String^ getSupportedFeatures_AG_String()
		{
			array<System::String^>^ text = Test1_SupportedFeatures_AG();

			System::String^ temp = "";

			if (repo.a0)
			{
				temp += text[0];
			}

			if (repo.a1)
			{
				temp += text[1];
			}

			if (repo.a2)
			{
				temp += text[2];
			}

			if (repo.a3)
			{
				temp += text[3];
			}

			if (repo.a4)
			{
				temp += text[4];
			}

			if (repo.a5)
			{
				temp += text[5];
			}

			if (repo.a6)
			{
				temp += text[6];
			}

			if (repo.a7)
			{
				temp += text[7];
			}

			return temp;
		}

		System::String^ getSupportedFeaturesString()
		{
			array<System::String^>^ text = Test1_SupportedFeatures();

			System::String^ temp = "";

			if (repo.a0)
			{
				temp += text[0];
			}

			if (repo.a1)
			{
				temp += text[1];
			}

			if (repo.a2)
			{
				temp += text[2];
			}

			if (repo.a3)
			{
				temp += text[3];
			}

			if (repo.a4)
			{
				temp += text[4];
			}

			if (repo.a5)
			{
				temp += text[5];
			}

			if (repo.a6)
			{
				temp += text[6];
			}

			if (repo.a7)
			{
				temp += text[7];
			}

			return temp;
		}
	};

	public ref struct CLI_NETWORK : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_13);

			printATTR_ELEMENT(&dd);

			printVALUE_ELEMENT(v, dd);

			if((BYTE)VALUE.value[0] == (BYTE)0x01)
				Console::WriteLine("Network: Ability to reject a call");
			else
				Console::WriteLine("Network: No ability to reject a call");
		}
	};

	public ref struct CLI_SUPPORTED_FEATURES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT supported_features_value;

			CLI_SUPPORTED_FEATURES_DATA^ sfds;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_9);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Supported features: 0x{0:X4}\n", VALUE.supported_features_value);

			if (dd.temp_service == SDP::HandsfreeAudioGateway)
				Console::WriteLine("{0}", VALUE.sfds->getSupportedFeatures_AG_String());
			else
				Console::WriteLine("{0}", VALUE.sfds->getSupportedFeaturesString());

			Console::WriteLine("");
		}
	};
}

namespace HSP
{
	public ref struct CLI_REMOTE_AUDIO_VOLUME_CONTROL : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_14);

			printATTR_ELEMENT(&dd);

			printVALUE_ELEMENT(v, dd);
		}
	};
}

namespace NAP
{
	public ref struct CLI_SECURITY_DESCRIPTION : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT security_value;
		} VALUE;

		System::String^ getSecurityDescriptionString(SHORT type)
		{
			System::String^ temp;

			switch (type)
			{
				case 0x0000:
					temp = "None";
				break;

				case 0x0001:
					temp = "Service - level enforced Security";
				break;

				case 0x0002:
					temp = "802.1x Security";
				break;
			}

			return temp;
		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_15);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Security Description [0x{0:X4}][{1}]", VALUE.security_value, getSecurityDescriptionString(VALUE.security_value));
		}
	};

	public ref struct CLI_NET_ACCESS_TYPE : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT NetAccessType;
		} VALUE;

		System::String^ getNetAccessTypeString(SHORT type)
		{
			System::String^ temp;

			switch (type)
			{
			case 0x0000:
				temp = "PSTN";
				break;

			case 0x0001:
				temp = "ISDN";
				break;

			case 0x0002:
				temp = "DSL";
				break;

			case 0x0003:
				temp = "Cable Modem";
				break;

			case 0x0004:
				temp = "10Mb Ethernet";
				break;

			case 0x0005:
				temp = "100Mb Ethernet";
				break;

			case 0x0006:
				temp = "4 Mb Token Ring";
				break;

			case 0x0007:
				temp = "16 Mb Token Ring";
				break;

			case 0x0008:
				temp = "100 Mb Token Ring";
				break;

			case 0x0009:
				temp = "FDDI";
				break;

			case 0x000A:
				temp = "GSM";
				break;

			case 0x000B:
				temp = "CDMA";
				break;

			case 0x000C:
				temp = "GPRS";
				break;

			case 0x000D:
				temp = "3G Cellular";
				break;

			case 0xFFFE:
				temp = "other";
				break;
			}

			return temp;
		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_16);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Type of Network Access Available[0x{0:X4}][{1}]", VALUE.NetAccessType, getNetAccessTypeString(VALUE.NetAccessType));
		}
	};

	public ref struct CLI_MAX_NET_ACCESS_RATE : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			DWORD Maximum_possible_Network_Access_Data_Rate;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_17);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Maximum possible Network Access Data Rate: 0x{0:X8}", VALUE.Maximum_possible_Network_Access_Data_Rate);
			Console::WriteLine("");
		}
	};
}

namespace OBEX
{
	public ref struct CLI_SERVICE_VERSION : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		// TODO: naredi do konca, ko bos imel example
	};

	public ref struct CLI_SUPPORTED_FORMATS : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			int num_of_formats;
			array<System::Byte^>^ formats;

		} VALUE;

		array<System::String^>^ Test1_SupportedFormats()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(7);

			local[0] = "vCard 2.1\n";
			local[1] = "vCard 3.0\n";
			local[2] = "vCal 1.0\n";
			local[3] = "iCal 2.0\n";
			local[4] = "vNote\n";
			local[5] = "vMessage\n";
			local[6] = "any type of object\n";
			

			return local;
		}

		System::String^ getSupportedFormatsString(BYTE data_arr[], int size)
		{
			array<System::String^>^ text = Test1_SupportedFormats();

			System::String^ temp = "";

			for (int aa = 0; aa < size; aa++)
				switch (data_arr[aa])
				{
				case 0x01:
					temp += text[0];
					break;

				case 0x02:
					temp += text[1];
					break;

				case 0x03:
					temp += text[2];
					break;

				case 0x04:
					temp += text[3];
					break;

				case 0x05:
					temp += text[4];
					break;

				case 0x06:
					temp += text[5];
					break;

				case 0xff:
					temp += text[6];
					break;
				};

			return temp;
		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_18);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Number of supported formats: {0}", VALUE.num_of_formats);

			Console::WriteLine("Supported formats: ");
			for (int aa = 0; aa < VALUE.num_of_formats; aa++)
				Console::Write("0x{0:X2} ", VALUE.formats[aa]);
			Console::WriteLine("");

			Console::WriteLine("Formats: \n{0}\n", getSupportedFormatsString(v.formats, v.num_of_formats));
		}
	};
};

namespace PBAP
{
	public ref struct CLI_SUPPORTED_REPOSITORIES_DATA
	{
		ref struct SR_S
		{
			BYTE a0;
			BYTE a1;
			BYTE a2;
			BYTE a3;
		};

		SR_S repo;

		array<System::String^>^ Test1_SupportedRepositories()
		{
			array< System::String^ >^ local = gcnew array< System::String^ >(9);

			local[0] = "Local Phonebook\n";
			local[1] = "SIM card\n";
			local[2] = "Speed dial\n";
			local[3] = "Favorites\n";

			return local;
		}

		System::String^ getSupportedRepositoriesString()
		{
			array<System::String^>^ text = Test1_SupportedRepositories();

			System::String^ temp = "";

			if (repo.a0)
			{
				temp += text[0];
			}

			if (repo.a1)
			{
				temp += text[1];
			}

			if (repo.a2)
			{
				temp += text[2];
			}

			if (repo.a3)
			{
				temp += text[3];
			}

			return temp;
		}
	};

	public ref struct CLI_SUPPORTED_REPOSITORIES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			CLI_SUPPORTED_REPOSITORIES_DATA^ srs;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_19);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Repositories: \n{0}\n", VALUE.srs->getSupportedRepositoriesString());
		}
	};

	public ref struct CLI_PBAP_SUPPORTED_FEATURES : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_20);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);
		}
	};



}

namespace PNPINFO
{
	public ref struct CLI_INFO : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		SHORT SpecificationID;
		SHORT VendorID;
		SHORT ProductID;
		SHORT Version;
		BOOL PrimaryRecord;
		SHORT VendorIDSource;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_21);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::WriteLine("Specification ID: 0x{0:X4}", this->SpecificationID);
			Console::WriteLine("Vendor ID: 0x{0:X4}", this->VendorID);
			Console::WriteLine("Product ID: 0x{0:X4}", this->ProductID);
			Console::WriteLine("Version: 0x{0:X4}", this->Version);
			Console::WriteLine("Primary Record: 0x{0:X2}", this->PrimaryRecord);
			Console::WriteLine("Vendor ID Source: 0x{0:X4}", this->VendorIDSource);
		}
	};
}





namespace CLI_EXPORTS
{
	public ref struct CLI_MAP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		MAP::CLI_GOEPL2CAPPSM^ goepl2cappsm_handle_export;
		MAP::CLI_SUPPORTED_MESSAGE_TYPES^ supported_message_types_handle;
		MAP::CLI_MAS_INSTANCE_ID^ mas_instance_id_handle;
		MAP::CLI_MAP_SUPPORTED_FEATURES^ map_supported_features_handle;

	};

	public ref struct CLI_A2DP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		A2DP::CLI_SUPPORTED_FEATURES^ supported_features_handle_export;

	};

	public ref struct CLI_AVRCP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		AVRCP::CLI_SUPPORTED_FEATURES^ supported_features_handle_export;
	};

	public ref struct CLI_HFP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		HFP::CLI_NETWORK^ network_handle_export;
		HFP::CLI_SUPPORTED_FEATURES^ supported_features_handle_export;
	};

	public ref struct CLI_HSP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		HSP::CLI_REMOTE_AUDIO_VOLUME_CONTROL^ remote_audio_volume_control_handle_export;
	};

	public ref struct CLI_NAP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		NAP::CLI_SECURITY_DESCRIPTION^ security_description_handle_export;
		NAP::CLI_NET_ACCESS_TYPE^ net_access_type_handle_export;
		NAP::CLI_MAX_NET_ACCESS_RATE^ max_net_access_rate_handle_export;
	};

	public ref struct CLI_OBEX_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		MAP::CLI_GOEPL2CAPPSM^ goepl2cappsm_handle_export;
		OBEX::CLI_SERVICE_VERSION^ service_version_handle_export;
		OBEX::CLI_SUPPORTED_FORMATS^ supported_formats_handle_export;

	};

	public ref struct CLI_PBAP_EXPORT
	{
		CLI_DEFAULT_EXPORT^ default_export;

		MAP::CLI_GOEPL2CAPPSM^ goepl2cappsm_handle_export;
		PBAP::CLI_SUPPORTED_REPOSITORIES^ supported_repositories_handle_export;
		PBAP::CLI_PBAP_SUPPORTED_FEATURES^ pbap_supported_features_handle_export;
	};

	public ref struct CLI_INFO_EXPORT
	{
		PNPINFO::CLI_INFO^ info_handle_export;
	};

}
