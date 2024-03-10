#include <stdio.h>
#include <string.h>

#define MONTHS 12

float calculate_average(float sales[]) {
    float total = 0;
    for (int i = 0; i < MONTHS; i++) {
        total += sales[i];
    }
    return total / MONTHS;
}

void sort_sales_desc(float sales[], char months[][15]) {
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales[i] < sales[j]) {
                float temp_sales = sales[i];
                sales[i] = sales[j];
                sales[j] = temp_sales;

                char temp_month[15];
                strcpy(temp_month, months[i]);
                strcpy(months[i], months[j]);
                strcpy(months[j], temp_month);
            }
        }
    }
}

int main() {
    char months[MONTHS][15] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
    float sales[MONTHS];
    float moving_average[MONTHS - 5];
    float lowest_sales = 9999999;
    float highest_sales = 0;
    float average_sales;
    
    FILE *input_file;
    input_file = fopen("sales_input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(input_file, "%f", &sales[i]);

        if (sales[i] < lowest_sales)
            lowest_sales = sales[i];
        if (sales[i] > highest_sales)
            highest_sales = sales[i];
        
        if (i >= 5) {
            float sum = 0;
            for (int j = i; j > i - 6; j--) {
                sum += sales[j];
            }
            moving_average[i - 5] = sum / 6;
        }
    }
    fclose(input_file);

    average_sales = calculate_average(sales);

    printf("Monthly sales report for 2024:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }

    sort_sales_desc(sales, months);

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", lowest_sales, months[MONTHS - 1]);
    printf("Maximum sales: $%.2f (%s)\n", highest_sales, months[0]);
    printf("Average sales: $%.2f\n", average_sales);

    printf("\nSix-Month Moving Average Report:\n");
    printf("Month\tMoving Average\n");
    for (int i = 5; i < MONTHS; i++) {
        printf("%s - %s\t$%.2f\n", months[i - 5], months[i], moving_average[i - 5]);
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }

    return 0;
}
