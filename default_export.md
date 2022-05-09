# Data elements
* CLI_DEFAULT::CLI_SERVICE_RECORD^ record_handle_export;
* CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST^ class_id_handle_export;
* CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST^ protocol_descriptor_list_handle_export;
* CLI_DEFAULT::CLI_SERVICE_NAME^ service_name_handle_export;
* CLI_DEFAULT::CLI_PROVIDER_NAME^ provider_name_export;
* CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST^ bluetooth_profile_descriptor_list_handle_export;
* CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST^ language_base_attribute_id_list_export;
* CLI_DEFAULT::CLI_SERVICE_DESCRIPTION^ service_description_export;

# SubStructures
## CLI_DEFAULT::CLI_SERVICE_RECORD
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* unsigned int handle


## CLI_DEFAULT::CLI_SERVICE_CLASS_ID_LIST
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE;

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)
* 
### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* int num_classes
* array<CLI_SERVICE_CLASS^>^ classes


## CLI_DEFAULT::CLI_PROTOCOL_DESCRIPTOR_LIST
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* int num_protocols;
* array<CLI_PROTOCOL_DESCRIPTOR^>^ protocols;
* int _BNEP_flag;
#### CLI_PROTOCOL_DESCRIPTOR
##### Data elements
* CLI_ATTRIBUTE_ID_ELEMENT^ element
* int size_bytes
* int additional_bits_flag
* int additional_bits_for_size
* array< BYTE >^ value
* CLI_ATTRIBUTE_ID_ELEMENT^ element_protocol
* SHORT protocol_id
* int additional_parameters_flag
* CLI_PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER^ pdsp


## CLI_DEFAULT::CLI_SERVICE_NAME
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* System::String^ service_name


## CLI_DEFAULT::CLI_PROVIDER_NAME
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* System::String^ provider_name


## CLI_DEFAULT::CLI_BLUETOOTH_PROFILE_DESCRIPTOR_LIST
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* SHORT profile_UUID
* SHORT profile_version


## CLI_DEFAULT::CLI_LANGUAGE_BASE_ATTRIBUTE_ID_LIST
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* SHORT triplet_id_natural_lang
* SHORT triplet_id_char_encoding
* SHORT triplet_attribute_id



## CLI_DEFAULT::CLI_SERVICE_DESCRIPTION
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### SubStructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* System::String^ description

