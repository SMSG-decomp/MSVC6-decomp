char * __cdecl decorate_check_name_length(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  c1_type *pcVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) {
LAB_106186b4:
    return sym->name->text;
  }
  pcVar4 = sym->type;
  if ((pcVar4->code & 0x8f) == 0x83) {
    pcVar4 = type_skip_arrays(pcVar4->base);
  }
  if ((pcVar4->flags & 0x1f) != 5) {
    pcVar4 = sym->type;
    if ((pcVar4->code & 0x8f) == 0x83) {
      pcVar4 = type_skip_arrays(pcVar4->base);
    }
    if ((pcVar4->flags & 0x1f) != 3) goto LAB_106186b4;
  }
  iVar2 = format_snprintf(g_decorated_name,"%s",0x1800,sym->name->text);
  if ((sym->flags4 & 0x40) == 0) {
    func_check_argument_bytes_and_prototype(sym);
  }
  iVar3 = format_snprintf(g_decorated_name + iVar2,"@%d",0x1800 - iVar2,sym->detail);
  iVar3 = iVar3 + iVar2;
  iVar2 = iVar3;
  if (0x7ff < iVar3) {
    diag_warning(1,0x1f7,0x53,sym);
    iVar2 = 0xff;
    uVar5 = SigForPbCb(g_decorated_name,iVar3,0xffffffff);
    iVar3 = 8;
    pcVar6 = g_decorated_name + 0xfe;
    do {
      uVar7 = uVar5 & 0xf;
      uVar5 = uVar5 >> 4;
      iVar3 = iVar3 + -1;
      *pcVar6 = "0123456789abcdef"[uVar7];
      pcVar6 = pcVar6 + -1;
    } while (iVar3 != 0);
  }
  g_decorated_name[iVar2] = '\0';
  return g_decorated_name;
}

