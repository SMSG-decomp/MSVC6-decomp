c1_u32 __cdecl debug_type_index_derived(c1_type *type)

{
  c1_u32 cVar1;
  ushort uVar2;
  
  cVar1 = debug_cv_primitive_pointer_index(type);
  if (cVar1 == 0) {
    cVar1 = debug_type_index(type->base);
    uVar2 = type->code & 0x8f;
    if (uVar2 == 0x83) {
      cVar1 = debug_type_record_array(type,cVar1);
      type->debug_index = cVar1;
      return cVar1;
    }
    if (((byte)type->code & 0x83) == 0x81) {
      if (uVar2 != 0x85) {
        cVar1 = debug_type_record_procedure_leaf(type,cVar1);
        type->debug_index = cVar1;
        return cVar1;
      }
      cVar1 = debug_type_record_mfunction(type,0);
      type->debug_index = cVar1;
      return cVar1;
    }
    cVar1 = debug_type_record_pointer(type,cVar1);
  }
  type->debug_index = cVar1;
  return cVar1;
}

