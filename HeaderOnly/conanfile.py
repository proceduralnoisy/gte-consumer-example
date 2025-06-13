import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain, CMakeDeps
from conan.tools.build import can_run

class HeaderOnlyExample(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    options = {
        "geometry_provider": ["none", "gte"]
    }

    default_options = {
        "geometry_provider": "gte"
    }   

    def requirements(self):
        if self.options.geometry_provider == "gte":
            self.requires("geometrictoolsengine/[>=8.0 <9]")
        
        self.test_requires("gtest/[>=1.13.0 <2]")

    def generate(self):
        tc = CMakeToolchain(self)
        if self.options.geometry_provider == "gte":
            tc.variables["PN_USE_GTE"] = True
            tc.preprocessor_definitions["PN_USE_GTE"] = True
        else:
            tc.variables["PN_USE_GTE"] = False
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if can_run(self):
            cmake.test()

    def layout(self):
        cmake_layout(self)
