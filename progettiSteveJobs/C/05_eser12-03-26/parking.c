#include <stdio.h>

int readMinutes( char prompt[]) {
    int m;
    printf("%s", prompt);
    scanf("%d", &m);
    return m;
}

int calculatCost(int minutes) {
    if (minutes < 0) {
        return -1;
    }

    if (minutes <= 30) {
        return 1;
    }
    else if (minutes <= 120) {
        return 3;
    }
    else {
        int extra = minutes - 120;
        int extra_hours = (extra + 59) / 60;
        return 3 + extra_hours;
    }
}

int main() {
    int minutes = readMinutes("Enter the parking time in minutes: ");
    int cost = calculatCost(minutes);

    if (cost == -1) {
        printf("Error: minutes cannot be negative.\n");
        return 0;
    }

    printf("Total cost: %d euros\n", cost);
    return 0;
}
