#include "get_next_line.h"
//read malloc free

char *read_chunks(int fd, char *str)
{
    char *buffer;
    int r;
    
    r = 1;
    if (!(buffer = malloc(BUFFER_SIZE + 1)))
        return (NULL);
    while(!ft_strchr(str, '\n') && r != 0)
    {
        r = read(fd, buffer, BUFFER_SIZE);
        if (r == -1)
        {
            free(buffer);
            return (NULL);
        }
        str = ft_strjoin(str, buffer);
        printf("buffer = %s\n", buffer);
    }
    free(buffer);
    return str;
}

char *get_next_line(int fd)
{
    static char *str;

    str = read_chunks(fd, str);
    printf("%s\n", str);
    return str;
}

int main()
{
    int fd;
    fd = open("h.txt", O_RDONLY);
    char *str;
    str = get_next_line(fd);
    printf("%s\n", str);
}