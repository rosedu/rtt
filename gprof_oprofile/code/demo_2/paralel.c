#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
 
#define BIGNUM           (1 << 30) // limita superioară a intervalului de prelucrare
#define NR_CPUS           2
#define NR_THREADS        NR_CPUS
#define PER_CPU_INTERVAL (BIGNUM / NR_THREADS) //lungimea intervalului pe care va căuta fiecare thread
 
struct thd_data {
  int div2;
  int div3;
  int padding[500];
};
 
struct thd_data per_cpu_vec[NR_THREADS];
pthread_t threads[NR_THREADS];
 
/**
 * Se impune threadului `thdid` să ruleze doar pe procesorul `thdid % NR_CPUS`.
 * Dacă există procesoare >= threaduri, fiecare thread va rula pe un procesor separat.
 */
static void set_affinity(int thdid)
{
  int rc;
  cpu_set_t cmask;
  CPU_ZERO(&cmask);
  CPU_SET(thdid % NR_CPUS, &cmask);
  rc = sched_setaffinity(0 /*current thead*/, sizeof(cpu_set_t), &cmask);
  if (-1 == rc)
    perror("sched_setaffinity error");
}
 
 
static void * thd_func(void *param)
{
  int thdid = (int)param;
  int i;
  /* Fiecare thread operează pe o porțiune distinctă a intervalului. */
  int start = thdid       * PER_CPU_INTERVAL;
  int stop  = (thdid + 1) * PER_CPU_INTERVAL;
 
  set_affinity(thdid);
 
  for (i = start; i < stop; i++) {
    if (i % 2 == 0)
      per_cpu_vec[thdid].div2 ++;
    if (i % 3 == 0)
      per_cpu_vec[thdid].div3 ++;
  }
 
  return NULL;
}
 
 
int main()
{
  int rc, i, sum;
 
  /* se creează threadurile */
  for (i = 0; i < NR_THREADS; i++) {
    rc = pthread_create(&threads[i], NULL, thd_func, (void*)i);
    if (-1 == rc) {
      perror("error creating thread");
      exit(-1);
    }
  }
 
 
  /* se așteaptă ca toate threadurile să-și termine execuția */
  for (i = 0; i < NR_THREADS; i++) {
    rc = pthread_join(threads[i], NULL);
    if (-1 == rc) {
      perror("error joining thread");
      exit(-1);
    }
  }
 
 
  /* se integrează rezultatele parțiale ale fiecărui thread */
  sum = 0;
  for (i = 0; i < NR_THREADS; i++) {
    sum += per_cpu_vec[i].div2;
  }
  printf("div2=%d, ", sum);
 
  sum = 0;
  for (i = 0; i < NR_THREADS; i++) {
    sum += per_cpu_vec[i].div3;
  }
  printf("div3=%d\n", sum);
  return 0;
}
