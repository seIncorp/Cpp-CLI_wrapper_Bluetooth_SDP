# Data elements
* CLI_DEFAULT_EXPORT^ default_export ([DETAILS](default_export.md))
* A2DP::CLI_SUPPORTED_FEATURES^ supported_features_handle_export


# SubStructures
## A2DP::CLI_SUPPORTED_FEATURES
Structure is child of CLI_DEFAULT::CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))

### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)



## VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
### Data elements
* SHORT supported_features_value
* CLI_SUPPORTED_FEATURES_DATA^ sfds




## CLI_SUPPORTED_FEATURES_DATA

### Data elements
* BYTE a0
* BYTE a1
* BYTE a2
* BYTE a3

### Functions
* System::String^ getSupportedFeaturesString()