; WAP to print a 16-bit string using 09h

.data
string dw "Hello, World!$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov dx, offset string

    mov ah, 09h
    int 21h

end start
