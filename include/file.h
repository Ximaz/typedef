/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** file.h
*/

#ifndef __FILE_H_
    #define __FILE_H_

unsigned int file_get_size(const char *path);
int file_setup_read(const char *path, int *fd, char **buffer,
    unsigned int *file_size);
int file_read_content(int fd, int chunk_size, char **buffer,
    unsigned int file_size);
char *file_read(const char *path);

#endif /* !__FILE_H_ */
