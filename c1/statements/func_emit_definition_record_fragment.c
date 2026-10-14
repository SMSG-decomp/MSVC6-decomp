void __cdecl func_emit_definition_record_fragment(fe_function_record *rec,c1_symbol *sym,int symref)

{
  char cVar1;
  c1_type *type;
  c1_symbol *tag;
  int iVar2;
  
  if ((g_opt_noexpinl == '\0') &&
     ((((g_function_in_pch == '\0' || (g_pch_automatic != '\0')) || (g_pch_creating != 0)) ||
      (g_auto_pch_using != 0)))) {
    g_compile_function_body = '\x01';
  }
  if ((sym->flags21 & 0x80) == 0) {
    if (((g_compile_function_body == '\0') && ((sym->key_ref & 3) == 0)) &&
       ((g_c9il_mode != '\0' ||
        (iVar2 = (*g_idb->vtbl->idb_has_name)(g_idb,sym->name->text), iVar2 == 0)))) {
      diag_warning(4,(-(uint)((sym->flags21 & 1) != 0) & 9) + 0x1f9,sym);
      sym->flags1 = sym->flags1 | 2;
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
    free_list_push_124c(sym);
    type = sym->type;
    if (g_opt_Zg == '\0') {
      debug_type_index(type);
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        type = type->base;
        cVar1 = (char)type->code;
      }
      if ((((type->code & 0x300) != 0) && (tag = (type->extra).sym, tag != (c1_symbol *)0x0)) &&
         (((tag->kind & 0x1f) == 4 && ((tag->x2c).references == (c1_symbol_cell *)0x0)))) {
        debug_type_record_struct_complete(tag);
      }
    }
    free_list_pop_124c();
  }
  il_emit_symbol_with_mode(0xe,symref,g_compile_function_body);
  sym->flags1 = sym->flags1 | 2;
  return;
}

