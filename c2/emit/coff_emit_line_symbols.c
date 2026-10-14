void __fastcall coff_emit_line_symbols(c2_fe_symbol *f)

{
  if (((short)_g_coff_line_entry_count != 0) &&
     ((g_opt_debug_info != 0 || (g_opt_line_numbers != 0)))) {
    cv_emit_lf_symbol(_g_coff_line_entry_count);
    cv_emit_ef_symbol(g_coff_last_line,f->code_size + f->offset);
  }
  g_coff_lines_function_closed = 1;
  return;
}

