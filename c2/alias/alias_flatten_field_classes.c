void __fastcall alias_flatten_field_classes(c2_symbol *field_class)

{
  c2_alias_sym_info *pcVar1;
  c2_alias_ref *pcVar2;
  c2_bitset *pcVar3;
  int iVar4;
  c2_symbol_cell *pcVar5;
  c2_symbol *sub_field;
  c2_alias_ref *ref_row;
  c2_alias_ref *refs;
  
  refs = g_alias_ref_table;
  pcVar1 = (field_class->u30).alias_info;
  iVar4 = (int)&((field_class->u34).source_links)->next_of_source + g_alias_exposed_ref_count;
  pcVar2 = pcVar1->points_to;
  pcVar3 = pcVar2->pointee_nodes;
  ref_row = g_alias_ref_table + iVar4;
  ref_row->pointees = pcVar2->pointees;
  refs[iVar4].pointee_nodes = pcVar3;
  sub_field = pcVar1->fields;
  refs[iVar4].sym = field_class;
  if (sub_field != (c2_symbol *)0x0) {
    pcVar5 = symbol_list_add_unique(ref_row->pointees,sub_field->part_next,4);
    g_alias_ref_table[iVar4].pointees = pcVar5;
    do {
      alias_flatten_field_classes(sub_field);
      sub_field = sub_field->part_next;
    } while (sub_field != (c2_symbol *)0x0);
  }
  return;
}

