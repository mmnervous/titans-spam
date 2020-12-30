#include "spam.h"

void	delay(int seconds)
{
	int milli_seconds;

	milli_seconds = 1000 * seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

size_t	write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t realsize = size * nmemb;
	get_request *req = (get_request *) userdata;

	// printf("receive chunk of %zu bytes\n", realsize);
	while (req->buflen < req->len + realsize + 1)
	{
		req->buffer = realloc(req->buffer, req->buflen + CHUNK_SIZE);
		req->buflen += CHUNK_SIZE;
	}
	memcpy(&req->buffer[req->len], ptr, realsize);
	req->len += realsize;
	req->buffer[req->len] = 0;

	return realsize;
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s)
	{
		i = 0;
		str = (char*)malloc(len + 1);
		if (!str)
			return (NULL);
		while (s[start] && i < len)
		{
			str[i] = s[start];
			++i;
			++start;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

start_len ft_truncate(char *buffer, int delimiter, int x) // this function calculate where to start and where to end
{
	int		j;
	int		k;

	x = x * 2 - 1;
	start_len data = {.start = 0, .len = 0};

	j = 0;
	k = 0;
	while (buffer[data.start] && x != j)
	{
		if (buffer[data.start] == delimiter)
			++j;
		++data.start;
	}
	k = data.start;
	while (buffer[k] && buffer[k] != delimiter)
		++k;
	data.len = k - data.start;
	// printf("truncate : data.start = %d, j = %d, k = %d, data.len = %d\n", data.start, j, k, data.len); // debug
	return (data);
}
