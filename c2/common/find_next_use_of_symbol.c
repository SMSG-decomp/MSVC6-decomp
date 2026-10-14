c2_tuple * __fastcall find_next_use_of_symbol(c2_node *t,c2_symbol *sym,c2_operand **use)

{
  c2_operand *pcVar1;
  c2_operand *t_00;
  c2_symbol *use_sym;
  
  t_00 = (c2_operand *)t->next;
  if (t_00 == (c2_operand *)0x0) {
    return (c2_tuple *)0x0;
  }
  do {
    if ((t_00->flags9 & 1) == 0) {
      if (((1 << (t_00->kind & 0x1f) & 0xffeU) != 0) && ((1 << (t_00->kind & 0x1f) & 6U) != 0)) {
        use_sym = ((c2_tuple_u14 *)&t_00->sym)->expr;
        if (use_sym == sym) {
LAB_10703482:
          if (use == (c2_operand **)0x0) {
            return (c2_tuple *)0x0;
          }
          *use = t_00;
          return (c2_tuple *)0x0;
        }
        if (use_sym->storage == sym->storage) {
          if ((use_sym->offset < sym->size + sym->offset) &&
             (sym->offset < use_sym->size + use_sym->offset)) goto LAB_10703482;
        }
      }
    }
    else {
      pcVar1 = find_src_symbol_ref((c2_tuple *)t_00,sym);
      if (pcVar1 != (c2_operand *)0x0) {
        if (use != (c2_operand **)0x0) {
          *use = pcVar1;
        }
        return (c2_tuple *)t_00;
      }
    }
    t_00 = t_00->next;
    if (t_00 == (c2_operand *)0x0) {
      return (c2_tuple *)0x0;
    }
  } while( true );
}

