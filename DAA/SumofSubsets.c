#include <stdio.h>

int n, target, found = 0;
int w[10], x[10];

void subsetSum(int idx, int sum) {
    // Base condition
    if (sum == target) {
        printf("\nSubset found: ");
        for (int i = 0; i < idx; i++)
            if (x[i]) printf("%d ", w[i]);
        found = 1;
        return;
    }

    // If we reach end or sum exceeds target → stop
    if (idx == n || sum > target)
        return;

    // Include current element
    x[idx] = 1;
    subsetSum(idx + 1, sum + w[idx]);

    // Exclude current element
    x[idx] = 0;
    subsetSum(idx + 1, sum);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nSubsets with sum = %d:\n", target);
    subsetSum(0, 0);

    if (!found)
        printf("\nNo subset found.\n");

    return 0;
}
