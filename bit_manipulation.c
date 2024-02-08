#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet);
void    print_bits(unsigned char octet);
unsigned char   swap_bits(unsigned char octet);

int     main(void)
{
        unsigned char	num;

        num = 38;
	print_bits(num);
        num = reverse_bits(num);
	print_bits(num);
	num = swap_bits(num);
	print_bits(num);
        return(0);
}

void    print_bits(unsigned char octet)
{
        int     bit_len;
        unsigned char   bit;

        bit_len = 7;
        while (bit_len >= 0)
        {
                bit = (octet >> bit_len) & 1;
                bit += '0';
                write(1, &bit, 1);
                bit_len--;
        }
        write(1, "\n", 1);
}

unsigned char	reverse_bits(unsigned char octet)
{
        int		bit_len;
        unsigned char	reversed_byte;

        bit_len = 0;
        while (bit_len < 8)
        {
                reversed_byte = (reversed_byte << 1) | ((octet >> bit_len) & 1);
                bit_len++;
        }
	return (reversed_byte);
}


unsigned char   swap_bits(unsigned char octet)
{
        int             bit_index;
        unsigned char   swapped_byte;

	bit_index = 7;
	while (bit_index >= 4)
        {
                swapped_byte = (swapped_byte << 1) | (octet >> bit_index) & 1;
                bit_index--;
        }
        bit_index = 4;
        while (bit_index > 0)
        {
                swapped_byte = (swapped_byte << 1) | (octet >> bit_index) & 1;
                bit_index--;
        }
	return (swapped_byte);
}

