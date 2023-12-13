data segment
        n1 dw 1234h
        n2 dw 0027h
        prod dw 2 dup(?)
data ends
code segment
assume cs:code,ds:data
    start: mov ax,data
           mov ds,ax
           mov ax,n1
           mov bx,n2
           mul bx
           mov prod,ax
           mov prod+2,dx
           mov ah,4ch
           int 21h      
           code ends
           end start
