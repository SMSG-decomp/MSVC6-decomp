void __fastcall g5_split_memory_operand(c2_tuple *t,c2_operand *mem,int reg,int is_dst)

{
  uint16_t type;
  c2_operand *dst;
  c2_tuple *pcVar1;
  c2_symbol *pcVar2;
  c2_operand *src;
  int iVar3;
  
  type = mem->type;
  if ((type & 0xfff) == 1) {
    pcVar2 = reg_find_subreg(g_reg_symbols + reg,8,0);
    reg = pcVar2->id;
  }
  dst = operand_new_temp(type);
  (dst->u18).reg = g_reg_symbols + reg;
  pcVar1 = tuple_new(1,type,dst,mem,tuple_insert_before,t);
  dst->sym->def = pcVar1;
  pcVar1->flags = pcVar1->flags | 4;
  if (is_dst == 0) {
    tuple_replace_src(t,mem,dst);
    t->flags = t->flags | 4;
    return;
  }
  src = operand_new_temp(mem->type);
  (src->u18).reg = g_reg_symbols + reg;
  pcVar1 = tuple_new(1,mem->type,mem,src,tuple_insert_after,t);
  pcVar1->flags = pcVar1->flags | 4;
  iVar3 = operand_compare(mem,t->src);
  if (iVar3 == 0) {
    tuple_replace_src(t,t->src,dst);
  }
  tuple_replace_dst(t,mem,src);
  src->sym->def = t;
  t->flags = t->flags | 4;
  return;
}

