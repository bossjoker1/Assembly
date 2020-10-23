.model flat, c
public toCal
.code
;传了3个整型数
toCal proc,g1:word, g2:word, g3:word
		mov ax, 0
		mov dx, 0
		mov ax, g1
		add ax, ax
		add ax,ax
		mov dx, g2
		add dx,dx
		add ax, dx
		mov dx, g3
		add ax, dx
		;mov cx,7
        ;idiv cx 一直报错没办法，只好不用除法了
		ret	 
toCal endp
end

