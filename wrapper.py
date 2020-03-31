#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4

from __future__ import print_function
import os
import subprocess
import sys


def main():
    if "CONAN_DOCKER_IMAGE" in os.environ:
        image = os.environ.get("CONAN_DOCKER_IMAGE")
        command = ["docker", "run", "-w", "/host", "-v", "%s:/host" % os.getcwd(), "--rm", image, "python", "/host/run.py"]
    else:
        command = [sys.executable, "run.py"]
    print('running "%s"' % command)
    subprocess.check_call(command)


if __name__ == "__main__":
    main()
