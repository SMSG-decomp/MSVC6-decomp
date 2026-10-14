char * __cdecl decorate_name(c1_symbol *sym,c1_symbol *sym2)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  if ((sym->kind & 0x1f) == 0x15) {
    return sym->name->text;
  }
  g_decorate_template_arg_backref_count = 0;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  g_decorate_output_base = g_decorated_name;
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 4) || (bVar1 == 0x19)) {
    pcVar2 = decorate_scope_prefix_2(g_decorated_name,sym);
  }
  else {
    pcVar2 = decorate_name_body(g_decorated_name,sym,sym2);
  }
  pcVar2 = pcVar2 + -0x104df238;
  pcVar5 = pcVar2;
  if (0x7ff < (int)pcVar2) {
    diag_warning(1,0x1f7,0x53,sym);
    pcVar5 = (char *)0xff;
    uVar3 = SigForPbCb(g_decorated_name,pcVar2,0xffffffff);
    iVar6 = 8;
    pcVar2 = g_decorated_name + 0xfe;
    do {
      uVar4 = uVar3 & 0xf;
      uVar3 = uVar3 >> 4;
      iVar6 = iVar6 + -1;
      *pcVar2 = "0123456789abcdef"[uVar4];
      pcVar2 = pcVar2 + -1;
    } while (iVar6 != 0);
  }
  pcVar5[0x104df238] = '\0';
  return g_decorated_name;
}

