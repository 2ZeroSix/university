.PHONY: all clean

TARGET = 'a.out'
SRC    = *.cpp
OBJ    = $(SRC:.cpp=.o)


all: $(TARGET)

objects:
	clang++ -c $(SRC)

$(TARGET): objects
	clang++ -o $(TARGET) $(OBJ) -O3

clean:
	rm -f $(TARGET) *.o
