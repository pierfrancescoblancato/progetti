#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 50
#define FIXED_SIZE 10

/* --- Input utilities --- */
int readRange(const char prompt[], int min_value, int max_value) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }
        if (value >= min_value && value <= max_value) {
            return value;
        }
    }
}

/* --- Array I/O --- */
void readArrayWithRange(int array[], int length, const char basePrompt[], int min_value, int max_value) {
    for (int i = 0; i < length; i++) {
        char prompt[128];
        snprintf(prompt, sizeof(prompt), "%s %d (%d..%d): ", basePrompt, i, min_value, max_value);
        array[i] = readRange(prompt, min_value, max_value);
    }
}

void readFixedArray(int array[], int length) {
    printf("Inserisci %d numeri interi:\n", length);
    for (int i = 0; i < length; i++) {
        while (scanf("%d", &array[i]) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

void printArray(const int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }
}

void printArrayInline(const int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printArrayReversed(const int array[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* --- Basic statistics --- */
int arrayMin(const int array[], int length) {
    int tmp = array[0];
    for (int i = 1; i < length; i++) {
        if (tmp > array[i]) tmp = array[i];
    }
    return tmp;
}

int arrayMax(const int array[], int length) {
    int tmp = array[0];
    for (int i = 1; i < length; i++) {
        if (tmp < array[i]) tmp = array[i];
    }
    return tmp;
}

int arraySum(const int array[], int length) {
    int s = 0;
    for (int i = 0; i < length; i++) s += array[i];
    return s;
}

float arrayAvg(int sum, int elements) {
    return (float)sum / (float)elements;
}

/* --- Search / counts --- */
int countAboveThreshold(const int array[], int length, int threshold) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] >= threshold) count++;
    }
    return count;
}

int findTargetIndex(const int array[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (array[i] == target) return i;
    }
    return -1;
}

/* --- Three demos (derivate dalle tre versioni originali) --- */

/* Demo 1: gestione voti (versione con ARRAY_SIZE) */
void demoVotes(void) {
    int votes[ARRAY_SIZE];
    int count = readRange("Quanti voti vuoi inserire? (1..50): ", 1, ARRAY_SIZE);
    printf("Inserisci i voti (0..30):\n");
    readArrayWithRange(votes, count, "Inserire voto", 0, 30);

    printf("\nHai inserito questi voti:\n");
    printArray(votes, count);

    int minValue = arrayMin(votes, count);
    int maxValue = arrayMax(votes, count);
    int sum = arraySum(votes, count);
    float average = arrayAvg(sum, count);

    printf("Valore minimo: %d\n", minValue);
    printf("Valore massimo: %d\n", maxValue);
    printf("Media: %.2f\n", average);

    int threshold = readRange("Inserisci la soglia per contare voti >= soglia (0..30): ", 0, 30);
    int above = countAboveThreshold(votes, count, threshold);
    printf("Numero di voti >= %d: %d\n", threshold, above);

    int target = readRange("Inserisci il valore target da cercare (0..30): ", 0, 30);
    int idx = findTargetIndex(votes, count, target);
    if (idx != -1) {
        printf("Valore %d trovato all'indice: %d\n", target, idx);
    } else {
        printf("Valore %d non trovato nell'array.\n", target);
    }
}

/* Demo 2: lettura di SIZE elementi e stampa invertita (versione con SIZE=10) */
void demoFixedReverse(void) {
    int number[FIXED_SIZE];
    printf("\n--- Demo array fisso (%d elementi) ---\n", FIXED_SIZE);
    readFixedArray(number, FIXED_SIZE);

    printf("Hai inserito: ");
    printArrayInline(number, FIXED_SIZE);

    printf("Array invertito: ");
    printArrayReversed(number, FIXED_SIZE);
}

/* Demo 3: stampa array statico (versione con array inizializzato) */
void demoStaticArray(void) {
    int votes[] = {2, 3, 4, 5, 6, 7, 4, 3, 2, 8};
    int length = sizeof(votes) / sizeof(votes[0]);

    printf("\n--- Demo array statico ---\n");
    printf("Array statico: ");
    printArrayInline(votes, length);
}

/* --- Main pulito --- */
int main(void) {
    demoVotes();
    demoFixedReverse();
    demoStaticArray();
    return 0;
}
