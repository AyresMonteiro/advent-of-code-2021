#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 120

typedef struct str_array {
    char ** array;
    int size;
} str_array;

char * read_line(FILE * stream) {
    char * buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_SIZE);
    
    int read = strlen(fgets(buffer, MAX_BUFFER_SIZE, stream));

    if(read < MAX_BUFFER_SIZE && buffer[read - 1] == '\n') {
        buffer[--read] = '\0';
    }

    printf("characters read: %d\n", read);

    return buffer;
}

char ** push_str (char ** arr, int current_size, char * str) {
    char ** new_arr = (char **) malloc(sizeof(char *) * (current_size + 1));

    for (int i = 0; i < current_size; i++) {
        new_arr[i] = arr[i];
    }

    new_arr[current_size] = str;

    free(arr);

    return new_arr;
}

char * trim_str (char * str) {
    if (str[0] == ' ' || str[0] == '\n') {
        str++;
    }

    int size = strlen(str);

    if (str[size - 1] == ' ' || str[size - 1] == '\n') {
        str[size - 1] = '\0';
    }

    return strdup(str);
}

str_array split_array_str(char * str, const char * delimiters) {
    str_array data = { .array = NULL, .size = 0 };

    char * tmp = strtok(str, delimiters);

    if(tmp == NULL) {
        return data;
    }

    while(tmp != NULL) {
        data.array = push_str(data.array, data.size, trim_str(tmp));
        data.size++;
        tmp = strtok(NULL, delimiters);
    }

    return data;
}

void print_join(char ** arr, int size, const char * jointer) {
    printf("\"%s\"", arr[0]);;

    for (int i = 1; i < size; i++) {
        printf("%s\"%s\"", jointer, arr[i]);;
    }
}

void free_str_array (char ** array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        free(array[i]);
    }

    free(array);
}

int main () {
    char * buffer = read_line(stdin);

    str_array arr = split_array_str(buffer, "|");

    str_array signals = split_array_str(arr.array[0], " ");

    printf("data:\n");
    print_join(arr.array, arr.size, ",\n");

    printf("\n\nsignals:\n");

    print_join(signals.array, signals.size, ",\n");

    putchar('\n');

    free_str_array(signals.array, signals.size);
    free_str_array(arr.array, arr.size);

    free(buffer);

    return 0;
}