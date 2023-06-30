#include <errno.h>
#include <stdio.h>
#include <string.h>

int writeData(FILE *fp, char *data, size_t datalength) {
    fwrite(data, sizeof(char), datalength, fp);
}

int main(int argc, char **argv) {
    FILE *fp = fopen("hello", "w+");
    if (errno != 0) {
        char *errmsg = "Something happened...";
        fwrite(errmsg, sizeof(char), sizeof(errmsg), stdin);
    }
    fprintf(stdout, "Writing to file \"hello\"...\n");
    fflush(stdout);

    // argv[1] should be the string we want to write.
    // Include the null terminator.
    writeData(fp, argv[1], strlen(argv[1]) + 1);
    fclose(fp);
    fprintf(stdout, "Closed file \"hello\"...\n");
    fflush(stdout);
}

