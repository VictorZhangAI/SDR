#ifndef __STATE_H__
#define __STATE_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include<stdint.h>

#include"buffer.h"
#include"table.h"

typedef enum
{
        PREPARE_SUCCESS,
        PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum
{
        STATEMENT_INSERT,
        STATEMENT_SELECT
} StatementType;

typedef struct
{
        StatementType type;
	Row row_to_insert;
} Statement;



PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement* statement, Table* table);

#endif
