#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdataframe.h"


CDATAFRAME * create_cdataframe(){
    CDATAFRAME* new_cdataframe = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));

    new_cdataframe->columns = NULL;
    new_cdataframe->num_columns = 0;

    return new_cdataframe;
}

void fill_df_user(CDATAFRAME* cdataframe){
    int number_column, number_value_collumn, value;
    char title[20];

    printf("\nHow many collumn do you want ?\n");
    scanf("%d", &number_column);
    cdataframe->columns = (COLUMN*)realloc(cdataframe->columns, number_column * sizeof(COLUMN));

    for(int i = 0; i < number_column; i++){
        printf("\nWrite the title of the collumn %d\n", i);
        scanf("%s", title);
        cdataframe->columns[i] = create_column(title);
        cdataframe->num_columns += 1;

        printf("How many value do you want in your collumn ?\n");
        scanf("%d", &number_value_collumn);
        for(int k = 0; k < number_value_collumn; k++){
            printf("Enter the value %d :", k);
            scanf("%d", &value);
            insert_value(cdataframe->columns[i], value);
        }
    }
}

void fill_df_hard(CDATAFRAME* cdataframe){
    char *title[][3] = {"Col1", "Col2", "Col3"};

    cdataframe->columns = (COLUMN*)realloc(cdataframe->columns, 3 * sizeof(COLUMN));

    for(int i = 0; i < 3; i++){
        cdataframe->columns[i] = create_column(title[0][i]);
        cdataframe->num_columns += 1;

        for(int k = 0; k < 5; k++){
            insert_value(cdataframe->columns[i], k);
        }
    }

}

void print_df(CDATAFRAME* cdataframe){
    for(int i = 0; i < cdataframe->num_columns; i++){
        print_column(cdataframe->columns[i]);
    }
}

void print_partial_columns(CDATAFRAME* cdataframe, int limit){
    for(int i = 0; i < limit; i++){
        print_column(cdataframe->columns[i]);
    }
}

void print_partial_rows(CDATAFRAME* cdataframe, int limit){
    int temp;

    for(int i = 0; i < cdataframe->num_columns; i++){
        temp = cdataframe->columns[i]->size;
        cdataframe->columns[i]->size = limit;

        print_column(cdataframe->columns[i]);

        cdataframe->columns[i]->size = temp;
    }
}

void add_row_df(CDATAFRAME* cdataframe, int column_index){
    int value;

    printf("Write the value that you want to add to the column %s :\n", cdataframe->columns[i]->title);
    scanf("%d", &value);
    insert_value(cdataframe->columns[column_index], value);
}

void delete_row_df(CDATAFRAME* cdataframe, int column_index){
    cdataframe->columns[column_index]->data[cdataframe->columns[column_index]->size] = NULL;
    cdataframe->columns[column_index]->size -= 1;
}

void add_column_df(CDATAFRAME* cdataframe, char* title){
    cdataframe->columns[cdataframe->num_columns + 1] = create_column(title);
    cdataframe->num_columns += 1;
}

void delete_column_df(CDATAFRAME* cdataframe, int column_index){
    delete_column(cdataframe->columns[column_index]);
    cdataframe->num_columns -= 1;
}

void rename_column(CDATAFRAME* cdataframe, int column_index, char* new_title){
    cdataframe->columns[column_index]->title = new_title;
}

bool search_value_df(CDATAFRAME* cdataframe, int value){
    for(int i = 0; i < cdataframe->num_columns; i++){
        for(int k = 0; k < cdataframe->columns[i]->size; k++){
            if(cdataframe->columns[i]->data[k] == value){
                return true;
            }
        }
    }
    return false;
}

int get_value(CDATAFRAME* cdataframe, int row_index, int column_index){
    return cdataframe->columns[column_index]->data[row_index];
}

void replace_value(CDATAFRAME* cdataframe, int row_index, int column_index, int value){
    cdataframe->columns[column_index]->data[row_index] = value;
}

void print_column_title(CDATAFRAME* cdataframe){
    for(int i = 0; i < cdataframe->num_columns; i++){
        printf("%s", cdataframe->columns[i]->title);
    }
}

int count_rows(CDATAFRAME* cdataframe, int column_index){
    return cdataframe->columns[column_index]->size;
}

int count_columns(CDATAFRAME* cdataframe){
    return cdataframe->num_columns;
}

int count_cells_equal_to(CDATAFRAME* cdataframe, int value){
    int count = 0;

    for(int i = 0; i < cdataframe->num_columns; i++){
        for(int k = 0; k < cdataframe->columns[i]->size; k++){
            if(cdataframe->columns[i]->data[k] == value){
                count += 1;
            }
        }
    }
    return count;
}

int count_cells_bigger_than(CDATAFRAME* cdataframe, int value){
    int count = 0;

    for(int i = 0; i < cdataframe->num_columns; i++){
        count += number_value_bigger(cdataframe->columns[i], value);
    }
    return count;
}

int count_cells_lower_than(CDATAFRAME* cdataframe, int value){
    int count = 0;

    for(int i = 0; i < cdataframe->num_columns; i++){
        count += number_value_lower(cdataframe->columns[i], value);
    }
    return count;
}