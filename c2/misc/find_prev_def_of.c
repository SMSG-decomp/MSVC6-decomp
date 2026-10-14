c2_tuple * __fastcall find_prev_def_of(c2_tuple *t,c2_symbol *s,c2_operand **out)

{
  c2_tuple *t_00;
  c2_operand *pcVar1;
  
  t_00 = t->prev;
  while( true ) {
    if (t_00 == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    if (((t_00->flags & 1) != 0) &&
       (pcVar1 = find_dst_symbol_ref(t_00,s), pcVar1 != (c2_operand *)0x0)) break;
    t_00 = t_00->prev;
  }
  if (out != (c2_operand **)0x0) {
    *out = pcVar1;
  }
  return t_00;
}

