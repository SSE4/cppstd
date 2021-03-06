#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4

from __future__ import print_function
import subprocess
import os
import platform
import shutil


class chdir(object):
    def __init__(self, path):
        self._old_dir = os.getcwd()
        self._new_dir = path

    def __enter__(self):
        os.chdir(self._new_dir)

    def __exit__(self, *args):
        os.chdir(self._old_dir)


def get_compiler():
    if "CXX" in os.environ:
        compiler = os.environ["CXX"]
    else:
        compiler = "clang++" if platform.system() == "Darwin" else "g++"
    return compiler


def check_standard(flags):
    for flag in flags:
        command = [get_compiler(), flag, "-dM", "-E", "-x", "c++", "/dev/null"]
        try:
            print('running "%s"' % " ".join(command))
            subprocess.check_output(command)
            return flag
        except subprocess.CalledProcessError:
            pass
    return None


def main():
    cpp98 = ["-std=c++98", "-std=gnu++98"]
    cpp11 = ["-std=c++11", "-std=gnu++11", "-std=c++0x", "-std=gnu++0x"]
    cpp14 = ["-std=c++14", "-std=gnu++14", "-std=c++1y", "-std=gnu++1y"]
    cpp17 = ["-std=c++17", "-std=gnu++17", "-std=c++1z", "-std=gnu++1z"]
    cpp20 = ["-std=c++20", "-std=gnu++20", "-std=c++2a", "-std=gnu++2a"]

    standards = {1998: cpp98,
                 2011: cpp11,
                 2014: cpp14,
                 2017: cpp17,
                 2020: cpp20}

    supported_standards = dict()

    if os.name == 'nt':
        supported_standards[1998] = ''
        supported_standards[2014] = '/std:c++14'
        supported_standards[2017] = '/std:c++17'
    else:
        for standard, flags in standards.items():
            flag = check_standard(flags)
            if flag:
                supported_standards[standard] = flag

    print(supported_standards)

    is_clang = "clang" in get_compiler()
    if is_clang:
        if platform.system() == "Darwin":
            stdlibs = ["libc++"]  # libstdc++ is deprecated!
        else:
            stdlibs = ["libc++", "libstdc++"]
    elif os.name == 'nt':
        stdlibs = [""]
    else:
        stdlibs = ["libstdc++"]

    for stdlib in stdlibs:
        for high_standard in sorted(supported_standards.keys()):
            for low_standard in sorted(supported_standards.keys()):
                if low_standard >= high_standard:
                    continue
                print(low_standard, high_standard)

                def get_definitions(standard):
                    flag = supported_standards[standard]
                    gnu = "ON" if "gnu" in flag else "OFF"
                    return standard % 100, gnu

                definitions = dict()
                definitions["STDHI"], definitions["GNUHI"] = get_definitions(high_standard)
                definitions["STDLO"], definitions["GNULO"] = get_definitions(low_standard)
                definitions["STDFLAGHI"] = supported_standards[high_standard]
                definitions["STDFLAGLO"] = supported_standards[low_standard]
                definitions["CMAKE_VERBOSE_MAKEFILE"] = "ON"
                definitions["CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS"] = "ON"
                if is_clang:
                    stdlib_flag = "-stdlib=%s" % stdlib
                    definitions["CMAKE_CXX_FLAGS"] = stdlib_flag
                    definitions["CMAKE_MODULE_LINKER_FLAGS"] = stdlib_flag
                    definitions["CMAKE_SHARED_LINKER_FLAGS"] = stdlib_flag
                    definitions["CMAKE_EXE_LINKER_FLAGS"] = stdlib_flag

                cmake_dir = ".%s_%s" % (low_standard, high_standard)
                if os.path.isdir(cmake_dir):
                    shutil.rmtree(cmake_dir)
                os.makedirs(cmake_dir)

                with chdir(cmake_dir):
                    command = ["cmake", "..", "-Wno-dev"]
                    for name, value in definitions.items():
                        command.append("-D%s=%s" % (name, value))
                    print('running "%s"' % " ".join(command))
                    subprocess.check_call(command)

                    command = ["cmake", "--build", "."]
                    print('running "%s"' % " ".join(command))
                    subprocess.check_call(command)

                    old_path = os.environ["PATH"]
                    try:
                        if os.name == 'nt':
                            os.environ["PATH"] += os.pathsep + os.path.join(os.getcwd(), "engine", "Debug")
                            command = [os.path.join(os.getcwd(), "example", "Debug", "example.exe")]
                        else:
                            command = [os.path.join(os.getcwd(), "example", "example")]
                        print('running "%s"' % " ".join(command))
                        subprocess.check_call(command)
                    finally:
                        os.environ["PATH"] = old_path


if __name__ == '__main__':
    main()
