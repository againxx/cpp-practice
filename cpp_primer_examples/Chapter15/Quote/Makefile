quote: BulkQuote.o main.o
	gcc -g -o quote main.o BulkQuote.o -lstdc++

main.o: Quote.h BulkQuote.h DiscQuote.h main.cpp
	gcc -g -c main.cpp

BulkQuote.o: Quote.h BulkQuote.h DiscQuote.h BulkQuote.cpp
	gcc -g -c BulkQuote.cpp
