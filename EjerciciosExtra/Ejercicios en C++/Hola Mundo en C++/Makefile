CC=g++
SRC=HolaMundo.cpp
TARGET=build\HolaMundo++.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC)
	@if not exist build mkdir build
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(CLEAN)

