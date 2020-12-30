#include "spam.h"
#include "data.h"

int sendTransaction(char **result, char *from, char *to, char *gas, char *gasPrice, char *value)
{
	char				int_sendTransaction[1000];
	// char				*result;
	start_len			data = {.start = 0, .len = 0};
	get_request			req = {.buffer = NULL, .len = 0, .buflen = 0};
	CURLcode ret;
	CURL *hnd;
	struct curl_slist *slist1;

	slist1 = NULL;
	slist1 = curl_slist_append(slist1, "content-type: application/json;");
	hnd = curl_easy_init();

	snprintf(int_sendTransaction, sizeof(int_sendTransaction), "{\"jsonrpc\": \"2.0\",\"method\": \"int_sendTransaction\",\"params\": [{\"from\": \"%s\",\"to\": \"%s\",\"gas\": \"%s\",\"gasPrice\": \"%s\",\"value\": \"%s\",\"data\": \"\"}],\"id\": 1}", from, to, gas, gasPrice, value);

	curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
	curl_easy_setopt(hnd, CURLOPT_URL, "http://localhost:8555/testnet");
	curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, int_sendTransaction);
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");

	req.buffer = malloc(CHUNK_SIZE);
	req.buflen = CHUNK_SIZE;
	curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(hnd, CURLOPT_WRITEDATA, (void *)&req);

	ret = curl_easy_perform(hnd);
	data = ft_truncate(req.buffer, '"', 5);
	if (!(*result = ft_strsub(req.buffer, data.start, data.len))) // crop string
		return (-1);
	// printf("TX: %s\n", *result);

	free(req.buffer);

	curl_easy_cleanup(hnd);
	hnd = NULL;
	curl_slist_free_all(slist1);
	slist1 = NULL;
	return (0);
}

int main(int argc, char *argv[])
{
	char	*result;
	int		i = 0;

	if (argc != 3)
		printf("usage: %s <number of tx> <delay(ms) between tx>\n", argv[0]);
	else
		while (i++ < atoi(argv[1]))
		{
			sendTransaction(&result, FROM_ADDRESS, TO_ADDRESS, GAS, GAS_PRICE, VALUE);
			printf("\r%d Transaction sent. TX: %s", i, result);
			fflush(stdout);
			delay(atoi(argv[2]));
		}
	return (0);
}
