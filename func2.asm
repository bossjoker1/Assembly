.model flat, c
public toCal
.code
;����3��������
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
        ;idiv cx һֱ����û�취��ֻ�ò��ó�����
		ret	 
toCal endp
end

