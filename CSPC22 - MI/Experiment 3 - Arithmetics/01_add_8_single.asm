; WAP to add two 8-bit single-digit numbers

.data
num1 DB 8
num2 DB 8

.code
start:
    MOV AX, data
    MOV DS, AX

    MOV AL, num1
    ADD AL, num2 ; Adding num1 and num2

    ; Calculating remainder (2nd digit) and storing it in BL
    MOV AH, 00
    MOV BL, 10
    DIV BL
    MOV BL, AH

    ; If the result is single-digit, print only 1 digit
    CMP AL, 00
    JE print2nd

    ; Printing first digit
    MOV DL, AL
    ADD DL, 48
    MOV AH, 02
    INT 21h

    print2nd:
        ; Printing second digit
        MOV DL, BL
        ADD DL, 48
        MOV AH, 02
        INT 21h

END start
