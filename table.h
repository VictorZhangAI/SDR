#ifndef __TABLE_H__
#define __TABLE_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define ID_SIZE (size_of_attribute(Row, id))
#define USERNAME_SIZE (size_of_attribute(Row, username))
#define EMAIL_SIZE (size_of_attribute(Row, email))
#define ID_OFFSET 0
#define USERNAME_OFFSET (ID_OFFSET + ID_SIZE)
#define EMAIL_OFFSET (USERNAME_OFFSET + USERNAME_SIZE)
#define ROW_SIZE (ID_SIZE + USERNAME_SIZE + EMAIL_SIZE)

#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 100
#define ROWS_PER_PAGE (PAGE_SIZE / ROW_SIZE)
#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

#define size_of_attribute(Struct, Attribute) \
        sizeof(((Struct*)0)->Attribute)

typedef struct
{
        uint32_t id;
        char username[COLUMN_USERNAME_SIZE];
        char email[COLUMN_EMAIL_SIZE];
} Row;

typedef struct 
{
	uint32_t num_rows;
	void* pages[TABLE_MAX_PAGES];
} Table;

Table* new_table();
void free_table(Table* table);

void print_row(Row* row);

void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);

void* row_slot(Table* table, uint32_t row_num);

#endif
