SHELL := cmd.exe

CC=g++
SRC1=campus_rodrigo_facio.cpp 
SRC2=main.cpp
TARGET=build\campus_rodrigo_facio.exe
CLEAN=del /f $(TARGET)

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC1) $(SRC2)
	if not exist build mkdir build
	$(CC) $(SRC1) $(SRC2) -o $(TARGET)

clean:
	$(CLEAN)
