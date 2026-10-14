int __cdecl asm_symbol_length(c1_symbol *sym)

{
  int iVar1;
  
  if ((((sym->kind & 0x1f) == 9) || ((sym->flags4 & 4) == 0)) ||
     (iVar1 = *(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8), iVar1 == 0))
  {
    iVar1 = 1;
  }
  return iVar1;
}

