int __fastcall
alias_collect_pointees_of_tree_offset
          (c2_symbol *root,c2_operand *op,c2_bitset *mask,c2_alias_ref *rec)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *op_00;
  c2_symbol *pcVar3;
  int iVar4;
  c2_bitset *pcVar5;
  c2_symbol_cell *pcVar6;
  c2_bitset *pcVar7;
  int iVar8;
  c2_symbol *ptr_sym;
  
  if ((op->flags & 0x20) == 0) {
    bVar1 = op->kind;
    switch(bVar1) {
    case 1:
    case 2:
      if (((1 << (bVar1 & 0x1f) & 6U) != 0) && (pcVar2 = op->sym->def, pcVar2 != (c2_tuple *)0x0)) {
        iVar8 = 0;
        if (pcVar2->op == 0x17d) {
          return 0;
        }
        if (pcVar2->kind == '\x0e') {
          return 1;
        }
        if (pcVar2->kind == '\x12') {
          return 1;
        }
        for (op_00 = pcVar2->src; op_00 != (c2_operand *)0x0; op_00 = op_00->next) {
          iVar4 = alias_collect_pointees_of_tree_offset(root,op_00,mask,rec);
          if (iVar4 != 0) {
            iVar8 = 1;
          }
        }
        return iVar8;
      }
      ptr_sym = op->sym;
      if ((ptr_sym->flags5 & 8) != 0) {
        pcVar7 = symbol_overlap_alias_set(ptr_sym,mask);
        if (rec->pointee_nodes == (c2_bitset *)0x0) {
          pcVar5 = bitset_new(6);
          rec->pointee_nodes = pcVar5;
        }
        bitset_or(rec->pointee_nodes,pcVar7);
        bitset_free(pcVar7);
        alias_find_or_add_offset_class(ptr_sym,0);
        return 0;
      }
      if (bVar1 != 2) {
        return 1;
      }
      ptr_sym = ptr_sym->storage;
      if ((ptr_sym->u30).order_prev == (c2_symbol *)0x0) {
        return 1;
      }
      pcVar7 = rec->pointee_nodes;
      break;
    case 3:
      pcVar6 = symbol_list_add_unique(rec->pointees,op->sym->storage,4);
      rec->pointees = pcVar6;
      return 0;
    default:
      goto switchD_10769c68_caseD_4;
    case 6:
      ptr_sym = (c2_symbol *)(op->u18).range;
      if (ptr_sym == g_alias_unknown_base) {
        return 1;
      }
      for (pcVar3 = ((root->u30).order_prev)->part_next; pcVar3 != (c2_symbol *)0x0;
          pcVar3 = pcVar3->part_next) {
        if (pcVar3 == ptr_sym) {
          if (pcVar3 != (c2_symbol *)0x0) {
            return 1;
          }
          break;
        }
      }
      pcVar7 = rec->pointee_nodes;
    }
    if (pcVar7 == (c2_bitset *)0x0) {
      pcVar7 = bitset_new(6);
      rec->pointee_nodes = pcVar7;
    }
    bitset_set(rec->pointee_nodes,
               (int)&((ptr_sym->u34).source_links)->next_of_source + g_alias_exposed_ref_count);
    alias_find_or_add_offset_class(ptr_sym,0);
    return 1;
  }
switchD_10769c68_caseD_4:
  return 0;
}

