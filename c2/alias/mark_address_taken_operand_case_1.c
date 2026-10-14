void mark_address_taken_operand_case_1(c2_operand *op,c2_bitset *mask)

{
  c2_tuple *pcVar1;
  c2_bitset *bs;
  int iVar2;
  c2_operand *op_00;
  
  if (((1 << (op->kind & 0x1f) & 6U) == 0) || (pcVar1 = op->sym->def, pcVar1 == (c2_tuple *)0x0)) {
    if ((op->sym->flags5 & 8) != 0) {
      bs = symbol_overlap_alias_set(op->sym,mask);
      iVar2 = bitset_iter_next(bs);
      while (iVar2 != -1) {
        g_alias_ref_table[iVar2].addr_taken = 1;
        iVar2 = bitset_iter_next((c2_bitset *)0x0);
      }
      bitset_free(bs);
      return;
    }
  }
  else if ((((pcVar1->kind != '\x0e') && (pcVar1->kind != '\x12')) && (pcVar1->op != 0x17d)) &&
          (op_00 = pcVar1->src, op_00 != (c2_operand *)0x0)) {
    do {
      mark_address_taken_operand(op_00,mask);
      op_00 = op_00->next;
    } while (op_00 != (c2_operand *)0x0);
    return;
  }
  return;
}

