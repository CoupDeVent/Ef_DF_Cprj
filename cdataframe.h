#ifndef PROJET_DE_PROGRAMMATION_C_CDATAFRAME_H
#define PROJET_DE_PROGRAMMATION_C_CDATAFRAME_H
#include <stdbool.h>

#include "column.h"

typedef struct{
    COLUMN** columns;
    int num_columns;
}CDATAFRAME;

CDATAFRAME * create_cdataframe();
int fill_df_user(CDATAFRAME* cdataframe);
int fill_df_hard(CDATAFRAME* cdataframe);

void print_df(CDATAFRAME* cdataframe);
void print_partial_rows(CDATAFRAME* cdataframe, int limit);
void print_partial_columns(CDATAFRAME* cdataframe, int limit);

void add_row_df(CDATAFRAME* cdataframe, int column_index);
void delete_row_df(CDATAFRAME* cdataframe, int column_index);
void add_column_df(CDATAFRAME* cdataframe, ENUM_TYPE type, char* title);
void delete_column_df(CDATAFRAME* cdataframe, int column_index);
void rename_column(CDATAFRAME* cdataframe, int column_index, char* new_title);
int search_value_df(CDATAFRAME* cdataframe, void* value);
void* get_value(CDATAFRAME* cdataframe, int row_index, int column_index);
void replace_value(CDATAFRAME* cdataframe, int row_index, int column_index, void* value);
void print_column_title(CDATAFRAME* cdataframe);

int count_rows(CDATAFRAME* cdataframe, int column_index);
int count_columns(CDATAFRAME* cdataframe);
int count_cells_equal_to(CDATAFRAME* cdataframe, void* value);
int count_cells_bigger_than(CDATAFRAME* cdataframe, void* value);
int count_cells_lower_than(CDATAFRAME* cdataframe, void* value);

#endif
