.586                      
.MODEL flat, stdcall      
includelib kernel32.lib   

ExitProcess PROTO : DWORD
MessageBoxA PROTO: DWORD, :DWORD, :DWORD, :DWORD

.stack 4096

.CONST

.DATA
MB_OK EQU 0
STR1 DB "СЛОЖЕНИЕ ДВУХ ЧИСЕЛ",0
STR2 DB "РЕЗУЛЬТАТ СЛОЖЕНИЯ = ", 0
HW DD ?
c db "Х", 0

.CODE

main PROC
START:
     MOV ax,2 ;перемещает значение 2 в регистр ax
     ADD ax,7 ;прибавляет значение 7 к регистру ax
     ADD ax,30h;прибавляет значение 30h (48 в десятичной системе) к регистру ax
     MOV ebx, LENGTHOF STR2-1;перемещает длину строки STR2 минус 1 в регистр ebx
     MOV [STR2 + ebx], al;сохраняет значение регистра al в памяти по адресу STR2 + ebx

     INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK
     push 0
     call ExitProcess

main ENDP
end main
