c1_u32 __cdecl type_member_pointer_class(c1_type *type)

{
  ushort uVar1;
  
  uVar1 = type->code & 0x8f;
  if ((uVar1 != 0x8a) && (uVar1 != 0x8e)) {
    return 0;
  }
  return (c1_u32)(type->extra).cls;
}

