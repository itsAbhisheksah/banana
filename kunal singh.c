#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct list {
    int item[SIZE];
    int len;
} list;

void create(list *pl) {
    pl->len = 0;
}
int insert(list *pl, int k, int value) {
    int i;
    if (pl->len < 0 || k > pl->len || pl->len >= SIZE)
        return 0;
    if (pl->len == 0) {
        pl->item[0] = value;
        pl->len++;
        return 1;
    }
    for (i = pl->len - 1; i >= k; i--)
        pl->item[i + 1] = pl->item[i];
    pl->item[i + 1] = value;
    pl->len++;
    return 1;
}
int del(list *pl, int k, int *status) {
    int i, x;
    if (k < 0 || k >= pl->len) {
        *status = 0;
    } else {
        x = pl->item[k];
        for (i = k + 1; i < pl->len; i++)
            pl->item[i - 1] = pl->item[i];
        pl->len--;
        *status = 1;
        return x;
    }
}
void display(list l) {
    int i;
    if (l.len == 0)
        printf("List is empty\n");
    else {
        printf("\nThe list is:\n");
        for (i = 0; i < l.len; i++)
            printf("%d\t", l.item[i]);
    }
    printf("\n");
}

void printFrequency(list l) {
    int i, j, count;
    printf("\nFrequency of each element:\n");
    for (i = 0; i < l.len; i++) {
        count = 1;
        for (j = i + 1; j < l.len; j++) {
            if (l.item[i] == l.item[j]) {
                count++;
                // Avoid counting same element again
                l.item[j] = l.item[l.len - 1];
                l.len--;
            }
        }
        printf("%d occurs %d times\n", l.item[i], count);
    }
}

void appendList(list *l1, list *l2) {
    int i;
    if ((l1->len + l2->len) > SIZE) {
        printf("Appending lists exceeds maximum size\n");
        return;
    }
    for (i = 0; i < l2->len; i++) {
        l1->item[l1->len++] = l2->item[i];
    }
}

void createArray(list l, int arr[], int *size) {
    int i;
    for (i = 0; i < l.len; i++)
        arr[(*size)++] = l.item[i];
}

int main() {
    list l;
    int r, k, m, i, op, rs;
    create(&l);
    while (1) {
        printf("\nMENU\n1: Insert\n2: Delete\n3: Display\n4: Print Frequency\n5: Append List\n6: Create Array\n7: Quit\n ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Enter the position of insertion.\n");
                scanf("%d", &k);
                printf("Enter the element to be inserted.\n");
                scanf("%d", &m);
                r = insert(&l, k, m);
                if (r)
                    printf("%d inserted successfully\n", m);
                else
                    printf("Insertion fails.\n");
                break;
            case 2:
                printf("Enter the position of deletion.\n");
                scanf("%d", &k);
                r = del(&l, k, &rs);
                if (rs)
                    printf("Deleted element is %d\n", r);
                else
                    printf("Deletion fails.\n");
                break;
            case 3:
                display(l);
                break;
            case 4:
                printFrequency(l);
                break;
            case 5: {
                list l2;
                printf("Creating list l2 for appending:\n");
                create(&l2);
                printf("Enter the number of elements in l2:\n");
                scanf("%d", &l2.len);
                printf("Enter the elements of l2:\n");
                for (i = 0; i < l2.len; i++)
                    scanf("%d", &l2.item[i]);
                appendList(&l, &l2);
                printf("Lists appended successfully.\n");
                break;
            }
            case 6: {
                int arr[SIZE];
                int size = 0;
                createArray(l, arr, &size);
                printf("Array created successfully from the list.\n");
                printf("Elements of the array are:\n");
                for (i = 0; i < size; i++)
                    printf("%d\t", arr[i]);
                printf("\n");
                break;
            }
            case 7:
                exit(0);
        }
    }
}
