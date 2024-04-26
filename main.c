#include "column.h"
#include "cdataframe.h"

int main(){

    COLUMN *col1 = create_column("My column 1");

    insert_value(col1, 10);
    insert_value(col1, 8);
    insert_value(col1, 2);
    insert_value(col1, 650);

    print_column(col1);

    return 0;
}