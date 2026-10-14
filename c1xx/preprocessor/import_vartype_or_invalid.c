ushort __cdecl import_vartype_or_invalid(void *typeinfo,void *typedesc)

{
  ushort uVar1;
  
  uVar1 = import_typedesc_to_vartype(typeinfo,typedesc);
  if ((uVar1 & 0x8000) != 0) {
    uVar1 = 0xffff;
  }
  return uVar1;
}

