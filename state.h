#ifndef __STATE_H__
#define __STATE_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include"buffer.h"

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
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);

#endif
