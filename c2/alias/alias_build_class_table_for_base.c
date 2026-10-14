void __fastcall alias_build_class_table_for_base(c2_symbol *s,uint32_t nsyms)

{
  c2_symbol_cell **ppcVar1;
  uint8_t uVar2;
  ushort uVar3;
  c2_alias_sym_info *pcVar4;
  uint32_t uVar5;
  int off;
  c2_symbol *pcVar6;
  bool bVar7;
  c2_bitvec *v;
  c2_symbol *field_rec;
  c2_symbol_cell *pcVar8;
  c2_bitvec *pcVar9;
  c2_symbol_cell *member_cell;
  int iVar10;
  c2_symbol_cell *struct_pointees;
  int off_00;
  uint32_t size;
  c2_symbol_cell *struct_pointees_head;
  c2_alias_class_cache *local_14;
  c2_symbol_cell *class_cell;
  int32_t alias_number;
  c2_symbol_cell *cell;
  
  pcVar4 = (s->u30).alias_info;
  local_14 = pcVar4->classes;
  if (local_14 != (c2_alias_class_cache *)0x0) {
    v = bitvec_new(8,nsyms);
    alias_number = (int32_t)(s->u34).source_links;
    bVar7 = false;
    struct_pointees_head = (c2_symbol_cell *)0x0;
    struct_pointees = (c2_symbol_cell *)0x0;
    pcVar8 = g_alias_ref_table[alias_number + g_alias_exposed_ref_count].pointees;
    while (cell = pcVar8, cell != (c2_symbol_cell *)0x0) {
      pcVar8 = cell->next;
      uVar2 = cell->sym->cls;
      if ((uVar2 != '\f') && (uVar2 != '\x0e')) {
        bitvec_set(v,(cell->sym->u34).refs);
        uVar2 = cell->sym->cls;
        if ((uVar2 == '\a') || (uVar2 == '\b')) {
          cell->next = struct_pointees;
          struct_pointees = cell;
          struct_pointees_head = cell;
        }
      }
    }
    do {
      if (struct_pointees == (c2_symbol_cell *)0x0) {
        iVar10 = local_14->cls * 4;
        g_alias_primary_table[local_14->cls] = g_alias_primary_table[(int)local_14->pointees];
      }
      else {
        uVar5 = local_14->cls;
        iVar10 = uVar5 * 4;
        do {
          ppcVar1 = g_alias_primary_table + uVar5;
          pcVar8 = symbol_list_add_unique(g_alias_primary_table[uVar5],struct_pointees->sym,1);
          struct_pointees = struct_pointees->next;
          *ppcVar1 = pcVar8;
        } while (struct_pointees != (c2_symbol_cell *)0x0);
        if (g_alias_primary_table[(int)local_14->pointees] != (c2_symbol_cell *)0x0) {
          pcVar8 = symbol_list_add_unique
                             (g_alias_primary_table[uVar5],
                              g_alias_primary_table[(int)local_14->pointees]->sym,1);
          g_alias_primary_table[uVar5] = pcVar8;
        }
      }
      if (bVar7) {
        pcVar9 = bitvec_clone(v);
      }
      else {
        bVar7 = true;
        pcVar9 = v;
      }
      uVar5 = local_14->size;
      off = *(int *)((int)local_14->key + 0x24);
      *(c2_bitvec **)((int)g_alias_class_symbol_sets + iVar10) = pcVar9;
      if (off < 1) {
        for (pcVar8 = g_alias_ref_table[alias_number + g_alias_exposed_ref_count].pointees;
            pcVar8 != (c2_symbol_cell *)0x0; pcVar8 = pcVar8->next) {
          if (pcVar8->sym->cls == '\x0e') {
            alias_mark_offset_members(pcVar8->sym,pcVar9,off,uVar5);
          }
        }
      }
      else {
        for (pcVar8 = g_alias_ref_table[alias_number + g_alias_exposed_ref_count].pointees;
            pcVar8 != (c2_symbol_cell *)0x0; pcVar8 = pcVar8->next) {
          field_rec = pcVar8->sym;
          if (field_rec->cls == '\x0e') {
            off_00 = off;
            size = uVar5;
            field_rec = alias_find_member_by_offset(field_rec,field_rec->offset + off);
            alias_mark_offset_members(field_rec,pcVar9,off_00,size);
          }
        }
      }
      for (class_cell = *(c2_symbol_cell **)((int)g_alias_primary_table + iVar10);
          class_cell != (c2_symbol_cell *)0x0; class_cell = class_cell->next) {
        if ((class_cell->sym->cls == '\f') &&
           (member_cell = (class_cell->sym->u30).members, member_cell != (c2_symbol_cell *)0x0)) {
          field_rec = pcVar4->fields;
          do {
            uVar3 = (member_cell->sym->fe->u3e).alias_class;
            pcVar6 = field_rec;
            if (g_alias_class_symbol_sets[uVar3] == (c2_bitvec *)0x0) {
              pcVar9 = bitvec_new(8,nsyms);
              g_alias_class_symbol_sets[uVar3] = pcVar9;
            }
            for (; pcVar6 != (c2_symbol *)0x0; pcVar6 = pcVar6->part_next) {
              bitvec_set(g_alias_class_symbol_sets[uVar3],(pcVar6->u34).refs);
            }
            member_cell = member_cell->next;
          } while (member_cell != (c2_symbol_cell *)0x0);
        }
      }
      local_14 = local_14->next;
      struct_pointees = struct_pointees_head;
    } while (local_14 != (c2_alias_class_cache *)0x0);
  }
  for (field_rec = pcVar4->fields; field_rec != (c2_symbol *)0x0; field_rec = field_rec->part_next)
  {
    if ((field_rec->u30).order_prev != (c2_symbol *)0x0) {
      alias_build_class_table_for_base(field_rec,nsyms);
    }
  }
  return;
}

