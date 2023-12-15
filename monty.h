#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

/* Data structure for a stack/queue node */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/* Data structure for opcode and its function */
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Stack , String and  Math operations */
void push_(stack_t **, unsigned int);
void pall_(stack_t **, unsigned int);
void pint_(stack_t **, unsigned int);
void pop_(stack_t **, unsigned int);
void swap_(stack_t **, unsigned int);
void add_(stack_t **, unsigned int);
void nop_(stack_t **, unsigned int);
void sub_(stack_t **, unsigned int);
void div_(stack_t **, unsigned int);
void mul_(stack_t **, unsigned int);
void mod_(stack_t **, unsigned int);
void pchar_(stack_t **, unsigned int);
void pstr_(stack_t **, unsigned int);
void rotl_(stack_t **, unsigned int);
void rotr_(stack_t **, unsigned int);

/*Tools */
void open_f(char *fl_name);
int parse(char *buffer, int line_number, int format);
void read_f(FILE *);
int len_chars(FILE *);
void f_func(char *, char *, int, int);
/*Main */
stack_t *cr_nd(int n);
void fr_nd(void);
void queue_add(stack_t **, unsigned int);

void call_function(op_func, char *, char *, int, int);

/*Handling_Errors*/
void errors(int error_code, ...);
void more_errors(int error_code, ...);
void string_errors(int error_code, ...);

#endif
