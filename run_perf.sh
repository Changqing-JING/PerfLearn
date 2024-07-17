sudo perf record -g -F 99  -o build/perf.data -- ./build/PerfLearn
sudo perf script -i build/perf.data > build/out.perf
stackcollapse-perf.pl build/out.perf > build/out.floded
flamegraph.pl build/out.floded > build/flame.svg
perf script | c++filt | gprof2dot -f perf | dot -Tsvg -o output.svg