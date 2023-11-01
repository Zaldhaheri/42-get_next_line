#include "get_next_line.h"

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

char *ft_strdup(const char *str)
{
    char *dup;
    int i;

    i = 0;
    if (!(dup = (char *) malloc(ft_strlen(str) + 1)))
        return (NULL);
    while (str[i])
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1;
    size_t len2;
    size_t i;
    size_t j;
    char *r;

    i = 0;
    j = 0;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if (!(r = malloc(sizeof(char) * (len1 + len2 + 1))))
        return (NULL);
    while(s1[i])
    {
        r[i] = s1[i];
        i++;
    }
    while(s2[j])
        r[i++] = s2[j++];
    r[i] = '\0';
    return (r);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *r;
    size_t i;

    i = 0;
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s))
        len = ft_strlen(s);
    if (!(r = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while(i < len && s[start])
        r[i++] = s[start++];
    r[i] = '\0';
    return (r);
}
