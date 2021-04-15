#include "testStack.h"

main() {
	Stack s = { NULL };
	testPush(&s);
	testPop(&s);
	testPeek(&s);
	testIsEmpty(&s);

    int i = 0, j = 0, k = 0, a = 0, b = 0, value = 0;
    hStack top1 = initStack();
    hStack top2 = initStack();
    hStack top3 = initStack();
    printf("Enter number of disks:");
    scanf("%d", &i);

    for (j = 0; j < i; j++)
        hpush(&top1, j);

    display(&top1);
    display(&top2);
    display(&top3);

    for (k = 1; k < 1 << i; k++) {
        a = (k & k - 1) % 3;
        b = ((k | k - 1) + 1) % 3;

        switch (a) {
        case 0:
            value = hpop(&top1);
            break;
        case 1:
            value = hpop(&top2);
            break;
        case 2:
            value = hpop(&top3);
            break;
        }

        switch (b) {
        case 0:
            hpush(&top1, value);
            break;
        case 1:
            hpush(&top2, value);
            break;
        case 2:
            hpush(&top3, value);
            break;
        }

        display(&top1);
        display(&top2);
        display(&top3);
        printf("\n");
    }

	return 0;
}