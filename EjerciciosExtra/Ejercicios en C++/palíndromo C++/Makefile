CC=g++
SRC=Palindromo_palabra.cpp
TARGET=build\Palindromo_palabra.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC)
	@if not exist build mkdir build
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(CLEAN)
