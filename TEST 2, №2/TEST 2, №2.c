#include <stdio.h>
#include <malloc.h>


struct list {
    int data;
    struct list* next;
};

struct list* create(int a) {
    struct list* root;
    root = (struct list*)malloc(sizeof(struct list));
    root->data = a;
    root->next = NULL;
    return root;
}

struct list* insert(struct list* node, int data) {
    struct list* tmp = (struct list* )malloc(sizeof(struct list));
    if (tmp != NULL) {
        tmp->data = data;

        if (node != NULL) {
            tmp->next = node->next;
            node->next = tmp;
        }
        else {
            tmp->next = NULL;
        }
    }
    return tmp;
}

void output(struct list* node) {
    for (; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
}

struct list* remove(struct list* node) {
    while (node != NULL) {
        struct list* tmp = node;
        node = node->next;
        free(tmp);
    }

    return node;
}

struct list* InsertionSort(struct list* root) {
    struct list* newRoot = NULL;
    while (root != NULL) {
        struct list* node = root;
        root = root->next;
        if (newRoot == NULL || node->data < newRoot->data) {
            node->next = newRoot;
            newRoot = node;
        }
        else {
            struct list* current = newRoot;
            while (current->next != NULL && !(node->data < current->next->data)) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }
    return newRoot;
}

int main() {
    int arrayLen = 0;
    printf("Enter the length of the array: ");
    scanf_s("%d", &arrayLen);
    int* array = (int*)malloc(arrayLen * sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < arrayLen; i++) {
        scanf_s("%d", &array[i]);
    }
    struct list* root = NULL;
    struct list** tmp = &root;

    for (size_t i = 0; i < arrayLen; i++) {
        *tmp = insert(*tmp, array[i]);
        tmp = &(*tmp)->next;
    }
    printf("List: ");
    output(root);
    printf("\n");
    root = InsertionSort(root);
    printf("Sorted list: ");
    output(root);
    printf("\n");
    root = remove(root);
}