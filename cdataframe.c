#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdataframe.h"


CDATAFRAME * create_cdataframe(){
    /**
     * @brief : Create a new cdataframe
     * @return : Pointer to the created cdataframe
     * @error_return : NULL if an error in memory allocation
     */
    CDATAFRAME* new_cdataframe = (CDATAFRAME*)malloc(sizeof(CDATAFRAME)); // Allocation of memory space required for variables in a cdataframe
    if(new_cdataframe == NULL){
        return NULL; // Memory allocation failed
    }

    new_cdataframe->columns = NULL;
    new_cdataframe->num_columns = 0;

    return new_cdataframe;
}

int fill_df_user(CDATAFRAME* cdataframe){
    /**
     * @brief : Fill a cdataframe with column fill by the user
     * @param1 : Cdataframe (pointer to)
     * @return : 1 if the cdataframe is create corectly
     * @error_return : 0 if error
     */
    int number_column, number_value_column, type = 1;
    void* value;
    char title[20];


    printf("\nHow many collumn do you want ? :\n");
    scanf("%d", &number_column);
    cdataframe->columns = (COLUMN*)realloc(cdataframe->columns, number_column * sizeof(COLUMN));
    if(cdataframe->columns == NULL){
        return 0; // Memory allocation failed
    }

    for(int i = 0; i < number_column; i++){
        printf("\nWrite the title of the collumn %d :\n", i);
        scanf("%s", title);
        printf("\nWhich type do you want for the collumn %d :\n", i);
        printf("1- UINT\n");
        printf("2- INT\n");
        printf("3- CHAR\n");
        printf("4- FLOAT\n");
        printf("5- DOUBLE\n");
        printf("6- STRING\n");
        scanf("%d", &type);

        switch(type){
            case 1: cdataframe->columns[i] = create_column(UINT, title); break;
            case 2: cdataframe->columns[i] = create_column(INT, title); break;
            case 3: cdataframe->columns[i] = create_column(CHAR, title); break;
            case 4: cdataframe->columns[i] = create_column(FLOAT, title); break;
            case 5: cdataframe->columns[i] = create_column(DOUBLE, title); break;
            case 6: cdataframe->columns[i] = create_column(STRING, title); break;
        }
        cdataframe->num_columns += 1;

        printf("How many value do you want in your collumn ? :\n");
        scanf("%d", &number_value_column);
        for(int k = 0; k < number_value_column; k++) {
            printf("Write the value %d:\n", k + 1);
            switch (type) {
                case 1: {
                    unsigned int value;
                    scanf("%u", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 2: {
                    int value;
                    scanf("%d", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 3: {
                    char value;
                    scanf(" %c", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 4: {
                    float value;
                    scanf("%f", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 5: {
                    double value;
                    scanf("%lf", &value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
                case 6: {
                    char value[100];
                    scanf("%s", value);
                    insert_value(cdataframe->columns[i], &value);
                    break;
                }
            }
        }
    }
    return 1;
}

int fill_df_hard(CDATAFRAME* cdataframe){
    /**
     * @brief : Fill a cdataframe with 3 column fill by 5 int
     * @param1 : Cdataframe (pointer to)
     * @return : 1 if the cdataframe is create corectly
     * @error_return : 0 if error
     */
    char *title[][3] = {"Col1", "Col2", "Col3"};

    cdataframe->columns = (COLUMN*)realloc(cdataframe->columns, 3 * sizeof(COLUMN));
    if(cdataframe->columns == NULL){
        return 0; // Memory allocation failed
    }

    for(int i = 0; i < 3; i++){
        cdataframe->columns[i] = create_column(INT, title[0][i]);
        cdataframe->num_columns += 1;

        for(int k = 0; k < 5; k++){
            insert_value(cdataframe->columns[i], &k);
        }
    }
    return 1;
}

void print_df(CDATAFRAME* cdataframe){
    /**
     * @brief : Print all the cdataframe
     * @param1 : Cdataframe (pointer to)
     */
    for(int i = 0; i < cdataframe->num_columns; i++){
        print_column(cdataframe->columns[i]);
    }
}

void print_partial_columns(CDATAFRAME* cdataframe, int limit){
    /**
     * @brief : Print the cdataframe until limit
     * @param1 : Cdataframe (pointer to)
     * @param2 : The limit until we want to print the cdataframe
     */
    for(int i = 0; i < limit; i++){
        print_column(cdataframe->columns[i]);
    }
}

void print_partial_rows(CDATAFRAME* cdataframe, int limit){
    /**
     * @brief : Print all the cdataframe but with a row limit
     * @param1 : Cdataframe (pointer to)
     * @param2 : The limit until we want to print the row
     */
    int temp;

    for(int i = 0; i < cdataframe->num_columns; i++){
        temp = cdataframe->columns[i]->size;
        cdataframe->columns[i]->size = limit;

        print_column(cdataframe->columns[i]);

        cdataframe->columns[i]->size = temp;
    }
}

void add_row_df(CDATAFRAME* cdataframe, int column_index){
    /**
     * @brief : Add a row to a column in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The index of the column that we want to add a row
     */
    printf("Write the value that you want to add to the column %s :\n", cdataframe->columns[column_index]->title);
    switch(cdataframe->columns[column_index]->column_type){
        case UINT:{
            unsigned int value;
            scanf("%u", &value);
            insert_value(cdataframe->columns[column_index], &value);
            break;
        }
        case INT:{
            int value;
            scanf("%d", &value);
            insert_value(cdataframe->columns[column_index], &value);
            break;
        }
        case CHAR:{
            char value;
            scanf(" %c", &value);
            insert_value(cdataframe->columns[column_index], &value);
            break;
        }
        case FLOAT: {
            float value;
            scanf("%f", &value);
            insert_value(cdataframe->columns[column_index], &value);
            break;
        }
        case DOUBLE: {
            double value;
            scanf("%lf", &value);
            insert_value(cdataframe->columns[column_index], &value);
            break;
        }
        case STRING:{
            char value[100];
            scanf("%s", value);
            char *str_value = strdup(value); // Allocate and copy string
            insert_value(cdataframe->columns[column_index], &str_value);
            free(str_value); // Free the duplicated string
            break;
        }
    }
}

void delete_row_df(CDATAFRAME* cdataframe, int column_index){
    /**
     * @brief : Delete a row of a column in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The index of the column
     */
    cdataframe->columns[column_index]->data[cdataframe->columns[column_index]->size] = NULL;
    cdataframe->columns[column_index]->size -= 1;
}

void add_column_df(CDATAFRAME* cdataframe, ENUM_TYPE type, char* title){
    /**
     * @brief : Add a column to the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The type of the column (ENUM_TYPE)
     * @param3 : The title of the column
     */
    cdataframe->columns = (COLUMN*)realloc(cdataframe->columns, (cdataframe->num_columns + 1) * sizeof(COLUMN));
    cdataframe->columns[cdataframe->num_columns] = create_column(type, title);
    cdataframe->num_columns += 1;
}

void delete_column_df(CDATAFRAME* cdataframe, int column_index){
    /**
     * @brief : Delete a column in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The index of the column
     */
    delete_column(&cdataframe->columns[column_index]);
    cdataframe->num_columns -= 1;
}

void rename_column(CDATAFRAME* cdataframe, int column_index, char* new_title){
    /**
     * @brief : Rename a column in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The index of the column
     * @param3 : The new title
     */
    cdataframe->columns[column_index]->title = new_title;
}

int search_value_df(CDATAFRAME* cdataframe, void* value){
    /**
     * @brief : Search if a value is in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The value (pointer to)
     * @return : 1 if the value is in the cdataframe, 0 else
     */
    for(int i = 0; i < cdataframe->num_columns; i++){
        if(number_occurence(cdataframe->columns[i], value) >= 1){
            return 1;
        }
    }
    return 0;
}

void* get_value(CDATAFRAME* cdataframe, int row_index, int column_index){
    /**
     * @brief : Get a value in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The row index
     * @param3 : The column index
     * @return : The value
     */
    return cdataframe->columns[column_index]->data[row_index];
}

void replace_value(CDATAFRAME* cdataframe, int row_index, int column_index, void* value){
    /**
     * @brief : Replace a value in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The row index
     * @param3 : The column index
     * @param4 : The value (pointer to)
     */
    cdataframe->columns[column_index]->data[row_index] = value;
}

void print_column_title(CDATAFRAME* cdataframe){
    /**
     * @brief : Print all the column titlte of the cdataframe
     * @param1 : Cdataframe (pointer to)
     */
    for(int i = 0; i < cdataframe->num_columns; i++){
        printf(".%s \n", cdataframe->columns[i]->title);
    }
}

int count_rows(CDATAFRAME* cdataframe, int column_index){
    /**
     * @brief : Count the row of a column in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param1 : The index of the column
     * @return : The number of row of the column
     */
    return cdataframe->columns[column_index]->size;
}

int count_columns(CDATAFRAME* cdataframe){
    /**
     * @brief : Count the number of column in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @return : The number of column
     */
    return cdataframe->num_columns;
}

int count_cells_equal_to(CDATAFRAME* cdataframe, void* value){
    /**
     * @brief : Count the number of cells equal to value in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The value (pointer to)
     * @return : The number of cells equal to value
     */
    int count = 0;

    for(int i = 0; i < cdataframe->num_columns; i++){
        count += number_occurence(cdataframe->columns[i], value);
    }
    return count;
}

int count_cells_bigger_than(CDATAFRAME* cdataframe, void* value){
    /**
     * @brief : Count the number of cells bigger than value in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The value (pointer to)
     * @return : The number of cells bigger than value
     */
    int count = 0;

    for(int i = 0; i < cdataframe->num_columns; i++){
        count += number_value_bigger(cdataframe->columns[i], value);
    }
    return count;
}

int count_cells_lower_than(CDATAFRAME* cdataframe, void* value){
    /**
     * @brief : Count the number of cells lower than value in the cdataframe
     * @param1 : Cdataframe (pointer to)
     * @param2 : The value (pointer to)
     * @return : The number of cells lower than value
     */
    int count = 0;

    for(int i = 0; i < cdataframe->num_columns; i++){
        count += number_value_lower(cdataframe->columns[i], value);
    }
    return count;
}
