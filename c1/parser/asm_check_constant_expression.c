short * __cdecl asm_check_constant_expression(short op,short *left,short *right)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined2 in_stack_00000006;
  
  psVar1 = (short *)g_arenas[3].cur;
  iVar3 = (int)op;
  if (iVar3 != 0x16) {
    if (iVar3 == 0x17) {
      if (*right == 0) {
        g_arenas[3].cur = g_arenas[3].cur + 0xc;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        *(int *)((int)psVar1 + 4) = *(int *)(left + 2) - *(int *)(right + 2);
        *psVar1 = *left;
        return psVar1;
      }
      iVar3 = asm_operand_description_id();
      diag_error(0x1a9,"-",iVar3);
      return left;
    }
    if ((iVar3 != 0x1c) && (iVar3 != 0x23)) {
      return _op;
    }
  }
  if (((*left == 3) || (*right == 3)) || ((*left == 2 && (*right == 2)))) {
    iVar2 = asm_operand_description_id();
    diag_error(0x1a8,(&PTR_s_no_token_1065b868)[iVar3],iVar2);
    psVar1 = left;
  }
  else {
    g_arenas[3].cur = g_arenas[3].cur + 0xc;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    *(int *)((int)psVar1 + 4) = *(int *)(left + 2) + *(int *)(right + 2);
    sVar4 = *left;
    if (*left <= *right) {
      sVar4 = *right;
    }
    *psVar1 = sVar4;
  }
  return psVar1;
}

