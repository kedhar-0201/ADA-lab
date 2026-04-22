#include <stdio.h>
struct Item {
    float profit, weight, ratio;
};
void sort(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
int main() {
    int n, i;
    float capacity, total_profit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    float selected[n];
    for(i = 0; i < n; i++) selected[i] = 0;
    printf("Enter profit and weight for each item:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].ratio = items[i].profit / items[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);
    sort(items, n);
    for(i = 0; i < n; i++) {
        if(items[i].weight <= capacity) {
            selected[i] = items[i].weight;
            total_profit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            selected[i] = capacity;
            total_profit += items[i].profit * (capacity / items[i].weight);
            capacity = 0;
            break;
        }
    }
    printf("\nSelected Weights:\n");
    for(i = 0; i < n; i++) {
        if(selected[i] > 0) {
            printf("Item %d -> Weight taken = %.2f\n", i + 1, selected[i]);
        }
    }
    printf("\nMaximum Profit = %.2f\n", total_profit);
    return 0;
}
