int __fastcall alias_collect_pointees_of_tree(c2_operand *op,c2_bitset *mask,c2_alias_ref *rec)

{
  c2_tuple *pcVar1;
  c2_operand *op_00;
  int iVar2;
  c2_bitset *src;
  c2_bitset *pcVar3;
  c2_symbol_cell *pcVar4;
  int iVar5;
  
  if ((op->flags & 0x20) == 0) {
    if (op->kind == '\x05') {
      op = op->base;
    }
    switch(op->kind) {
    case '\x01':
    case '\x02':
      if (((1 << (op->kind & 0x1f) & 6U) == 0) || (pcVar1 = op->sym->def, pcVar1 == (c2_tuple *)0x0)
         ) {
        if ((op->sym->flags5 & 8) == 0) {
          return 1;
        }
        src = symbol_overlap_alias_set(op->sym,mask);
        if (rec->pointee_nodes == (c2_bitset *)0x0) {
          pcVar3 = bitset_new(6);
          rec->pointee_nodes = pcVar3;
        }
        bitset_or(rec->pointee_nodes,src);
        bitset_free(src);
      }
      else {
        iVar5 = 0;
        if (pcVar1->op != 0x17d) {
          if (pcVar1->kind == '\x0e') {
            return 1;
          }
          if (pcVar1->kind == '\x12') {
            return 1;
          }
          for (op_00 = pcVar1->src; op_00 != (c2_operand *)0x0; op_00 = op_00->next) {
            iVar2 = alias_collect_pointees_of_tree(op_00,mask,rec);
            if (iVar2 != 0) {
              iVar5 = 1;
            }
          }
          return iVar5;
        }
      }
      break;
    case '\x03':
      pcVar4 = symbol_list_add_unique(rec->pointees,op->sym->storage,4);
      rec->pointees = pcVar4;
      return 0;
    case '\x06':
      return 1;
    }
  }
  return 0;
}

