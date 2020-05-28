TARGET=main
OBJECTS=util.o mat_mul.o

CFLAGS=-std=c99 -Wall -mavx2 -g
LDFLAGS=-lm -pthread

all: $(TARGET)

$(TARGET): $(OBJECTS)

clean:
	rm -rf $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)
