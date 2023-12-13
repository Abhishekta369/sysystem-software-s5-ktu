data segment
        n1 dw 0003h
        n2 dw 0007h
        diff dw ?
        borrow db ?
data ends
code segment
assume cs:code,ds:data
    start: mov ax,data
           mov ds,ax
           mov dh,00h     ;clear  dh
           mov ax,n1
           sub ax,n2
           jnc ahead
           inc dh
    ahead:mov diff,ax
           mov borrow,dh
           mov ah,4ch
           int 21h
           code ends
           end start   
