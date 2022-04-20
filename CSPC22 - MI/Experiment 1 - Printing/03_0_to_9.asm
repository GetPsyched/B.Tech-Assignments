; WAP to print the numbers from 0-9

.code
start:
    mov dl, '0'
    mov cl, 10

    L:
        mov ah, 02h
        int 21h
        inc dl
        loop L

end start
