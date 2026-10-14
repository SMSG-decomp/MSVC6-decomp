void __fastcall inline_find_pending_copy_marker(c2_tuple *t)

{
  c2_operand *opnd;
  c2_tuple *t_00;
  c2_operand *op;
  c2_symbol *pcVar1;
  c2_tuple *marker;
  c2_operand *pcStack_4;
  
  opnd = t->src;
  pcStack_4 = (c2_operand *)t;
  while( true ) {
    if (opnd == (c2_operand *)0x0) {
      return;
    }
    if (((((1 << (opnd->kind & 0x1f) & 6U) != 0) && (t_00 = opnd->sym->def, t_00 != (c2_tuple *)0x0)
         ) && ((t_00->op == 0x15a || (t_00->op == 0x16a)))) &&
       ((((op = t_00->src, (1 << (op->kind & 0x1f) & 6U) != 0 &&
          (pcVar1 = op->sym, pcVar1->cls == '\x03')) && (pcVar1->def == (c2_tuple *)0x0)) &&
        (((pcVar1->flags7 & 2) != 0 &&
         (marker = find_prev_def_of_operand(t_00,op,&pcStack_4), marker->op == 0x1aa)))))) break;
    opnd = opnd->next;
  }
  lower_1aa_move_operand(marker,t_00);
  inline_find_pending_copy_marker_part(opnd);
  return;
}

