# Compilador a usar
CC = g++ 

# Flag c++98
CFLAGS = -Wall -std=c++98 -Iinclude

# Carpetas
SRC_DIR = src
OBJ_DIR = obj

# Nombre del ejecutable
EJECUTABLE = lab4

# Archivo a entregar
ENTREGABLE = 70_parte2_lab4.zip

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean entrega memcheck run

# Regla por defecto
all: $(EJECUTABLE)

# Linkeo final
$(EJECUTABLE): $(OBJS)
	$(CC) $(OBJS) -o $(EJECUTABLE)

# Regla patrón: compilar .cpp -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EJECUTABLE)
	./$(EJECUTABLE)

# Limpiar artefactos
clean:
	rm -rf $(OBJ_DIR) $(EJECUTABLE)

#comprimir todo en un zip para entregar
entrega:
	rm -f $(ENTREGABLE)
	zip -r $(ENTREGABLE) Makefile src include

memcheck: $(EJECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EJECUTABLE)