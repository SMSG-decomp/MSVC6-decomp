c1_u8 * __cdecl asm_check_constant_operand_2(short op,short *operand)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  
  if (*operand != 0) {
    iVar2 = asm_operand_description_id();
    diag_error(0x1a9,(&PTR_s_no_token_1065b868)[op],iVar2);
  }
  puVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0xc;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  puVar1[0] = '\0';
  puVar1[1] = '\0';
  if (op == 9) {
    uVar3 = ~*(uint *)(operand + 2);
  }
  else if (op == 0xe) {
    uVar3 = (uint)*(byte *)((int)operand + 5);
  }
  else if (op == 0x10) {
    uVar3 = *(uint *)(operand + 2) & 0xff;
  }
  else if (op == 0x16) {
    uVar3 = *(uint *)(operand + 2);
  }
  else {
    if (op != 0x17) {
      return puVar1;
    }
    uVar3 = -*(int *)(operand + 2);
  }
  *(uint *)(puVar1 + 4) = uVar3;
  return puVar1;
}

