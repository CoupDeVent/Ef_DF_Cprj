#ifndef PROJET_DE_PROGRAMMATION_C_COLUMN_H
#define PROJET_DE_PROGRAMMATION_C_COLUMN_H

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title;
    unsigned int size;
    unsigned int max_size;
    ENUM_TYPE column_type;
    COL_TYPE **data;
    unsigned long long int *index;
};
typedef struct column COLUMN;


COLUMN *create_column(ENUM_TYPE type, char *title);
int insert_value(COLUMN* column, void *value);
void delete_column(COLUMN **column);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void print_column(COLUMN* column);

int number_occurence(COLUMN* column, void* value);
int value_at_position_x(COLUMN* column, int x);
int number_value_bigger(COLUMN* column, int x);
int number_value_lower(COLUMN* column, int x);
int number_value_equal(COLUMN* column, int x);

#endif
