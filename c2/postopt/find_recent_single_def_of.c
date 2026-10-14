c2_tuple * __fastcall find_recent_single_def_of(c2_tuple *t,c2_operand *op)

{
  c2_tuple *t_00;
  int iVar1;
  c2_operand *pcVar2;
  int iVar3;
  
  t_00 = t->prev;
  iVar1 = 0;
  do {
    if (t_00 == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    iVar3 = iVar1;
    if ((t_00->flags & 1) != 0) {
      if (((t_00->dst != (c2_operand *)0x0) && (t_00->dst->next == (c2_operand *)0x0)) &&
         (pcVar2 = find_dst_symbol_ref(t_00,op->sym), pcVar2 != (c2_operand *)0x0)) {
        return t_00;
      }
      iVar3 = iVar1 + 1;
      if (6 < iVar1) {
        return (c2_tuple *)0x0;
      }
    }
    t_00 = t_00->prev;
    iVar1 = iVar3;
  } while( true );
}

