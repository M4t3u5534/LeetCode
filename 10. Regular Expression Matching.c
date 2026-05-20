#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    size_t len_s = strlen(s);
    size_t len_p = strlen(p);

    size_t ps = 0;
    size_t pp = 0;

    while (ps < len_s) {
        for (pp; pp < len_p && p[pp] != '*'; pp++);
        if (pp >= len_p) {
            for (ps; ps < pp; ps++) {
                if (p[ps] == '.') continue;
                if (s[ps] != p[ps] || ps >= len_s) return false;
            }
            if (ps != len_s) return false;
        } else {
            for (ps; ps < pp - 1; ps++) {
                if (p[ps] == '.') continue;
                if (s[ps] != p[ps] || ps >= len_s) return false;
            }
            char var = p[pp - 1];
            if (pp == len_p - 1 && var == '.') return true;
            if (var == '.') {
                while (s[ps] != p[pp] && ps < len_s) ps++;
                if (ps >= len_s) return false;
            } else {
                while (s[ps] == var) ps++;
                pp++;
            }
        }
    }
    return true;
}