#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "column.h"

#define REALOC_SIZE 256


COLUMN *create_column(ENUM_TYPE type, char *title){
    /**
     * Create a new column
     * @param1 : Column type
     * @param2 : Column title
     * @return : Pointer to the created column
     */
    COLUMN* new_column = (COLUMN*)malloc(sizeof(COLUMN));

    new_column->title = strdup(title);
    new_column->data = NULL;
    new_column->size = 0;
    new_column->max_size = 0;
    new_column->column_type = type;

    return new_column;
}

int insert_value(COLUMN* column, void *value){
    /**
    * @brief : Add a new value to a column
    * @param1 : Pointer to a column
    * @param2 : The value to be added
    * @return : 1 if the value is added 0 otherwise
    */

    if(column->max_size == 0){
        column->max_size = REALOC_SIZE;

        column->data = (COL_TYPE *)malloc(column->max_size* sizeof(COL_TYPE));
        if(column->data == NULL){
            return 0; // Echec allocation mémoire
        }
    }
    else if(column->size >= column->max_size){
        column->max_size += REALOC_SIZE;

        column->data = (COL_TYPE *)realloc(column->data, column->max_size* sizeof(COL_TYPE));
        if(column->data == NULL || column->data == REALOC_SIZE){
            return 0; // Echec allocation mémoire
        }
    }

    switch(column->column_type){
        case UINT:
            column->data[column->size] = (unsigned int*)malloc(sizeof(unsigned int));
            *((unsigned int*)column->data[column->size]) = *((unsigned int*)value);
            break;
        case INT:
            column->data[column->size] = (int*)malloc(sizeof(int));
            *((int*)column->data[column->size]) = *((int*)value);
            break;
        case CHAR:
            column->data[column->size] = (char*)malloc(sizeof(char));
            *((char*)column->data[column->size]) = *((char*)value);
            break;
        case FLOAT:
            column->data[column->size] = (float*)malloc(sizeof(float));
            *((float*)column->data[column->size]) = *((float*)value);
            break;
        case DOUBLE:
            column->data[column->size] = (double*)malloc(sizeof(double));
            *((double*)column->data[column->size]) = *((double*)value);
            break;
        case STRING:
            column->data[column->size] = malloc((strlen(value) + 1) * sizeof(char));
            strcpy((char*)column->data[column->size], (char*)value);
            break;
    }
    column->size++;
    return 1;
}

void delete_column(COLUMN **column){
    /**
    * @brief : Free allocated memory
    * @param1 : Pointer to the column
    */

    free((*column)->title);
    for(int i = 0; i < (*column)->max_size; i++){
        free((*column)->data[i]);
    }
    free((*column)->data);
    free((*column)->index);
    free(*column);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
        
}

void print_column(COLUMN* column){
    /**
    * @brief: Print a column content
    * @param: Pointer to a column
    */

    printf("%s :\n", column->title);
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