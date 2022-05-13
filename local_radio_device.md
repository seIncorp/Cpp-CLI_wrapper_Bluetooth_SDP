# Data elements
* UInt32 flags
* USHORT HCI_minor_version
* UCHAR HCI_major_version
* CLI_DEVICE_DATA^ device
* CLI_RADIO_DATA^ radio

# Functions
* void print()



# Substructures


## CLI_DEVICE_DATA
### Data elements
* System::String^ name
* array address
* UInt32 flags
* CLI_DEVICE_PARSED_COD_DATA^ cod
### Functions
* void print()
### Substructures
#### CLI_DEVICE_PARSED_COD_DATA
##### Data elements
* vector major_service_class
* vector major_device_class
* vector minor_device_class

##### Functions
* void print()



## CLI_RADIO_DATA
### Data elements
* ULONGLONG LMP_SupportedFeatures
* USHORT mfg
* USHORT LMP_minor_version
* UCHAR LMP_major_version

### Functions
* void print()

