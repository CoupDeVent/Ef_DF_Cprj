#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "column.h"

#define REALOC_SIZE 256


COLUMN *create_column(ENUM_TYPE type, char *title){
    /**
     * @brief : Create a new column
     * @param1 : Column type
     * @param2 : Column title (pointer to)
     * @return : Pointer to the created column
     * @error_return : NULL if an error in memory allocation
     */
    COLUMN* new_column = (COLUMN*)malloc(sizeof(COLUMN)); // Allocation of memory space required for variables in a column
    if(new_column == NULL){
        return NULL; // Memory allocation failed
    }

    new_column->title = strdup(title); // Allocates memory space for the title and copy
    if(new_column->title == NULL){
        return NULL; // Title memory allocation failed
    }
    new_column->data = NULL;
    new_column->size = 0;
    new_column->max_size = 0;
    new_column->column_type = type;

    return new_column;
}

int insert_value(COLUMN* column, void *value){
    /**
     * @brief : Add a new value to a column
     * @param1 : Column (pointer to)
     * @param2 : The value to be added (pointer to)
     * @return : 1 if the value is added
     * @error_return : 0 if error
     */
    if(column->size >= column->max_size){
        column->max_size += REALOC_SIZE;

        column->data = (COL_TYPE **)realloc(column->data, column->max_size * sizeof(COL_TYPE*));
        if(column->data == NULL){
            return 0; // Memory allocation failed
        }
    }

    if(value == NULL){
        column->data[column->size] = NULL;
    }
    else{
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
    }
    column->size++;
    return 1;
}

void delete_column(COLUMN **column){
    /**
     * @brief : Free the space allocated by a column
     * @param1 : Column (pointer to)
     */
    free((*column)->title);
    for(int i = 0; i < (*column)->max_size; i++){
        free((*column)->data[i]);
    }
    free((*column)->data);
    //free((*column)->index);
    free(*column);
}

void convert_value(COLUMN *column, unsigned long long int i, char *str, int size){
    /**
     * @brief: Convert a value into a string
     * @param1: Column (pointer to)
     * @param2: Position of the value in the data array
     * @param3: The string in which the value will be written
     * @param4: Maximum size of the string
     */
    switch(column->column_type){
        case UINT:
            snprintf(str, size, "%u", *((unsigned int*)column->data[i]));
            break;
        case INT:
            snprintf(str, size, "%d", *((int*)column->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float*)column->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double*)column->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)column->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", (char*)column->data[i]);
    }
}

void print_column(COLUMN* column){
    /**
     * @brief : Print a column content
     * @param1 : Column (pointer to)
     */
    char str[256];

    printf("%s :\n", column->title);
    for(int i = 0; i < column->size; i++){
        if(column->data[i] == NULL) {
            printf("%d. [NULL]\n", i); // Case where data[i] is NULL
        }
        else{
            convert_value(column, i, str, 256);
            printf("%d. [ %s ]\n", i, str);
        }
    }
}

int number_occurence(COLUMN* column, void* value){
    /**
     * @brief : Count occurence of a value
     * @param1 : Column (pointer to)
     * @param2 : The value to be counted (pointer to)
     * @return : The occurence of the value
     * @error_return : 0 else
     */
    if(column == NULL || column->data == NULL || value == NULL){
        return 0; // Case where the column is empty
    }

    int count = 0;

    for(int i = 0; i < column->size; i++){
        if(column->data[i] != NULL){ // If data[i] is not NULL
            switch(column->column_type){
                case UINT:
                    if(*((unsigned int *)column->data[i]) == *((unsigned int *)value)){
                        count++;
                    }
                    break;
                case INT:
                    if(*((int *)column->data[i]) == *((int *)value)){
                        count++;
                    }
                    break;
                case CHAR:
                    if(*((char *)column->data[i]) == *((char *)value)){
                        count++;
                    }
                    break;
                case FLOAT:
                    if(*((float *)column->data[i]) == *((float *)value)){
                        count++;
                    }
                    break;
                case DOUBLE:
                    if(*((double *)column->data[i]) == *((double *)value)){
                        count++;
                    }
                    break;
                case STRING:
                    if(strcmp((char *)column->data[i], (char *)value) == 0){ // strcmp() compares two strings character by character. If the strings are equal, the function returns 0
                        count++;
                    }
                    break;
            }
        }
    }
    return count;
}

void* value_at_position_x(COLUMN* column, int x){
    /**
     * @brief : Take the value at the index x
     * @param1 : Column (pointer to)
     * @param2 : The index of the value that we want
     * @return : The value at the index x (pointer to)
     * @error_return : NULL else
     */
    if(x < column->size){ // Check if x is lower than the size of data
        return column->data[x];
    }
    return NULL;
}

int number_value_bigger(COLUMN* column, void* value){
    /**
     * @brief : Count occurence of the value bigger than value
     * @param1 : Column (pointer to)
     * @param2 : The value to be counted (pointer to)
     * @return : The occurence of the value bigger than value
     * @error_return : 0 else
     */
    if(column == NULL || column->data == NULL || value == NULL){
        return 0; // Case where the column is empty
    }

    int count = 0;

    for(int i = 0; i < column->size; i++){
        if(column->data[i] != NULL){
            switch(column->column_type){
                case UINT:
                    if(*((unsigned int *)column->data[i]) > *((unsigned int *)value)){
                        count++;
                    }
                    break;
                case INT:
                    if(*((int *)column->data[i]) > *((int *)value)){
                        count++;
                    }
                    break;
                case CHAR:
                    if(*((char *)column->data[i]) > *((char *)value)){
                        count++;
                    }
                    break;
                case FLOAT:
                    if(*((float *)column->data[i]) > *((float *)value)){
                        count++;
                    }
                    break;
                case DOUBLE:
                    if(*((double *)column->data[i]) > *((double *)value)){
                        count++;
                    }
                    break;
                case STRING:
                    if(strcmp((char *)column->data[i], (char *)value) > 0){ // strcmp() compares two strings character by character. If the strings are equal, the function returns 0
                        count++;
                    }
                    break;
            }
        }
    }
    return count;
}

int number_value_lower(COLUMN* column, void* value){
    /**
     * @brief : Count occurence of the value lower than value
     * @param1 : Column (pointer to)
     * @param2 : The value to be counted (pointer to)
     * @return : The occurence of the value lower than value
     * @error_return : 0 else
     */
    if(column == NULL || column->data == NULL || value == NULL){
        return 0; // Case where the column is empty
    }

    int count = 0;

    for(int i = 0; i < column->size; i++){
        if(column->data[i] != NULL){
            switch(column->column_type){
                case UINT:
                    if(*((unsigned int *)column->data[i]) < *((unsigned int *)value)){
                        count++;
                    }
                    break;
                case INT:
                    if(*((int *)column->data[i]) < *((int *)value)){
                        count++;
                    }
                    break;
                case CHAR:
                    if(*((char *)column->data[i]) < *((char *)value)){
                        count++;
                    }
                    break;
                case FLOAT:
                    if(*((float *)column->data[i]) < *((float *)value)){
                        count++;
                    }
                    break;
                case DOUBLE:
                    if(*((double *)column->data[i]) < *((double *)value)){
                        count++;
                    }
                    break;
                case STRING:
                    if(strcmp((char *)column->data[i], (char *)value) < 0){ // strcmp() compares two strings character by character. If the strings are equal, the function returns 0
                        count++;
                    }
                    break;
            }
        }
    }
    return count;
}