
/*

So, polynomials in GF(3) can be used to create a random number generator, in a form of a linear feedback shift register.

- David Shoon


e.g.

if we tap the bits in 0th bit (1) and 1st bit(2) then we get the value = 3.

i.e. our polynomial = x^1 + x^0 

then xoring those bits (i.e. the addition operator in modulo 2 aka binary)
and set it to our 'lfsr output'.

And then rotating the input 32-bit integer to the left, and then xoring the right-most bit (least significant bit) with our lfsr output to modify the 32-bit integer, should create an LFSR.

That is all.

The cycle of this LFSR hasn't been calculated. You need to loop it through
at least 0xffffffff times to create a histogram, or at least work out...

(But it's assumed a single LFSR has at least the same cycle as the width of the integer, but I can't prove that?).

Cycle = before the integers start repeating again. This may not necessarily have
to be limited the width of the input integer (e.g.32-bits) as it may still be
random after 2^32 calls to the LFSR.

It's believed a multiple (higher order) LFSR chain can create larger cycles than
the input integer's width. (This makes sense as it's the same as a feistel network with multiple rounds).



*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <map>

int main()
{
	unsigned int polynomial = 3;
	unsigned int x = 1;
	std::map <unsigned int, unsigned int> table;

//	for (unsigned int i = 0; i < (unsigned int) 0xffffffff ; i++) {
	for (unsigned int i = 0; i < (unsigned int) 1000 ; i++) {
		unsigned y = (((x & 0x2) >> 1) ^ (x & 0x1));

//		printf("y: %u\n", y);

		x = (x << 1) | (((x & 0x80000000) >> 31) ^ y);

//		printf("x: %u\n", x);

		table[x]++;
	}



	for (auto &x : table) {
		printf("%u : %u\n", x.first, x.second);
	}
}
