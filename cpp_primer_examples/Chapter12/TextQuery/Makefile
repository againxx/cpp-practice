all: main.o query_result.o text_query.o
	g++ -g -o text_query main.o query_result.o text_query.o

main.o: main.cpp
	g++ -g -c main.cpp

query_result.o: query_result.h query_result.cpp
	g++ -g -c query_result.cpp

text_query.o: text_query.h text_query.cpp
	g++ -g -c text_query.cpp

clean:
	rm *.o text_query
