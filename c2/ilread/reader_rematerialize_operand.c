c2_operand * __fastcall
reader_rematerialize_operand(c2_operand *op,c2_tuple *t,c2_tuple **first,c2_tuple **last)

{
  uint16_t type;
  int iVar1;
  c2_operand *pcVar2;
  c2_operand *dst;
  c2_tuple *pcVar3;
  
  pcVar2 = op;
  if (op->kind == '\x06') {
    pcVar2 = op->base;
  }
  iVar1 = node_has_side_effects((c2_node *)op);
  if ((iVar1 == 0) && (iVar1 = reader_value_has_side_effects(op), iVar1 == 0)) {
    pcVar2 = clone_temp_def_tree(pcVar2->sym,first,last);
    if (op->kind == '\x06') {
      pcVar2 = operand_new_mem(op->op,op->type,(c2_symbol *)0x0,0,pcVar2,(c2_operand *)0x0,op->tag);
      return pcVar2;
    }
  }
  else {
    pcVar2 = pcVar2->sym->def->dst;
    type = pcVar2->type;
    dst = operand_new_temp_sym(type);
    pcVar3 = tuple_new(0x15b,type,dst,pcVar2,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    *last = pcVar3;
    *first = pcVar3;
    if (op->kind == '\x06') {
      pcVar2 = operand_new_mem(op->op,op->type,(c2_symbol *)0x0,0,dst,(c2_operand *)0x0,op->tag);
      if (t != (c2_tuple *)0x0) {
        iVar1 = tuple_list_contains(t,op);
        if (iVar1 != 0) {
          tuple_replace_dst(t,op,pcVar2);
          pcVar2 = (c2_operand *)node_clone((c2_node *)pcVar2);
          return pcVar2;
        }
        tuple_replace_src(t,op,pcVar2);
        pcVar2 = (c2_operand *)node_clone((c2_node *)pcVar2);
      }
      return pcVar2;
    }
    pcVar2 = (c2_operand *)node_clone((c2_node *)dst);
    pcVar2->type = op->type;
  }
  return pcVar2;
}

