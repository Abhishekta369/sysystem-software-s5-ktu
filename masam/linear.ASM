       data segment
       list dw 1234h,3456h,2345h,6798h,8989h
       key dw 8989h
       msg1 db "Found$"
       msg2 db "Not found$" 
data ends
print macro  msg
        lea dx, msg
        mov ah,09h
        int 21h
endm
code segment
assume cs:code,ds:data
    start: mov ax,data
           mov ds,ax
           mov si, offset list
           mov dx,key
           mov cx,0005h
     above:mov ax,[si]
           cmp ax,dx
           je below
           inc si
           inc si
           loop above
           print msg2
           jmp stop
     below:print msg1
          stop:  mov ah,4ch
           int 21h           
           
           code ends
           end start
