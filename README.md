# titans-spam
TX spam on INTCHAIN's testnet

## Installation

```bash
git clone https://github.com/mmnervous/titans-spam.git
cd titans-spam/
gcc spam.c -o spam_titans
```

## Set addresses, gas prices and value

Edit sendTransaction.json

```bash
nano sendTransaction.json
```
## Usage

./spam [number of blocks] [number of tx in a block] [delay (ms) between blocks]

> You need to unlock your account before using the program.

## Example

`./spam_titans 5 10 3000`

> This will send  50tx in total, 10tx every 3 seconds.

[Telegram @mmnervous](https://t.me/mmnervous)
