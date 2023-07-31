#include <pybind11/pybind11.h>
#include "gperftools/profiler.h"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(pygperftools, m) {
    m.doc() = R"pbdoc(
        Pybind11 gperftools bindings
        -----------------------

        .. currentmodule:: pygperftools

        .. autosummary::
           :toctree: _generate

           start_profiler
           stop_profiler
    )pbdoc";

    m.def("start_profiler", &ProfilerStart, R"pbdoc(
        Start the profiler, passing in a location to save the profile
    )pbdoc");

    m.def("stop_profiler", &ProfilerStop, R"pbdoc(
        Stop the profiler
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
