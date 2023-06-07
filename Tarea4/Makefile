# Configuración del Makefile
PYTHON = python3  # Comando para ejecutar Python en Linux
MAIN_FILE = main.py  # Nombre del archivo principal

ifeq ($(OS), Windows_NT)
	PYTHON = python  # Comando para ejecutar Python en Windows
endif

.PHONY: run

# Regla para compilar y ejecutar el programa
run:
	$(PYTHON) $(CURDIR)/$(MAIN_FILE)

