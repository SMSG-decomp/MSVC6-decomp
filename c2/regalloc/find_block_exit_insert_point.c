c2_tuple * __fastcall find_block_exit_insert_point(c2_block *block2,c2_symbol *sym,c2_function *fn)

{
  uint8_t uVar1;
  byte bVar2;
  ushort uVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_tuple *pcVar7;
  
  pcVar6 = block2->end->prev;
  uVar1 = pcVar6->kind;
  while (uVar1 == '\x1b') {
    pcVar6 = pcVar6->prev;
    uVar1 = pcVar6->kind;
  }
  if (pcVar6->kind != 0xf) {
    if ((1 << (pcVar6->kind & 0x1f) & 0xa0000U) == 0) {
      pcVar6 = pcVar6->next;
    }
    else if (sym->cls == '\r') {
      pcVar7 = pcVar6->prev;
      uVar4 = pcVar7->op;
      while (uVar4 == 0x163) {
        pcVar7 = pcVar7->prev;
        uVar4 = pcVar7->op;
      }
      if (((((pcVar7->flags & 1) != 0) && (pcVar5 = pcVar7->dst, pcVar5 != (c2_operand *)0x0)) &&
          (pcVar5->next == (c2_operand *)0x0)) &&
         (((pcVar5->kind == '\x01' && (pcVar5->sym->cls == '\x03')) &&
          (pcVar5->sym->def != (c2_tuple *)0x0)))) {
        pcVar6 = pcVar7;
      }
    }
  }
  if ((pcVar6->flags & 1) == 0) {
    for (pcVar7 = pcVar6->prev; pcVar7 != (c2_tuple *)0x0; pcVar7 = pcVar7->prev) {
      if ((pcVar7->flags & 1) != 0) {
        if (pcVar7 != (c2_tuple *)0x0) goto LAB_10713c14;
        break;
      }
    }
    pcVar7 = pcVar6->next;
    bVar2 = pcVar7->flags;
    while ((bVar2 & 1) == 0) {
      pcVar7 = pcVar7->next;
      bVar2 = pcVar7->flags;
    }
LAB_10713c14:
    uVar3 = pcVar7->line;
  }
  else {
    uVar3 = pcVar6->line;
  }
  if (uVar3 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar3;
    g_cur_line = uVar3;
  }
  return pcVar6;
}

