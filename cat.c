#include <stdio.h>
#include <string.h>

void
concat(FILE *ifp, FILE *ofp) {

	char chr;

	while((chr = fgetc(ifp)) != EOF) {
		fputc(chr, ofp);
	}
}

int
main(int argc, char **argv) {
	FILE *fp;

	if (argc < 2) {
		concat(stdin, stdout);
	}
	else {
		while(*++argv) {
		
			if( (strcmp(*argv, "-")) == 0)
				concat(stdin, stdout);
			else if ((fp = fopen(*argv, "r")) != NULL) {
				concat(fp, stdout);
				fclose(fp);
			}
			else
				return 1;
		}
	}
	return 0;
}
