#include <Stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combine_path(char *destination, const char *path1, const char *path2,
                  int size) {
    if (path1 == NULL && path2 == NULL) {
        strcpy(destination, "");
        ;
    } else if (path2 == NULL || strlen(path2) == 0) {
        strcpy(destination, path1);
    } else if (path1 == NULL || strlen(path1) == 0) {
        strcpy(destination, path2);
    } else {
        char directory_separator[] = "/";
        const char *last_char = path1;
        while (*last_char != '\0')
            last_char++;
        int append_directory_separator = 0;
        if (strcmp(last_char, directory_separator) != 0) {
            append_directory_separator = 1;
        }
        strcpy(destination, path1);
        if (append_directory_separator)
            strcat(destination, directory_separator);
        strcat(destination, path2);
    }
}

void get_file_name(char *destination, const char *path, int size) {
    const char *last_char = path;
    while (*last_char != '\0')
        last_char++;
    while (last_char != path && *last_char != '/')
        last_char--;
    if (*last_char == '/')
        last_char++;
    strcpy(destination, last_char);
}

void get_file_extension(char *destination, const char *path, int size) {
    const char *last_char = path;
    while (*last_char != '\0')
        last_char++;
    while (last_char != path && *last_char != '.')
        last_char--;
    if (*last_char == '.')
        last_char++;
    strcpy(destination, last_char);
}

void get_file_path(char *destination, const char *path, int size) {
    const char *last_char = path;
    while (*last_char != '\0')
        last_char++;
    while (last_char != path && *last_char != '/')
        last_char--;
    if (*last_char == '/')
        last_char++;
    strncpy(destination, path, last_char - path);
    destination[last_char - path] = '\0';
}

void get_file_name_without_extension(char *destination, const char *path,
                                     int size) {
    char file_name[256];
    get_file_name(file_name, path, 256);
    const char *last_char = file_name;
    while (*last_char != '\0')
        last_char++;
    while (last_char != file_name && *last_char != '.')
        last_char--;
    if (*last_char == '.')
        last_char++;
    strncpy(destination, file_name, last_char - file_name);
    destination[last_char - file_name] = '\0';
}

bool file_exists(const char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r+")) != NULL) {
        fclose(file);
        return true;
    }
    return false;
}
