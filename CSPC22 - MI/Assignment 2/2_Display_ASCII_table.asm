; Display ASCII table

.code
start:
    mov dl, 0
    mov cx, 256

    L:
        mov ah, 02h
        int 21h
        inc dl
        loop L

end start