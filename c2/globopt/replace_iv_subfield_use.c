int __fastcall replace_iv_subfield_use(c2_operand *node,c2_tuple *t)

{
  c2_symbol *pcVar1;
  c2_symbol *pcVar2;
  uint32_t uVar3;
  c2_operand *op;
  c2_tuple *pcVar4;
  
  pcVar1 = node->sym;
  pcVar2 = pcVar1->storage;
  while( true ) {
    if (pcVar2 == (c2_symbol *)0x0) {
      return 0;
    }
    if ((((pcVar2->offset <= pcVar1->offset) &&
         (pcVar1->size + pcVar1->offset <= pcVar2->size + pcVar2->offset)) &&
        (uVar3 = bitset_test(g_iv_syms,pcVar2->id), uVar3 != 0)) && (pcVar1 != pcVar2)) break;
    pcVar2 = pcVar2->part_next;
  }
  op = (c2_operand *)node_clone((c2_node *)node);
  operand_set_type(op,pcVar2->type);
  pcVar4 = tuple_new_cse_value(0x15f,node->type,op,tuple_insert_before,t);
  node->sym = pcVar4->dst->sym;
  pcVar4->line = t->line;
  return 1;
}

