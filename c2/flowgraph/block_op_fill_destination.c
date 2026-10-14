c2_operand * __fastcall block_op_fill_destination(c2_tuple *t,c2_operand *v,int pattern)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *local_4;
  
  pcVar1 = t->dst;
  if ((pcVar1 != (c2_operand *)0x0) && (pcVar1->kind != '\v')) {
    local_4 = v;
    if (pattern != 0) {
      build_fill_pattern(1,0x1004,pcVar1,&local_4,t->prev);
      tuple_remove_dst(t,pcVar1);
      return local_4;
    }
    pcVar2 = tuple_new(1,0x1004,pcVar1,v,tuple_insert_before,t);
    pcVar1 = t->dst;
    pcVar1->sym->def = pcVar2;
    tuple_remove_dst(t,pcVar1);
    v = local_4;
  }
  return v;
}

