int __fastcall expand_mul_by_constant(c2_tuple *t)

{
  c2_operand *src;
  uint x;
  int iVar1;
  c2_mul_decomp *pcVar2;
  c2_tuple *pcVar3;
  int32_t partial;
  uint budget;
  c2_operand *local_8;
  uint local_4;
  
  src = t->src;
  x = (src->next->u18).lo;
  local_4 = x;
  if (g_opt_favor_speed == 0) {
    budget = 2;
  }
  else if (g_opt_cpu_target < 5) {
    iVar1 = log2_floor(x);
    if (iVar1 < 4) {
      iVar1 = 3;
    }
    budget = iVar1 + 6;
  }
  else {
    budget = 10;
  }
  if ((x == 0) || ((t->type & 0xfff) != 4)) {
    return 0;
  }
  if ((x & 1) == 0) {
    local_8 = (c2_operand *)(budget - 1);
    iVar1 = odd_part(x);
    pcVar2 = find_mul_decomposition(iVar1,(int)local_8);
    if (pcVar2->from == (c2_mul_decomp *)0x0) {
      return 0;
    }
    if (budget <= (uint)pcVar2->cost) {
      return 0;
    }
    if (((src->kind != '\x01') || (src->sym->cls != '\x03')) || (src->sym->def == (c2_tuple *)0x0))
    {
      pcVar3 = tuple_new_unary_temp(0x15b,src->type,src,tuple_insert_before,t);
      tuple_replace_src(t,t->src,pcVar3->dst);
    }
    local_8 = t->src;
    partial = emit_mul_decomposition(pcVar2,&local_8,t);
    emit_mul_by_pow2(local_4,partial,&local_8,t);
    tuple_remove_src(t,t->src->next);
  }
  else {
    pcVar2 = find_mul_decomposition(x,budget);
    if (pcVar2->from == (c2_mul_decomp *)0x0) {
      return 0;
    }
    if (budget <= (uint)pcVar2->cost) {
      return 0;
    }
    if (((src->kind != '\x01') || (src->sym->cls != '\x03')) || (src->sym->def == (c2_tuple *)0x0))
    {
      pcVar3 = tuple_new_unary_temp(0x15b,src->type,src,tuple_insert_before,t);
      tuple_replace_src(t,t->src,pcVar3->dst);
    }
    local_8 = t->src;
    emit_mul_decomposition(pcVar2,&local_8,t);
    tuple_remove_src(t,t->src->next);
  }
  tuple_replace_src(t,t->src,local_8);
  t->op = 0x15b;
  return 1;
}

