CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = bin/obli

SOURCES = $(shell find . -name "*.cpp")
OBJECTS = $(addprefix build/,$(SOURCES:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p bin
	$(CXX) $(OBJECTS) -o $(TARGET)

build/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build bin