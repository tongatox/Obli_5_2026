CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Carpeta de salida
TARGET = bin/obli 

# Archivos de c++ a compilar
SOURCES = $(shell find . -name "*.cpp")

# Lista de archivos objeto generados en build/
OBJECTS = $(addprefix build/,$(SOURCES:.cpp=.o))	


# Regla para compilar el programa
all: $(TARGET)


# Regla para crear el directorio de salida y compilar el programa
$(TARGET): $(OBJECTS)
	mkdir -p bin
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regla para compilar los archivos de objetos
build/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: all
	./$(TARGET)

clean:
	rm -rf build bin