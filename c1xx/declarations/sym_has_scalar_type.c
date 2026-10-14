int __cdecl sym_has_scalar_type(c1_symbol *sym)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = sym->type->code;
  if (((((uVar1 & 0x30) == 0) && ((uVar1 & 0x100) == 0)) && ((uVar1 & 0x400) == 0)) &&
     ((-1 < (char)uVar1 || (((uVar1 & 0x8f) != 0x86 && ((uVar1 & 0x8f) != 0x82)))))) {
    uVar2 = uVar1 & 0x8f;
    if (uVar2 == 0x83) {
      return 0;
    }
    if (((-1 < (char)uVar1) || (uVar2 != 0x80)) && ((uVar2 != 0x8a && (uVar2 != 0x8e)))) {
      return 0;
    }
  }
  return 1;
}

