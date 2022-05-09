# Data elements
* CLI_ATTR_ID^ attr_id;
* ref struct VV VALUE 
> Child of CLI_VALUE structure([DETAILS](VALUE_structure.md))

# Functions
* void printATTR_ELEMENT(IOCTL_S::DEFAULT_DATA* dd)
* void printVALUE_ELEMENT(T v, IOCTL_S::DEFAULT_DATA dd)
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

# Substructure
## CLI_ATTR_ID
### Data elements
* CLI_ATTRIBUTE_ID_ELEMENT^ element ([DETAILS](ATTRIBUTE_ID_ELEMENT_structure.md))
* int size_bytes
* int additional_bits_flag
* int additional_bits_for_size
* array< BYTE^ >^ value


