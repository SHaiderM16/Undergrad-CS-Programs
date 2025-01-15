.686            ; Target processor. Use instructions for Pentium class machines
.MODEL FLAT, C  ; Use the flat memory model. Use C calling conventions
.STACK 2048     ; Define a stack segment of 1KB (Not required for this example)

.DATA           ; Create a near data segment. Local variables are declared after

.CODE
GCD PROC
    ; Check if either EAX or EBX is 0
    TEST EAX, EAX
    jz setToZero
    TEST EBX, EBX
    jz setToZero

    GCDLoop:
        TEST EBX, EBX
        jz GCDDone

        ; EAX % EBX
        XOR EDX, EDX
        DIV EBX

        MOV EAX, EBX
        MOV EBX, EDX
        JMP GCDLoop

    GCDDone:
        ret

    setToZero:
        MOV EAX, 0
        ret
GCD ENDP

END