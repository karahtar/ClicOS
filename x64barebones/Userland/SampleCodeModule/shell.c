#include "include/shell.h"
#include "include/lib.h"

static char buffer[50] = {0};

int shell(void) {
	int exit = 0;
	while(!exit) {
		printf("[SCM]$ ");
		while(getChar() != '\n');
		getInput();
		exit = processCommand();
	}
	return exit;
}

void getInput(void) {
	scanf(buffer);
}

int processCommand(void) {
	// maquina de estados o varios strcmp
	if(strcmp(buffer, "help")) {
		helpMenu();
		return 0;
	} else if(strcmp(buffer, "null")) {
		clear();
		return 0;
	} else if(strcmp(buffer, "time")) {
		showCurrTime();
		return 0;
	} else if(strcmp(buffer, "exit")) {
		return 1;
	} else {
		int i;
		char aux[4];
		for(i = 0; i < 4; i++) {
			aux[i] = buffer[i];
		}
		if(strcmp(aux, "echo")) {
			echo(buffer+5);
		} else {
			printf("Comando no reconocido.\n");
		}
	}
	return 0;
}

void helpMenu(void) {
	printf("Los comandos reconocidos son:\n");
	printf("null:              Limpia la pantalla.\n");
	printf("echo [mensaje]:    Muestra el mensaje.\n");
	printf("time:              Muestra la hora actual.\n");
	printf("help:              Muestra este menu de ayuda.\n");
}

void clear(void) {
	char null[1] = {0};
	printf(null);
}

void showCurrTime(void) {
	showTime();
}

void echo(char * s) {
	printf(s);
	printf("\n");
}

void clearShellBuffer(void) {
	int i;
	for(i = 0; i < 50; i++) {
		buffer[i] = 0;
	}
}