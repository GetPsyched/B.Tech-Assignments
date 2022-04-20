; WAP to print the pattern AaBbCc...

.code
start:
    mov dl, 'A'
    mov cl, 26

    L:
        mov ah, 02h
        int 21h

        add dl, 32

        mov ah, 02h
        int 21h

        sub dl, 32
        inc dl
        loop L

end start
