# Rgperftools

This is a small package designed to help profile C/C++ code that lives within python packages.

It provides two functions `start_profiler` and `stop_profiler`, to be used as follows:
```R
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

# Installation
TBD; I'm attempting to provide pre-compiled wheels