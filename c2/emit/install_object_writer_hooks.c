void install_object_writer_hooks(void)

{
  char *b;
  
  g_segment_group_name = "FLAT";
  if (g_opt_dos == 0) {
    g_segment_group_name = "DGROUP";
  }
  if ((g_opt_object_path == (char *)0x0) || (g_opt_debug_info == 0)) {
    g_hook_cv_function_debug_info = empty_hook;
    g_hook_cv_symbol_header = empty_hook;
    g_hook_cv_finish_globals = empty_hook;
  }
  else {
    g_hook_cv_function_debug_info = cv_emit_function_debug_info;
    g_hook_cv_symbol_header = cv_emit_end_symbol;
    g_hook_cv_finish_globals = cv_finish_global_symbols;
  }
  if (g_opt_object_path != (char *)0x0) {
    if (g_emit_coff_object != 0) {
      g_hook_lines_function_done = coff_lines_function_done;
      g_hook_emit_line_symbols = coff_emit_line_symbols;
      g_hook_start_function = coff_start_function;
      g_writer_write_bytes_hook = coff_write_bytes;
      g_hook_write_code_bytes = coff_write_bytes;
      g_hook_pad_section = coff_pad_section_to_offset;
      if ((g_opt_debug_info == 0) && (g_opt_line_numbers == 0)) {
        g_hook_lines_file_changed = empty_hook;
        g_hook_lines_add_entry = empty_hook;
      }
      else {
        g_hook_lines_file_changed = coff_lines_file_changed;
        g_hook_lines_add_entry = coff_lines_add_entry;
      }
      g_hook_enter_section_state = coff_enter_writer_section_state;
      g_hook_leave_section_state = coff_leave_writer_section_state;
      g_writer_reloc_type9_hook = coff_add_reloc_type9;
      g_hook_add_reloc_dir32 = coff_add_reloc_dir32;
      g_hook_add_reloc_type7 = coff_add_reloc_type7;
      g_hook_add_reloc_rel32 = coff_add_reloc_rel32;
      g_hook_cv_secrel_section_relocs = cv_add_secrel_section_relocs;
      g_hook_finish_object = coff_finish_object;
      g_hook_emit_init_record = coff_emit_init_record;
      g_hook_writer_request = coff_handle_writer_request;
      g_hook_emit_symbol_once = coff_emit_symbol_once;
    }
    if (g_opt_default_lib != 0) {
      b = default_crt_library_name();
      if (b != (char *)0x0) {
        add_comment_record(4,(int)b);
      }
      if ((g_opt_no_extensions == 0) && (g_opt_fortran_frontend == 0)) {
        add_comment_record(4,0x107a575c);
      }
    }
    if ((g_opt_edit_and_continue != 0) || (g_opt_ZX != 0)) {
      add_comment_record(10,0x107a8f28);
      if (g_opt_ZX != 0) {
        enc_load_previous_object();
      }
    }
    if (g_opt_dlp != 0) {
      add_comment_record(10,0x107a8f18);
    }
    if (g_emit_coff_object != 0) {
      coff_open_object_file();
    }
    if (g_opt_debug_info != 0) {
      cv_emit_compile_env_symbols();
    }
    return;
  }
  g_hook_lines_function_done = empty_hook;
  g_hook_emit_line_symbols = empty_hook;
  g_hook_pad_section = empty_hook;
  g_hook_start_function = objless_start_function;
  g_writer_write_bytes_hook = empty_hook;
  g_hook_write_code_bytes = empty_hook;
  g_writer_reloc_type9_hook = empty_hook;
  g_hook_add_reloc_dir32 = empty_hook;
  g_hook_add_reloc_type7 = empty_hook;
  g_hook_add_reloc_rel32 = empty_hook;
  g_hook_cv_secrel_section_relocs = empty_hook;
  g_hook_lines_file_changed = empty_hook;
  g_hook_lines_add_entry = empty_hook;
  g_hook_enter_section_state = empty_hook;
  g_hook_leave_section_state = empty_hook;
  g_hook_finish_object = empty_hook;
  g_hook_emit_init_record = objless_init_record_size;
  g_hook_writer_request = empty_hook;
  g_hook_emit_symbol_once = objless_mark_symbol_emitted;
  return;
}

