void inline_find_pending_copy_marker_part(c2_operand *opnd)

{
  c2_tuple *t;
  c2_operand *op;
  c2_symbol *pcVar1;
  c2_tuple *marker;
  
  do {
    opnd = opnd->next;
    if (opnd == (c2_operand *)0x0) {
      return;
    }
  } while (((((1 << (opnd->kind & 0x1f) & 6U) == 0) || (t = opnd->sym->def, t == (c2_tuple *)0x0))
           || ((t->op != 0x15a && (t->op != 0x16a)))) ||
          ((((op = t->src, (1 << (op->kind & 0x1f) & 6U) == 0 ||
             (pcVar1 = op->sym, pcVar1->cls != '\x03')) || (pcVar1->def != (c2_tuple *)0x0)) ||
           (((pcVar1->flags7 & 2) == 0 ||
            (marker = find_prev_def_of_operand(t,op,(c2_operand **)&stack0x00000008),
            marker->op != 0x1aa))))));
  lower_1aa_move_operand(marker,t);
  inline_find_pending_copy_marker_part(opnd);
  return;
}

