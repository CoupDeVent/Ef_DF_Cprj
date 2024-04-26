#ifndef PROJET_DE_PROGRAMMATION_C_COLUMN_H
#define PROJET_DE_PROGRAMMATION_C_COLUMN_H

typedef struct{
    char* title;
    int* data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* column, int value);
void delete_column(COLUMN* column);
int get_logical_size(COLUMN* column);
int get_value_at_index(COLUMN* column, int index);
void print_column(COLUMN* column);

#endif
