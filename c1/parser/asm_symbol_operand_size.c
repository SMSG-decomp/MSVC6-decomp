int __cdecl asm_symbol_operand_size(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  c1_type *type;
  
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    iVar2 = type_size(sym->type);
    if (iVar2 == 4) {
      return 0xffff;
    }
  }
  if ((sym->kind & 0x1f) != 9) {
    type = sym->type;
    if ((sym->flags4 & 4) != 0) {
      type = type->base;
    }
    iVar2 = type_size(type);
    return iVar2;
  }
  return 0xffff;
}

