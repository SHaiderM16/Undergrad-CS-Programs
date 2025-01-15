INCLUDE Irvine32.inc

.data
    prompt BYTE "Enter the number of rows: ", 0  ; Prompt for user input

.code
    main PROC

    ; Prompt user for the number of rows
    mov edx, OFFSET prompt       ; Load address of prompt string
    call WriteString             ; Print the prompt
    call ReadInt                 ; Read integer input from user into EAX

    call CRLF                    ; Print a newline

    mov esi, eax                 ; Store the number of rows in ESI
    mov ecx, eax                 ; Set ECX for outer loop (number of rows)
    mov ebx, 1                   ; Set EBX for current row count
    mov edx, ecx                 ; Initialize EDX with total number of rows for spacing

    outer:  
        ; Print leading spaces before stars for the upward arrow
        mov ecx, edx                 ; Set ECX to current number of spaces
    space:
        mov eax, ' '                 ; Load space character
        call WriteChar               ; Print space
        LOOP space                   ; Repeat for all leading spaces

        ; Print stars with spaces in between
        mov ecx, ebx                 ; Set ECX for the number of stars in the current row
    star:
        mov eax, '*'                 ; Load star character
        call WriteChar               ; Print star

        mov eax, ' '                 ; Load space character
        call WriteChar               ; Print space

        LOOP star                    ; Repeat for all stars in the current row

        call CRLF                    ; Print a newline

        ; Prepare for the next row
        mov ecx, edx                 ; Reset ECX to total rows
        dec edx                      ; Decrease number of spaces for the next row
        inc ebx                      ; Increment current row count

        LOOP outer                   ; Repeat for all rows

        ; Prepare for the downward arrow section
        mov ecx, esi                 ; Load total rows into ECX
        mov eax, ecx                 ; Set EAX for half calculation
        shr eax, 1                   ; Right shift EAX by 1 to divide by 2

        mov edx, eax                 ; Store half value in EDX
        inc edx                      ; Increment EDX for spacing calculation

        sub esi, edx                 ; Subtract EDX from ESI to adjust total rows for downward arrow
        inc esi                      ; Increment ESI for the initial row count

    rows:
        mov ebx, ecx                 ; Store original row count in EBX for loop control

        ; Print leading spaces for downward arrow
        mov ecx, esi                 ; Set ECX for current number of leading spaces
    printSpaces:
        mov eax, ' '                 ; Load space character
        call WriteChar               ; Print space
        loop printSpaces             ; Repeat for all leading spaces

        ; Print stars for downward arrow
        mov ecx, edx                 ; Set ECX for the number of stars in the current row
    cols:
        mov eax, '*'                 ; Load star character
        call WriteChar               ; Print star

        mov eax, ' '                 ; Load space character
        call WriteChar               ; Print space

        loop cols                    ; Repeat for all stars in the current row
        call CRLF                    ; Print a newline

        mov ecx, ebx                 ; Reset ECX to total rows for the downward arrow
        loop rows                    ; Loop until all rows are printed

    exit
    main ENDP
END main