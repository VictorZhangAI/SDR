#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include<stdlib.h>
#include<string.h>

#include"buffer.h"
#include"meta.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer)
{
        if(strcmp(input_buffer->buffer, ".exit") == 0)
        {
                exit(EXIT_SUCCESS);
        }
        else
        {
                return META_COMMAND_UNRECOGNIZED_COMMAND;
        }
}
