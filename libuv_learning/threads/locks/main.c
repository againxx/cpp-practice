#include <stdio.h>
#include <uv.h>

static uv_barrier_t blocker;
static int shared_num;
static uv_rwlock_t numlock;

void reader(void *n) {
    int num = *(int *)n;
    for (int i = 0; i < 20; ++i) {
        uv_rwlock_rdlock(&numlock);
        printf("Reader %d: acquired lock\n", num);
        printf("Reader %d: shared num = %d\n", num, shared_num);
        uv_rwlock_rdunlock(&numlock);
        printf("Reader %d: release lock\n", num);
    }
    uv_barrier_wait(&blocker);
}

void writer(void *n) {
    int num = *(int *)n;
    for (int i = 0; i < 20; ++i) {
        uv_rwlock_wrlock(&numlock);
        printf("Writer %d: acquired lock\n", num);
        ++shared_num;
        printf("Writer %d: incremented shared num = %d\n", num, shared_num);
        uv_rwlock_wrunlock(&numlock);
        printf("Writer %d: released lock\n", num);
    }
    uv_barrier_wait(&blocker);
}

int main() {
    uv_barrier_init(&blocker, 5);
    shared_num = 0;
    uv_rwlock_init(&numlock);

    uv_thread_t threads[4];

    int thread_nums[] = {1, 2, 1, 2};
    uv_thread_create(&threads[0], reader, &thread_nums[0]);
    uv_thread_create(&threads[1], reader, &thread_nums[1]);

    uv_thread_create(&threads[2], writer, &thread_nums[2]);
    uv_thread_create(&threads[3], writer, &thread_nums[3]);

    uv_barrier_wait(&blocker);
    uv_barrier_destroy(&blocker);

    uv_rwlock_destroy(&numlock);
    return 0;
}
