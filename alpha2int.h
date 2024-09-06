#ifndef INCLUDED_ALPHA2INT
#define INCLUDED_ALPHA2INT

#include <string.h>
//#include <stdint.h>

unsigned long long alpha2int(char* inStr) {
	unsigned int maxChars = (sizeof(unsigned long long)*8)/5;
	unsigned long long retVal = 0;
	unsigned long long validChar = 1;
	for (unsigned long long i = 0; i < strlen(inStr) && i < maxChars; i++) {
		//validChar is true if inStr[i] is in A-Z or a-z
		//|32u is a bitmask that converts to all lowercase
		validChar = (validChar & (!!((!!((inStr[i]|32u)>='a')) && (!!((inStr[i]|32u)<='z')))));
		//&31u is bitmask that zeroes all but the first 5 bits
		retVal = (retVal | ((inStr[i]&31u) << i*5));
	}
	return retVal*validChar;
}

#endif
