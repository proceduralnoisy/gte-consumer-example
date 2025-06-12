# Geometric Tools Engine Conan Consumer Example

This is a simple demonstration of C++ software that leverages the [Geometric Tools Engine](https://github.com/davideberly/GeometricTools) library using the [Conan Package Manager](https://conan.io/). 
It defines a library ('SimpleGeometry') that uses the GTE Mathematics headers, and a unit test executable ('TestSimpleGeometry') to validate the functionality using [GoogleTest](https://github.com/google/googletest).

## Usage

### Install Conan (one-time setup)

Conan installation instructions can be found [here](https://docs.conan.io/2/installation.html). 

To avoid dealing with Python virtual environments, these instructions will use `pipx` to install Conan. If you don't want to deal with Python at all, then you can alternatively use the direct installers (jump to the ['Alternative: Direct installers'](#alternative-direct-installers) section below).

#### Install Python
Reference: [python.org](https://www.python.org/).

To check if you already have Python installed, try running `python --version` from the command line. If that doesn't work, try running `python3 --version`. 
> **Note (Windows):** The above commands may open the Windows Store (that means it's not installed). **Do not** install Python via the windows Store.

> **Note (Linux):** If the first command shows a 2.x version, ignore it and use `python3` for the remainder of the steps in this guide.

Simplified install instructions:
* **Windows:** Download the [64-bit Windows installer](https://www.python.org/downloads/windows/) for the latest stable version of Python. During the installation, ensure the option to add Python to the path is checked.
* **Linux:** [This guide](https://www.geeksforgeeks.org/how-to-install-python-on-linux/) is a good reference. For Ubuntu/Debian you can run:
  ```
  sudo apt update && sudo apt upgrade
  sudo apt install python3
  ```

After installing, verify that Python is installed using the commands at the top of this section.

#### Install pipx
Reference: [pipx installation](https://pipx.pypa.io/stable/installation/)

`pipx` enables installation of Python-based CLI tools without the risk of dependency conflicts or the hassle of dealing with Python virtual environments.

To check if you already have Python installed, try running `pipx --version` from the command line.

Simplified install instructions:
* **Windows:**
  * Run `python -m pip install --user pipx`
  * You may see a warning indicating that the 'Scripts' folder is not on PATH. Copy the referenced folder and add it to your PATH. Restart your terminal and ensure that you can run `pipx --version`
  * Run `pipx ensurepath`, then restart your terminal one more time.
* **Linux:**
  * Run:
    ```
    sudo apt update && sudo apt upgrade
    sudo apt install pipx
    pipx ensurepath
    ```
  * Restart your terminal

#### Install Conan via pipx
After installing pipx, Conan can be installed via `pipx install conan`. You can check that Conan was successfully installed by running `conan --version`.

#### Alternative: Direct installers

As an alternative to installing via Python, you could use the installers provided on their [download page](https://conan.io/downloads). Specifically:
* **Windows:** Use the x86_64 installer. Ensure that the option to add Conan to the path is checked.
* **Linux:** Use the wget and tar commands (click the clipboard button to copy the actual commands). You'll need to either copy the untarred contents to a location on your path (e.g. `/usr/local/bin`), or add the untarred location to your path (e.g. by editing `.bashrc`).

## Remaining steps (WIP)

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
