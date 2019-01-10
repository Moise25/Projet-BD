//   % JSON_checker <test/pass1.json

#include <stdlib.h>
#include <stdio.h>
#include "JSON_checker.h"

int main(int argc, char* argv[]) {
//    jc will contain a JSON_checker with a maximum depth of 20.
    JSON_checker jc = new_JSON_checker(20);
    for (;;) {
        int next_char = getchar();
        if (next_char <= 0) {
            break;
        }
        if (!JSON_checker_char(jc, next_char)) {
            fprintf(stderr, "JSON_checker_char: syntax error\n");
            return(1);
        }
    }
    if (!JSON_checker_done(jc)) {
        fprintf(stderr, "JSON_checker_end: syntax error\n");
        return(1);
    }
	else printf("pas d'erreur,syntaxe correcte en input \n");
}
