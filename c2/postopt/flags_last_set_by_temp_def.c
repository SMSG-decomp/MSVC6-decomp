int __fastcall flags_last_set_by_temp_def(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  do {
    if (t == (c2_tuple *)0x0) {
      return 0;
    }
    if ((t->flags & 1) != 0) {
      pcVar1 = find_src_overlapping_reg(t,g_reg_symbols + 0x42);
      if (pcVar1 != (c2_operand *)0x0) {
        return 0;
      }
      pcVar1 = find_dst_clobbering_reg(t,g_reg_symbols + 0x42);
      if ((((pcVar1 != (c2_operand *)0x0) && (pcVar1->kind == '\x01')) &&
          (pcVar1->sym->cls == '\x03')) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
        return 1;
      }
    }
    t = t->prev;
  } while( true );
}

