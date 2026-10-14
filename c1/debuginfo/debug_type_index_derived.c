c1_u32 __cdecl debug_type_index_derived(c1_type *type)

{
  c1_u32 cVar1;
  byte bVar2;
  
  cVar1 = debug_cv_primitive_pointer_index(type);
  if (cVar1 == 0) {
    cVar1 = debug_type_index(type->base);
    bVar2 = (byte)type->code;
    if ((bVar2 & 0x8f) == 0x83) {
      cVar1 = debug_type_record_array(type,cVar1);
      type->debug_index = cVar1;
      return cVar1;
    }
    if ((bVar2 & 0x83) == 0x81) {
      cVar1 = debug_type_record_procedure_leaf(type,cVar1);
      type->debug_index = cVar1;
      return cVar1;
    }
    cVar1 = debug_type_record_pointer(type,cVar1);
  }
  type->debug_index = cVar1;
  return cVar1;
}

