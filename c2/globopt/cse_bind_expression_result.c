void __fastcall cse_bind_expression_result(c2_symbol *e,c2_tuple *t,uint16_t type,int keep)

{
  uint16_t type_00;
  c2_symbol *chain;
  c2_bitset *bs;
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  uint32_t uVar5;
  c2_operand *local_4;
  
  pcVar3 = t->dst;
  link_expression_operands(e);
  if (pcVar3->sym != e) {
    pcVar1 = operand_new_sym(0x14a,type,e);
    if (((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (pcVar3->sym->def != (c2_tuple *)0x0)) {
      chain = pcVar3->sym->storage;
      pcVar2 = find_next_use_of_dst(t,&local_4);
      tuple_replace_dst(t,pcVar3,pcVar1);
      type_00 = local_4->type;
      pcVar3 = tuple_replace_src(pcVar2,local_4,pcVar1);
      operand_set_type(pcVar3,type_00);
      symbol_free_chain(chain);
      return;
    }
    pcVar1 = operand_new_sym(0x14a,type,e);
    pcVar2 = tuple_new(0x15b,type,pcVar3,pcVar1,tuple_insert_after,t);
    tuple_replace_dst(t,pcVar3,pcVar1);
    iVar4 = is_compare_branch_op(t->op);
    if (iVar4 != 0) {
      pcVar2->flags13 = '\x01';
    }
    if (keep == 0) {
      g_next_tuple_cursor = pcVar2;
    }
    pcVar3 = pcVar2->dst;
    if ((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && ((pcVar3->sym->u18).expr != (c2_cse_expr *)0x0)
        ) && (bs = pcVar3->sym->dependents, bs != (c2_bitset *)0x0)) {
      uVar5 = bitset_test(bs,e->id);
      if (uVar5 != 0) {
        pcVar3 = find_src_symbol_ref(t,pcVar3->sym);
        if (pcVar3 != (c2_operand *)0x0) {
          pcVar2->flags13 = '\x0e';
        }
      }
    }
    number_assignment(pcVar2,1);
  }
  return;
}

