
#include <stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    
    printf("\nEnter the number of pages: ");
    scanf("%d", &n);
    
    printf("\nEnter the page numbers: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("\nEnter the number of frames: ");
    scanf("%d", &no);
    
    for (i = 0; i < no; i++) {
        frame[i] = -1;
    }

    j = 0;
    printf("\nRef_String\tPage_Frames\n");
    
    for (i = 1; i <= n; i++) {
        printf("%d\t", a[i]);
        avail = 0;
        
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
            
            for (k = 0; k < no; k++) {
                printf("%d\t", frame[k]);
            }
        } else {
            printf("Hit");
        }

        printf("\n");
    }
    
    printf("\nPage fault is %d", count);
    printf("\n");
    
    return 0;
}

	

