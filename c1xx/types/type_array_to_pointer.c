c1_type * __cdecl type_array_to_pointer(c1_type *array_type)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_type_extra *extra;
  
  extra = &array_type->extra;
  uVar1 = decl_apply_default_calling_convention(0x82,array_type->flags);
  pcVar2 = type_intern_from_parts(array_type,0x82,uVar1 & 0x18,&extra->count);
  return pcVar2;
}

