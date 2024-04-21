#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <column.h>
#include <cdataframe.h>


COLUMN* create_column(char* title){
    COLUMN* new_column = (COLUMN*)malloc(sizeof(COLUMN));

    new_column->title = strdup(title);
    new_column->data = NULL;
    new_column->logical_size = 0;
    new_column->physical_size = 0;

    return new_column;
}

int main(){

    COLUMN *col1 = create_column("My column 1");
    COLUMN *col2 = create_column("My column 2");
    COLUMN *col3 = create_column("My column 3");
    for(int i = 0; i < 10; i++){
        add_value_to_column(col1, i);
        add_value_to_column(col2, -i);
    }
    delete_column(col3);
    print_column(col1);

    CDATAFRAME *df = create_dataframe();

    return 0;
}