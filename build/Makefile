CC=g++
CFLAGS=-g -Wall -Wextra -std=c++14 -pedantic
LDFLAGS=-no-pie -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

SRCDIR=../src
OBJDIR=.

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

EXECUTABLE=../2D-Warfare

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
