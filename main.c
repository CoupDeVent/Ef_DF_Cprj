#include <stdio.h>

#include "column.h"
#include "cdataframe.h"

int main(){

    /*
    COLUMN *col1 = create_column("My column 1");

    insert_value(col1, 2);
    insert_value(col1, 10);
    insert_value(col1, 8);
    insert_value(col1, 2);
    insert_value(col1, 650);
    insert_value(col1, 2);

    print_column(col1);

    printf("\n- nb oc 2 : %d\n", number_occurence(col1, 2));
    printf("- nb oc 650 : %d\n", number_occurence(col1, 650));

    printf("\n- val at 1 : %d\n", value_at_position_x(col1, 1));
    printf("- val at 5 : %d\n", value_at_position_x(col1, 5));

    printf("\n- val bigger 5 : %d\n", number_value_bigger(col1, 5));
    printf("- val lower 8 : %d\n", number_value_lower(col1, 8));

    delete_column(col1);
    */


    CDATAFRAME *cdataframe = create_cdataframe();

    //fill_df_user(cdataframe);
    fill_df_hard(cdataframe);

    print_df(cdataframe);

    return 0;
}

// Faire les saisies sécurisé