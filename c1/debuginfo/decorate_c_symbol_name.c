char * __cdecl decorate_c_symbol_name(char *buf,c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) {
    iVar2 = format_snprintf(buf,"..%s",0x1800,sym->name->text);
    return buf + iVar2;
  }
  iVar2 = format_snprintf(buf,"%s",0x1800,sym->name->text);
  buf[iVar2] = '@';
  pcVar3 = decorate_calling_convention
                     (buf + iVar2 + 1,
                      (c1_type *)((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)));
  return pcVar3;
}

