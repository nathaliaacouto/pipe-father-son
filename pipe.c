#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main () {
    	int turn = 0, i = 0, pipeFile[2], writeInt, readInt;
	char writeMessage[2][20] = {"Mensagem 1", "Nova Mensagem"};
	pid_t x;

	int returnPipe = pipe(pipeFile);

	if (returnPipe == -1) {
		printf("Error!");
		return 1;
	}

	x = fork();
	
	if (x != 0) {
		turn++;
		printf("Int: ");
		scanf(" %d", &writeInt);
		printf("Writing Message Int: %d\n", writeInt);
		write(pipeFile[1], &writeInt, sizeof(int) * 1);
	}
	if (turn == 1) {
		read(pipeFile[0], &readInt, sizeof(int) * 1);
		printf("Reading Message Int: %d\n", readInt);
	}
	
	
    	return 0;
}
