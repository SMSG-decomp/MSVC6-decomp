int __cdecl format_parameter_list_text(int buf,int *list)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  c1_symbol *sym;
  int local_4;
  
  uVar1 = -(uint)(g_format_parameter_names != 0) & (uint)g_pending_parameter_scope;
  sym = (c1_symbol *)0x0;
  g_format_parameter_names = 0;
  local_4 = *list;
  list = list + 2;
  if (uVar1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(uVar1 + 4);
  }
  if (iVar4 != 0) {
    sym = (c1_symbol *)(iVar4 + -8);
  }
  while( true ) {
    if (sym == (c1_symbol *)0x0) {
      iVar2 = format_declaration_text((c1_symbol *)0x0,(c1_type *)*list);
      pcVar3 = format_buffer_text(iVar2);
      format_buffer_append_string(buf,pcVar3);
      format_buffer_free(iVar2);
    }
    else {
      iVar2 = format_declaration_text(sym,(c1_type *)0x0);
      pcVar3 = format_buffer_text(iVar2);
      format_buffer_append_string(buf,pcVar3);
      format_buffer_free(iVar2);
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 4), iVar4 != 0)) {
        sym = (c1_symbol *)(iVar4 + -8);
      }
    }
    list = list + 1;
    local_4 = local_4 + -1;
    if (local_4 < 1) break;
    format_buffer_append_char(buf,',');
  }
  return buf;
}

