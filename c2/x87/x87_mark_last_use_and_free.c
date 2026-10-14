void __fastcall x87_mark_last_use_and_free(c2_tuple *t)

{
  c2_symbol *reg;
  c2_operand *pcVar1;
  c2_tuple *t_00;
  
  if ((t->flags & 0xf0) != 0) {
    t_00 = t->prev;
    reg = (t->src->u18).reg;
    do {
      if ((t_00->flags & 1) != 0) {
        pcVar1 = find_src_reg_operand(reg,t_00);
        if (pcVar1 != (c2_operand *)0x0) goto LAB_10779980;
      }
      t_00 = t_00->prev;
    } while( true );
  }
LAB_1077998b:
  tuple_unlink_free(t);
  return;
LAB_10779980:
  pcVar1->flags11 = pcVar1->flags11 | 0x10;
  goto LAB_1077998b;
}

