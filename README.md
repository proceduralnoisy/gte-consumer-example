## Geometric Tools Engine Conan Consumer Example

This is a simple demonstration of C++ software that leverages the [Geometric Tools Engine]([url](https://github.com/davideberly/GeometricTools)) library using the [Conan Package Manager]([url](https://conan.io/)). 
It defines a library ('SimpleGeometry') that uses the GTE Mathematics headers, and a unit test executable ('TestSimpleGeometry') to validate the functionality using [GoogleTest]([url](https://github.com/google/googletest)).

## Usage
To install depenedencies, build, and run the tests:
* Install a recent version of Conan. Instructions ([here]([url](https://docs.conan.io/2/installation.html)))
* Create a Conan profile specifying your compiler, etc. In most cases, you can auto-detect by running:
```
conan profile detect --force
```  
* Clone this repository
* Build using Conan (automatically retrieving and building any necessary dependencies):
```
conan build . --build=missing
```
You can also build and debug with an IDE. For further details on using Conan, consult the [Conan Tutorials]([url](https://docs.conan.io/2/tutorial.html))

**Note**
As of June 3, 2025, the Conan recipe for GTE is [awaiting merge]([url](https://github.com/conan-io/conan-center-index/pull/27563)). You can locally install the pending recipe as follows:
* Clone [this repository]([url](https://github.com/proceduralnoisy/conan-center-index)) and checkout the add-geometrictools branch.
* Run the following:
```
cd recipes/geometrictoolsengine/all
conan create . --version=8.0
```
