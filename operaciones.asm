section .text
    global recibir_Operacion

recibir_Operacion:
    xor eax, eax ;Operando 1
    xor ebx, ebx ;Operando 2
    xor ecx, ecx ;Operando
    xor edx, edx ;Garantiza que la división no genere un error de Floating point exception

    mov eax, [ebp + 8] ;Traigo el parámetro 1
    mov ebx, [ebp + 16] ;Traigo el parámetro 3
    mov ecx, [ebp + 12] ;Traigo el parámetro 2 (+, -, x, /)

    cmp ecx, '+'
    je suma

    cmp ecx, '-'
    je resta

    cmp ecx, '*'
    je multiplicacion

    cmp ecx, '/'
    je division

    ;En caso de que no se encuentre el operador, debe ejecutarse otra cosa o mandarse un msj ...
suma:
    add eax, ebx
    jmp fin
resta:
    sub eax, ebx
    jmp fin
multiplicacion:
    mul ebx
    jmp fin
division:
    cmp ebx, 0 ;En caso de que el divisor sea 0
    je division_por_cero_detected ;Salta a la subrutina para devolver un 0
    div ebx
    jmp fin
division_por_cero_detected:
    mov eax, 0
    jmp fin
fin:
    ret