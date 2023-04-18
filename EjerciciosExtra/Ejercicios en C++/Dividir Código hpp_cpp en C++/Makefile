SHELL := cmd.exe

CC=g++
SRC1=ejemplo.cpp 
SRC2=main.cpp
TARGET=build\division_en_archivos.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC1) $(SRC2)
	if not exist build mkdir build
	$(CC) $(SRC1) $(SRC2) -o $(TARGET)

clean:
	$(CLEAN)
