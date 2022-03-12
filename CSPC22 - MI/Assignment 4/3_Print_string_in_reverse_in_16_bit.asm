; Print string in reverse in 16-bit

.data
string dw "Hello, World!$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset string
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