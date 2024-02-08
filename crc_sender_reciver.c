#include <stdio.h>
#include <stdint.h>

#define DATA_SIZE 4
#define CRC_SIZE 1 


uint8_t crc_remainder(uint8_t *data, int data_size, uint8_t polynomial) {
    uint8_t crc = 0;
    int i, j;
    for (i = 0; i < data_size; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ polynomial;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}


void crc_encode(uint8_t *data, int data_size, uint8_t polynomial, uint8_t *encoded_data) {
    int i;
    for (i = 0; i < data_size; i++) {
        encoded_data[i] = data[i];
    }
    encoded_data[data_size] = crc_remainder(data, data_size, polynomial);
}


int crc_check(uint8_t *data, int data_size, uint8_t polynomial) {
    return crc_remainder(data, data_size, polynomial) == 0;
}

int main() {
    uint8_t  input_byte[DATA_SIZE]  = {0xFF,0xFF,0xFF,0xFF}; 
  
    uint16_t crc_polynomial = 0x107; 

    // Sender's side
    uint8_t encoded_data[DATA_SIZE + CRC_SIZE];
    crc_encode(input_byte, DATA_SIZE, crc_polynomial, encoded_data);
    printf("Encoded Data: ");
    for (int i = 0; i < DATA_SIZE + CRC_SIZE; i++) {
        printf("%02X ", encoded_data[i]);
    }
    printf("\n");

    // Receiver's side
    int is_valid_crc = crc_check(encoded_data, DATA_SIZE + CRC_SIZE, crc_polynomial);
    if (is_valid_crc) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}


