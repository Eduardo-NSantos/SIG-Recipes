# Name do projeto
PROJ_NAME=programa
 
# Arquivos .c
C_SOURCE=$(wildcard *.c)
 
# Arquivos .h
H_SOURCE=$(wildcard *.h)
 
# Arquivos .o
OBJ=$(C_SOURCE:.c=.o)
 
# Compilador
CC=gcc
 
# Falgs do compilador
CC_FLAGS=-c         \
         -Wall
 
#
# Compilação
#
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^
	@ echo ' '
	@ echo 'Criado o execútavel "$(PROJ_NAME)"'
	@ echo ' '
 
%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)
 
main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
	rm -rf *.o $(PROJ_NAME) *~