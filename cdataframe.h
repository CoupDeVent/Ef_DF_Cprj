#ifndef PROJET_DE_PROGRAMMATION_C_CDATAFRAME_H
#define PROJET_DE_PROGRAMMATION_C_CDATAFRAME_H
#include <stdbool.h>

typedef struct{
    COLUMN** columns;
    int num_columns;
    int num_rows;
} CDATAFRAME;

CDATAFRAME * create_dataframe();
void fill_df_user(CDATAFRAME* dataframe);
void fill_df_hard(CDATAFRAME* dataframe);

void print_df(CDATAFRAME* dataframe);
void print_partial_rows(CDATAFRAME* dataframe, int limit);
void print_partial_columns(CDATAFRAME* dataframe, int limit);

void add_row_df(CDATAFRAME* dataframe);
void delete_row_df(CDATAFRAME* dataframe);
void add_column_df(CDATAFRAME* dataframe, char* title);
void delete_column_df(CDATAFRAME* dataframe, int column_index);
void rename_column(CDATAFRAME* dataframe, int column_index, char* new_title);
bool search_value_df(CDATAFRAME* dataframe, int value);
int get_value(CDATAFRAME* dataframe, int row_index, int column_index);
void set_value(CDATAFRAME* dataframe, int row_index, int column_index, int value);
void print_column_title(CDATAFRAME* dataframe);

int count_rows(CDATAFRAME* dataframe);
int count_columns(CDATAFRAME* dataframe);
int count_cells_equal_to(CDATAFRAME* dataframe, int value);
int count_cells_greater_than(CDATAFRAME* dataframe, int value);
int count_cells_less_than(CDATAFRAME* dataframe, int value);

#endif
