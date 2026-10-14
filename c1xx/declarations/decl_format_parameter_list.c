void * __cdecl decl_format_parameter_list(void *buf,c1_function_params *params,c1_type *fntype)

{
  c1_type_list **ppcVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  c1_type **ppcVar6;
  bool bVar7;
  c1_symbol *local_4;
  
  bVar7 = g_format_params_with_names != 0;
  g_format_params_with_names = 0;
  ppcVar1 = &params->list;
  local_4 = (c1_symbol *)0x0;
  uVar2 = -(uint)bVar7 & (uint)g_pending_parameter_scope;
  params = (c1_function_params *)(*ppcVar1)->count;
  ppcVar6 = (*ppcVar1)->types;
  if (g_opt_Zg != '\0') {
    if ((fntype->flags & 0x4000) != 0) {
      format_buffer_append_string((int)buf,"void");
      return buf;
    }
    if (((fntype->flags & 0x8000) != 0) &&
       (params = (c1_function_params *)((int)&params[-1].list + 3),
       params == (c1_function_params *)0x0)) {
      format_buffer_append_string((int)buf,"...");
      return buf;
    }
  }
  if (uVar2 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(uVar2 + 4);
  }
  if (iVar5 == 0) goto LAB_10484cb1;
  while ((*(byte *)(iVar5 + -5) & 1) != 0) {
    params = (c1_function_params *)((int)&params[-1].list + 3);
    ppcVar6 = ppcVar6 + 1;
    if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 4), iVar5 == 0)) break;
  }
  do {
    iVar3 = format_symbol_declaration_text((c1_symbol *)0x0,*ppcVar6);
    pcVar4 = format_buffer_text(iVar3);
    format_buffer_append_string((int)buf,pcVar4);
    format_buffer_free(iVar3);
    while( true ) {
      ppcVar6 = ppcVar6 + 1;
      params = (c1_function_params *)((int)&params[-1].list + 3);
      if ((int)params < 1) {
        if ((g_opt_Zg != '\0') && ((fntype->flags & 0x8000) != 0)) {
          format_buffer_append_string((int)buf,",...");
        }
        return buf;
      }
      format_buffer_append_char((int)buf,',');
LAB_10484cb1:
      if (local_4 == (c1_symbol *)0x0) break;
      iVar3 = format_symbol_declaration_text(local_4,(c1_type *)0x0);
      pcVar4 = format_buffer_text(iVar3);
      format_buffer_append_string((int)buf,pcVar4);
      format_buffer_free(iVar3);
      if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 4), iVar5 != 0)) {
        local_4 = (c1_symbol *)(iVar5 + -8);
      }
    }
  } while( true );
}

