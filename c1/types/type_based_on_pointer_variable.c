int __cdecl type_based_on_pointer_variable(c1_type *type)

{
  ushort uVar1;
  
  if ((((type->flags & 0x18) == 0x18) && ((type->code & 0x8f) == 0x82)) &&
     ((uVar1 = ((type->extra).sym)->type->code & 0x8f, uVar1 == 0x83 ||
      ((uVar1 == 0x82 || (uVar1 == 0x86)))))) {
    return 1;
  }
  return 0;
}

