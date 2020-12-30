/*
**
**	SPAM program written by @mmnervous for INTchain titans testnet.
**	REAL COST: 0.000021	ESTIMATED : 0.0000304 INT	-	gas: 0x76c0 gasPrice: 0x3B9ACA00
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
#define SEND_TRANSACTION "curl -d \"@sendTransaction.json\" -H 'content-type: application/json;' -X POST http://localhost:8555/testnet"
#define ECHO "echo test"

void	delay(int seconds)
{
	int milli_seconds;

	milli_seconds = 1000 * seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void	displayMessage(int argv1, int argv2, int argv3)
{
	int timer;

	timer = 2000; // milli seconds
	if (argv1 > 1 && argv2)
	{
		printf(YEL "This will send %d TX in total. %d TX every %d seconds... Starting in %d seconds... CTRL + Z for cancel" RESET "\n", (argv1 * argv2), argv2, (argv3 / 1000), (timer / 1000));
		delay(timer);
	}
	else if (argv1 == 1 && argv2)
	{
		printf(YEL "This will send %d TX in total... Starting in %d seconds... CTRL + Z for cancel" RESET "\n", (argv1 * argv2), (timer / 1000));
		delay(timer);
	}

}

void	spam(int argv1, int argv2, int argv3)
{
	int i;
	int j;
	int total;

	i = 0;
	j = 0;
	total = argv1 * argv2;
	displayMessage(argv1, argv2, argv3);
	while (i++ < argv1)
	{
		while(j++ < argv2)
			system(SEND_TRANSACTION);
		if (i < argv1)
		{
			total -= argv2;
			printf(GRN "Success ! %d TX sent. Next %d TX in %d seconds. %d TX left" RESET "\n", argv2, argv2, (argv3 / 1000), total);
			delay(argv3); // milli seconds
		}
		j = 0;
	}
	printf(GRN "Success !! %d TX sent !\n", (argv1 * argv2), RESET);
}

int		main(int argc, char *argv[])
{
	if (argc != 4 || atoi(argv[1]) < 1 || atoi(argv[2]) < 1)
	{
		if (argc == 4 && atoi(argv[1]) < 1 && atoi(argv[2]))
			printf(RED "Number of blocks should be >= 1" RESET "\n");
		else if (argc == 4 && atoi(argv[1]) && atoi(argv[2]) < 1)
			printf(RED "Number of TX should be >= 1" RESET "\n");
		else
			printf(RED "usage: %s <number of blocks> <number of tx in a block> <delay (ms) between blocks>" RESET "\n", argv[0]);
		return (-1);
	}
	else
		spam(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	return (0);
}
