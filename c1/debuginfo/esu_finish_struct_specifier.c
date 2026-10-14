c1_type * __cdecl esu_finish_struct_specifier(void)

{
  c1_tag_symbol *pcVar1;
  c1_type *pcVar2;
  fe_line_map_row *pfVar3;
  int iVar4;
  int local_4;
  
  pcVar1 = g_struct_layouts[g_class_depth].tag;
  pcVar2 = g_struct_layouts[g_class_depth].type;
  if (((pcVar1->name != g_name_unnamed) && (g_browse_file != (char *)0x0)) &&
     ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->end_block)();
  }
  iVar4 = g_class_depth;
  if ((g_struct_layouts[g_class_depth].bitfield_type != 0) &&
     (g_struct_layouts[g_class_depth].bitfield_bits != '\0')) {
    g_struct_layouts[g_class_depth].offset =
         g_struct_layouts[g_class_depth].offset +
         (int)(char)(&g_type_rank_table)[g_struct_layouts[g_class_depth].bitfield_type & 0xf];
  }
  class_warn_packing_sensitive_alignment((uint)g_struct_layouts[iVar4].alignment);
  iVar4 = g_struct_layouts[g_class_depth].offset;
  pcVar1->size = iVar4;
  if (iVar4 == 0) {
    pcVar1->size = 4;
  }
  local_4 = 0;
  pcVar1->alignment =
       (ushort)(byte)((byte)g_struct_layouts[g_class_depth].alignment ^ (byte)pcVar1->alignment) ^
       pcVar1->alignment;
  pcVar1->flags1 = pcVar1->flags1 | 1;
  g_class_depth = g_class_depth + -1;
  g_tag_found_in_current_scope = 1;
  if ((g_token_source->stream->flags & 1) != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar3 = &g_line_map_cached_row;
    }
    else {
      pfVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    iVar4 = (*g_idb->vtbl->idb_class_end)
                      (g_idb,CONCAT22((short)((uint)&local_4 >> 0x10),
                                      (short)pfVar3->line - (short)pfVar3->position) +
                             g_token_position,0,&local_4);
    if (iVar4 == 0) {
      diag_fatal(0x49,".\\esu.c",0x5b5);
    }
  }
  return pcVar2;
}

