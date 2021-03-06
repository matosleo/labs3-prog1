# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Define o nome do binario/executavel final
PROG = $(BIN)/prog1

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc direc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binario/executavel final
OBJS = $(OBJ)/produto.o $(OBJ)/fruta.o $(OBJ)/roupa.o $(OBJ)/bebida.o $(OBJ)/loja.o $(OBJ)/main.o

all : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

# Alvo para a compilação com informações de debug
# Altera a flag CFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

# Alvo para a construcao do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main.o : $(OBJ)/loja.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@
	
$(OBJ)/loja.o : $(INC)/loja.h $(OBJ)/produto.o $(OBJ)/fruta.o $(OBJ)/bebida.o $(OBJ)/roupa.o
	$(CC) $(CPPFLAGS) -c $(SRC)/loja.cpp -o $@

$(OBJ)/produto.o : $(INC)/produto.h
	$(CC) $(CPPFLAGS) -c $(SRC)/produto.cpp -o $@

$(OBJ)/fruta.o : $(INC)/fruta.h $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/fruta.cpp -o $@

$(OBJ)/roupa.o : $(INC)/roupa.h $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/roupa.cpp -o $@

$(OBJ)/bebida.o : $(INC)/bebida.h $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/bebida.cpp -o $@


# Alvo para a criação dos diretórios padrão de projetos.
direc:
	mkdir bin build doc include lib src test

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(PROG) $(OBJS)