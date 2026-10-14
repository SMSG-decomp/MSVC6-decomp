void __cdecl func_emit_definition_record(fe_function_record *rec)

{
  char cVar1;
  int *symref;
  c1_type *type;
  c1_symbol *pcVar2;
  int iVar3;
  
  il_emit_source_file((char *)rec->source_file);
  symref = rec->symbol_entry;
  pcVar2 = (c1_symbol *)(symref + -2);
  if ((*(byte *)((int)symref + -7) & 2) != 0) {
    return;
  }
  g_compile_function_body = '\0';
  g_function_in_pch = (byte)(rec->flags >> 4) & 1;
  if ((*(uint *)(*symref + 8) >> 0x1e & 1) == 0) {
    if ((*(byte *)(symref + 6) & 7) == 3) goto LAB_10620605;
    if ((*(byte *)((int)symref + 0x19) & 1) != 0) {
      *(byte *)(symref + 6) = *(byte *)(symref + 6) | 0x40;
      if ((*(byte *)((int)symref + 0x1a) & 8) != 0) goto LAB_10620605;
      if ((*(byte *)((int)symref + 0x19) & 0x10) == 0) {
        if ((*(byte *)((int)symref + 0x1a) & 4) != 0) {
          func_emit_definition_record_fragment(rec,pcVar2,(int)symref);
          return;
        }
        goto LAB_10620605;
      }
    }
  }
  else {
    if ((*(byte *)(symref + 6) & 7) == 3) {
      diag_warning(3,8,pcVar2,9);
      *(byte *)(symref + 6) = *(byte *)(symref + 6) & 0xf8 ^ 1;
    }
    if ((*(byte *)((int)symref + 0x19) & 8) == 0) {
      if ((*(byte *)((int)symref + 0x19) & 1) != 0) {
        diag_warning(3,8,pcVar2,0xe);
        *(byte *)((int)symref + 0x19) = *(byte *)((int)symref + 0x19) & 0xfe;
      }
      *(byte *)(symref + -1) = *(byte *)(symref + -1) | 0x80;
    }
    else {
      diag_warning(3,8,pcVar2,0xec);
      *(byte *)((int)symref + 0x19) = *(byte *)((int)symref + 0x19) & 0xf6;
      *(byte *)(symref + -1) = *(byte *)(symref + -1) | 0x80;
    }
  }
  g_compile_function_body = '\x01';
LAB_10620605:
  if ((*(byte *)((int)symref + 0x19) & 0x80) == 0) {
    if (((g_compile_function_body == '\0') && ((*(byte *)(symref + 4) & 3) == 0)) &&
       ((g_c9il_mode != '\0' ||
        (iVar3 = (*g_idb->vtbl->idb_has_name)(g_idb,*(char **)(*symref + 4)), iVar3 == 0)))) {
      diag_warning(4,(-(uint)((*(byte *)((int)symref + 0x19) & 1) != 0) & 9) + 0x1f9,pcVar2);
      *(byte *)((int)symref + -7) = *(byte *)((int)symref + -7) | 2;
      return;
    }
  }
  else {
    g_compile_function_body = '\x01';
  }
  g_function_ex_offset = rec->ex_offset;
  g_function_sy_offset = rec->sy_offset;
  g_function_tuple_count = rec->tuple_count;
  g_function_start_line = rec->start_line;
  g_function_formal_count = rec->formal_count;
  g_function_auto_inline = rec->flags & 1;
  g_function_has_body = 1;
  g_function_not_inlinable = rec->flags >> 2 & 1;
  g_function_body_reused = (byte)(rec->flags >> 5) & 1;
  if (g_opt_Zi != '\0') {
    free_list_push_124c(pcVar2);
    type = (c1_type *)symref[3];
    if (g_opt_Zg == '\0') {
      debug_type_index(type);
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        type = type->base;
        cVar1 = (char)type->code;
      }
      if (((((type->code & 0x300) != 0) && (pcVar2 = (type->extra).sym, pcVar2 != (c1_symbol *)0x0))
          && ((pcVar2->kind & 0x1f) == 4)) && ((pcVar2->x2c).references == (c1_symbol_cell *)0x0)) {
        debug_type_record_struct_complete(pcVar2);
      }
    }
    free_list_pop_124c();
  }
  il_emit_symbol_with_mode(0xe,(int)symref,g_compile_function_body);
  *(byte *)((int)symref + -7) = *(byte *)((int)symref + -7) | 2;
  return;
}

