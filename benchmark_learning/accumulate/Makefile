default_target: all
.PHONY: default_target

all: accumulate_benchmark.cpp
	g++ accumulate_benchmark.cpp -lbenchmark -lpthread -O3 -march=native -mtune=native -flto -fuse-linker-plugin -o accumulate_benchmark
