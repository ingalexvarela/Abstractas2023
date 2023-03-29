CC=g++
SRC=Palindromo.cpp
TARGET=build\Palindromo.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC)
	@if not exist build mkdir build
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(CLEAN)
