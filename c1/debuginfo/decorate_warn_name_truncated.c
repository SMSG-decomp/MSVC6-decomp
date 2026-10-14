char * __cdecl decorate_warn_name_truncated(c1_symbol *sym)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  bVar1 = sym->kind & 0x1f;
  if ((((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) && ((sym->storage & 7) != 3)) {
    return sym->name->text;
  }
  pcVar2 = decorate_c_symbol_name(g_decorated_name,sym);
  pcVar2 = pcVar2 + -0x1066a0e0;
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
  pcVar5[0x1066a0e0] = '\0';
  return g_decorated_name;
}

