/*
**
**	SPAM program written by @mmnervous for INTchain titans testnet.
**	REAL COST:	0.000021 ESTIMATED : 0.0000304 INT	- gas: 0x76c0 gasPrice: 0x3B9ACA00
**	https://t.me/mmnervous
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

#define SEND_TRANSACTION "curl -X POST --data '{\"jsonrpc\":\"2.0\",\"method\":\"int_sendTransaction\",\"params\":[{ \
\"from\": \"INT3HcmxkEx7dDRwVHqEVV46v1dYFsyd\", \
\"to\": \"INT3Qq1MPZME1ie6DvZ5Hf4QgTzuhPSJ\", \
\"gas\": \"0x76c0\", \
\"gasPrice\": \"0x3B9ACA00\", \
\"value\": \"0x174876E800\", \"data\": \"\"}],\"id\":1}' -H 'content-type: application/json;' http://localhost:8555/testnet"
#define ECHO "echo test"

void delay(int seconds)
{
	int milli_seconds;

	milli_seconds = 1000 * seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void displayMessage(int argv1, int argv2, int argv3)
{
	int timer = 2000; // milli seconds

	if (argv1 > 1 && argv2 && argv3)
	{
		printf(YEL "This will send %d TX in total. %d TX every %d seconds... Starting in %d seconds... CTRL + Z for cancel" RESET "\n", (argv1 * argv2), argv2, (argv3 / 1000), (timer / 1000));
		delay(timer);
	}
	else if (argv1 == 1 && argv2 && argv3)
	{
		printf(YEL "This will send %d TX in total... Starting in %d seconds... CTRL + Z for cancel" RESET "\n", (argv1 * argv2), (timer / 1000));
		delay(timer);
	}

}

int	main(int argc, char *argv[])
{
	int i, j = 0;
	int argv1, argv2, argv3 = 0;
	if (argc != 4)
	{
		printf(RED "usage: %s <number of blocks> <number of tx in a block> <delay (ms) between blocks>\n", argv[0], RESET);
		return (-1);
	}
	else
	{
		argv1 = atoi(argv[1]);
		argv2 = atoi(argv[2]);
		argv3 = atoi(argv[3]);
		if (!argv1 || !argv2 || !argv3)
		{
			printf(RED "error\n", RESET);
			return (-1);
		}
		displayMessage(argv1, argv2, argv3);
		while (i++ < argv1)
		{
			while(j++ < argv2)
				system(SEND_TRANSACTION);
			if (i < argv1)
			{
				printf(GRN "Success ! %d TX sent. Next %d TX in %d seconds" RESET "\n", argv2, argv2, (argv3 / 1000));
				delay(argv3); // milli seconds
			}
			j = 0;
		}
		printf(GRN "Success !! %d TX sent !\n", (argv1 * argv2), RESET);
	}
	return (0);
}
