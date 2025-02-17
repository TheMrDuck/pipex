
#include "pipex.h"

int main ()
{
	fork();
	printf("Hi\n");
	wait(NULL);
}
