c2_operand * __fastcall tuple_forward_src_and_free(c2_tuple *t,c2_tuple *user)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  t->src = (c2_operand *)0x0;
  if ((1 << (pcVar1->kind & 0x1f) & 0xffeU) != 0) {
    pcVar1->flags = pcVar1->flags & 0xef;
  }
  symbol_free_chain(t->dst->sym->storage);
  if (user != (c2_tuple *)0x0) {
    pcVar1 = tuple_replace_src(user,(c2_operand *)t,pcVar1);
    return pcVar1;
  }
  node_free((c2_node *)t);
  return pcVar1;
}

