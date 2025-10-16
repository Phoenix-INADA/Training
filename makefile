CC =  gcc 
CFLAGS = -fdiagnostics-color=always -g -c

OBJPATH = .
SRCPATH = .
INCPATH = .

OBJS = $(OBJPATH)/training.o 
TARGET = $(OBJPATH)/training

all:	$(TARGET)

$(TARGET): $(OBJS)
	$(CC)  $(OBJS) -o $(TARGET)

$(OBJPATH)/training.o: $(SRCPATH)/training.c $(INCPATH)/training.h
	$(CC) $(CFLAGS) -I$(INCPATH) -o $(OBJPATH)/training.o $(SRCPATH)/training.c

clean:    rm -f $(OBJPATH)/*.o $(TARGET)

