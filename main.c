#include <stdio.h>

int main() {
    const char *file_in = "test.txt";
    const char *file_out = "output.txt";

    FILE *fp_in = fopen(file_in, "r");
    FILE *fp_out = fopen(file_out, "w");

    fseek(fp_in, -1, SEEK_END);
    while(ftell(fp_in)) {
        fputc(fgetc(fp_in), fp_out);
        fseek(fp_in, -2, SEEK_CUR);
    }
    fputc(fgetc(fp_in), fp_out);

    fclose(fp_out);
    fclose(fp_in);
}
