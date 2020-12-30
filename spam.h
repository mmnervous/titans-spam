#ifndef SPAM_H
# define SPAM_H

# include <curl/curl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define CHUNK_SIZE 2048

typedef struct {
	unsigned char *buffer;
	size_t len;
	size_t buflen;
} get_request;

typedef struct {
	size_t start;
	size_t len;
} start_len;

size_t				write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
start_len 			ft_truncate(char *buffer, int delimiter, int x);
void				delay(int seconds);

#endif
