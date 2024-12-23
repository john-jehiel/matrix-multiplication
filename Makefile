CC = gcc
CFLAGS = -Wall -O2

TARGET = driver
SRCS = driver.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)