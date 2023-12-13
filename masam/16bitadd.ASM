data segment
        n1 dw 1999h
        n2 dw 0320h
        sum dw ?
        carry db ?
data ends
code segment
assume cs:code,ds:data
    start: mov ax,data
           mov ds,ax
           mov dh,00h     ;clear  dh
           mov ax,n1
           add ax,n2
           jnc ahead
           inc dh
           ahead:mov sum,ax
           mov carry,dh
           mov ah,4ch
           int 21h
           code ends
           end start
