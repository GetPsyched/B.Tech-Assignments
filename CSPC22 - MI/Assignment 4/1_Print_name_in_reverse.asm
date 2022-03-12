; Print name in reverse

.data
name db "Priyanshu Tripathi$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset name
    mov cx, 0

    move_to_end:
        inc si
        inc cx

        cmp [si] , '$'
        jne move_to_end

    print_from_end:
        dec si
        mov dl, [si]

        mov ah,02h
        int 21h

        loop print_from_end

end start