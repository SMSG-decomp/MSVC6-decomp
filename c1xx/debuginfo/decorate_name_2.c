char * __cdecl decorate_name_2(c1_symbol *tmpl,int *args)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  g_decorate_output_base = g_decorated_name;
  g_decorate_template_arg_backref_count = 0;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  g_decorated_name[0] = '?';
  g_decorated_name[1] = '$';
  pcVar1 = decorate_name_with_backreference(g_decorated_name + 2,(int)tmpl->name,0);
  iVar4 = *args;
  do {
    pcVar1 = decorate_backreference(pcVar1,iVar4);
    iVar4 = *(int *)(iVar4 + 4);
  } while (iVar4 != 0);
  if ((int)(pcVar1 + -0x104df238) < 0x800) {
    *pcVar1 = '\0';
    return g_decorated_name;
  }
  diag_warning(1,0x1f7,0x53,tmpl);
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

