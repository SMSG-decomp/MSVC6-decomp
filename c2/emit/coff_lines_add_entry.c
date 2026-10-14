void __fastcall coff_lines_add_entry(int line,int offset)

{
  int iVar1;
  
  g_coff_last_line = line;
  if (g_coff_lines_function_closed == 0) {
    iVar1 = line - g_coff_function_first_line;
    if (iVar1 == 0) {
      iVar1 = 0x7fff;
    }
    coff_add_line_entry((uint16_t)iVar1,offset);
    g_coff_line_entry_count = g_coff_line_entry_count + 1;
    return;
  }
  g_coff_lines_function_closed = 0;
  return;
}

