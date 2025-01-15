INCLUDE Irvine32.inc
.data
arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20
searchValue WORD ?

inputMessage BYTE "Enter value to be found: ", 0
foundMessage BYTE " found", 0
notFoundMessage BYTE " not found", 0

.code
    main PROC

    mov eax, 0
    mov edx, OFFSET inputMessage
    call writestring
    call readdec
    mov searchValue, ax

    mov esi, OFFSET arr
    mov ecx, LENGTHOF arr
    comparisionLoop:
        mov ax, [esi]
        cmp ax, searchValue
        je found
        
        add esi, 2
        loop comparisionLoop

    ; Value not found
    call crlf
    mov ax, searchValue
    call writedec

    mov edx, OFFSET notFoundMessage
    call writestring
    call crlf
    jmp exitProgram

    found:
        call crlf
        mov ax, searchValue
        call writedec

        mov edx, OFFSET foundMessage
        call writestring
        call crlf

    exitProgram:
    exit
    main ENDP
END main