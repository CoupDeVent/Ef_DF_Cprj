#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "column.h"
#include "cdataframe.h"

int main(){
    int exit = 0, column_exit = 0;
    int workplace_choice, column_choice;
    COLUMN *mycol = create_column(INT, "Column");

    while(exit != 1){
        printf("\nWhat do you want to work with ?\n");
        printf("1- Column\n");
        printf("2- CdataFrame\n");
        printf("3- Exit\n");
        scanf("%d", &workplace_choice);
        switch(workplace_choice){
            case 1:{
                printf("\n");

                while(column_exit != 1){
                    printf("\nWhat do you want to do ?\n");
                    printf("1- Create or recreate the column\n");
                    printf("2- Insert a value in the column\n");
                    printf("3- Print the column\n");
                    printf("4- Print the number of occurence of a value\n");
                    printf("5- Print the number of value bigger than a value\n");
                    printf("6- Print the number of value lower than a value\n");
                    printf("7- Exit\n");
                    scanf("%d", &column_choice);
                    switch(column_choice){
                        case 1:{
                            char title[100];
                            int type;
                            //delete_column(mycol);

                            printf("\nWhat title do you want for your column ?\n");
                            scanf("%s", title);

                            printf("What type do you want for your column ?\n");
                            printf("1- UINT\n");
                            printf("2- INT\n");
                            printf("3- CHAR\n");
                            printf("4- FLOAT\n");
                            printf("5- DOUBLE\n");
                            printf("6- STRING\n");
                            scanf("%d", &type);
                            switch(type){
                                case 1:
                                    mycol = create_column(UINT, title); break;
                                case 2:
                                    mycol = create_column(INT, title); break;
                                case 3:
                                    mycol = create_column(CHAR, title); break;
                                case 4:
                                    mycol = create_column(FLOAT, title); break;
                                case 5:
                                    mycol = create_column(DOUBLE, title); break;
                                case 6:
                                    mycol = create_column(STRING, title); break;
                                default:
                                    printf("Wrong choice.\n"); break;
                            }
                            break;
                        }
                        case 2:{
                            int nb_value_add;
                            printf("\nWrit the number of value you want to add :\n");
                            scanf("%d", &nb_value_add);
                            for(int k = 0; k < nb_value_add; k++){
                                printf("Writ the value you want to add :\n");
                                switch(mycol->column_type) {
                                    case UINT: {
                                        unsigned int value;
                                        scanf("%u", &value);
                                        insert_value(mycol, &value);
                                        break;
                                    }
                                    case INT: {
                                        int value;
                                        scanf("%d", &value);
                                        insert_value(mycol, &value);
                                        break;
                                    }
                                    case CHAR: {
                                        char value;
                                        scanf(" %c", &value);
                                        insert_value(mycol, &value);
                                        break;
                                    }
                                    case FLOAT: {
                                        float value;
                                        scanf("%f", &value);
                                        insert_value(mycol, &value);
                                        break;
                                    }
                                    case DOUBLE: {
                                        double value;
                                        scanf("%lf", &value);
                                        insert_value(mycol, &value);
                                        break;
                                    }
                                    case STRING: {
                                        char value[100];
                                        scanf("%s", value);
                                        char *str_value = strdup(value); // Allocate and copy string
                                        insert_value(mycol, &value);
                                        free(str_value); // Free the duplicated string
                                        break;
                                    }
                                    default:
                                        printf("Wrong choice.\n");
                                        break;
                                }
                            }
                            break;
                        }
                        case 3:{
                            print_column(mycol);
                            break;
                        }
                        case 4:{
                            int count = 0;
                            printf("\nWrit the value you want to now the occurence :\n");
                            switch(mycol->column_type) {
                                case UINT: {
                                    unsigned int value;
                                    scanf("%u", &value);
                                    count = number_occurence(mycol, &value);
                                    printf("The occurence of %u is : %d\n", value, count);
                                    break;
                                }
                                case INT: {
                                    int value;
                                    scanf("%d", &value);
                                    count = number_occurence(mycol, &value);
                                    printf("The occurence of %d is : %d\n", value, count);
                                    break;
                                }
                                case CHAR: {
                                    char value;
                                    scanf(" %c", &value);
                                    count = number_occurence(mycol, &value);
                                    printf("The occurence of %c is : %d\n", value, count);
                                    break;
                                }
                                case FLOAT: {
                                    float value;
                                    scanf("%f", &value);
                                    count = number_occurence(mycol, &value);
                                    printf("The occurence of %f is : %d\n", value, count);
                                    break;
                                }
                                case DOUBLE: {
                                    double value;
                                    scanf("%lf", &value);
                                    count = number_occurence(mycol, &value);
                                    printf("The occurence of %lf is : %d\n", value, count);
                                    break;
                                }
                                case STRING: {
                                    char value[100];
                                    scanf("%s", value);
                                    char *str_value = strdup(value); // Allocate and copy string
                                    count = number_occurence(mycol, &value);
                                    free(str_value); // Free the duplicated string
                                    printf("The occurence of %s is : %d\n", value, count);
                                    break;
                                }
                            }
                            break;
                        }
                        case 5:{
                            int count = 0;
                            printf("\nWrit the value you want to now how much are greater :\n");
                            switch(mycol->column_type){
                                case UINT: {
                                    unsigned int value;
                                    scanf("%u", &value);
                                    count = number_value_bigger(mycol, &value);
                                    printf("The number of value bigger than %u is : %d\n", value, count);
                                    break;
                                }
                                case INT: {
                                    int value;
                                    scanf("%d", &value);
                                    count = number_value_bigger(mycol, &value);
                                    printf("The number of value bigger than %d is : %d\n", value, count);
                                    break;
                                }
                                case CHAR: {
                                    char value;
                                    scanf(" %c", &value);
                                    count = number_value_bigger(mycol, &value);
                                    printf("The number of value bigger than %c is : %d\n", value, count);
                                    break;
                                }
                                case FLOAT: {
                                    float value;
                                    scanf("%f", &value);
                                    count = number_value_bigger(mycol, &value);
                                    printf("The number of value bigger than %f is : %d\n", value, count);
                                    break;
                                }
                                case DOUBLE: {
                                    double value;
                                    scanf("%lf", &value);
                                    count = number_value_bigger(mycol, &value);
                                    printf("The number of value bigger than %lf is : %d\n", value, count);
                                    break;
                                }
                                case STRING: {
                                    char value[100];
                                    scanf("%s", value);
                                    char *str_value = strdup(value); // Allocate and copy string
                                    count = number_value_bigger(mycol, &value);
                                    free(str_value); // Free the duplicated string
                                    printf("The number of value bigger than %s is : %d\n", value, count);
                                    break;
                                }
                            }
                            break;
                        }
                        case 6:{
                            int count = 0;
                            printf("\nWrit the value you want to now how much are lower :\n");
                            switch(mycol->column_type){
                                case UINT: {
                                    unsigned int value;
                                    scanf("%u", &value);
                                    count = number_value_lower(mycol, &value);
                                    printf("The number of value lower than %u is : %d\n", value, count);
                                    break;
                                }
                                case INT: {
                                    int value;
                                    scanf("%d", &value);
                                    count = number_value_lower(mycol, &value);
                                    printf("The number of value lower than %d is : %d\n", value, count);
                                    break;
                                }
                                case CHAR: {
                                    char value;
                                    scanf(" %c", &value);
                                    count = number_value_lower(mycol, &value);
                                    printf("The number of value lower than %c is : %d\n", value, count);
                                    break;
                                }
                                case FLOAT: {
                                    float value;
                                    scanf("%f", &value);
                                    count = number_value_lower(mycol, &value);
                                    printf("The number of value lower than %f is : %d\n", value, count);
                                    break;
                                }
                                case DOUBLE: {
                                    double value;
                                    scanf("%lf", &value);
                                    count = number_value_lower(mycol, &value);
                                    printf("The number of value lower than %lf is : %d\n", value, count);
                                    break;
                                }
                                case STRING: {
                                    char value[100];
                                    scanf("%s", value);
                                    char *str_value = strdup(value); // Allocate and copy string
                                    count = number_value_lower(mycol, &value);
                                    free(str_value); // Free the duplicated string
                                    printf("The number of value lower than %s is : %d\n", value, count);
                                    break;
                                }
                            }
                            break;
                        }
                        case 7:{
                            column_exit = 1; break;
                        }
                        default:{
                            printf("Wrong choice.\n"); break;
                        }
                    }
                }
                break;
            }
            case 2:{
                printf("\n");
                printf("Demo (WIP) :\n");

                CDATAFRAME *cdf1 = create_cdataframe();
                CDATAFRAME *cdf2 = create_cdataframe();

                printf("\n- Fill a CdataFrame : ");
                fill_df_user(cdf1);
                fill_df_hard(cdf2);

                printf("\n- Print CdataFrame fill by user :\n");
                print_df(cdf1);
                printf("\n- Print CdataFrame hard fill :\n");
                print_df(cdf2);

                printf("\n- Print CdataFrame partial rows (2) : \n");
                print_partial_rows(cdf2, 2);
                printf("- Print CdataFrame partial column (2) : \n");
                print_partial_columns(cdf2, 2);

                printf("\n- Add row :\n");
                add_row_df(cdf2, 2);
                printf("- Add column (STRING) and add a value: \n");
                add_column_df(cdf2, STRING, "New column");
                printf("- Rename column (1)\n");
                printf("- Replace the value (1, 1) by 100: \n");
                rename_column(cdf2, 0, "New name");
                int e = 100;
                replace_value(cdf2, 1, 1, &e);
                print_df(cdf2);
                printf("\n- Print all the title\n");
                print_column_title(cdf2);
                printf("- Delete change : \n");
                delete_row_df(cdf2, 2);
                delete_column_df(cdf2, 3);
                print_df(cdf2);

                printf("\n- Search if the value 100 is in the CdataFrame (1 = True, 0 = False) :\n");
                int a = 100;
                printf("%d\n", search_value_df(cdf2, &a));
                printf("- Get the value at the position (1, 1) :\n");
                printf("%d\n", *(int*)get_value(cdf2, 1, 1));
                printf("- Count the number of rows of the column 1 : \n");
                printf("%d\n", count_rows(cdf2, 0));
                printf("- Count the number of column in the CdataFrame : \n");
                printf("%d\n", count_columns(cdf2));
                printf("- Count the number of cells (equal to 1, bigger than 4, lower than 2) : \n");
                int b = 1, c = 4, d = 2;
                printf("(%d, %d, %d)\n", count_cells_equal_to(cdf2, &b), count_cells_bigger_than(cdf2, &c),
                       count_cells_lower_than(cdf2, &d));
                break;
            }
            case 3:{
                exit = 1;
                break;
            }
            default:{
                printf("Wrong choice.\n"); break;
            }
        }
    }
    delete_column(mycol);

    return 0;
}
