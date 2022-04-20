; WAP to print a 16-bit string character-wise

.data
string dw "Hello, World!$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset string

    L:
        mov dx, [si]
        mov ah, 02h
        int 21h
        inc si

        cmp [si], '$'
        jnz L

end start
