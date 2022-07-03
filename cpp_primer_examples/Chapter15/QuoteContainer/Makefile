quote: BulkQuote.o main.o Basket.o
	gcc -g -std=c++17 -o quote main.o BulkQuote.o Basket.o -lstdc++

main.o: Quote.h BulkQuote.h DiscQuote.h Basket.h main.cpp
	gcc -g -std=c++17 -c main.cpp

Basket.o: Basket.h Basket.cpp
	gcc -g -std=c++17 -c Basket.cpp

BulkQuote.o: Quote.h BulkQuote.h DiscQuote.h BulkQuote.cpp
	gcc -g -std=c++17 -c BulkQuote.cpp
