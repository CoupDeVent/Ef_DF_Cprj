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
void print_column(COLUMN* column);

int number_occurence(COLUMN* column, int value);
int value_at_position_x(COLUMN* column, int x);
int number_value_bigger(COLUMN* column, int x);
int number_value_lower(COLUMN* column, int x);

#endif
