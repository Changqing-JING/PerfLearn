LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libprofiler.so.0 CPUPROFILE=test.prof ./build/PerfLearn
google-pprof  ./build/PerfLearn  --svg ./test.prof > test.svg
google-pprof  ./build/PerfLearn  --collapsed ./test.prof > flame
