int __cdecl warning(int level,int id,...)

{
  c2_incr_function_record *level_00;
  int iVar1;
  char *pcVar2;
  
  level_00 = (c2_incr_function_record *)warning_state_lookup(id);
  switch(level_00) {
  case (c2_incr_function_record *)0x0:
    level_00 = (c2_incr_function_record *)g_opt_warning_level;
    if (level <= g_opt_warning_level) {
      pcVar2 = format_message(id + 4000);
      print_diagnostic(4000,id,pcVar2,&stack0x0000000c);
      if ((g_opt_warnings_as_errors != 0) && (g_error_count == 0)) {
        error(0xdc);
      }
      level_00 = (c2_incr_function_record *)0x0;
      if ((g_opt_incremental != 0) &&
         (level_00 = (c2_incr_function_record *)0x0, g_cur_func_sym != (c2_fe_symbol *)0x0)) {
        level_00 = g_cur_func_sym->incr;
        level_00->il_version = level_00->il_version - 1;
      }
    }
    break;
  case (c2_incr_function_record *)0x1:
  case (c2_incr_function_record *)0x2:
  case (c2_incr_function_record *)0x3:
  case (c2_incr_function_record *)0x4:
    iVar1 = warning_case_0((int)level_00,id);
    return iVar1;
  case (c2_incr_function_record *)0x5:
    warning_state_set((uint16_t)id,0xd);
    iVar1 = warning_case_0(level,id);
    return iVar1;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\error.c",0x83);
  case (c2_incr_function_record *)0xd:
    break;
  case (c2_incr_function_record *)0xe:
    pcVar2 = format_message(id + 4000);
    print_diagnostic(2000,id + 2000,pcVar2,&stack0x0000000c);
    level_00 = (c2_incr_function_record *)g_error_count;
    if (g_error_count == 0) {
      g_error_count = 1;
      return 0;
    }
  }
  return (int)level_00;
}

