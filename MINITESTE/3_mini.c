#include <stdio.h>
#include <string.h>

int hash(char s[]) {
    int r = 0;
    while (*s) {
        r += *s;
        s++;
    }
    return r;
}

int word(char s[]) {
    int u = strlen(s), total = 0;
    for (int i = 0; s[i]; i++) {
        total += s[i] * (u - i);
    }
    return total;
}

int next(char s[], int n) {
    while (n > 0) {
        n--;
        if (s[n] < 'Z') {
            s[n]++;
            return 1;
        } else if (s[n] == 'Z'){
            s[n] = 'a';
        }
        else if (s[n] < 'z'){
            s[n]++;
            return 1;
        }
        else{
            s[n] = 'A';
        }
    }
    return 0;
}

int main() {
    printf("%d\n",hash ("Aayzz"));
    char s[10];
    int n, i;
    for (n = 0; n < 10; n++) {
        for (i = 0; i < n; i++) s[i] = 'A';
        s[n] = '\0';
        do {
           if (hash (s) == 527) {printf("%s\n", s);return 0;}
        } while (next(s, n));
    }
    return 0;
}
