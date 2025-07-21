void nonRestoringDivision(char* Q, char* M, char* A, int bits) {
    char temp[bits + 1];
    int count = bits; 
    printf("Initial Values: A: %s Q: %s M: %s\n", A, Q, M);
    while (count > 0) {
        if (A[0] == '1') {
            leftShift(A, Q, bits);
            add(A, M, temp, bits);
            strcpy(A, temp);
            printf("After left shift and add: A: %s Q: %s\n", A, Q);
        } else {
            leftShift(A, Q, bits);
            subtract(A, M, temp, bits);
            strcpy(A, temp);
            printf("After left shift and subtract: A: %s Q: %s\n", A, Q);
        }
        if (A[0] == '0') {
            Q[bits - 1] = '1';
        } else {
            Q[bits - 1] = '0';
        }
        count--;
    }
    if (A[0] == '1') {
        add(A, M, temp, bits);
        strcpy(A, temp);
    }
    printf("\nQuotient(Q): ");
    printBinary(Q);
    printf(" Remainder(A): ");
    printBinary(A);
    printf("\n");
}

int main() {
    char dividend[65], divisor[65];
    int bitLength;
    printf("Enter the dividend (binary): ");
    scanf("%s", dividend);
    printf("Enter the divisor (binary): ");
    scanf("%s", divisor);
    bitLength = strlen(dividend);
    char Q[bitLength + 1];
    char M[bitLength + 1];
    char A[bitLength + 1];
    strcpy(Q, dividend);
    strcpy(M, divisor);
    memset(A, '0', bitLength);
    A[bitLength] = '\0';
    nonRestoringDivision(Q, M, A, bitLength);
    return 0;
}
