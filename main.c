#include "monty.h"

fileinfo_t info;

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	char *token;
	int line_number = 0;
	stack_t *stack = NULL;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.file = fopen(argv[1], "r");
	if (info.file == NULL)
	{
		vprintf("Error: Can't open file ", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, info.file)) != -1)
	{
		info.fileline = line;
		line_number++;
		token = strtok(info.fileline," \t\n");
		info.args = strtok(NULL, " \t\n");
		printf("%s\n", token);
	}
	fclose(info.file);
}
