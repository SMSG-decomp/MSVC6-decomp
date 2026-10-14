uint __cdecl type_member_pointer_class_has_vfptr(c1_type *type)

{
  c1_u32 cVar1;
  
  cVar1 = type_member_pointer_class(type);
  return (*(byte *)(*(int *)(cVar1 + 0x24) + 0x3a) & 0x40) >> 6;
}

