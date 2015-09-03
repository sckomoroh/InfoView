#ifndef AMAZON_UTILS_H
#define AMAZON_UTILS_H

#include <stdint.h>

typedef struct
{
	uint32_t state[5];
	uint32_t count[2];
	unsigned char buffer[64];
} amazon_SHA1Context;

int			amazon_base64Encode(const unsigned char *in, int inLen, char *out);
void		amazon_SHA1_transform(uint32_t state[5], const unsigned char buffer[64]);
void		amazon_SHA1_init(amazon_SHA1Context *context);
void		amazon_SHA1_update(amazon_SHA1Context *context, const unsigned char *data, unsigned int len);
void		amazon_SHA1_final(unsigned char digest[20], amazon_SHA1Context *context);
void		amazon_HMAC_SHA1(unsigned char hmac[20], const unsigned char *key, int key_len, const unsigned char *message, int message_len);
uint64_t	amazon_hash(const unsigned char *k, int length);

#endif
