#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "column.h"

#define REALOC_SIZE 256


COLUMN* create_column(char* title){
    /**
    * Create a column
    * @param1 : Column title
    * @return : Pointer to created column
    */

    COLUMN* new_column = (COLUMN*)malloc(sizeof(COLUMN));

    new_column->title = strdup(title);
    new_column->data = NULL;
    new_column->logical_size = 0;
    new_column->physical_size = 0;

    return new_column;
}

int insert_value(COLUMN* column, int value){
    /**
    * @brief : Add a new value to a column
    * @param1 : Pointer to a column
    * @param2 : The value to be added
    * @return : 1 if the value is added 0 otherwise
    */

    if(column->physical_size == 0){
        column->logical_size = 1;
        column->physical_size = REALOC_SIZE;

        column->data = (int *)malloc(column->physical_size* sizeof(int));
        if(column->data == NULL){
            return 0; // Echec allocation mémoire
        }
        column->data[0] = value;

        return 1;
    }
    else if(column->logical_size >= column->physical_size){
        column->logical_size += 1;
        column->physical_size += REALOC_SIZE;

        column->data = (int*)realloc(column->data, column->physical_size* sizeof(int));
        if(column->data == NULL){
            return 0; // Echec allocation mémoire
        }
        column->data[column->logical_size - 1] = value;

        return 1;
    }
    else{
        column->logical_size += 1;

        column->data[column->logical_size - 1] = value;

        return 1;
    }
}

void delete_column(COLUMN* column){
    /**
    * @brief : Free allocated memory
    * @param1 : Pointer to a column
    */

    free(column->data);
    free(column->title);
    free(column);
}

void print_column(COLUMN* column){
    /**
    * @brief: Print a column content
    * @param: Pointer to a column
    */

    for(int i = 0; i < column->logical_size; i++){
        printf("%d. [ %d ]\n", i, column->data[i]);
    }
}

