; WAP to print a string character-wise

.data
string db "Hello, World!$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset string

    L:
        mov dl, [si]
        mov ah, 02h
        int 21h
        inc si

        cmp [si], '$'
        jnz L

end start
