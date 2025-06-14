# Conan Consumer Guide

This guide provides step-by-step instructions for building, testing, and debugging C++ software that is configured to use the [Conan Package Manager](https://conan.io/) to obtain its dependencies.

## Introduction

### About Conan

Conan is a modern C/C++ package manager to simplify dependencies on open-source (and in-house) libraries across platforms. There are currently over 1,800 open-source libraries available through [Conan Center](https://conan.io/center), which is a central repository of Conan recipes.

### Why does this exist?

Conan is powerful and flexible, handling a wide range of existing build systems and configurations. However, despite [tutorials](https://docs.conan.io/2/tutorial.html) and [expansive documentation](https://docs.conan.io/2/index.html), it still has a bit of a steep learning curve for developers who aren't well-versed in C++ build systems.

This guide aims to be a **detailed quickstart for Conan newbies** who want to use Conan for common day-to-day development workflows.

In the interest of simplicity, an opinioned stance is taken on many topics. When there are multiple ways to achieve the same result (e.g. `conanfile.py` vs. `conanfile.txt`), only one option (typically the more modern option) is favored (e.g. `conanfile.py`).

## Prerequisites

* You have the URL of a repository that already uses Conan with CMake to build (referred to as 'your repository').
  > **Note:** The steps below assume the `conanfile.py` (or `conanfile.txt`) file is at the root of your repository. If the file is in a subfolder, you should `cd` into that folder before running `conan` commands.
* You have a basic understanding of C++ development and common terminology.

## Initial setup

### Install Conan

Conan installation instructions can be found [here](https://docs.conan.io/2/installation.html). 

To avoid dealing with Python virtual environments, these instructions will use `pipx` to install Conan. If you don't want to deal with Python at all, then you can alternatively use the direct installers (jump to the ['Alternative: Direct installers'](#alternative-direct-installers) section below).

#### Install Python

Conan requires Python 3.x (see the [Conan install page](https://docs.conan.io/2/installation.html) for the specific minimum version).

To check if you already have Python installed, try running `python --version` from the command line. If that doesn't work, try running `python3 --version`. 

> **Note (Windows):** The above commands may open the Windows Store (that means it's not installed). **Do not** install Python via the windows Store.

> **Note (Linux):** If the first command shows a 2.x version, ignore it and use `python3` for the remainder of the steps in this guide.

Simplified install instructions:
* **Windows:** Download the [64-bit Windows installer](https://www.python.org/downloads/windows/) for the latest stable version of Python. During the installation, ensure the option to add Python to the path is checked.
* **Linux (Ubuntu/Debian):** [This guide](https://www.geeksforgeeks.org/how-to-install-python-on-linux/) is a good reference. For Ubuntu/Debian you can run:
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
* **Linux (Ubuntu/Debian):**
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

### Install CMake

Although it's possible to obtain CMake automatically via Conan, this guide (as with the Conan tutorials) assumes you have a recent version of CMake installed.

To check if you already have CMake installed, try running `cmake --version` from the command line.

Simplified install instructions:
* **Windows:** Download and install a recent version from the [CMake downloads page](https://cmake.org/download/)
* **Linux (Ubuntu/Debian):** The version provided by the package manager is sufficient for many distros.
  * Run:
    ```
    sudo apt update && sudo apt upgrade
    sudo apt install cmake
    ```

### Install Git

This guide assumes you have git installed in order to clone examples. Instructions will use `git` from the command line, but you can alternatively perform the same operations with a Git UI

To check if you already have Git installed, try running `git --version` from the command line.

There are many online tutorials for installing Git. Some options:
* The [Github Git install guide](https://github.com/git-guides/install-git)
* The [official Git installation page](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
* [Git is integrated in Visual Studio Code](https://code.visualstudio.com/docs/sourcecontrol/overview)

### Create a Conan profile


Create a Conan profile specifying your compiler, etc. In most cases, you can auto-detect by running:
```
conan profile detect --force
```  

## Remaining steps (WIP)

* **Temporary**: 
* Clone this repository
* Build using Conan (automatically retrieving and building any necessary dependencies):
```
conan build . --build=missing
```
You can also build and debug with an IDE. For further details on using Conan, consult the [Conan Tutorials](https://docs.conan.io/2/tutorial.html)
