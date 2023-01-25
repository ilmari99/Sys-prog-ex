.section .rodata            # define read-only data
msg1: .string "Countdown:"
msg2: .string "%d bottles of beer on the wall, %d bottles of beer. \nTake one down and pass it around, %d bottles of beer on the wall. \n \n"
.data                       # define writable variable
i: .quad 99
.text
.global main
.type   main, @function

main:
  /* for elf-function call compatibility. Do not touch. */
  pushq %rbp
  movq %rsp ,%rbp
  /* Program code starts here */
  loop:
    leaq  msg2(%rip), %rdi  # move msg2 to %rdi (register for parameter 1)
    movq  i(%rip), %rsi     # move i to %rsi (parameter 2)
    movq  i(%rip), %rdx     # Parameter 3 goes to rdx
    subq  $1, i(%rip)       # substract 1 from i.
    movq  i(%rip), %rcx     # Move the subratced i to param 4
    movq  $0, %rax          # zero the %rax register. Do this before calling printf.
    call  printf@PLT        # print the number to terminal. This uses the parameter registers
    //subq  $1, i(%rip)       # substract 1 from i.
    cmpq  $94, i(%rip)       # compare i to 0
    jne   loop              # if i was not equal to 0, jump to loop.
    /* Program code ends here */
  movl  $0, %eax
  leave
  ret   $0