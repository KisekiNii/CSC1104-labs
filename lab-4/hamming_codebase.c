#include <math.h>
#include <stdio.h>

int main() {
  // ------------ don't modify codes below ----------------------
  int C1, C2, C4, C8;      // parity bit/check bits of original binary data
  int C1p, C2p, C4p, C8p;  // parity bit/check bits of 1-bit error binary data
  int fC1, fC2, fC4, fC8;  // syndrome word
  int input[8];            // 8-bit input data without error
  int error_input[8];      // 8-bit input data with 1-bit error
  int position[16] = {11,   101,  110,  111,   1001,  1010,  1011,  1100,
                      1101, 1110, 1111, 10001, 10010, 10011, 10100, 10101};
  // positions of data bits in the table

  printf("\nEnter 8-bit data stream without error: ");  // provide input data
                                                        // without error
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d", &input[7], &input[6], &input[5], &input[4],
        &input[3], &input[2], &input[1], &input[0]);

  printf("\nEnter 8-bit data stream with 1-bit error: ");  // provide input data
                                                           // with 1-bit error
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d", &error_input[7], &error_input[6],
        &error_input[5], &error_input[4], &error_input[3], &error_input[2],
        &error_input[1], &error_input[0]);

  // ------------ADD your codes below ----------------------
  // calculate parity bits of data without error; and print out them on screen
  // in C code, in C code, use ^ for XOR operation. e.g., c1 = D1 ^ D2
  C1 = input[0] ^ input[1] ^ input[3] ^ input[4] ^ input[6];
  C2 = input[0] ^ input[2] ^ input[3] ^ input[5] ^ input[6];
  C4 = input[1] ^ input[2] ^ input[3] ^ input[7];
  C8 = input[4] ^ input[5] ^ input[6] ^ input[7];

  // ------------Print out the old parity bits (i.e., check bits). Don't modify
  // codes below ----------------------
  printf("\nC8: %d", C8);
  printf("\nC4: %d", C4);
  printf("\nC2: %d", C2);
  printf("\nC1: %d", C1);

  // calculate parity bits of data with 1-bit error; and print out them on
  // screen
  C1p = error_input[0] ^ error_input[1] ^ error_input[3] ^ error_input[4] ^
        error_input[6];
  C2p = error_input[0] ^ error_input[2] ^ error_input[3] ^ error_input[5] ^
        error_input[6];
  C4p = error_input[1] ^ error_input[2] ^ error_input[3] ^ error_input[7];
  C8p = error_input[4] ^ error_input[5] ^ error_input[6] ^ error_input[7];

  // ------------Print out the new parity bits (i.e., check bits). Don't modify
  // codes below ----------------------
  printf("\nC8p: %d", C8p);
  printf("\nC4p: %d", C4p);
  printf("\nC2p: %d", C2p);
  printf("\nC1p: %d", C1p);

  // calculate the syndrome word; and print out them on screen
  fC8 = C8 ^ C8p;  // fC8 = C8 XOR C8p
  fC4 = C4 ^ C4p;
  fC2 = C2 ^ C2p;
  fC1 = C1 ^ C1p;

  // ------------Print out the derived syndrome word. Don't modify
  // codes below ---------------
  printf("\n==============================");
  printf("\nC''8: %d", fC8);
  printf("\nC''4: %d", fC4);
  printf("\nC''2: %d", fC2);
  printf("\nC''1: %d", fC1);
  printf(
      "\nSyndrome word indicates that position number: %d%d%d%d has an error.",
      fC8, fC4, fC2, fC1);

  // ------------ don't modify codes below ----------------------
  // convert the syndrome word into the bit position in the table.
  int num, binary_val, decimal_val = 0, base = 1, rem;
  num = (fC8 * 1000 + fC4 * 100 + fC2 * 10 + fC1 * 1);
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
  return 0;
}
