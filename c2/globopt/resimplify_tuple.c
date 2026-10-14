c2_tuple * __fastcall resimplify_tuple(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  g_const_overflow_warned = 0;
  switch(*(undefined1 *)((int)&switchD_107074a4::switchdataD_107074d8 + (uint)t->kind)) {
  case 0:
    pcVar1 = t->dst;
    if (((pcVar1 != (c2_operand *)0x0) && ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) &&
       (pcVar1->sym->def != (c2_tuple *)0x0)) {
      g_const_overflow_warned = 0;
      return t;
    }
    break;
  case 2:
    g_const_overflow_warned = 0;
    return t;
  }
  pcVar2 = simplify_tuple_tree(t);
  return pcVar2;
}

