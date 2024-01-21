#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n > 0) {
        towerOfHanoi(n - 1, source, target, auxiliary);
        printf("Move disk %d from %c to %c\n", n, source, target);
        towerOfHanoi(n - 1, auxiliary, source, target);
    }
}

int main() {
    int n = 3; // Number of disks
    char source = 'A', auxiliary = 'B', target = 'C';

    printf("Tower of Hanoi solution:\n");
    towerOfHanoi(n, source, auxiliary, target);

    return 0;
}
