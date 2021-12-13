# Exploring the XV6 Scheduler

Resources for downloading the VM:
- Setting Up Vagrant: https://www.taniarascia.com/what-are-vagrant-and-virtualbox-and-how-do-i-use-them/
- Modifying the Memory: https://ostechnix.com/how-to-increase-memory-and-cpu-on-vagrant-machine/

Resources for setting up XV6:
- Guide to setting up XV6 code: https://www.assistedcoding.eu/2017/11/06/install-vx6-operating-system/
- XV6 Codebase: https://github.com/mit-pdos/xv6-public

Significant Code Changes
- Test processes 
  - runnerprog.c
  - shortprocess.c
  - longprocess.c
  - ioheavyprocess.c
- XV6 Modifications 
  - proc.c
  - Files changes for syscall implementation
    - syscall.c
    - syscall.h
    - sysproc.c
    - user.h
    - usys.S
  - Makefile


NOTE: ALL XV6 CODE IS BEING USED FOR EDUCATIONAL PURPOSES. WE CLAIM NO OWNERSHIP OR CREDIT FOR XV6, 
AND ONLY CLAIM TO HAVE MADE CHANGES TO THE FILES LISTED ABOVE. 

#Other Sources Used 
https://wiki.osdev.org/Scheduling_Algorithms
https://pdos.csail.mit.edu/6.828/2016/homework/xv6-syscall.html
https://pdos.csail.mit.edu/6.828/2014/xv6/book-rev8.pdf
https://pages.cs.wisc.edu/~remzi/Classes/537/Spring2016/Projects/p2b.html
http://www.cs.binghamton.edu/~kchiu/cs550/prog/2/
https://viduniwickramarachchi.medium.com/how-to-add-a-user-program-to-xv6-1209069feee4
https://ampleux.wordpress.com/2018/03/07/add-a-new-system-call-in-xv6/
http://pages.cs.wisc.edu/~cs537-3/Projects/p2b.html

