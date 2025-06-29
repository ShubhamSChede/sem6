#include <stdio.h>
#include <string.h>

unsigned int compute_crc(char *bitstring, unsigned int poly, int width) {
    unsigned int crc = 0;
    int len = strlen(bitstring);
    unsigned int mask = (1U << width) - 1;  // Keep only 'width' bits
    
    // Process input bits
    for (int i = 0; i < len; i++) {
        int bit = bitstring[i] - '0';
        crc = (crc << 1) | bit;
        
        if (crc & (1U << width)) {  // If overflow bit is set
            crc ^= poly;
        }
        crc &= mask;  // Mask to keep only 'width' bits
    }
    
    // Append zeros (padding step) - CRITICAL for correct CRC
    for (int i = 0; i < width; i++) {
        crc = crc << 1;
        if (crc & (1U << width)) {
            crc ^= poly;
        }
        crc &= mask;
    }
    
    return crc;
}

int main() {
    char data[] = "10110011";
    
    unsigned int crc12 = compute_crc(data, 0x180F, 12);
    printf("Input: %s\n", data);
    printf("CRC-12: 0x%03X\n", crc12);
    
    unsigned int crc16 = compute_crc(data, 0x8005, 16);
    printf("CRC-16: 0x%04X\n", crc16);
    
    return 0;
}