.586                      
.MODEL flat, stdcall      
includelib kernel32.lib   

ExitProcess PROTO : DWORD
MessageBoxA PROTO: DWORD, :DWORD, :DWORD, :DWORD

.stack 4096

.CONST

.DATA
MB_OK EQU 0
STR1 DB "�������� ���� �����",0
STR2 DB "��������� �������� = ", 0
HW DD ?
c db "�", 0

.CODE

main PROC
START:
     MOV ax,2 ;���������� �������� 2 � ������� ax
     ADD ax,7 ;���������� �������� 7 � �������� ax
     ADD ax,30h;���������� �������� 30h (48 � ���������� �������) � �������� ax
     MOV ebx, LENGTHOF STR2-1;���������� ����� ������ STR2 ����� 1 � ������� ebx
     MOV [STR2 + ebx], al;��������� �������� �������� al � ������ �� ������ STR2 + ebx

     INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK
     push 0
     call ExitProcess

main ENDP
end main
