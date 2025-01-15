INCLUDE Irvine32.inc
.data
array DWORD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20

minMessage BYTE "The minimum value in the array is ", 0
maxMessage BYTE "The maximum value in the array is ", 0

.code
    main PROC

    push OFFSET array
    call MinMaxArray

    exit
    main ENDP

    MinMaxArray PROC
        push EBP
        mov EBP, ESP

        mov ESI, [EBP + 8]

        mov EAX, [ESI]
        mov EDI, EAX
        mov EBX, EAX
        add ESI, TYPE DWORD   ; Move to the next element

        mov ECX, 19
    Loop1:
        mov EAX, [ESI]

        cmp EAX, EDI
        jl UpdateMin
        jmp CheckMax

    UpdateMin:
        mov EDI, EAX

    CheckMax:
        cmp EAX, EBX
        jg UpdateMax
        jmp ContinueLoop

    UpdateMax:
        mov EBX, EAX

    ContinueLoop:
        add ESI, TYPE DWORD
        LOOP Loop1

        mov EDX, OFFSET minMessage
        call WriteString
        mov EAX, EDI
        call WriteDec
        call crlf

        mov EDX, OFFSET maxMessage
        call WriteString
        mov EAX, EBX
        call WriteDec
        call crlf

        pop EBP
        ret
    MinMaxArray ENDP

END main