void __fastcall alias_refine_pointer_offsets_oa(uint32_t nrefs)

{
  c2_tuple *pcVar1;
  int iVar2;
  c2_symbol *pcVar3;
  c2_symbol *s;
  c2_symbol_cell *pcVar4;
  int row_off;
  int local_4;
  c2_symbol *fields;
  c2_symbol_cell *pointee;
  c2_operand *add_src;
  c2_tuple *def;
  c2_symbol *ptr_sym;
  c2_symbol *node_sym;
  
  if (1 < nrefs) {
    local_4 = nrefs - 1;
    row_off = 0x14;
    do {
      pcVar3 = *(c2_symbol **)((int)&g_alias_ref_table->sym + row_off);
      if ((pcVar3 != (c2_symbol *)0x0) &&
         (fields = ((pcVar3->u30).order_prev)->part_next, fields != (c2_symbol *)0x0)) {
        def = *(c2_tuple **)((int)&g_alias_ref_table->def + row_off);
        if (((def != (c2_tuple *)0x0) &&
            ((((def->op == 0x15b && ((1 << (def->src->kind & 0x1f) & 6U) != 0)) &&
              (pcVar1 = def->src->sym->def, pcVar1 != (c2_tuple *)0x0)) &&
             ((pcVar1->op == 0x16d && (add_src = pcVar1->src, add_src->kind == '\x02')))))) &&
           (add_src->next->kind == '\a')) {
          ptr_sym = add_src->sym;
          if ((ptr_sym->flags5 & 8) == 0) {
            ptr_sym = ptr_sym->storage;
          }
          if (((pcVar3 != ptr_sym) && ((ptr_sym->u30).order_prev != (c2_symbol *)0x0)) &&
             ((pcVar3 = ((ptr_sym->u30).order_prev)->part_next, pcVar3 != (c2_symbol *)0x0 &&
              (s = alias_find_member_by_offset(pcVar3,(add_src->next->u18).lo), s != pcVar3)))) {
            pcVar4 = symbol_list_add_unique
                               (*(c2_symbol_cell **)((int)&g_alias_ref_table->pointees + row_off),s,
                                4);
            *(c2_symbol_cell **)((int)&g_alias_ref_table->pointees + row_off) = pcVar4;
          }
        }
        for (node_sym = fields->part_next->part_next; node_sym != (c2_symbol *)0x0;
            node_sym = node_sym->part_next) {
          iVar2 = node_sym->offset;
          for (pointee = *(c2_symbol_cell **)((int)&g_alias_ref_table->pointees + row_off);
              pointee != (c2_symbol_cell *)0x0; pointee = pointee->next) {
            pcVar3 = pointee->sym;
            if (pcVar3->cls == '\x0e') {
              alias_add_offset_member(pcVar3,pcVar3->offset + iVar2);
            }
          }
        }
      }
      row_off = row_off + 0x14;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

