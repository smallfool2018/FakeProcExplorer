DWORD __cdecl sub_453E70(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION pSystemLogicalProcessorInfo, int dwCount, signed int dwProcessorID, signed int *pnValue1, int *pnValue2)
{
	__asm
	{
		push    ebp
		mov     ebp, esp
		push    ecx
		push    ebx
		push    esi
		push    edi
		mov     edi, [ebp + dwCount]
		or ecx, 0FFFFFFFFh
		or ebx, 0FFFFFFFFh
		mov[ebp + Flags], ecx
		or esi, 0FFFFFFFFh
		xor     edx, edx
		test    edi, edi
		jz      short __Exit



		mov     ecx, [ebp + dwProcessorID]
		mov     eax, 1
		shl     eax, cl
		mov     ecx, [ebp + pSystemLogicalProcessorInfo]
		add     ecx, 4
		mov[ebp + dwCount], eax
		nop

__Loop :
		mov     eax, [ebp + dwCount]
		test[ecx - 4], eax //pSystemLogicalProcessorInfo->ProcessorMask
		jz      short loc_453EBD

		mov     eax, [ecx]
		cmp     eax, RelationNumaNode
		jnz     short loc_453EB7

		/// pSystemLogicalProcessorInfo->NumaNode.NodeNumber
		mov     eax, [ecx + 4]
		mov[ebp + NodeNumber], eax
		jmp     short loc_453EBD

loc_453EB7:
		///RelationProcessorCore
		test    eax, eax
		jnz     short loc_453EC6
		///RelationProcessorCore
		mov     ebx, edx

loc_453EBD :

		mov     eax, [ecx]
		test    eax, eax
		jnz     short loc_453EC6
		inc     edx
		jmp     short loc_453ECC

loc_453EC6:

		cmp     eax, 1
		jnz     short loc_453ECC
		inc     esi

loc_453ECC :

		add     ecx, 18h
		dec     edi
		jnz     short __Loop



		cmp     esi, 1
		ja      short __quit2
			mov     eax, [ebp + pnValue1]
			cmp     ebx, 0FFFFFFFFh
			jz      short __quit1
			mov[eax], ebx
			mov     eax, [ebp + pnValue2]
			mov[eax], edi
			pop     edi
			pop     esi
			pop     ebx
			mov     esp, ebp
			pop     ebp
			retn

__quit1:
			mov     ecx, [ebp + dwProcessorID]
			mov[eax], ecx
			mov     eax, [ebp + pnValue2]
			pop     edi
			pop     esi
			pop     ebx
			mov     dword ptr[eax], 0FFFFFFFFh
			mov     esp, ebp
			pop     ebp
			retn

__quit2:
		mov     ecx, [ebp + NodeNumber]
__Exit :
			mov     eax, [ebp + pnValue1]
			pop     edi
			pop     esi
			pop     ebx
			mov[eax], ecx
			mov     eax, [ebp + pnValue2]
			mov     dword ptr[eax], 1
			mov     esp, ebp
			pop     ebp
			retn
	}

}