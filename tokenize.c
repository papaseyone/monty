#include "monty.h"

/**
 * tokenize_input_line - extracts the opcode and if any argument from the read line
 * @buffer: line read from script
 * @opcode: pointer for opcode
 * @arg: argument for the opcode
 *
 * Return: -1 if unsuccesful, 1 if empty and 0 if something was read
 */
int tokenize_input_line(char *buffer, char **opcode, char **arg)
{
	int i = 0, x = 0, found = 0;
	char *temp;

	while (buffer[i] != '\n' && buffer[i] != '\0' && buffer[i] != '#')
	{
		if (buffer[i] != ' ')
		{
			temp = malloc(128 * sizeof(char));
			if (temp == NULL)
			{
				if (found == 1)
					free(*opcode);
				return (-1);
			}
			if (found == 0)
				*opcode = temp;
			else if (found == 1)
				*arg = temp;
			for (x = 0; buffer[i] != '\n' || buffer[i] != '\0'; x++)
			{
				temp[x] = buffer[i];
				i++;
				if (buffer[i] == ' ' || buffer[i] == '\0' || buffer[i] == '\n')
				{
					temp[++x] = '\0';
					found++;
					break;
				}
			}
			if ((strcmp(temp, "push") == 0) && found == 1)
				continue;
			break;
		}
		i++;
	}
	if (found == 0)
		return (1);
	return (0);
}
