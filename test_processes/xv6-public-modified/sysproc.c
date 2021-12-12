#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint sys_gettime(void) {
  struct rtcdate r = {};

  cmostime(&r);
  uint sincemid = ((r.hour-5) * 60 * 60) + (r.minute * 60) + r.second;
  cprintf("Time: %d:%d:%d", r.hour-5, r.minute, r.second);
  cprintf("This is the time in seconds %d\n", sincemid);
  return sincemid;
}

// uint sys_gettime(void) {   
//   struct rtcdate r = {};   
//   //fill_rtcdate(r);   
//   //r->second = 33;   
//   cmostime(&r);
//   //   uint s = r.second;
//   uint sincemid = (r.hour * 60 * 60) + (r. minute * 60) + r.second;    
//   cprintf("this is the time in seconds %d", sincemid);   
//   //return (y);   
//   return sincemid; }
