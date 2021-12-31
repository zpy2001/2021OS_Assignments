.section .rodata
.lcomm  buff, 1
.text
.global _start
_start:
        #number:3 sys_read(0,buff,1)
	movl $3, %eax    
        movl $0, %ebx    # 1st param
        movl $buff, %ecx # 2st param
        movl $1, %edx    # 3st param  
        int $0x80

        #number:4 sys_write(1)
	movl $4, %eax 
        movl $1, %ebx  # 1st param 
        int $0x80
        
	# exit(0)
	movl $1, %eax
	movl $0, %ebx  # 1st param
	int $0x80

