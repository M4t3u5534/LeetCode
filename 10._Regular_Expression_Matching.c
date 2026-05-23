#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool isMatchRecursive(char* s, char* p, int sp, int pp, int len_s, int len_p) {
    if (pp > len_p && sp == len_s) return true;
    if (pp > len_p) return false;
    if (p[pp] == '*') {
        for (int i = sp; i <= len_s; i++) {
            if (isMatchRecursive(s, p, i, pp+2, len_s, len_p)) return true;
            if (s[i] != p[pp-1] && p[pp-1] != '.') return false;
        }
    } 
    else {
        if (sp == len_s) return false;
        if (s[sp] == p[pp-1] || p[pp-1] == '.') return isMatchRecursive(s, p, sp+1, pp+1, len_s, len_p);
    }
    return false;
}

bool isMatch(char* s, char* p) {
    int len_s = strlen(s);
    int len_p = strlen(p);

    return isMatchRecursive(s, p, 0, 1, len_s, len_p);
}

int main() {
    char *s = "mississippi";
    char *p = "mis*is*ip*.";

    printf("Status: %s\n", isMatch(s, p) ? "true" : "false");
}