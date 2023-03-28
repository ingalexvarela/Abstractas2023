CC=gcc
SRC=HolaMundo.c
TARGET=build\HolaMundocc.exe
CLEAN=del $(TARGET)

all: clean $(TARGET)
	$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

clean:
	$(CLEAN)
