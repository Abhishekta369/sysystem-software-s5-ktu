data segment
        n1 dd 121234h
        n2 dw 1207h
        quotient dw ?
        remainder dw ?
data ends
code segment
assume cs:code,ds:data
    start: mov ax,data
           mov ds,ax
           mov si,offset n1
           mov ax,[si]
           mov dx,[si+2]
           mov bx,n2
           div bx
           mov quotient,ax
           mov remainder,dx
           mov ah,4ch
           int 21h      
           code ends
           end start
