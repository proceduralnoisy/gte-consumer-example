# Geometric Tools Engine Conan Consumer Example

This is a simple demonstration of C++ software that leverages the [Geometric Tools Engine](https://github.com/davideberly/GeometricTools) library using the [Conan Package Manager](https://conan.io/). 
It defines a library ('SimpleGeometry') that uses the GTE Mathematics headers, and a unit test executable ('TestSimpleGeometry') to validate the functionality using [GoogleTest](https://github.com/google/googletest).

## Usage
To build and run the example, follow the steps in [the Conan consumer guide](/doc/conan-consumer-guide.md) using this example repository, with the following deviations:

### Temporary: Install the Conan GTE recipe
As of June 3, 2025, the Conan recipe for GTE is [awaiting merge](https://github.com/conan-io/conan-center-index/pull/27563). Until that PR is merged, you will need to locally install the GTE recipe.

After following the 'Initial Setup' steps:
  * Clone the repository to a local folder and checkout the recipe branch:
    ```
      git clone https://github.com/proceduralnoisy/conan-center-index
      cd conan-center-index
      git checkout -t origin/add-geometrictools`
    ```
  * Use Conan to create the package and make it available in the local Conan cache:
    ```
    cd recipes/geometrictoolsengine/all
    conan create . --version=8.0
    ```