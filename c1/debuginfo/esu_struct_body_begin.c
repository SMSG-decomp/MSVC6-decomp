c1_tag_symbol * __cdecl esu_struct_body_begin(c1_tag_symbol *tag,c1_type *type)

{
  uchar *puVar1;
  ushort uVar2;
  fe_line_map_row *pfVar3;
  int iVar4;
  
  if ((g_token_source->stream->flags & 1) != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar3 = &g_line_map_cached_row;
    }
    else {
      pfVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    iVar4 = (*g_idb->vtbl->idb_class_begin)
                      (g_idb,((short)pfVar3->line - (short)pfVar3->position) +
                             (short)g_token_position,0);
    if (iVar4 == 0) {
      diag_fatal(0x49,".\\esu.c",0x158);
    }
  }
  if ((g_browse_file != (char *)0x0) &&
     (((g_block_depth == '\0' || (g_opt_FR_browse != 0)) && (tag->name != g_name_unnamed)))) {
    (*g_il_emitter->vtbl->begin_block)();
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,(c1_symbol *)tag);
    (*g_il_emitter->vtbl->set_owner)(tag);
  }
  iVar4 = g_class_depth + 1;
  g_class_depth = iVar4;
  if (iVar4 != 0x10) {
    uVar2 = type->code & 0x20f;
    if ((uVar2 == 0x201) || (uVar2 == 0x202)) {
      g_struct_layouts[iVar4].flags = g_struct_layouts[iVar4].flags | 1;
    }
    else {
      g_struct_layouts[iVar4].flags = g_struct_layouts[iVar4].flags & 0xfe;
    }
    g_struct_layouts[iVar4].tag = tag;
    g_struct_layouts[iVar4].unk04 = 0;
    g_struct_layouts[iVar4].offset = 0;
    g_struct_layouts[iVar4].bitfield_bits = '\0';
    g_struct_layouts[iVar4].flags = g_struct_layouts[iVar4].flags & 0xfb;
    g_struct_layouts[iVar4].bitfield_type = 0;
    g_struct_layouts[iVar4].type = type;
    g_struct_layouts[iVar4].alignment = 1;
    if (g_scope_pool.left < 0xc) {
      pool_reserve(&g_scope_pool,0xc);
      iVar4 = g_class_depth;
    }
    puVar1 = g_scope_pool.cur;
    g_scope_pool.left = g_scope_pool.left - 0xc;
    if (g_scope_pool.cur == (uchar *)0x0) {
      g_scope_pool.cur = g_scope_pool.cur + 0xc;
      (g_struct_layouts[iVar4].tag)->members = (void *)0x0;
      return tag;
    }
    g_scope_pool.cur = g_scope_pool.cur + 0xc;
    puVar1[0] = '\0';
    puVar1[1] = '\0';
    puVar1[2] = '\0';
    puVar1[3] = '\0';
    puVar1[4] = '\0';
    puVar1[5] = '\0';
    puVar1[6] = '\0';
    puVar1[7] = '\0';
    puVar1[8] = '\0';
    puVar1[9] = '\0';
    puVar1[10] = '\0';
    puVar1[0xb] = '\0';
    (g_struct_layouts[g_class_depth].tag)->members = puVar1;
    return tag;
  }
  diag_fatal(0x2e,tag->type);
}

