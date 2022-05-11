# Data elements
* CLI_DEFAULT_EXPORT^ default_export ([DETAILS](default_export.md))
* NAP::CLI_SECURITY_DESCRIPTION^ security_description_handle_export
* NAP::CLI_NET_ACCESS_TYPE^ net_access_type_handle_export
* NAP::CLI_MAX_NET_ACCESS_RATE^ max_net_access_rate_handle_export


# Substructures


## CLI_SECURITY_DESCRIPTION
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)
* getSecurityDescriptionString(SHORT type)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* SHORT security_value



## CLI_NET_ACCESS_TYPE
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)
* getNetAccessTypeString(SHORT type)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* SHORT NetAccessType



## CLI_MAX_NET_ACCESS_RATE
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* DWORD Maximum_possible_Network_Access_Data_Rate