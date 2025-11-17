#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    double sum = 0.0;
    double v[n];

    for (int i = 0; i < n; i++)
        scanf("%lf", &v[i]);

    for (int i = 0; i < n; i++) {
        sum += v[i];

        if (i >= k)
            sum -= v[i - k];

        int window_size = (i + 1 < k) ? (i + 1) : k;

        printf("%.4lf\n", sum / window_size);
    }

    return 0;
}
