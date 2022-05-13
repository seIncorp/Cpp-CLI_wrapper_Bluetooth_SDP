# Data elements
* CLI_DEFAULT_EXPORT^ default_export  ([DETAILS](default_export.md))
* AVRCP::CLI_SUPPORTED_FEATURES^ supported_features_handle_export


# Substructures


## CLI_SUPPORTED_FEATURES
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)



### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* SHORT supported_features_value
* CLI_SUPPORTED_FEATURES_DATA^ sfds

#### CLI_SUPPORTED_FEATURES_DATA
##### Data elements
* CLI_AVRCT avrct
* CLI_AVRC_AVRCC avrc_avrcc
##### Functions
* Test1_AVRC_AVRCC()
* Test1_AVRCT()
* getSupportedFeaturesString_AVRC_AVRCC()
* getSupportedFeaturesString_AVRCT()