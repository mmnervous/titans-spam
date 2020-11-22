# titans-spam
TX spam on INTCHAIN's testnet

## Installation

```bash
git clone https://github.com/mmnervous/titans-spam.git
cd titans-spam/
gcc spam.c -o spam_titans
```

## Set addresses

Edit sendTransaction.json to put your addresses.

## Usage

./spam [number of blocks] [number of tx in a block] [delay (ms) between blocks]

## Example

`./spam_titans 5 10 3000`

> This will send  50tx in total, 10tx every 3 seconds.

[Telegram @mmnervous](https://t.me/mmnervous)
