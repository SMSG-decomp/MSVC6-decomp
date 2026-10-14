c2_tuple * __fastcall find_root_def_tuple(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *local_4;
  
  pcVar1 = t->dst;
  if (((pcVar1 != (c2_operand *)0x0) && ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) &&
     (pcVar1->sym->def != (c2_tuple *)0x0)) {
    local_4 = (c2_operand *)t;
    pcVar2 = find_next_use_of_dst(t,&local_4);
    if (pcVar2 != (c2_tuple *)0x0) {
      pcVar2 = find_root_def_tuple(pcVar2);
      return pcVar2;
    }
  }
  return t;
}

