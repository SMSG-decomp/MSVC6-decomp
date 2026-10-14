c2_symbol * alias_new_class_record(void)

{
  c2_symbol *pcVar1;
  c2_alias_sym_info *pcVar2;
  c2_alias_ref *pcVar3;
  
  pcVar1 = arena_alloc(4,0x54);
  (pcVar1->u34).refs = g_alias_symbol_number_count;
  g_alias_symbol_number_count = g_alias_symbol_number_count + 1;
  pcVar1->cls = '\x0e';
  pcVar2 = arena_alloc(4,0x14);
  (pcVar1->u30).alias_info = pcVar2;
  pcVar3 = arena_alloc(4,0x14);
  pcVar2->points_to = pcVar3;
  return pcVar1;
}

