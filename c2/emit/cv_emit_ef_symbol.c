void __fastcall cv_emit_ef_symbol(int value,int offset)

{
  void *local_4;
  
  if ((g_coff_line_info & 1) != 0) {
    local_4 = (void *)value;
    coff_add_symbol_with_aux(".ef",(uint16_t)_g_coff_cur_code_section,'e',offset,0,&local_4,0);
    *(short *)((int)local_4 + 4) = (short)value;
  }
  return;
}

