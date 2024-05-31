/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** path.c
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int file_exists(const char *path)
{
    struct stat spath = { 0 };

    if (-1 == stat(path, &spath))
        return 0;
    return S_ISREG(spath.st_mode);
}

int directory_exists(const char *path)
{
    struct stat spath = { 0 };

    if (-1 == stat(path, &spath))
        return 0;
    return S_ISDIR(spath.st_mode);
}

int mkdir_s(const char *path, mode_t mode)
{
    if (1 == directory_exists(path))
        return 0;
    return mkdir(path, mode);
}

int rmdir_s(const char *path)
{
    if (0 == directory_exists(path))
        return 0;
    return rmdir(path);
}
