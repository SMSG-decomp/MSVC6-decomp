void __fastcall alias_collect_pointees(c2_operand *op,c2_alias_call_record *rec,c2_bitset *sets)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_bitset *src;
  c2_symbol_cell *pcVar3;
  int32_t ref_number;
  c2_operand *op_00;
  c2_symbol *ptr_sym;
  
  if ((op->flags & 0x20) == 0) {
    bVar1 = op->kind;
    switch(bVar1) {
    case 1:
    case 2:
      if (((1 << (bVar1 & 0x1f) & 6U) != 0) && (pcVar2 = op->sym->def, pcVar2 != (c2_tuple *)0x0)) {
        if (pcVar2->kind == '\x0e') {
          return;
        }
        if (pcVar2->kind == '\x12') {
          return;
        }
        if (pcVar2->op == 0x17d) {
          return;
        }
        op_00 = pcVar2->src;
        if (op_00 == (c2_operand *)0x0) {
          return;
        }
        do {
          alias_collect_pointees(op_00,rec,sets);
          op_00 = op_00->next;
        } while (op_00 != (c2_operand *)0x0);
        return;
      }
      ptr_sym = op->sym;
      if ((ptr_sym->flags5 & 8) != 0) {
        src = symbol_overlap_alias_set(ptr_sym,sets);
        bitset_or(rec->pointee_nodes,src);
        bitset_free(src);
        return;
      }
      if (bVar1 != 2) {
        return;
      }
      ref_number = (ptr_sym->storage->u34).refs;
      break;
    case 3:
      ptr_sym = op->sym->storage;
      bitset_set(rec->pointee_nodes,
                 (int)&((ptr_sym->u34).source_links)->next_of_source + g_alias_exposed_ref_count);
      pcVar3 = symbol_list_add_unique(rec->pointees,ptr_sym,4);
      rec->pointees = pcVar3;
      return;
    default:
      goto switchD_1076a248_caseD_4;
    case 6:
      ptr_sym = (op->u18).reg;
      if (ptr_sym == (c2_symbol *)0x0) {
        return;
      }
      if (ptr_sym == g_alias_unknown_base) {
        return;
      }
      ref_number = (ptr_sym->u34).refs;
    }
    bitset_set(rec->pointee_nodes,ref_number + g_alias_exposed_ref_count);
  }
switchD_1076a248_caseD_4:
  return;
}

