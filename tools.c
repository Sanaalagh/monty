#include "monty.h"

/**
 * open_f - It opens a file
 * @file_name: the file namepath
 * Return: void
 */

void open_f(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		errors(2, file_name);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - It reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_f(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse - It Separates each line into tokens to determine
 * which function to call
 * @buffer: a line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return:  0 if the opcode is stack , 1 if queue.
 */

int parse(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		errors(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	f_func(opcode, value, line_number, format);
	return (format);
}

/**
 * f_func - It finds the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @ln: the line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void f_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_},
                {"pall", pall_},
                {"pint", pint_},
                {"pop", pop_},
                {"nop", nop_},
                {"swap", swap_},
                {"add", add_},
                {"sub", sub_},
                {"div", div_},
                {"mul", mul_},
                {"mod", mod_},
                {"pchar", pchar_},
                {"pstr", pstr_},
                {"rotl", rotl_},
                {"rotr", rotr_},
                {NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, ln, opcode);
}


/**
 * call_function - It Calls the required function.
 * @op: string representing the opcode.
 * @function: Pointer to the function that is about to be called.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function(op_func function, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, ln);
		}
		node = cr_nd(atoi(val) * flag);
		if (format == 0)
			function(&node, ln);
		if (format == 1)
			queue_add(&node, ln);
	}
	else
		function(&head, ln);
}
