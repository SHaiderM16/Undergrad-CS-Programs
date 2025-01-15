INCLUDE Irvine32.inc
.data

.code
    main PROC

    ; Write ASM instructions that calculate EAX * 21 using binary multiplication.

    mov eax, 1      ; Value hardcoded
    mov ebx, eax
    mov edx, eax

    SHL ebx, 4      ; 1 * (2^4) = 16
    SHL edx, 2      ; 1 * (2^2) = 4

    ADD eax, ebx    ; 1 + 16 = 17
    ADD eax, edx    ; 17 + 4 = 21

    SHL eax, 0      ; 21 * (2^0) = 21, no effect on answer

    call writedec
    call crlf

    exit
    main ENDP
END main