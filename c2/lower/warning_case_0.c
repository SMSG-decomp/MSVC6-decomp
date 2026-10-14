c2_incr_function_record * __cdecl warning_case_0(int level,int id)

{
  c2_incr_function_record *pcVar1;
  char *fmt;
  
  pcVar1 = (c2_incr_function_record *)g_opt_warning_level;
  if (level <= g_opt_warning_level) {
    fmt = format_message(id + 4000);
    print_diagnostic(4000,id,fmt,&stack0x0000000c);
    if ((g_opt_warnings_as_errors != 0) && (g_error_count == 0)) {
      error(0xdc);
    }
    pcVar1 = (c2_incr_function_record *)0x0;
    if ((g_opt_incremental != 0) &&
       (pcVar1 = (c2_incr_function_record *)0x0, g_cur_func_sym != (c2_fe_symbol *)0x0)) {
      pcVar1 = g_cur_func_sym->incr;
      pcVar1->il_version = pcVar1->il_version - 1;
    }
  }
  return pcVar1;
}

