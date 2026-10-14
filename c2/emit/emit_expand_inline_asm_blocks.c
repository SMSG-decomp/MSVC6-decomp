void __fastcall emit_expand_inline_asm_blocks(c2_function *fn)

{
  c2_fe_symbol *pcVar1;
  uint uVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *t;
  c2_operand *pcVar5;
  c2_operand_u18 cVar6;
  c2_tuple *pos;
  
  pcVar1 = fn->fsym;
  uVar2 = pcVar1->attrs;
  pcVar3 = fn->cfg->last->end;
  pcVar4 = fn->cfg->first->head->next;
  while (pos = pcVar4, pos != pcVar3) {
    pcVar4 = pos->next;
    if (pos->kind == '\x15') {
      for (t = (pos->u20).default_label; t != (c2_tuple *)0x0; t = t->next) {
        if (((t->flags & 1) != 0) &&
           (clear_tuple_frame_operand_adjustments(t), (uVar2 & 0x400) != 0)) {
          for (pcVar5 = t->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if (pcVar5->op == 0x157) {
              cVar6 = (c2_operand_u18)pcVar1->frame_size;
              pcVar5->op = 0x146;
              pcVar5->u18 = cVar6;
              pcVar5->tag = 0;
            }
          }
        }
      }
      tuple_splice_after(pos,(pos->u20).default_label);
      (pos->u20).cond_cells = (c2_cond_cell *)0x0;
      tuple_unlink_free(pos);
    }
  }
  return;
}

