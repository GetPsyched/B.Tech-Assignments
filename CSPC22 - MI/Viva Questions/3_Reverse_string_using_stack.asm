; WAP to reverse the string using stack

.data
string db "Hello, World!$"

.code
start:
    mov ax, @data
    mov ds, ax
    mov si, offset string
    mov si, 0
    mov bx, sp ; save original location of the stack pointer for comparison

    push_to_stack:
        inc si
        push [si]

        cmp [si] , '$'
        jne push_to_stack

    ; pop the '$' from the stack
    pop dx

    print_from_end:
        pop dx
        mov ah, 02h
        int 21h

        cmp sp, bx
        jne print_from_end

    ; print last character
    pop dx
    mov ah, 02h
    int 21h

end start