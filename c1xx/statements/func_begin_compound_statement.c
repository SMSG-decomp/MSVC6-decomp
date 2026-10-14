void __cdecl func_begin_compound_statement(void)

{
  fe_name *pfVar1;
  
  (*g_il_emitter->vtbl->begin_block)();
  if (0xf8 < g_block_depth) {
    diag_fatal_simple(0x3d);
  }
  g_il_block_level = g_block_depth + '\x01';
  g_block_number = g_block_number + 1;
  g_block_depth = g_il_block_level;
  if (g_ilstore_status != 4) {
    if (((byte)g_compile_flags_c4 & 0x20) == 0) {
      scope_cleanup_record_new(g_current_scope);
    }
    if (g_opt_Zg == '\0') {
      il_emit_tuple(0x53,(node *)0x0);
    }
    if (1 < g_block_depth) {
      func_flow_state_note_f();
    }
    if (((g_opt_Zg == '\0') && (g_block_depth == '\x02')) &&
       ((g_flow_analysis_active == 0 || (g_current_function != (c1_symbol *)0x0)))) {
      if ((g_current_function->flags1 & 0x10) == 0x10) {
        init_member_initializer(g_member_function_class,g_ctor_mem_initializers);
        g_ctor_mem_initializers = (c1_node *)0x0;
        return;
      }
      if (g_ctor_mem_initializers != (c1_node *)0x0) {
        diag_error(0x226,g_current_function);
        return;
      }
      if ((g_current_function->flags1 & 0x20) == 0x20) {
        class_dtor_prologue(g_member_function_class);
        return;
      }
      pfVar1 = g_current_function->name;
      if (pfVar1 == g_name_scalar_deleting_dtor) {
        class_build_scalar_deleting_dtor_body(g_member_function_class);
        return;
      }
      if (pfVar1 == g_name_vector_deleting_dtor) {
        class_build_vector_deleting_dtor_body(g_member_function_class);
        return;
      }
      if (pfVar1 == g_name_default_ctor_closure) {
        class_build_default_ctor_closure_body(g_member_function_class);
        return;
      }
      if (pfVar1 == g_name_local_vftable_ctor_closure) {
        class_build_local_vftable_ctor_closure_body(g_member_function_class);
        return;
      }
      if (pfVar1 == g_name_copy_ctor_closure) {
        class_build_copy_ctor_closure_body(g_member_function_class);
        return;
      }
      if ((pfVar1 == g_name_placement_delete_closure) ||
         (pfVar1 == g_name_placement_array_delete_closure)) {
        class_build_placement_delete_closure_body(g_current_function);
      }
    }
  }
  return;
}

