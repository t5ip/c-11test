CC=g++
INCLUDES=-I.
CFLAGS=$(INCLUDES) -c
CFLAGS+=-std=c++0x
LDFLAGS= -lpthread
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o) 
EXECUTABLE=c++11test1

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f $(EXECUTABLE) $(OBJECTS)
