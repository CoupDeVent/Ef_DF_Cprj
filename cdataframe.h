#ifndef PROJET_DE_PROGRAMMATION_C_CDATAFRAME_H
#define PROJET_DE_PROGRAMMATION_C_CDATAFRAME_H
#include <stdbool.h>

#include "column.h"

typedef struct{
    COLUMN** columns;
    int num_columns;
}CDATAFRAME;

CDATAFRAME * create_cdataframe();
void fill_df_user(CDATAFRAME* cdataframe);
void fill_df_hard(CDATAFRAME* cdataframe);

void print_df(CDATAFRAME* cdataframe);
void print_partial_rows(CDATAFRAME* cdataframe, int limit);
void print_partial_columns(CDATAFRAME* cdataframe, int limit);

void add_row_df(CDATAFRAME* cdataframe);
void delete_row_df(CDATAFRAME* cdataframe);
void add_column_df(CDATAFRAME* cdataframe, char* title);
void delete_column_df(CDATAFRAME* cdataframe, int column_index);
void rename_column(CDATAFRAME* cdataframe, int column_index, char* new_title);
bool search_value_df(CDATAFRAME* cdataframe, int value);
int get_value(CDATAFRAME* cdataframe, int row_index, int column_index);
void set_value(CDATAFRAME* cdataframe, int row_index, int column_index, int value);
void print_column_title(CDATAFRAME* cdataframe);

int count_rows(CDATAFRAME* cdataframe);
int count_columns(CDATAFRAME* cdataframe);
int count_cells_equal_to(CDATAFRAME* cdataframe, int value);
int count_cells_greater_than(CDATAFRAME* cdataframe, int value);
int count_cells_less_than(CDATAFRAME* cdataframe, int value);

#endif
