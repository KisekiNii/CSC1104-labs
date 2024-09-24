#include <math.h>
#include <stdio.h>

int main() {
  int C1, C2, C4, C8, C16;  // parity bit/check bits of original binary data
  int C1p, C2p, C4p, C8p,
      C16p;  // parity bit/check bits of 1-bit error binary data
  int fC1, fC2, fC4, fC8, fC16;  // syndrome word
  int input[16];                 // 8-bit input data without error
  int error_input[16];           // 8-bit input data with 1-bit error
  int position[16] = {11,   101,  110,  111,   1001,  1010,  1011,  1100,
                      1101, 1110, 1111, 10001, 10010, 10011, 10100, 10101};
  // positions of data bits in the table

  printf("\nEnter 16-bit data stream without error: ");  // provide input data

  for (int i = 15; i >= 0; scanf("%1d", &input[i--]));

  printf("\nEnter 16-bit data stream with 1-bit error: ");  // provide input
                                                            // data with
                                                            // 1-bit error
  for (int i = 15; i >= 0; scanf("%1d", &error_input[i--]));

  // check bits, original data
  C1 = input[0] ^ input[1] ^ input[3] ^ input[4] ^ input[6] ^ input[8] ^
       input[10] ^ input[11] ^ input[13] ^ input[15];
  C2 = input[0] ^ input[2] ^ input[3] ^ input[5] ^ input[6] ^ input[9] ^
       input[10] ^ input[12] ^ input[13];
  C4 = input[1] ^ input[2] ^ input[3] ^ input[7] ^ input[8] ^ input[9] ^
       input[10] ^ input[14] ^ input[15];
  C8 = input[4] ^ input[5] ^ input[6] ^ input[7] ^ input[8] ^ input[9] ^
       input[10];

  C16 = input[11] ^ input[12] ^ input[13] ^ input[14] ^ input[15];

  printf("\nC16: %d", C16);
  printf("\nC8: %d", C8);
  printf("\nC4: %d", C4);
  printf("\nC2: %d", C2);
  printf("\nC1: %d", C1);

  // check bits, error data
  C1p = error_input[0] ^ error_input[1] ^ error_input[3] ^ error_input[4] ^
        error_input[6] ^ error_input[8] ^ error_input[10] ^ error_input[11] ^
        error_input[13] ^ error_input[15];
  C2p = error_input[0] ^ error_input[2] ^ error_input[3] ^ error_input[5] ^
        error_input[6] ^ error_input[9] ^ error_input[10] ^ error_input[12] ^
        error_input[13];
  C4p = error_input[1] ^ error_input[2] ^ error_input[3] ^ error_input[7] ^
        error_input[8] ^ error_input[9] ^ error_input[10] ^ error_input[14] ^
        error_input[15];
  C8p = error_input[4] ^ error_input[5] ^ error_input[6] ^ error_input[7] ^
        error_input[8] ^ error_input[9] ^ error_input[10];

  C16p = error_input[11] ^ error_input[12] ^ error_input[13] ^ error_input[14] ^
         error_input[15];

  printf("\nC16p: %d", C16p);
  printf("\nC8p: %d", C8p);
  printf("\nC4p: %d", C4p);
  printf("\nC2p: %d", C2p);
  printf("\nC1p: %d", C1p);

  // syndrome word
  fC1 = C1 ^ C1p;
  fC2 = C2 ^ C2p;
  fC4 = C4 ^ C4p;
  fC8 = C8 ^ C8p;
  fC16 = C16 ^ C16p;

  printf("\n==============================");
  printf("\nC''16: %d", fC16);
  printf("\nC''8: %d", fC8);
  printf("\nC''4: %d", fC4);
  printf("\nC''2: %d", fC2);
  printf("\nC''1: %d", fC1);
  printf(
      "\nSyndrome word indicates that position number: %d%d%d%d%d has an "
      "error.",
      fC16, fC8, fC4, fC2, fC1);

  // convert the syndrome word into the bit position in the table.
  int num, binary_val, decimal_val = 0, base = 1, rem;
  num = (fC16 * 10000 + fC8 * 1000 + fC4 * 100 + fC2 * 10 + fC1 * 1);
  binary_val = num;
  while (num > 0) {
    rem = num % 10;
    decimal_val = decimal_val + rem * base;
    num = num / 10;
    base = base * 2;
  }
  for (int i = 0; i < 16; i++) {
    if (position[i] == binary_val) {  // print out the error bit position
      printf("\nDatabit: %d , at Bit Position %d has an error", i + 1,
             decimal_val);
    }
  }
}