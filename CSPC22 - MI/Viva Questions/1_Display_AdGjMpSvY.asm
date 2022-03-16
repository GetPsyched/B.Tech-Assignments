; Print AdGjMp...

.code
start:
    mov dl, 'A'
    mov cl, 5

    L:
        mov ah, 02h
        int 21h

        add dl, 35

        mov ah, 02h
        int 21h

        sub dl, 29

        loop L

end start