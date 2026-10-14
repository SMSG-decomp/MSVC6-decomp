char * __cdecl decorate_function_string_literal(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  builtin_strncpy(g_decorated_name,"??_C",4);
  g_decorate_template_arg_backref_count = 0;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  g_decorate_output_base = g_decorated_name;
  pcVar1 = decorate_name_body(g_decorated_name + 4,g_current_function,(c1_symbol *)0x0);
  pcVar1 = decorate_number(pcVar1,g_function_string_literal_count);
  if (0x7ff < (int)(pcVar1 + -0x104df238)) {
    diag_warning(1,0x1f7,0x53,g_current_function);
    uVar2 = SigForPbCb(g_decorated_name,pcVar1 + -0x104df238,0xffffffff);
    iVar4 = 8;
    pcVar1 = g_decorated_name + 0xfe;
    do {
      uVar3 = uVar2 & 0xf;
      uVar2 = uVar2 >> 4;
      iVar4 = iVar4 + -1;
      *pcVar1 = "0123456789abcdef"[uVar3];
      pcVar1 = pcVar1 + -1;
    } while (iVar4 != 0);
    g_decorated_name[0xff] = '\0';
    return g_decorated_name;
  }
  *pcVar1 = '\0';
  return g_decorated_name;
}

