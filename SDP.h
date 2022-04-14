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


	// TODO: pri print spremeni iz v. ... v VALUE. ... (da se printa iz saved exported in ne iz DLL-ja)

	public ref struct CLI_SERVICE_RECORD : CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			// TODO: dodaj parameter za shranjevanje podatka, za lazji export
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
			CLI_SERVICE_CLASS^ classes;				// pointer to array of SERVICE_CLASS objects
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{


			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_1);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			// TODO: naredi tako da se bodo kreirali objekt za vsak class posebej, ker jih je v prihodnosti lahko vec

			for (int a = 0; a < v.num_classes; a++)
				Console::Write("Class ID [{0}]: 0x{1:X4}\n", a, v.classes[a].value);

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

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_2);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);


			for (int c = 0; c < v.num_protocols; c++)
			{
				if (v._BNEP_flag == 1 && c < (v.num_protocols - 1))
				{
					/* za vse protokole ki so BNEP  */
					Console::WriteLine("Protocol [{0}]:", c);

					Console::Write("\tValue: ");
					for (int d = 0; d < v.protocols[c].additional_bits_for_size; d++)
						Console::WriteLine("0x{0} ", v.protocols[c].value[d]);
					Console::WriteLine("");
					// TODO: uredi se za tekst
					Console::WriteLine("\tID [0x{0:X4}][]", v.protocols[c].protocol_id/*, SUB_FUNCTIONS::getProtocolTypeString(VALUE.protocols[c].protocol_id).c_str()*/);
					if (v.protocols[c].additional_parameters_flag)
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
							Console::WriteLine("\tChannel number: {0}", v.protocols[c].pdsp->server_channel_num);

						if (dd.service_class_id_in_use == SDP::AudioSource ||
							dd.service_class_id_in_use == SDP::AudioSink ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlTarget ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControl ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlController ||
							dd.service_class_id_in_use == SDP::PANU ||
							dd.service_class_id_in_use == SDP::_NAP
							)
						{
							if (v.protocols[c].protocol_id == SDP::_L2CAP)
								Console::WriteLine("\tPSM: 0x{0:X4}", v.protocols[c].pdsp->PSM);

							if (v.protocols[c].protocol_id == SDP::_AVDTP ||
								v.protocols[c].protocol_id == SDP::_AVCTP ||
								v.protocols[c].protocol_id == SDP::_BNEP
								)
								Console::WriteLine("\tVersion: 0x{0:X4}", v.protocols[c].pdsp->Version);

							if (v.protocols[c].protocol_id == SDP::_BNEP)
							{
								Console::WriteLine("\tNumber of supported network packet type: {0}", v.protocols[c].pdsp->num_of_Supported_Network_Packet_Type_List_PANU);

								for (int aaa = 0; aaa < v.protocols[c].pdsp->num_of_Supported_Network_Packet_Type_List_PANU; aaa++)
								{// TODO: uredi se za tekst
									Console::WriteLine("\tnetwork packet type [0x{0:X4}][]\n", v.protocols[c].pdsp->Supported_Network_Packet_Type_List[aaa]/*, SUB_FUNCTIONS::getNetworkPacketTypeString(VALUE.protocols[c].pdsp->Supported_Network_Packet_Type_List[aaa]).c_str()*/);
								}
							}
						}
					}
				}
				else if (v._BNEP_flag != 1)
				{
					/* za vse protokole ki niso BNEP */

					Console::WriteLine("Protocol [{0}]:", c);

					Console::Write("\tValue: ");
					for (int d = 0; d < v.protocols[c].additional_bits_for_size; d++)
						Console::Write("0x{0:X} ", v.protocols[c].value[d]);
					Console::WriteLine("");

					// TODO: uredi se za tekst
					Console::WriteLine("\tID [0x{0:X4}][]", v.protocols[c].protocol_id/*, SUB_FUNCTIONS::getProtocolTypeString(VALUE.protocols[c].protocol_id).c_str()*/);
					if (v.protocols[c].additional_parameters_flag)
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
							Console::WriteLine("\tChannel number: {0}", v.protocols[c].pdsp->server_channel_num);

						if (dd.service_class_id_in_use == SDP::AudioSource ||
							dd.service_class_id_in_use == SDP::AudioSink ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlTarget ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControl ||
							dd.service_class_id_in_use == SDP::A_V_RemoteControlController ||
							dd.service_class_id_in_use == SDP::PANU ||
							dd.service_class_id_in_use == SDP::_NAP
							)
						{
							if (v.protocols[c].protocol_id == SDP::_L2CAP)
								Console::WriteLine("\tPSM: 0x{0:X4}", v.protocols[c].pdsp->PSM);

							if (v.protocols[c].protocol_id == SDP::_AVDTP ||
								v.protocols[c].protocol_id == SDP::_AVCTP ||
								v.protocols[c].protocol_id == SDP::_BNEP
								)
								Console::WriteLine("\tVersion: 0x{0:X4}", v.protocols[c].pdsp->Version);
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


		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_3);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			Console::Write("Service name: ");
			Console::Write(VALUE.service_name);
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

			Console::WriteLine("Profile UUID: 0x{0:X4}", v.profile_UUID);
			Console::WriteLine("Profile version: 0x{0:X4}", v.profile_version);
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
	// TODO: uredi se za text
	public ref struct CLI_SUPPORTED_FEATURES_DATA
	{
		BYTE a0;
		BYTE a1;
		BYTE a2;
		BYTE a3;
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

			// TODO: uredi se za text
			//Console::WriteLine("%s\n", v.sfds->getSupportedFeaturesString().c_str());
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


		std::string getSupportedFeaturesString_AVRC_AVRCC()
		{
			std::string temp = "";

			if (avrc_avrcc.a0)
			{
				temp.append("Category 1\n");
			}

			if (avrc_avrcc.a1)
			{
				temp.append("Category 2\n");
			}

			if (avrc_avrcc.a2)
			{
				temp.append("Category 3\n");
			}

			if (avrc_avrcc.a3)
			{
				temp.append("Category 4\n");
			}

			if (avrc_avrcc.a6)
			{
				temp.append("Supports browsing\n");
			}

			if (avrc_avrcc.a7)
			{
				temp.append("Supports Cover Art GetImageProperties feature\n");
			}

			if (avrc_avrcc.a8)
			{
				temp.append("Supports Cover Art GetImage feature\n");
			}

			if (avrc_avrcc.a9)
			{
				temp.append("Supports Cover Art GetLinkedThumbnail feature\n");
			}

			return temp;
		}

		std::string getSupportedFeaturesString_AVRCT()
		{
			std::string temp = "";

			if (avrct.a0)
			{
				temp.append("Category 1\n");
			}

			if (avrct.a1)
			{
				temp.append("Category 2\n");
			}

			if (avrct.a2)
			{
				temp.append("Category 3\n");
			}

			if (avrct.a3)
			{
				temp.append("Category 4\n");
			}

			if (avrct.a4)
			{
				temp.append("Player Application Settings\n");
			}

			if (avrct.a5)
			{
				temp.append("Group Navigation\n");
			}

			if (avrct.a6)
			{
				temp.append("Supports browsing\n");
			}

			if (avrct.a7)
			{
				temp.append("Supports multiple media player applications\n");
			}

			if (avrct.a8)
			{
				temp.append("Supports Cover Art\n");
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


			// TODO: uredi to text-ovno tezavo

			// TODO: najdi boljso resitev, ker se pri klicu printVALUE_ELEMENT() value spremeni na random
			//v.sfds->avrct = (CLI_SUPPORTED_FEATURES_DATA::AVRCT_S^)&VALUE.supported_features_value;

			if (dd.temp_class_id == SDP::A_V_RemoteControlTarget)
				printf("%s\n", v.sfds->getSupportedFeaturesString_AVRCT().c_str());

			if (dd.temp_class_id == SDP::A_V_RemoteControl ||
				dd.temp_class_id == SDP::A_V_RemoteControlController
				)
				printf("%s\n", v.sfds->getSupportedFeaturesString_AVRC_AVRCC().c_str());
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

			// TODO: uredi text
			//Console::WriteLine("Message types: \n%s\n", getMessageTypesString(VALUE.sfm).c_str());
			//Console::WriteLine("");
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

			// TODO: uredi text
			//Console::WriteLine("Features: \n%s\n", getSupportedFeaturesString(v.sfm).c_str());
			//Console::WriteLine("");
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

			
			//Console::WriteLine("Network: {0}", VALUE.value[0] == 0x01 ? "Ability to reject a call" : "No ability to reject a call");
			Console::WriteLine("");
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

			// TODO: uredi glede text-a
			/*if (dd.temp_service == SDP::HandsfreeAudioGateway)
				printf("%s\n", v.sfds->getSupportedFeatures_AG_String().c_str());
			else
				printf("%s\n", v.sfds->getSupportedFeaturesString().c_str());*/

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

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_15);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			// TODO: uredi glede text-a
			Console::WriteLine("Security Description [0x{0:X4}][]", VALUE.security_value/*, getSecurityDescriptionString(VALUE.security_value).c_str()*/);
			Console::WriteLine("\n");
		}
	};

	public ref struct CLI_NET_ACCESS_TYPE : CLI_DEFAULT::CLI_DEFAULT_OBJECT
	{
		ref struct VV : CLI_VALUE
		{
			SHORT NetAccessType;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			Console::Write(DELIMITER_PRINT);
			Console::Write(ATTR_NAME_16);

			printATTR_ELEMENT(&dd);
			printVALUE_ELEMENT(v, dd);

			// TODO: uredi glede text-a
			Console::WriteLine("Type of Network Access Available[0x{0:X4}][]", VALUE.NetAccessType/*, getNetAccessTypeString(VALUE.NetAccessType).c_str()*/);
			Console::WriteLine("");
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

			// TODO: uredi text-e
			//Console::WriteLine("Formats: \n%s\n", getSupportedFormatsString(v.formats, v.num_of_formats).c_str());
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

			Console::WriteLine("Repositories: \n\n"/*, v.srs->getSupportedRepositoriesString().c_str()*/);
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

	main->VALUE.element = gcnew CLI_ATTRIBUTE_ID_ELEMENT();
	main->VALUE.element->element.size = locale->VALUE.element->element.size;
	main->VALUE.element->element.type = locale->VALUE.element->element.type;

	main->VALUE.size_bytes = locale->VALUE.size_bytes;
	main->VALUE.additional_bits_flag = locale->VALUE.additional_bits_flag;
	main->VALUE.additional_bits_for_size = locale->VALUE.additional_bits_for_size;
	main->VALUE.size_bytes_additional = locale->VALUE.size_bytes_additional;

	main->VALUE.value = gcnew array< BYTE^ >(locale->VALUE.size_bytes);

	for (int i = 0; i < locale->VALUE.size_bytes; i++)
		main->VALUE.value[i] = locale->VALUE.value[i];
}






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


