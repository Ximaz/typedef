/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** file.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

unsigned int file_get_size(const char *path)
{
    struct stat pstat = { 0 };

    if (-1 == stat(path, &pstat))
        return 0;
    return pstat.st_size;
}

int file_read_content(int fd, int chunk_size, char **buffer,
    unsigned int file_size)
{
    int nbytes = -1;
    unsigned int cursor = 0;

    while (cursor < file_size) {
        nbytes = read(fd, &((*buffer)[cursor]), chunk_size);
        if (-1 == nbytes)
            return -1;
        cursor += nbytes;
    }
    return 0;
}

int file_setup_read(const char *path, int *fd, char **buffer,
    unsigned int *file_size)
{
    *file_size = file_get_size(path);
    if (0 == *file_size)
        return -1;
    *fd = open(path, O_RDONLY);
    if (-1 == *fd)
        return -1;
    *buffer = calloc(*file_size + 1, sizeof(char));
    if (NULL == *buffer) {
        close(*fd);
        return -1;
    }
    return 0;
}

char *file_read(const char *path)
{
    int err = 0;
    int fd = 0;
    char *buffer = NULL;
    unsigned int file_size = 0;

    if (-1 == file_setup_read(path, &fd, &buffer, &file_size))
        return NULL;
    err = -1 == file_read_content(fd, 1024, &buffer, file_size);
    close(fd);
    if (1 == err) {
        free(buffer);
        return NULL;
    }
    return buffer;
}
