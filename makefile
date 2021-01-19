CC=gcc
AR=ar

FLAGS= -Wall -g

all:frequency

frequency:main.o trie.o 
	$(CC) $(FLAGS) -o frequency main.o trie.o 

main.o: main.c trie.h
	$(CC) $(FLAGS) -c main.c

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all

clean:
	rm -f *.o *.a frequency		
