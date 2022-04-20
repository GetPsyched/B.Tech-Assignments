; WAP to print the pattern AbCdEf...

.code
start:
    mov dl, 'A'
    mov cl, 13

    L:
        mov ah, 02h
        int 21h
        inc dl

        add dl, 32
        mov ah, 02h
        int 21h

        sub dl, 32
        inc dl
        loop L

end start
