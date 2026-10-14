void __fastcall sizeopt_narrow_to_word(c2_block *block)

{
  byte bVar1;
  ushort uVar2;
  c2_tuple *pcVar3;
  c2_tuple *t;
  c2_operand *pcVar4;
  int iVar5;
  ushort uVar6;
  
  pcVar3 = block->head;
  for (t = block->end; t != pcVar3; t = t->prev) {
    bVar1 = t->kind;
    if (((bVar1 != 0xd) && (((bVar1 < 0x11 || (0x1b < bVar1)) && ((t->type & 0xf000) != 0x4000))))
       && ((uVar6 = t->type & 0xfff, uVar6 < 5 &&
           (((pcVar4 = t->src, pcVar4 == (c2_operand *)0x0 || ((pcVar4->type & 0xfff) < 5)) &&
            ((pcVar4->type & 0xf000) != 0x4000)))))) {
      uVar2 = t->line;
      if (uVar2 != 0) {
        g_current_line_abs = g_cur_function->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      pcVar4 = t->dst;
      if (((pcVar4 != (c2_operand *)0x0) && ((1 << (pcVar4->kind & 0x1f) & 6U) != 0)) &&
         ((pcVar4->sym->def != (c2_tuple *)0x0 &&
          (((2 < uVar6 && (iVar5 = can_change_op_width(t,2), iVar5 != 0)) &&
           (iVar5 = op_supports_width(t,2), iVar5 != 0)))))) {
        set_op_width(t,2);
      }
    }
  }
  return;
}

