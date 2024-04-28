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
            cdataframe->columns[i]->logical_size += 1;
        }
    }
}

void fill_df_hard(CDATAFRAME* cdataframe){
    char title = {'a', 'b', 'c'};

    cdataframe->columns = (COLUMN*)realloc(cdataframe->columns, 3 * sizeof(COLUMN));

    for(int i = 0; i < 3; i++){
        cdataframe->columns[i] = create_column(title[i]);
        cdataframe->num_columns += 1;

        for(int k = 0; k < 5; k++){
            insert_value(cdataframe->columns[i], k);
            cdataframe->columns[i]->logical_size += 1;
        }
    }

}

void print_df(CDATAFRAME* cdataframe){
    for(int i = 0; i < cdataframe->num_columns; i++){
        print_column(cdataframe->columns[i]);
    }
}