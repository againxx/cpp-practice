.PHONY: all
all: single_tu multi_tu

single_tu: single_tu_bench.cpp
	g++ single_tu_bench.cpp -lbenchmark -lpthread -O3 -march=native -mtune=native -o single_tu

multi_tu: multi_tu_bench.cpp base_mmul.cpp
	g++ -c base_mmul.cpp -O3 -march=native -mtune=native
	g++ multi_tu_bench.cpp base_mmul.o -lbenchmark -lpthread -O3 -march=native -mtune=native -flto -o multi_tu

.PHONY: clean
clean:
	rm base_mmul.o single_tu multi_tu
