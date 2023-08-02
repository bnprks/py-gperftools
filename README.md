# py-gperftools

This is a small Linux-only package designed to help profile C/C++ code that lives within python packages.

It makes it possible to record timing of C++ code called from within Python, which can then be
viewed in an excellent browser-based interface via [pprof](https://github.com/google/pprof).
This allows for everything from simple features like flamegraphs and sortable tables of long-running functions
to more exotic features like per-line timing and dissassembly views of the source code with per-instruction
time estimates.

# Usage

It provides two functions `start_profiler` and `stop_profiler`, to be used as follows:
```py
start_profiler("/tmp/profile.out")
run_your_cpp_stuff()
stop_profiler()

start_profile("/tmp/another-thing.out")
that_other_thing()
stop_profiler()
```

It can then be used with Google's pprof to visualize the profiler results in a convenient web interface.
```
pprof --http=localhost:[port_num] MyPackage/src/MyPackage.so /tmp/profile.out
```

If you want per-line metrics, make sure to add `-g` to the end of your 
compiler flags at build-time. For an easier time finding the `.so` file,
install an editable version of your package from your source directory
(`pip install -e .`)


# Installation

## Pre-built wheels

1. Go to the [latest release](https://github.com/bnprks/BPCells/releases/tag/v0.1.0) and identify the `.whl` file URL for the
   for your version of python (e.g. use the one with `cp39` for Python 3.9).
2. Run `pip install <URL_OF_WHL_FILE>`

## Install from source

1. Install gperftools (recommended through `conda install -c conda-forge gperftools`)
2. Run `pip install git+https://github.com/bnprks/py-gperftools.git`


## pprof
If you already have a good go installation, just run `go install github.com/google/pprof@latest` as per these [instructions](https://github.com/google/pprof#building-pprof).

<details>

<summary>Go setup instructions for those with only old go versions available</summary>

```bash
mkdir -p $HOME/go
export GOPATH=$HOME/go
export GO11MODULE=on
export PATH=$PATH:$HOME/go/bin

go get golang.org/dl/go1.20.7@latest
go1.20.7 install github.com/google/pprof@latest
```

Afterwards, don't forget to add the GOPATH, GO11MODULE, and especially the PATH modifications to your `.bashrc` or equivalent file so `pprof` will be available.

</details>