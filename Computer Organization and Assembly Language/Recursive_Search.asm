INCLUDE Irvine32.inc

.data
    array DWORD 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200
    arraySize DWORD LENGTHOF array
    prompt BYTE "Enter an integer to search in the array: ", 0
    foundMsg BYTE "Value found at index ", 0
    notFoundMsg BYTE "Value not found in the array", 0

.code
    RecursiveSearch PROTO, value:DWORD, arrayPtr:PTR DWORD, currentIndex:DWORD, endIndex:DWORD      

    main PROC
        mov EDX, OFFSET prompt
        call WriteString
        call ReadInt
        
        INVOKE RecursiveSearch, EAX, ADDR array, 0, arraySize           

        cmp EAX, -1
        je NotFound

        mov EDX, OFFSET foundMsg
        call crlf
        call WriteString
        call WriteDec
        call crlf
        jmp EndProgram

    NotFound:
        mov EDX, OFFSET notFoundMsg
        call crlf
        call WriteString
        call crlf

    EndProgram:
        exit
    main ENDP

    RecursiveSearch PROC USES EBX ECX EDX, value:DWORD, arrayPtr:PTR DWORD, currentIndex:DWORD, endIndex:DWORD      

        mov EAX, currentIndex
        cmp EAX, endIndex
        jge NotFound

        mov EBX, arrayPtr
        mov ECX, [EBX + EAX * 4]

        cmp ECX, value
        je Found

        inc currentIndex
        INVOKE RecursiveSearch, 
            value, 
            arrayPtr, 
            currentIndex, 
            endIndex

        jmp endProc

    Found:
        mov EAX, currentIndex
        jmp endProc

    NotFound:
        mov EAX, -1

    endProc:
        ret
    RecursiveSearch ENDP

END main