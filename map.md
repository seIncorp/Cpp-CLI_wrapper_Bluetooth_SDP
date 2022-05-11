# Data elements
* CLI_DEFAULT_EXPORT^ default_export ([DETAILS](default_export.md))
* MAP::CLI_GOEPL2CAPPSM^ goepl2cappsm_handle_export ([DETAILS](GOEPL2CAPPSM_struct.md))
* MAP::CLI_SUPPORTED_MESSAGE_TYPES^ supported_message_types_handle
* MAP::CLI_MAS_INSTANCE_ID^ mas_instance_id_handle
* MAP::CLI_MAP_SUPPORTED_FEATURES^ map_supported_features_handle

# Substructures


## CLI_SUPPORTED_MESSAGE_TYPES
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* CLI_SUPPORTED_FEATURES_MESSAGES^ sfm
#### CLI_SUPPORTED_FEATURES_MESSAGES
##### Data elements
* SMT_S ttt
* SF_S aaa
##### Functions
* Test1_MessageTypes()
* Test1_SupportedFeatures()
* getMessageTypesString()
* getSupportedFeaturesString()





## CLI_MAS_INSTANCE_ID
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE
### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)
### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* BYTE instance_ID


## CLI_MAP_SUPPORTED_FEATURES
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE
### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)
### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* CLI_SUPPORTED_FEATURES_MESSAGES^ sfm
