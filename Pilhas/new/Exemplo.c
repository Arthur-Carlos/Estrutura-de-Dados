//Codeforces 797C: Minimal String
#include <stdio.h>
#include <string.h>

#define MAXN 100005

char s[MAXN], t[MAXN], u[MAXN];
int count[26];

int main() {
    if (scanf("%s", s) != 1) return 0;
    int n = strlen(s);
    
    // Count frequency of each character to track what's left in s
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    int top = -1; // Stack pointer for t
    int u_idx = 0; // Index for result string u
    int s_idx = 0; // Index for source string s
    int min_char = 0; // Smallest char currently in s

    while (s_idx < n || top != -1) {
        // Find the smallest character still available in string s
        while (min_char < 26 && count[min_char] == 0) {
            min_char++;
        }

        // Case 1: Stack top is small enough to move to u
        if (top != -1 && (t[top] - 'a' <= min_char)) {
            u[u_idx++] = t[top--];
        } 
        // Case 2: Move from s to t until we hit the smallest char
        else if (s_idx < n) {
            count[s[s_idx] - 'a']--;
            t[++top] = s[s_idx++];
        } 
        // Case 3: s is empty, drain the rest of the stack
        else {
            u[u_idx++] = t[top--];
        }
    }

    u[u_idx] = '\0';
    printf("%s\n", u);
    
    return 0;
}
