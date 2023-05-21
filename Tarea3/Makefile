CC=g++
SRC1=empleados.cpp 
SRC2=main.cpp
TARGET=build\empleados.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	@echo "Mostrando dependencias de compilación:"
	@echo "$(SRC1)"
	@echo "$(SRC2)"
	$(TARGET)

$(TARGET): $(SRC1) $(SRC2)
	@if not exist build mkdir build
	$(CC) $(SRC1) $(SRC2) -o $(TARGET)

clean:
	$(CLEAN)
