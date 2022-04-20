; WAP to check if a given string is a pallindrome

.data
string db "racecar$"
true db "Given string is a pallindrome$"
false db "Given string is NOT a pallindrome$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset string
    mov di, offset string
    mov dl, offset true
    mov cx, 0

    move_to_end:
        inc si
        inc cx

        cmp [si] , '$'
        jne move_to_end

    check:
        dec si
        mov bh, [si] ; copy last char to BH register
        mov bl, [di] ; copy first char to BL register
        inc di

        cmp bh, bl
        jne not_pallindrome

        loop check

    mov ah, 09h
    int 21h

    mov ah, 0
    int 21h

not_pallindrome:
    mov dl, offset false
    mov ah, 09h
    int 21h

end start
