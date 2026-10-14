c1_type * class_end_definition(void)

{
  byte bVar1;
  c1_symbol *cls;
  c1_type *pcVar2;
  c1_u32 class_ni;
  c1_line_map_row *pcVar3;
  int iVar4;
  uint uStack_4;
  
  iVar4 = g_class_depth;
  g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags | 3;
  cls = g_class_def_stack[iVar4].cls;
  pcVar2 = g_class_def_stack[iVar4].type;
  if ((((cls->flags3 & 1) == 0) && (g_browse_file != (char *)0x0)) &&
     ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->end_block)();
  }
  if ((g_prototype_scope_depth == 0) && ((g_compile_flags_c8 & 0x20000000) == 0)) {
    if ((((cls->detail).cls)->flags3f & 6) != 0) {
      class_collect_conversion_types(cls);
    }
    if ((g_compile_flags_cc & 0x100000) == 0) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x4000000;
      class_layout_vptrs(cls);
      class_declare_implicit_special_members(cls);
      class_complete_layout_and_tables(cls);
      class_declare_constructor_closures(cls);
      class_declare_deleting_destructors_if_dtor(cls);
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfbffffff;
    }
  }
  bVar1 = ((cls->detail).cls)->layout_flags3a;
  ((cls->detail).cls)->layout_flags3a =
       ((byte)g_class_def_stack[g_class_depth].alignment ^ bVar1) & 0x3f ^ bVar1;
  cls->flags2 = cls->flags2 | 4;
  g_class_depth = g_class_depth + -1;
  ((cls->detail).cls)->flags3e = ((cls->detail).cls)->flags3e & 0xfb;
  g_qualified_lookup_found_overloads = 1;
  decl_state_restore(g_current_scope,'\0');
  decl_state_pop(g_current_scope);
  class_sort_members(cls);
  uStack_4 = 0;
  if ((g_token_source->stream->flags & 1) != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar3 = &g_line_map_cached_row;
    }
    else {
      pcVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    class_ni = ((cls->detail).cls)->gm_name_index;
    iVar4 = (*g_idb->vtbl->idb_class_end)
                      (g_idb,CONCAT22((short)(class_ni >> 0x10),
                                      (short)pcVar3->line - (short)pcVar3->position) +
                             g_token_position,class_ni,&uStack_4);
    if (iVar4 == 0) {
      diag_fatal(0x49,".\\esu.c",0x5b5);
    }
  }
  if (((g_minimal_rebuild != '\0') && (uStack_4 != 0)) &&
     (iVar4 = mre_note_class_type_index(g_minimal_rebuild_tracker,cls), iVar4 == 0)) {
    diag_error(0x1d7,g_pdb_file_name);
  }
  return pcVar2;
}

