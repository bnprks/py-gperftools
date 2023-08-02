import glob
import os.path

# Available at setup time due to pyproject.toml
from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup
from setuptools.command.install import install

__version__ = "1.0.0"

ext_modules = [
    Pybind11Extension("pygperftools",
        # Sort input files to ensure reproducible builds (https://github.com/pybind/python_example/pull/53)
        ["src/main.cpp"],
        # Example: passing in the version to the compiled code
        define_macros = [
            ('VERSION_INFO', __version__),
        ],
        libraries = ["profiler"]
        ),
]

setup(
    ext_modules=ext_modules,
    extras_require={"test": "pytest"},
    version = __version__,
)

