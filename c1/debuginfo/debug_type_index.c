c1_u32 __cdecl debug_type_index(c1_type *type)

{
  c1_u32 cVar1;
  c1_u32 extraout_EAX;
  
  cVar1 = type->debug_index;
  if (cVar1 == 0) {
    if ((char)type->code < '\0') {
      cVar1 = debug_type_index_derived(type);
      return cVar1;
    }
    if ((type->flags & 0x3e0) != 0) {
      debug_type_record_modifier(type);
      return extraout_EAX;
    }
    cVar1 = debug_type_index_compute(type);
    type->debug_index = cVar1;
  }
  return cVar1;
}

