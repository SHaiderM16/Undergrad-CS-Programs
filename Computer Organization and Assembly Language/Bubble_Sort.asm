INCLUDE Irvine32.inc

.data
    arr dword 8, 5, 1, 2, 6                     ; Define an array of integers to sort
    sizeOfArr dword LENGTHOF arr                ; Calculate the size of the array

.code
    main PROC
    
    mov ecx, sizeOfArr                          ; Load the number of elements into ECX
    dec ecx                                     ; Decrease ECX by 1 for zero-based index

    outerLoop:
        mov esi, 0                                  ; Initialize index ESI for the inner loop
    innerLoop:
        ; Load the current and next elements for comparison
        mov eax, [arr+esi*TYPE arr]                 ; Load current element into EAX
        mov ebx, [arr + esi*TYPE arr + TYPE arr]    ; Load the next element into EBX
        cmp eax, ebx                                ; Compare the two elements
        jle noChange                                ; Jump to noChange if EAX <= EBX (no swap needed)
        
        ; Swap elements if necessary
        mov [arr+esi*TYPE arr], ebx                 ; Place the larger element in the current position
        mov [arr+esi*TYPE arr + TYPE arr], eax      ; Place the smaller element in the next position

    noChange:
        inc esi                                     ; Increment index ESI to compare the next pair
        cmp esi, ecx                                ; Compare ESI with the loop counter (ECX)
        jl innerLoop                                ; If ESI < ECX, continue inner loop

        loop outerLoop                              ; Decrement ECX and repeat outer loop if not zero

        ; Printing the sorted array
        mov esi, 0                                  ; Reset ESI to 0 for printing
        mov ecx, sizeOfArr                          ; Reload the number of elements into ECX

    printLoop:
        mov eax, [arr+esi*TYPE arr]                 ; Load the current element to print into EAX
        call WriteInt                               ; Print the integer in EAX
        call crlf                                   ; Print a new line
        inc esi                                     ; Increment index ESI to move to the next element
        loop printLoop                              ; Decrement ECX and repeat if not zero

    exit
    main ENDP
END main