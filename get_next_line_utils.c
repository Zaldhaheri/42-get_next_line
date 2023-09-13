#include "get_next_line.h"

char *ft_strnstr(char *str, const char *find, size_t n)
{
    size_t len;

    len = 0;
    if (find == "")
        return ((char *)str);
    if (n == 0)
        return (NULL);
    while (find[len] != '\0')
        len++;
    while (len <= n && *str)
    {
        if (!(ft_strncmp(str, (char *)find, len)))
            return (str);
        str++;
        n--;
    }
    return (NULL);
}

char *ft_strchr(const char *str, int c)
{
    while(*str)
    {
        if (*str == (char)c)
            break;
        str++;
    }
    if (*str == (char)c)
        return ((char*) str);
    return (NULL);
}

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while (str1[i] && str2[i] && i < n - 1 && str1[i] == str2[i])
        i++;
    return (str1[i] - str2[i]);
}