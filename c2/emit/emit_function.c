int __fastcall emit_function(c2_function *fn)

{
  c2_fe_symbol *fn_00;
  uint uVar1;
  c2_list_cell *list;
  int want_fpo_section;
  
  fn_00 = fn->fsym;
  if (((g_opt_qif == 0) && ((fn->flags & 0x100) == 0)) && ((fn_00->attrs & 0x1000) == 0)) {
    want_fpo_section = 0;
  }
  else {
    want_fpo_section = 1;
  }
  emit_add_crt_refs();
  if ((fn->flags & 0x20000) != 0) {
    emit_expand_cgintrinsics(fn);
  }
  if ((fn->fsym->attrs & 0x1000) == 0) {
    if (g_cxx_eh_prolog_emitted == 0) goto LAB_1073de6e;
    cxx_eh_emit_funclets(fn);
  }
  else {
    if (g_opt_basic != 0) {
      emit_strip_scope_markers(fn);
    }
    emit_strip_eh_pseudo_ops(fn);
  }
  if (g_cxx_eh_prolog_emitted != 0) {
    cxx_eh_emit_handler_thunk(fn);
  }
LAB_1073de6e:
  emit_prepare_branches(fn);
  if (g_opt_qifdiv != 0) {
    emit_fix_x87_fwait(fn);
  }
  if ((fn->flags & 1) != 0) {
    emit_expand_inline_asm_blocks(fn);
  }
  if ((g_vb_entry_tail_chain != (c2_tuple *)0x0) || (g_vb_fp_error_label != (c2_tuple *)0x0)) {
    insert_vb_fp_exception_checks(fn);
  }
  list = emit_collect_symbol_refs(fn);
  g_func_source_file = (char *)0x0;
  g_func_first_line = 0;
  emit_fixup_symbol_offsets();
  relax_branches(fn);
  assign_code_offsets(fn,1);
  if (g_opt_qi0f != 0) {
    fix_jcc_line_crossings(fn);
  }
  if (g_func_source_file == (char *)0x0) {
    g_func_source_file = g_opt_f;
  }
  (*g_hook_start_function)(fn_00,g_func_source_file,want_fpo_section,g_func_first_line);
  emit_section_flush(list);
  (*g_hook_enter_section_state)();
  emit_code_bytes(fn);
  (*g_hook_leave_section_state)();
  emit_asm_listing(fn);
  if (((fn->flags & 0x18000) != 0) && (g_opt_debug_info != 0)) {
    emit_eh_section_symbols(fn);
  }
  (*g_hook_cv_function_debug_info)(fn_00);
  uVar1 = fn->flags;
  if (((uVar1 & 0x100) != 0) || (g_opt_qif != 0)) {
    emit_fpo_record(fn_00,~uVar1 >> 8 & 1,uVar1 >> 5 & 1);
  }
  g_param_cursor = 8;
  g_frame_cursor = 0;
  g_frame_eh_record = (c2_fe_symbol *)0x0;
  g_eh_guard_local = (c2_symbol *)0x0;
  g_eh_record_pushed = 0;
  g_frame_eh_extra_state = 0;
  return 0;
}

