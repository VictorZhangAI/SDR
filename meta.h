#ifndef __META_H__
#define __META_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include"buffer.h"

typedef enum
{
        META_COMMAND_SUCCESS,
        META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif
