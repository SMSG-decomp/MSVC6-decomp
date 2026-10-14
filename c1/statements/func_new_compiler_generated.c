c1_node * __cdecl func_new_compiler_generated(c1_node *value,void *name,c1_u8 local,char named)

{
  c1_u8 saved_il_block_level;
  c1_u8 saved_block_depth;
  c1_symbol *pcVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  bool bVar7;
  
  saved_block_depth = g_block_depth;
  saved_il_block_level = g_il_block_level;
  pcVar1 = sym_take_free_record(10,(void *)0x0,0);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = arena_alloc(g_arenas,g_symbol_size_table[10] + 3 & 0xfffffffc);
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = (c1_symbol *)0x0;
    }
    else {
      pcVar1 = sym_init_kind(pcVar1,'\n',(void *)0x0,0);
    }
  }
  if (0x7ffffffe < g_next_entity_id) {
    diag_fatal_simple(0x37);
  }
  uVar6 = pcVar1->entity ^ g_next_entity_id;
  g_next_entity_id = g_next_entity_id + 1;
  pcVar1->entity = uVar6 & 0xffffff ^ pcVar1->entity;
  pcVar3 = value->type;
  bVar5 = (byte)pcVar3->code;
  if (((char)bVar5 < '\0') && ((bVar5 & 0x8f) == 0x82)) {
    pcVar3 = type_base(pcVar3);
    pcVar1->type = pcVar3;
  }
  else {
    pcVar1->type = pcVar3;
  }
  sym_mark_referenced(pcVar1);
  bVar5 = pcVar1->storage;
  pcVar1->flags3 = pcVar1->flags3 | 8;
  pcVar1->storage = '\0';
  pcVar1->flags21 = '\0';
  pcVar1->flags22 = '\0';
  pcVar1->flags23 = '\0';
  pcVar1->storage = (pcVar1->storage ^ bVar5 & 7) & 7 ^ pcVar1->storage;
  pcVar1->flags4 = pcVar1->flags4 | 4;
  pcVar1->flags1 = pcVar1->flags1 | 1;
  pcVar1->flags3 = pcVar1->flags3 | 4;
  if ((local == '\0') && ((g_c9il_mode != '\0' || (named == '\0')))) {
    pcVar1->storage = pcVar1->storage & 0xf8 ^ 3;
LAB_1063b16d:
    if (named == '\0') goto LAB_1061fcc5;
  }
  else {
    bVar5 = (local & 1) << 6 | pcVar1->storage & 0xbf;
    pcVar1->storage = bVar5;
    pcVar1->storage = ((local == '\0') + 2U ^ bVar5) & 7 ^ bVar5;
    pcVar1->name = name;
    if (local == '\0') goto LAB_1063b16d;
  }
  bVar7 = g_c9il_mode == '\0';
  pcVar1->flags2 = bVar7 << 2 | pcVar1->flags2 & 0xfb;
  if ((bVar7) && (iVar4 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb), iVar4 == 0)) {
    diag_fatal(0x49,"p1inl.inl",0x2ee);
  }
  g_il_block_level = '\0';
  g_block_depth = '\0';
LAB_1061fcc5:
  if ((g_string_pooling_readonly_active == '\0') || (local == '\0')) {
    if (g_data_seg_name != (void *)0x0) {
      pcVar2 = func_new_compiler_generated_fragment
                         (g_data_seg_name,local,pcVar1,value,saved_il_block_level,saved_block_depth)
      ;
      return pcVar2;
    }
  }
  else if ((g_const_seg_name != (void *)0x0) && (g_const_seg_name != (void *)0x0)) {
    if (local == '\0') {
      sym_set_or_clear_segment(pcVar1,(int)g_const_seg_name);
    }
    else {
      sym_set_segment_checked(pcVar1,g_const_seg_name);
    }
  }
  if ((((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags22 & 0xc) != 0)) &&
      (((g_current_function->flags21 & 1) != 0 || ((g_compile_flags_c4 & 0x200) != 0)))) &&
     ((g_current_function->flags22 & 4) != 0)) {
    pcVar1->flags22 = pcVar1->flags22 | 4;
  }
  if (local == '\0') {
    pcVar1->flags2 = (g_block_depth != '\0') << 1 | pcVar1->flags2 & 0xfd;
  }
  else {
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,pcVar1);
  }
  pcVar2 = tree_new_symbol_ref(pcVar1);
  pcVar2->type = pcVar1->type;
  init_emit_relocations_to_buffer(pcVar1,value);
  il_emit_global_symbol((int *)&pcVar1->name);
  pcVar2->kind = '\x04';
  pcVar2->op = '\x06';
  g_il_block_level = saved_il_block_level;
  g_block_depth = saved_block_depth;
  return pcVar2;
}

