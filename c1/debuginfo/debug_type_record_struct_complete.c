c1_u32 __cdecl debug_type_record_struct_complete(c1_symbol *tag)

{
  c1_u32 cVar1;
  
  debug_type_record_struct(tag);
  cVar1 = debug_type_record_class_forward(tag);
  return cVar1;
}

