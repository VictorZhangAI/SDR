#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#include"buffer.h"
#include"meta.h"
#include"state.h"
#include"table.h"

int main(int argc, char **argv)
{
	Table* table = new_table();
	InputBuffer* input_buffer = new_input_buffer();
	while(true)
	{
		print_prompt();
		read_input(input_buffer);

		if(input_buffer->buffer[0] == '.')
		{
			switch(do_meta_command(input_buffer))
			{
				case(META_COMMAND_SUCCESS):
					continue;
				case(META_COMMAND_UNRECOGNIZED_COMMAND):
					printf("Unrecognized command '%s'\n", input_buffer->buffer);
					continue;
			}
		}
		
		Statement statement;
		switch(prepare_statement(input_buffer, &statement))
		{
			case(PREPARE_SUCCESS):
				break;
			case(PREPARE_SYNTAX_ERROR):
				printf("Syntax error. Could not parse statement.\n");
				continue;
			case(PREPARE_UNRECOGNIZED_STATEMENT):
				 printf("Unrecognized keyword at start of '%s'.\n",
					input_buffer->buffer);
				 continue;
		}

		switch(execute_statement(&statement, table))
		{
			case(EXECUTE_SUCCESS):
				printf("Executed.\n");
				break;
			case(EXECUTE_TABLE_FULL):
				printf("Error: table full.\n");
				break;
		}
	}
}
