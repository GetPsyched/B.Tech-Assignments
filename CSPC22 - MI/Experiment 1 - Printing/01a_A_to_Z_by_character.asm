; WAP to print the alphabets A-Z by character

.code
start:
    mov dl, 'A'
    mov cl, 26

    L:
        mov ah, 02h
        int 21h
        inc dl
        loop L

end start
