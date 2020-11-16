/*
**
**	SPAM program written by @mmnervous for INTchain titans testnet.
**	COST 0.00003 INT / TX	-	gasPrice : 0x3B9ACA00. = 1000000000. => 0.000000001 * gas (30000) = 0.00003 INT
**	COST 0.00015 INT / TX	-	gasPrice : 0x12A05F200. = 5000000000. => 0.000000005 * gas (30000) = 0.00015 INT
**	COST 0.015 INT / TX		-	gasPrice : 0x746A528800 = 500000000000. => 0.0000005 * gas (30000) = 0.015 INT
**	COST 0.15 INT / TX		-	gasPrice : 0x48C27395000 = 5000000000000. => 0.000005 * gas(30000) = 0.15 INT
**	https://t.me/mmnervous
**	gas: 0x7530 = 30000.
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SEND_TRANSACTION "curl -X POST --data '{\"jsonrpc\":\"2.0\",\"method\":\"int_sendTransaction\",\"params\":[{ \
\"from\": \"INT3HcmxkEx7dDRwVHqEVV46v1dYFsyd\", \
\"to\": \"INT3Qq1MPZME1ie6DvZ5Hf4QgTzuhPSJ\", \
\"gas\": \"0x7530\", \
\"gasPrice\": \"0x12A05F200\", \
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
	int timer = 10000; // milli seconds

	if (argv1 > 1 && argv2 && argv3)
	{
		printf("This will send %d TX in total. %d TX every %d seconds... Starting in %d seconds... CTRL + Z for cancel\n", (argv1 * argv2), argv2, (argv3 / 1000), (timer / 1000));
		delay(timer);
	}
	else if (argv1 == 1 && argv2 && argv3)
	{
		printf("This will send %d TX in total... Starting in %d seconds... CTRL + Z for cancel\n", (argv1 * argv2), (timer / 1000));
		delay(timer);
	}

}

int	main(int argc, char *argv[])
{
	int i, j = 0;
	int argv1, argv2, argv3 = 0;
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
		displayMessage(argv1, argv2, argv3);
		while (i++ < argv1)
		{
			while(j++ < argv2)
				system(SEND_TRANSACTION);
			printf("%d TX sent. Next TX in %d seconds\n", argv2, (argv3 / 1000));
			j = 0;
			if (i < argv1)
				delay(argv3); // milli seconds
		}
		printf("%d TX sent !\n", (argv1 * argv2));
	}
	return (0);
}
