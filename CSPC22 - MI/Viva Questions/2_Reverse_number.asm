; WAP to reverse the given number - 391992

.data
number db "391992$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset number
    mov cx, 0

    move_to_end:
        inc si
        inc cx

        cmp [si] , '$'
        jne move_to_end

    print_from_end:
        dec si
        mov dl, [si]

        mov ah, 02h
        int 21h

        loop print_from_end

end start