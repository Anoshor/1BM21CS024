#include <stdio.h>

int fr[3];

void display() {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("%d\t", fr[i]);
    }
}

int main() {
    void display();
    int i, j, page[15] = {7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3, top = 0;
    
    for (i = 0; i < 3; i++) {
        fr[i] = -1;
    }
    
    for (j = 0; j < 15; j++) {
        flag1 = 0;
        flag2 = 0;
        
        for (i = 0; i < frsize; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        
        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }
        
        if (flag2 == 0) {
            fr[top] = page[j];
            top = (top + 1) % frsize;  // Corrected the logic here
            pf++;
        }
        
        display();
    }

    printf("\n\nNumber of page faults: %d\n", pf);
    return 0;
}
