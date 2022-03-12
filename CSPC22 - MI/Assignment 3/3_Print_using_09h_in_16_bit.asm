; Print using 09h in 16-bit

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