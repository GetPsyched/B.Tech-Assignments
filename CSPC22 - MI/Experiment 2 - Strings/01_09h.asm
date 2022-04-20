; WAP to print a string using 09h

.data
string db "Hello, World!$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov dl, offset string

    mov ah, 09h
    int 21h

end start
