
# CRC (Cyclic Redundancy Check) Implementation with Binary Division

This repository contains a C code implementation of a CRC (Cyclic Redundancy Check) algorithm. CRC is a method used in error detection in digital networks or storage devices where it ensures the integrity of transmitted or stored data. This particular implementation performs CRC encoding, decoding, and checking using binary division.

## Introduction
CRC (Cyclic Redundancy Check) is a widely used error-detecting code. It works by generating a checksum (a small, fixed-size binary sequence) based on the data being sent, and appending it to the data. Upon reception, the checksum is recalculated, and if the result does not match the received checksum, an error is detected.

## Features
* __CRC Remainder Calculation__: The crc_remainder() function calculates the CRC remainder for a given set of data and polynomial.
* __CRC Encoding__: The crc_encode() function encodes the input data with CRC information.
* __CRC Checking__: The crc_check() function verifies the integrity of the received data using CRC.
* __Customizable Polynomial__: The polynomial used for CRC computation is customizable, allowing flexibility in different applications.

## CRC Algorithm Overview
The CRC algorithm works by dividing the input data (message) by a predetermined polynomial. The remainder of this division becomes the CRC checksum, which is appended to the original data before transmission. At the receiver's end, the received data along with the CRC checksum is divided by the same polynomial. If the remainder is zero, it indicates that the received data is likely error-free.

## Usage
To use the CRC implementation, follow these steps:
1. __Clone or Download the Repository__: Obtain the source code by cloning the repository to your local machine.
2. __Compile the Code__: Use a C compiler (e.g., gcc) to compile the code.
3. __Customize Parameters__: Define the appropriate input data, polynomial, and CRC size in the main() function before execution.
4. __Execute the Program__: Run the compiled executable.

## Implementation Details
* __Input Data Size__: You can customize the size of the input data by changing the DATA_SIZE macro.
* __CRC Size__: The size of the CRC is defined by the CRC_SIZE macro.
* __Polynomial__: The polynomial used for CRC computation is defined in the main() function as crc_polynomial.

## Example
 Here's a simple example demonstrating the usage of the CRC implementation:

## Manual Calculation
Binary form: *111111111111111111111111111111111* divided by *100000111*

Polynomial: *x^8 + x^2 + x + 1*

Binary form (added zeros): *11111111111111111111111111111111100000000* divided by *100000111*

Result: *111111010000110011011001111100100*
Remainder: *10111100*

Transmitted value: *11111111111111111111111111111111110111100*


## Code Example

```c
//C code
uint8_t input_byte[DATA_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF};
uint16_t crc_polynomial = 0x107;

// Sender's side
uint8_t encoded_data[DATA_SIZE + CRC_SIZE];
crc_encode(input_byte, DATA_SIZE, crc_polynomial, encoded_data);
printf("Encoded Data: ");
// Print encoded data

// Receiver's side
int is_valid_crc = crc_check(encoded_data, DATA_SIZE + CRC_SIZE, crc_polynomial);
if (is_valid_crc) {
    printf("Valid\n");
} else {
    printf("Invalid\n");
}


Feel free to customize the README to include any additional information or instructions you think would be helpful for users of your CRC implementatio
