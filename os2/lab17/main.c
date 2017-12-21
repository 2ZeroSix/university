#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t listMut = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t nodeMut = PTHREAD_MUTEX_INITIALIZER;
typedef struct _ListNode {
    char* data;
    pthread_mutex_t mutex;
    struct _ListNode* next;
} ListNode;

ListNode* initListNode() {
    ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
    pthread_mutex_init(&node->mutex, NULL);
    return node;
}

void freeListNode(ListNode* node) {
    pthread_mutex_lock(&nodeMut);
    if (!node || pthread_mutex_lock(&node->mutex))  return;
    pthread_mutex_unlock(&nodeMut);
    if (!node)                                      return;
    pthread_mutex_t mutex = node->mutex;
    free(node);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

typedef struct _List {
    ListNode* head;
    ListNode* tail;
    pthread_mutex_t mutex;
} List;

List* initList() {
    List* list = (List*)calloc(1, sizeof(List));
    pthread_mutex_init(&list->mutex, NULL);
    return list;
}

void pushList(List* list, char* data) {
    pthread_mutex_lock(&listMut);
    if (!list || pthread_mutex_lock(&list->mutex))  return;
    pthread_mutex_unlock(&listMut);
    if (!list)                                      return;
    if (!list->head) {
        list->head = list->tail = initListNode();
    } else {
        list->tail = list->tail->next = initListNode();
    }
    list->tail->data = data;
    pthread_mutex_unlock(&(list->mutex));
}

char* popList(List* list) {
    pthread_mutex_lock(&listMut);
    if (!list || pthread_mutex_lock(&list->mutex))  return NULL;
    pthread_mutex_unlock(&listMut);
    if (!list)                                      return NULL;
    if (!list->head)                                return NULL;
    char* retVal = list->head->data;
    ListNode* tmp = list->head;
    if (list->head == list->tail) list->tail = NULL;
    list->head = list->head->next;
    free(tmp);
    pthread_mutex_unlock(&(list->mutex));
    return retVal;
}

void freeList(List* list) {
    pthread_mutex_lock(&listMut);
    if (!list || pthread_mutex_lock(&list->mutex))  return;
    pthread_mutex_unlock(&listMut);
    if (!list)                                      return;
    ListNode *cur = list->head;
    while(cur) {
        ListNode *tmp = cur;
        cur = cur->next;
        free(tmp->data);
        free(tmp);
    }
    pthread_mutex_t mutex = list->mutex;
    free(list);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

void sortList(List* list, int (*cmp)(const char*, const char*)) {
    pthread_mutex_lock(&listMut);
    if (!list || pthread_mutex_lock(&list->mutex))  return;
    pthread_mutex_unlock(&listMut);
    if (!list)                                      return;
    int count = 0;
    for (ListNode* cur = list->head; cur->next != NULL; cur = cur->next, ++count) {}
    for (int j = 0; j < count; ++j) {
        int flag = 0;
        ListNode* cur = list->head;
        ListNode* prev = NULL;
        for (int i = 0; i < count - j; ++i) {
            if (cmp(cur->data, cur->next->data) > 0) {
                if (prev) {
                    prev->next = cur->next;
                } else {
                    list->head = cur->next;
                }
                prev = cur->next;
                cur->next = cur->next->next;
                prev->next = cur;
                if (i == count - 1) {
                    list->tail = cur;
                }
                flag = 1;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        if (!flag) break;
    }
    pthread_mutex_unlock(&(list->mutex));
}

void printList(List* list) {
    pthread_mutex_lock(&listMut);
    if (!list || pthread_mutex_lock(&list->mutex))  return;
    pthread_mutex_unlock(&listMut);
    if (!list)                                      return;
    for (ListNode* cur = list->head; cur != NULL; cur = cur->next) {
        printf("%s\n", cur->data);
    }
    pthread_mutex_unlock(&(list->mutex));
}

char* readString(FILE* fin) {
    size_t length = 255;
    size_t offset = 0;
    char* str = calloc(length, sizeof(char));
    while(1) {
        if (!fgets(str + offset, length - offset, fin))  {
            free(str);
            return NULL;
        }
        size_t realLength = strlen(str + offset) + offset;
        if ( realLength == length - 1 &&
             str[realLength - 1] != '\n' &&
             !feof(fin)) {
            offset = length-1;
            length = length * 3 / 2;
            str = realloc(str, length);
        } else {
            if (str[realLength - 1] == '\n') str[realLength - 1] = '\0';
            break;
        }
    }
    return str;
}

void* routine(void* list_p) {
    List* list = (List*)list_p;
    while (1) {
        pthread_testcancel();
        sleep(5);
        sortList(list, strcmp);
    }
}

int main(int argc, char** argv) {
    List* list = initList();
    char* str;
    pthread_t thread;
    pthread_create(&thread, NULL, routine, (void*)list);
    while((str = readString(stdin))) {
        if(str[0] == '\0') {
            printList(list);
            continue;
        };
        pushList(list, str);
    }
    pthread_cancel(thread);
    pthread_join(thread, NULL);
    freeList(list);
    pthread_exit(0);
}
