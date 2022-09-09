#include <stdio.h>

typedef struct _decrypted {
    char id;
    short area;
    char noOfDistricts;
} decrypted;

typedef union {
    short encrypted;
    decrypted dec;
} UShort;

typedef union {
    int encrypted;
    decrypted dec;
} UReg;

int main() {
    printf("decrypted: %d UShort: %d UReg: %d\n", sizeof(decrypted), sizeof(UShort), sizeof(UReg));
    return 0;
}

// Output from the program:
// decrypted: 6 UShort: 6 UReg: 8
