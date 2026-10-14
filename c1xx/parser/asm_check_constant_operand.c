short * __cdecl asm_check_constant_operand(short op,short *left,short *right)

{
  c1_u8 *pcVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  short n;
  
  pcVar1 = g_arenas[5].cur;
  psVar4 = right;
  if ((*left != 0) || (psVar4 = left, *right != 0)) {
    iVar2 = asm_operand_description_id();
    diag_error(0x1a9,g_asm_token_spelling[op],iVar2);
    return psVar4;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  if (8 < op) {
    if (op == 10) {
      uVar3 = *(uint *)(left + 2) | *(uint *)(right + 2);
    }
    else if (op == 0xb) {
      uVar3 = *(int *)(left + 2) << ((byte)*(undefined4 *)(right + 2) & 0x1f);
    }
    else if (op == 0xc) {
      uVar3 = *(int *)(left + 2) >> ((byte)*(undefined4 *)(right + 2) & 0x1f);
    }
    else if (op == 0xd) {
      uVar3 = *(uint *)(left + 2) ^ *(uint *)(right + 2);
    }
    else if (op == 0x18) {
      uVar3 = *(int *)(left + 2) * *(int *)(right + 2);
    }
    else {
      if (op != 0x19) {
        return (short *)pcVar1;
      }
      if (*(int *)(right + 2) == 0) {
        iVar2 = asm_operand_description_id();
        n = 0x1a1;
        goto LAB_104bb035;
      }
      uVar3 = *(int *)(left + 2) / *(int *)(right + 2);
    }
    goto LAB_104bafd4;
  }
  if (op == 8) {
    if (*(int *)(right + 2) != 0) {
      *(int *)(pcVar1 + 4) = *(int *)(left + 2) % *(int *)(right + 2);
      return (short *)pcVar1;
    }
    iVar2 = asm_operand_description_id();
    n = 0x1a3;
LAB_104bb035:
    diag_error(n,iVar2);
    return (short *)pcVar1;
  }
  if (op == 1) {
    if (*(int *)(left + 2) != *(int *)(right + 2)) {
LAB_104bb001:
      uVar3 = 0;
      goto LAB_104bafd4;
    }
  }
  else if (op == 2) {
    if (*(int *)(left + 2) < *(int *)(right + 2)) goto LAB_104bb001;
  }
  else if (op == 3) {
    if (*(int *)(left + 2) <= *(int *)(right + 2)) goto LAB_104bb001;
  }
  else if (op == 4) {
    if (*(int *)(right + 2) < *(int *)(left + 2)) goto LAB_104bb001;
  }
  else {
    if (op != 5) {
      if (op == 6) {
        uVar3 = -(uint)(*(int *)(left + 2) != *(int *)(right + 2)) & 0xffff;
      }
      else {
        if (op != 7) {
          return (short *)pcVar1;
        }
        uVar3 = *(uint *)(left + 2) & *(uint *)(right + 2);
      }
      goto LAB_104bafd4;
    }
    if (*(int *)(right + 2) <= *(int *)(left + 2)) goto LAB_104bb001;
  }
  uVar3 = 0xffff;
LAB_104bafd4:
  *(uint *)(pcVar1 + 4) = uVar3;
  return (short *)pcVar1;
}

