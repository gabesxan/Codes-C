CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Isrc/main/c/model -Isrc/main/c/persistence

SRC = \
	src/main/c/app/main.c \
	src/main/c/persistence/paciente.c \
	src/main/c/persistence/medico.c \
	src/main/c/persistence/agendamento.c \
	src/main/c/persistence/ala.c \
	src/main/c/persistence/leito.c \
	src/main/c/persistence/internacao.c \
	src/main/c/persistence/triagem.c \
	src/main/c/persistence/relatorio.c

OUT = sigeh

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

test:
	@echo "Testes automatizados serao implementados depois."
