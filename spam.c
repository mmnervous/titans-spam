/*
**
**	SPAM program written by @mmnervous.
**	COST 0.0105001 INT / TX
**	https://t.me/mmnervous
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SEND_TRANSACTION "curl -X POST --data '{\"jsonrpc\":\"2.0\",\"method\":\"int_sendTransaction\",\"params\":[{\"from\": \"INT3HcmxkEx7dDRwVHqEVV46v1dYFsyd\", \"to\": \"INT3Qq1MPZME1ie6DvZ5Hf4QgTzuhPSJ\", \"gas\": \"0x7530\", \"gasPrice\": \"0x12A05F200\", \"value\": \"0x174876E800\", \"data\": \"\"}],\"id\":1}' -H 'content-type: application/json;' http://localhost:8555/testnet"
#define ECHO "echo test"

void delay(int seconds)
{
	int milli_seconds;

	milli_seconds = 1000 * seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

int	main(int argc, char *argv[])
{
	int i, j = 0;
	int argv1, argv2, argv3 = 0;
	// printf("argv1 = %d, argv2 = %d, argv3 = %d\n", argv1, argv2, argv3); // debug
	if (argc != 4)
	{
		printf("usage: %s <number of blocks> <number of tx in a block> <delay (ms) between blocks>\n", argv[0]);
		return (-1);
	}
	else
	{
		argv1 = atoi(argv[1]);
		argv2 = atoi(argv[2]);
		argv3 = atoi(argv[3]);
		if (!argv1 || !argv2 || !argv3)
		{
			printf("error\n");
			return (-1);
		}
		while (i++ < argv1)
		{
			while(j++ < argv2)
				system(SEND_TRANSACTION);
			printf("%d TX sent. Break for %d seconds\n", argv2, (argv3 / 1000));
			j = 0;
			if (i < argv1)
				delay(argv3); // milli seconds
		}
		printf("%d TX sent !\n", (argv1 * argv2));
	}
	return (0);
}
