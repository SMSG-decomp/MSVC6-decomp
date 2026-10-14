c2_function * __fastcall read_function_il(c2_fe_symbol *fsym)

{
  uint32_t mod;
  uint32_t key;
  c2_reader_block *pcVar1;
  c2_reader_block *pcVar2;
  c2_function *fn;
  c2_scope_table *pcVar3;
  c2_tuple *pos;
  c2_tuple *first;
  c2_fe_symbol *label_sym;
  c2_reader_cell *local_4;
  
  local_4 = (c2_reader_cell *)0x0;
  fn = arena_alloc(1,0x40);
  g_reading_function = fn;
  fn->fsym = fsym;
  pcVar3 = scope_table_new();
  fn->scope = pcVar3;
  fn->flags = (fsym->fn_flags & 0x300) << 7 | fn->flags & 0xfffe7fff;
  g_reader_block_cursor = arena_alloc(1,0xc);
  if (g_pdb_il_mode == 0) {
    g_il_stream = g_pch_sym_il_file;
    if ((fsym->fn_flags & 1) == 0) {
      g_il_stream = g_sym_il_file;
    }
    fseek(g_il_stream,fsym->sym_offset,0);
  }
  else {
    g_il_stream = pdb_il_get_stream3(fsym->id,fsym->sym_offset);
  }
  read_function_symbols(fn);
  pcVar2 = g_reader_block_cursor->prev;
  while (pcVar1 = pcVar2, pcVar1 != (c2_reader_block *)0x0) {
    g_reader_block_cursor = pcVar1;
    pcVar2 = pcVar1->prev;
  }
  g_reader_block_cursor = g_reader_block_cursor->next;
  g_reader_new_locals = (c2_list_cell *)0x0;
  if (g_pdb_il_mode == 0) {
    g_il_stream = g_pch_exp_il_file;
    if ((fsym->fn_flags & 1) == 0) {
      g_il_stream = g_exp_il_file;
    }
    fseek(g_il_stream,(fsym->u4a).function.exp_offset,0);
  }
  else {
    mod = fsym->sym_offset;
    key = fsym->id;
    g_il_stream = pdb_il_get_stream4(key,mod);
    if (g_il_stream != (FILE *)0x0) {
      read_global_symbols(g_il_stream);
    }
    g_il_stream = pdb_il_get_stream2(key,mod);
  }
  g_reader_file_record_seen = 0;
  g_diag_line_needs_mapping = 1;
  g_current_line_abs = 0;
  g_cur_line = 0;
  g_cur_function_line_base = reset_line_state();
  fn->line_base = g_cur_function_line_base;
  pos = tuple_new_block_boundary();
  first = tuple_new_block_boundary();
  tuple_splice_after(pos,first);
  cfg_create(fn,pos,first,(-(uint)(g_inlining_active != 0) & 0xfffffff8) + 0xc);
  label_sym = label_symbol_new_in_scope(fn);
  g_return_label = tuple_new_label(label_sym);
  g_return_label_used = '\0';
  g_ptr_type = 0x3004;
  il_read_tree(fn,&local_4,pos,-1,1);
  g_current_line_abs = 0;
  g_cur_line = 0;
  g_ptr_type = g_ptr_type & 0xfff | 0x1000;
  empty_hook();
  lower_pointer_types_to_int(pos);
  reader_free_stack_and_reset();
  if ((g_opt_basic != 0) && (g_reader_basic_error_label != (c2_fe_symbol *)0x0)) {
    g_reader_basic_error_label = (c2_fe_symbol *)0x0;
    basic_split_entry_block(fn);
  }
  if (g_opt_debug_info != 0) {
    cv_link_scope_markers(fn);
  }
  g_reader_eh_object_locals = (c2_reader_eh_local *)0x0;
  return fn;
}

