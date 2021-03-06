//
// Created by hareld10 on 4/29/18.
//

#ifndef OSEX2_THREADS_H
#define OSEX2_THREADS_H
#include <vector>
#include <sys/time.h>
#include "Thread.h"
#include <iostream>
#include <queue>

#define FAIL_CODE (-1)
#define MAX_THREAD_NUM 100 /* maximal number of threads */


class Threads
{


public:
    static int total_num_of_threads;
    static std::priority_queue<int, std::vector<int>,  std::greater<int>> pq;
    static std::vector<int> *syncing[];
    static std::deque<Thread*> *_ready_threads;
    static std::deque<Thread*> *_blocked_threads;
    static Thread *_running_thread;

    static void init();
    ~Threads();
    static void addTid(int tid);
    static void add_ready(Thread* thread);
    static void add_blocked(Thread* thread);
    static int remove_blocked_thread(int id);
    static int remove_ready_thread(int id);
    static int sum_all_usec();
    static int sum_by_id(int tid);
    static void sync(int tid);
    static Thread* get_thread(int tid);
    static Thread* get_thread_ptr(int tid);
    static bool exist_by_id_ready(int id);
    static bool exist_by_id_blocked(int id);
    static int get_next_id();
    static void setRunningThread(Thread* thread);
    static int running_thread_id();
    static Thread* getReadyThread();
    static void free_syncing_threads(int tid);
    static Thread* get_running_thread();
    static bool is_synced(int tid);

};


#endif //OSEX2_THREADS_H
