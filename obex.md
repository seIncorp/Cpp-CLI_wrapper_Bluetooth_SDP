# Data elements
* CLI_DEFAULT_EXPORT^ default_export ([DETAILS](default_export.md))
* MAP::CLI_GOEPL2CAPPSM^ goepl2cappsm_handle_export ([DETAILS](GOEPL2CAPPSM_struct.md))
* OBEX::CLI_SERVICE_VERSION^ service_version_handle_export
* OBEX::CLI_SUPPORTED_FORMATS^ supported_formats_handle_export




# Substructures


## CLI_SERVICE_VERSION
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))


## CLI_SUPPORTED_FORMATS
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)
* Test1_SupportedFormats()
* getSupportedFormatsString(BYTE data_arr[], int size)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* int num_of_formats
* array formats