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

    printf("%s", column->title);
    for(int i = 0; i < column->logical_size; i++){
        printf("%d. [ %d ]\n", i, column->data[i]);
    }
}

int number_occurence(COLUMN* column, int value){
    /**
    * @brief: count occurence of a value
    * @param1: Pointer to a column
    * @param2: value
    * return: return occurence value
    */

    int occurence = 0;

    for(int i = 0; i < column->logical_size; i++){
        if(column->data[i] == value){
            occurence++;
        }
    }
    return occurence;
}

int value_at_position_x(COLUMN* column, int x){
    /**
    * @brief: take the value at the index x
    * @param1: Pointer to a column
    * @param2: index
    * return: return value at the index x or return -1 if the index is bigger than the logical size
    */

    if(x < column->logical_size){
        return column->data[x];
    }
    return -1;
}

int number_value_bigger(COLUMN* column, int x){
    /**
    * @brief: count occurence of the value bigger than x
    * @param1: Pointer to a column
    * @param2: x
    * return: return occurence value bigger than x
    */

    int occurence = 0;

    for(int i = 0; i < column->logical_size; i++){
        if(column->data[i] > x){
            occurence++;
        }
    }
    return occurence;
}

int number_value_lower(COLUMN* column, int x){
    /**
    * @brief: count occurence of the value lower than x
    * @param1: Pointer to a column
    * @param2: x
    * return: return occurence value lower than x
    */

    int occurence = 0;

    for(int i = 0; i < column->logical_size; i++){
        if(column->data[i] < x){
            occurence++;
        }
    }
    return occurence;
}