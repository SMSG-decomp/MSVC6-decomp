c1_node * __cdecl
func_new_compiler_generated(c1_node *str,void *literal_name,byte pooled,char in_inline_function)

{
  void *segment;
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_symbol *pcVar3;
  c1_node *pcVar4;
  c1_type *pcVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  bool bVar9;
  
  cVar2 = g_block_depth;
  cVar1 = g_il_block_level;
  pcVar3 = sym_take_free_record(10,(void *)0x0,0);
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = arena_alloc(g_arenas,g_symbol_size_table[10] + 3 & 0xfffffffc);
    if (pcVar3 == (c1_symbol *)0x0) {
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = sym_init_kind(pcVar3,'\n',(void *)0x0,0);
    }
  }
  if (0x7ffffffe < g_next_entity_id) {
    diag_fatal_simple(0x37);
  }
  uVar8 = pcVar3->entity ^ g_next_entity_id;
  g_next_entity_id = g_next_entity_id + 1;
  pcVar3->entity = uVar8 & 0xffffff ^ pcVar3->entity;
  pcVar5 = str->type;
  bVar7 = (byte)pcVar5->code;
  if (((char)bVar7 < '\0') && ((bVar7 & 0x8f) == 0x82)) {
    pcVar5 = type_base(pcVar5);
    pcVar3->type = pcVar5;
  }
  else {
    pcVar3->type = pcVar5;
  }
  sym_mark_referenced(pcVar3);
  bVar7 = pcVar3->storage;
  pcVar3->flags4 = pcVar3->flags4 | 8;
  pcVar3->storage = '\0';
  pcVar3->flags21 = '\0';
  pcVar3->flags22 = '\0';
  pcVar3->flags23 = '\0';
  pcVar3->storage = (pcVar3->storage ^ bVar7 & 7) & 7 ^ pcVar3->storage;
  pcVar3->flags5 = pcVar3->flags5 | 4;
  pcVar3->flags2 = pcVar3->flags2 | 4;
  pcVar3->flags4 = pcVar3->flags4 | 4;
  if ((pooled == 0) && ((g_c9il_mode != '\0' || (in_inline_function == '\0')))) {
    pcVar3->storage = pcVar3->storage & 0xf8 ^ 3;
LAB_1047f0a8:
    if (in_inline_function == '\0') goto LAB_10441252;
  }
  else {
    bVar7 = (pooled & 1) << 6 | pcVar3->storage & 0xbf;
    pcVar3->storage = bVar7;
    pcVar3->storage = ((pooled == 0) + 2U ^ bVar7) & 7 ^ bVar7;
    pcVar3->name = literal_name;
    if (pooled == 0) goto LAB_1047f0a8;
  }
  bVar9 = g_c9il_mode == '\0';
  pcVar3->flags3 = bVar9 << 4 | pcVar3->flags3 & 0xef;
  if ((bVar9) && (iVar6 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb), iVar6 == 0)) {
    diag_fatal(0x49,"p1inl.inl",0x2ee);
  }
  g_il_block_level = '\0';
  g_block_depth = '\0';
LAB_10441252:
  pcVar3->flags1 = pcVar3->flags1 & 0xfe | 2;
  segment = g_data_seg_name;
  if ((g_string_pooling_readonly_state != '\0') && (pooled != 0)) {
    segment = g_const_seg_name;
  }
  if ((segment != (void *)0x0) && (segment != (void *)0x0)) {
    if (pooled == 0) {
      sym_set_or_clear_segment(pcVar3,(int)segment);
    }
    else {
      sym_set_segment_checked(pcVar3,segment);
    }
  }
  if ((((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags22 & 0xc) != 0)) &&
      (((g_current_function->flags21 & 1) != 0 || ((g_compile_flags_c4 & 0x200) != 0)))) &&
     ((g_current_function->flags22 & 4) != 0)) {
    pcVar3->flags22 = pcVar3->flags22 | 4;
  }
  if (pooled == 0) {
    pcVar3->flags3 = (g_block_depth != '\0') << 3 | pcVar3->flags3 & 0xf7;
  }
  else {
    (*g_current_scope->global_scope->vtbl->insert)(pcVar3);
  }
  pcVar4 = tree_new_symbol_ref(pcVar3,'\0');
  pcVar4->type = pcVar3->type;
  init_emit_relocations_to_buffer(pcVar3,str);
  il_emit_global_symbol((int *)&pcVar3->name);
  pcVar4->kind = '\x04';
  pcVar4->op = '\x06';
  g_il_block_level = cVar1;
  g_block_depth = cVar2;
  return pcVar4;
}

