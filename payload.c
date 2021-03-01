#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *code = "CODE HERE";

unsigned char conv(const char *block) {
	unsigned char c;
	// we need to convert '5b' to 0x5b
	c = (block[0] >= 'a') ? (block[0]-'a'+10) << 4 : (block[0]-'0') << 4;
	c |= (block[1] >= 'a') ? block[1]-'a'+10 : block[1]-'0';
	return c;
}

int main() {
	size_t sz = strlen(code), i;
	unsigned char *ev = (unsigned char *) calloc(sz/2, 1);
	for (i=0; i<sz/2; i++) {
		ev[i] = conv(code + 2*i);
		ev[i] ^= 19;
	}
	((void (*)()) ev)();
	return 0;	
}