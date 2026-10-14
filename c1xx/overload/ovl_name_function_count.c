uint __cdecl ovl_name_function_count(c1_symbol *sym,char exclude_templates)

{
  uint uVar1;
  byte bVar2;
  
  if ((sym->kind & 0x1f) == 0x1a) {
    if (*(char *)((int)&sym->type->extra + 2) != '\0') {
      return 0;
    }
    sym = *(c1_symbol **)sym->type;
  }
  bVar2 = sym->kind & 0x1f;
  if ((bVar2 != 8) && (bVar2 != 7)) {
    uVar1 = ovl_set_has_single_function(bVar2,sym,exclude_templates);
    return uVar1;
  }
  bVar2 = *(byte *)((int)&sym->tail + 9);
  if ((bVar2 & 0x20) == 0) {
    return (byte)~bVar2 >> 6 & 1;
  }
  return (uint)(exclude_templates == '\0');
}

