#include <stdio.h>
#include <string.h>
#include "text_manipulation.h"

int right_align(const char* source, char* result, int result_length) {
    int i, num_chars_to_copy, source_length, num_trailing_spaces = 0, num_leading_spaces;

    if (source == NULL || result == NULL || result_length <= 0) {
        return FAILURE;
    }

    source_length = strlen(source);

    for (i = source_length - 1; i >= 0 && source[i] == ' '; i--) {
        num_trailing_spaces++;
    }

    num_chars_to_copy = source_length - num_trailing_spaces;

    if (result_length <= num_chars_to_copy) {
        return FAILURE;
    }

    num_leading_spaces = result_length - num_chars_to_copy - 1;

    for (i = 0; i < num_leading_spaces; i++) {
        result[i] = ' ';
    }

    for (i = num_leading_spaces; i < result_length - 1; i++) {
        result[i] = source[i - num_leading_spaces];
    }

    result[result_length - 1] = '\0';

    return SUCCESS;
}

int compact(char* string, int* word_count) {
    int read_index, len, count = 0, write_index = 0, inside_word = 0;

    if (string == NULL || string[0] == '\0') {
        return FAILURE;
    }

    if (word_count == NULL) {
        return FAILURE;
    }

    len = strlen(string);

    for (read_index = 0; read_index < len; read_index++) {
        if (string[read_index] != ' ') {
            string[write_index++] = string[read_index];
            if (!inside_word) {
                inside_word = 1;
                count++;
            }
        } else {
            inside_word = 0;
        }
    }

    string[write_index] = '\0';

    *word_count = count;

    return SUCCESS;
}
