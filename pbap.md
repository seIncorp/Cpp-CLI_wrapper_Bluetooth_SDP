# Data elements
* CLI_DEFAULT_EXPORT^ default_export ([DETAILS](default_export.md))
* MAP::CLI_GOEPL2CAPPSM^ goepl2cappsm_handle_export ([DETAILS](GOEPL2CAPPSM_struct.md))
* PBAP::CLI_SUPPORTED_REPOSITORIES^ supported_repositories_handle_export
* PBAP::CLI_PBAP_SUPPORTED_FEATURES^ pbap_supported_features_handle_export



# Substructures


## CLI_SUPPORTED_REPOSITORIES
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))
##### Data elements
* CLI_SUPPORTED_REPOSITORIES_DATA^ srs

#### CLI_SUPPORTED_REPOSITORIES_DATA
##### Data elements
* SR_S repo

##### Functions
* Test1_SupportedRepositories()
* getSupportedRepositoriesString()


## CLI_PBAP_SUPPORTED_FEATURES
Structure is child of CLI_DEFAULT_OBJECT structure ([DETAILS](default_object.md))
### Data elements
* VV^ VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA dd)

### Substructures
#### VV
This structure is child of CLI_VALUE structure([DETAILS](VALUE_structure.md))