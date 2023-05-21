CC=g++
SRC=empleados.cpp
TARGET=build/empleados.exe
CLEAN=rm -f $(TARGET)

all: $(TARGET)
	@echo "Mostrando dependencias de compilación:"
	@$(CC) -MM $(SRC)
	$(TARGET)

$(TARGET): $(SRC)
	@if [ ! -d "build" ]; then mkdir build; fi
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(CLEAN)
