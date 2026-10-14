c2_tuple * __fastcall simplify_expression_tree(c2_tuple *root)

{
  c2_symbol *pcVar1;
  c2_operand *dst;
  c2_operand *new_op;
  c2_operand *pcVar2;
  c2_tuple *copy_tuple;
  c2_tuple *result;
  int iVar3;
  
  dst = (c2_operand *)node_clone((c2_node *)root->dst);
  pcVar2 = root->dst;
  new_op = operand_new_temp(pcVar2->type);
  tuple_replace_dst(root,pcVar2,new_op);
  pcVar1 = root->dst->sym;
  if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
    pcVar1->def = root;
  }
  else {
    symbol_mark_overlapping_parts(pcVar1,root);
  }
  result = (c2_tuple *)build_nary_expression_tree(root);
  iVar3 = 1;
  while( true ) {
    g_simplify_changed = 0;
    pcVar2 = (c2_operand *)simplify_tree_bottom_up(result,(c2_tuple *)0x0,0);
    result = (c2_tuple *)distribute_and_propagate(pcVar2,(c2_tuple *)0x0);
    if ((g_simplify_changed == 0) || ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) != 0))
    break;
    iVar3 = iVar3 + 1;
    if (100 < iVar3) {
      fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\optimize.c",0x1c9);
    }
  }
  if ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) == 0) {
    iVar3 = 1;
    while( true ) {
      g_simplify_changed = 0;
      result = (c2_tuple *)simplify_tree_bottom_up(result,(c2_tuple *)0x0,1);
      if ((g_simplify_changed == 0) || ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) != 0))
      break;
      iVar3 = iVar3 + 1;
      if (100 < iVar3) {
        fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\optimize.c",0x1dc);
      }
    }
  }
  if ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) == 0) {
    iVar3 = 1;
    while( true ) {
      g_simplify_changed = 0;
      result = simplify_tree_final_stage(result,(c2_tuple *)0x0);
      if ((g_simplify_changed == 0) || ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) != 0))
      break;
      iVar3 = iVar3 + 1;
      if (100 < iVar3) {
        fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\optimize.c",0x1ee);
      }
    }
  }
  if ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) == 0) {
    result = (c2_tuple *)rebuild_subtractions((c2_node *)result,(c2_node *)0x0);
  }
  if ((1 << (((c2_operand *)result)->kind & 0x1f) & 0xffeU) == 0) {
    pcVar2 = (c2_operand *)((c2_operand *)result)->tag;
    symbol_free_chain(pcVar2->sym->storage);
    tuple_replace_dst(result,pcVar2,dst);
  }
  else {
    copy_tuple = tuple_new(0x15b,dst->type,dst,(c2_operand *)result,(c2_insert_fn *)0x0,
                           (c2_tuple *)0x0);
    tuple_unlink_mem_subops(copy_tuple);
    copy_tuple->flags12 = '\x02';
    result = copy_tuple;
  }
  if (((1 << (dst->kind & 0x1f) & 6U) != 0) && (pcVar1 = dst->sym, pcVar1->def != (c2_tuple *)0x0))
  {
    if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
      pcVar1->def = result;
      return result;
    }
    symbol_mark_overlapping_parts(pcVar1,result);
  }
  return result;
}

