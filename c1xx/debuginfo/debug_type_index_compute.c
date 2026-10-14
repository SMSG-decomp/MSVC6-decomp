c1_u32 __cdecl debug_type_index_compute(c1_type *type)

{
  ushort code;
  c1_u32 cVar1;
  uint uVar2;
  
  code = type->code;
  if ((code & 0x100) != 0) {
    cVar1 = debug_type_record_enum((type->extra).cls);
    type->debug_index = cVar1;
    return cVar1;
  }
  if ((code & 0x200) != 0) {
    cVar1 = debug_type_record_class_forward((type->extra).cls);
    type->debug_index = cVar1;
    return cVar1;
  }
  if ((code & 0x400) == 0) {
    uVar2 = debug_cv_primitive_type_index(code);
    return uVar2;
  }
  return 2;
}

