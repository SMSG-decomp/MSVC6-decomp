void __fastcall coff_lines_function_done(c2_fe_symbol *fn)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if ((g_coff_function_first_line == 0) || ((g_opt_debug_info == 0 && (g_opt_line_numbers == 0)))) {
    g_coff_line_entry_count = 0;
  }
  else {
    coff_add_bf_symbol_and_first_line
              (g_coff_function_symbol,(uint16_t)g_coff_function_first_line,fn->code_size,fn->offset)
    ;
    g_coff_line_entry_count = 1;
  }
  if ((g_opt_edit_and_continue != 0) || (g_opt_ZX != 0)) {
    uVar2 = 0xffffffff;
    pcVar3 = fn->name;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    coff_function_checksum_add(fn->name,~uVar2 - 1);
  }
  return;
}

