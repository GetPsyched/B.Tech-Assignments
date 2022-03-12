; Display A-Z by ASCII

.code
start:
    mov dl, 65
    mov cl, 26

    L:
        mov ah, 02h
        int 21h
        inc dl
        loop L

end start