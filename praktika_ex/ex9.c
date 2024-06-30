#include <stdio.h>

void compress_bits(unsigned char* input, int input_size) {
    int i = 0;
    while(i < input_size) {
        unsigned char curr_bit = input[i];
        int count = 1;

        while(i + 1 < input_size && input[i + 1] == curr_bit && count < 15) {
            count++;
            i++;
        }

        printf("%d%d ", count, curr_bit);
        i++;
    }

    printf("\n");
}

int main() {
    unsigned char input[] = {1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1}; // Пример неупакованного двоичного массива
    int input_size = sizeof(input) / sizeof(input[0]);

    compress_bits(input, input_size);

    return 0;
}