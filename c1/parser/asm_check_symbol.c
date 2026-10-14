c1_u8 * __cdecl asm_check_symbol(int name)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_symbol *sym;
  int iVar3;
  c1_u8 *pcVar4;
  uchar *puVar5;
  
  sym = asm_lookup_name(name,1);
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 < 7) || (0xb < bVar1)) {
    iVar3 = asm_operand_description_id();
    diag_error(0x1a4,name,iVar3);
    puVar5 = g_arenas[3].cur;
    g_arenas[3].cur = g_arenas[3].cur + 0xc;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    puVar5[0] = '\0';
    puVar5[1] = '\0';
  }
  else {
    pcVar4 = &g_asm_operand->expr->kind;
    *pcVar4 = *pcVar4 & 0xec;
    pcVar4 = &g_asm_operand->expr->kind;
    *pcVar4 = *pcVar4 | 3;
    if (((byte)sym->type->code >> 5 & 1) != 0) {
      pcVar4 = &g_asm_operand->expr->kind;
      *pcVar4 = *pcVar4 | 0x20;
    }
    if (sym != g_builtin_label_1) {
      sym_mark_referenced(sym);
    }
    if ((g_asm_operand->flags & 1) == 0) {
      bVar1 = sym->kind & 0x1f;
      if ((((bVar1 != 9) && (bVar1 != 7)) && (bVar1 != 8)) ||
         ((((g_asm_form != 0x10 && (g_asm_form != 0xf)) &&
           ((g_asm_form != 0x1b && ((g_asm_form != 0xe && (sym != g_builtin_label_1)))))) &&
          (sym != g_builtin_label_10)))) {
        pcVar4 = &g_asm_operand->expr->kind;
        *pcVar4 = *pcVar4 & 0xef;
        pcVar4 = &g_asm_operand->expr->kind;
        *pcVar4 = *pcVar4 | 0x10;
      }
      iVar3 = asm_symbol_operand_size(sym);
      cVar2 = asm_size_class_of_bytes(iVar3);
      g_asm_operand->size_class = cVar2;
    }
    else if (g_asm_size_without_ptr == 0) {
      pcVar4 = &g_asm_operand->expr->kind;
      *pcVar4 = *pcVar4 & 0xef;
      pcVar4 = &g_asm_operand->expr->kind;
      *pcVar4 = *pcVar4 | 0x10;
    }
    bVar1 = sym->storage & 7;
    if ((3 < bVar1) && (bVar1 < 7)) {
      if (g_asm_operand->expr->sym != (c1_symbol *)0x0) {
        diag_warning(1,0x19b,g_last_name);
      }
      pcVar4 = &g_asm_operand->expr->kind;
      *pcVar4 = *pcVar4 & 0xde;
      pcVar4 = asm_check_register_2(6);
      pcVar4[4] = '\0';
      pcVar4[5] = '\0';
      pcVar4[6] = '\0';
      pcVar4[7] = '\0';
      g_asm_operand->frame_sym = sym;
      return pcVar4;
    }
    if (g_asm_operand->expr->sym == (c1_symbol *)0x0) {
      g_asm_operand->expr->sym = sym;
    }
    puVar5 = g_arenas[3].cur;
    g_arenas[3].cur = g_arenas[3].cur + 0xc;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    puVar5[0] = '\x02';
    puVar5[1] = '\0';
  }
  puVar5[4] = '\0';
  puVar5[5] = '\0';
  puVar5[6] = '\0';
  puVar5[7] = '\0';
  return puVar5;
}

