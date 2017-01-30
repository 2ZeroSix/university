.PHONY: all clean test
CC     = clang++
CFLAGS = -c -O3 -std=c++11
LDFLAGS= -std=c++11
TARGET = a.out
SRC    = main.cpp sort_strings.cpp
OBJ    = $(SRC:.cpp=.o)
INF    = in.txt
OUTF   = out.txt
TESTF  = test.txt


all: $(TARGET) $(SRC)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJ) $(INF) $(OUTF) $(TESTF) 

test: all
	./'test.sh' $(TARGET) $(INF) $(OUTF) $(TESTF) 100

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
