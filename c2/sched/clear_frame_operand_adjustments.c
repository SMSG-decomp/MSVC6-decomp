void __fastcall clear_frame_operand_adjustments(c2_function *fn)

{
  c2_tuple *t;
  c2_tuple *t_00;
  
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if (((t->flags & 1) != 0) && (clear_tuple_frame_operand_adjustments(t), t->kind == '\x15')) {
      for (t_00 = (t->u20).default_label; t_00 != (c2_tuple *)0x0; t_00 = t_00->next) {
        if ((t_00->flags & 1) != 0) {
          clear_tuple_frame_operand_adjustments(t_00);
        }
      }
    }
  }
  return;
}

