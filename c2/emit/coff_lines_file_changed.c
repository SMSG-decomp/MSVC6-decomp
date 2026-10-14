void __fastcall coff_lines_file_changed(char *name)

{
  if ((g_coff_lines_function_closed == 0) && ((g_opt_debug_info != 0 || (g_opt_line_numbers != 0))))
  {
    cv_emit_lf_symbol(_g_coff_line_entry_count);
    coff_add_file_symbol(name);
    _g_coff_line_entry_count = _g_coff_line_entry_count & 0xffff0000;
    g_incr_object_not_reusable = 1;
    coff_close_pending_type6_slots();
  }
  return;
}

