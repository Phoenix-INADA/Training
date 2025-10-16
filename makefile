CC      = gcc
CFLAGS  = -Wall -Wextra -fdiagnostics-color=always -g
LDFLAGS =
OBJPATH = .
SRCPATH = .
INCPATH = .

TARGET_NAME = training
TARGET      = $(OBJPATH)/$(TARGET_NAME)

SRCS = $(SRCPATH)/training.c
OBJS = $(patsubst $(SRCPATH)/%.c, $(OBJPATH)/%.o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJPATH)/training.o: $(SRCPATH)/training.c $(INCPATH)/training.h
	$(CC) $(CFLAGS) -c -I$(INCPATH) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)