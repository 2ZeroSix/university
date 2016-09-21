.PHONY: all clean test
CC     = g++
CFLAGS = -std=c++11 -O3 -c -Wall
LDFLAGS= -std=c++11 -Wall 
TARGET = lab1.exe
SRC    = main.cpp tritset.cpp
OBJ    = $(SRC:.cpp=.o)
INF    = 
OUTF   = 
TESTF  = 


all: $(TARGET) $(SRC)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJ) $(INF) $(OUTF) $(TESTF) 

test: all
	./'test.sh' $(TARGET) $(INF) $(OUTF) $(TESTF) 100

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
