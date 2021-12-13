# Exploring the XV6 Scheduler

Resources for downloading the VM:
- Setting Up Vagrant: https://www.taniarascia.com/what-are-vagrant-and-virtualbox-and-how-do-i-use-them/
- Modifying the Memory: https://ostechnix.com/how-to-increase-memory-and-cpu-on-vagrant-machine/

Resources for setting up XV6:
- Guide to setting up XV6 code: https://www.assistedcoding.eu/2017/11/06/install-vx6-operating-system/
- XV6 Codebase: https://github.com/mit-pdos/xv6-public

Significant code 
- Test processes 
  - runnerprog.c
  - shortprocess.c
  - longprocess.c
  - ioheavyprocess.c
- XV6 Modifications 
  - proc.c
    - what changes were made?
  - Makefile
  - Files changes for syscall implementation
    - syscall.c
    - syscall.h
    - sysproc.c
    - user.h
    - usys.S


NOTE: ALL XV6 CODE IS BEING USED FOR EDUCATIONAL PURPOSES. WE CLAIM NO OWNERSHIP OR CREDIT FOR XV6, 
AND ONLY CLAIM TO HAVE MADE CHANGES TO THE FILES LISTED ABOVE. 
