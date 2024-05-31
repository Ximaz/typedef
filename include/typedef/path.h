/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** path.h
*/

#ifndef __PATH_H_
    #define __PATH_H_
    #include <sys/stat.h>

int file_exists(const char *path);
int directory_exists(const char *path);
int mkdir_s(const char *path, mode_t mode);
int rmdir_s(const char *path);

#endif
