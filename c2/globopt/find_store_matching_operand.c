c2_tuple * __fastcall find_store_matching_operand(c2_operand *op,c2_loop *loop)

{
  int iVar1;
  c2_tuple *clone;
  c2_list_cell *clone_cell;
  
  clone_cell = (loop->u30).iv_update_clones;
  while( true ) {
    if (clone_cell == (c2_list_cell *)0x0) {
      return (c2_tuple *)0x0;
    }
    clone = (clone_cell->u04).tuple;
    iVar1 = operand_compare(op,clone->src);
    if (iVar1 == 0) break;
    clone_cell = clone_cell->next;
  }
  return clone;
}

