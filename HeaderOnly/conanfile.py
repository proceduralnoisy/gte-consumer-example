import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.build import can_run


class HeaderOnlyExample(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):        
        self.requires("geometrictoolsengine/[>=8.0 <9]")
        
        self.test_requires("gtest/[>=1.13.0 <2]")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if can_run(self):
            cmake.test()

    def layout(self):
        cmake_layout(self)
