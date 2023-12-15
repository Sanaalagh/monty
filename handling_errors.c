#include "monty.h"

/**
 * errors - It Prints appropiate error messages determined by their error code.
 * @error_code: The error codes:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => Provided file cannot be opened or read.
 * (3) => Provided file contains an invalid instruction.
 * (4) => Unable to malloc more memoryby the program .
 * (5) => The parameter passed to the instruction "push" is not an int.
  */
void errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	fr_nd();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - It handles errors.
 * @error_code: The error codes :
 * (6) => The stack it empty for pint.
 * (7) => The stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => The division by zero.
 */
void more_errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	fr_nd();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - It handles string errors.
 * @error_code: The error codes are :
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void string_errors(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	fr_nd();
	exit(EXIT_FAILURE);
}
