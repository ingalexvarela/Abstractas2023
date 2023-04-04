SHELL := cmd.exe

CC=g++
SRC=Manejotienda.cpp
TARGET=build\Tienda_electronica.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC)
	if not exist build mkdir build
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(CLEAN)