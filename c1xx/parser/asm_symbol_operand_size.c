int __cdecl asm_symbol_operand_size(c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  c1_type *t;
  
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    iVar2 = type_size(sym->type);
    if (iVar2 == 4) {
      return 0xffff;
    }
  }
  if ((sym->kind & 0x1f) != 9) {
    t = sym->type;
    if ((sym->flags5 & 4) != 0) {
      t = t->base;
    }
    iVar2 = type_size(t);
    return iVar2;
  }
  return 0xffff;
}

