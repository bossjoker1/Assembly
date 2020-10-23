.model flat, c
public match
.code
match proc uses esi edi,s1:ptr,s2:ptr
      mov esi, s1
	  mov edi, s2
	  cld
	  mov ecx, 10
	  repz cmpsb
	  je True
      mov eax,0
      ret 
True: mov eax,1
      ret
match endp
end
