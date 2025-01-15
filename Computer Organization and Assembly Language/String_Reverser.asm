INCLUDE Irvine32.inc

.data
string1 BYTE 'Haider', 0
string2 BYTE 7 DUP(0)

.code
    main PROC

    MOV esi, OFFSET string1
    MOV edi, OFFSET string2
    MOV ecx, 6                      ; String length

    CALL Str_Reverse
        
    MOV edx, OFFSET string2
    CALL WriteString
    CALL crlf
    
    exit
    main ENDP

    Str_Reverse PROC
        PUSH esi
        PUSH edi
        PUSH ecx

        ADD esi, ecx                    ; Point to end of source string (null terminator)
        DEC esi                         ; Last character

    reverseLoop:
        MOV al, [esi]
        MOV [edi], al
        DEC esi
        INC edi
        LOOP reverseLoop

        MOV BYTE PTR [edi], 0           ; Add null terminator

        ; Restore registers
        POP ecx
        POP edi
        POP esi

        RET
    Str_Reverse ENDP

END main