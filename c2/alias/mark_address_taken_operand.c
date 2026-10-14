void __fastcall mark_address_taken_operand(c2_operand *op,c2_bitset *mask)

{
  uint8_t *puVar1;
  c2_tuple *pcVar2;
  c2_bitset *bs;
  int iVar3;
  c2_operand *op_00;
  
  if ((op->flags & 0x20) == 0) {
    switch(op->kind) {
    case '\x01':
    case '\x02':
      if (((1 << (op->kind & 0x1f) & 6U) == 0) || (pcVar2 = op->sym->def, pcVar2 == (c2_tuple *)0x0)
         ) {
        if ((op->sym->flags5 & 8) != 0) {
          bs = symbol_overlap_alias_set(op->sym,mask);
          iVar3 = bitset_iter_next(bs);
          while (iVar3 != -1) {
            g_alias_ref_table[iVar3].addr_taken = 1;
            iVar3 = bitset_iter_next((c2_bitset *)0x0);
          }
          bitset_free(bs);
          return;
        }
      }
      else if ((((pcVar2->kind != '\x0e') && (pcVar2->kind != '\x12')) && (pcVar2->op != 0x17d)) &&
              (op_00 = pcVar2->src, op_00 != (c2_operand *)0x0)) {
        do {
          mark_address_taken_operand(op_00,mask);
          op_00 = op_00->next;
        } while (op_00 != (c2_operand *)0x0);
        return;
      }
      break;
    case '\x03':
      if (op->op == 0x14a) {
        puVar1 = &op->sym->storage->flags5;
        *puVar1 = *puVar1 | 4;
      }
      break;
    case '\x05':
      mark_address_taken_operand_case_1(op->base,mask);
      return;
    }
  }
  return;
}

