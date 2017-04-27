SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror -g -fdiagnostics-color=always

all: main

%.o: %.cpp $(HEADERS)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

main: $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f *.o main

Final.zip: $(SOURCES) $(HEADERS) Makefile FinalProjectDesign.pdf
	rm -f $@
	zip $@ $^
