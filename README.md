## Geometric Tools Engine Conan Consumer Example

This is a simple demonstration of C++ software that leverages the [Geometric Tools Engine](https://github.com/davideberly/GeometricTools) library using the [Conan Package Manager](https://conan.io/). 
It defines a library ('SimpleGeometry') that uses the GTE Mathematics headers, and a unit test executable ('TestSimpleGeometry') to validate the functionality using [GoogleTest](https://github.com/google/googletest).

## Usage
To install depenedencies, build, and run the tests:
* Install a recent version of Conan. Instructions ([here](https://docs.conan.io/2/installation.html))
* Create a Conan profile specifying your compiler, etc. In most cases, you can auto-detect by running:
```
conan profile detect --force
```  
* **Temporary**: As of June 3, 2025, the Conan recipe for GTE is [awaiting merge](https://github.com/conan-io/conan-center-index/pull/27563). Until that PR is merged, you can locally install the recipe as follows:
  * Clone [this repository](https://github.com/proceduralnoisy/conan-center-index)
  * Checkout the add-geometrictools branch (`git checkout -t origin/add-geometrictools`).
  * Run the following command to create the package and make it available in the local Conan cache:
```
cd recipes/geometrictoolsengine/all
conan create . --version=8.0
```
* Clone this repository
* Build using Conan (automatically retrieving and building any necessary dependencies):
```
cd HeaderOnly
conan build . --build=missing
```
You can also build and debug with an IDE. For further details on using Conan, consult the [Conan Tutorials](https://docs.conan.io/2/tutorial.html)
