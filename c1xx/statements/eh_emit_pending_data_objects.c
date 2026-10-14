void __cdecl eh_emit_pending_data_objects(void)

{
  vector_for_each(g_rtti_type_descriptors,rtti_emit_type_descriptor);
  vector_for_each(PTR_104d2cac,eh_emit_catchable_type);
  PTR_104d2cac = (c1_vector *)0x0;
  vector_for_each(PTR_104d2cb0,eh_emit_catchable_type_array);
  PTR_104d2cb0 = (c1_vector *)0x0;
  vector_for_each(PTR_104d2cb4,eh_emit_throw_info);
  PTR_104d2cb4 = (c1_vector *)0x0;
  return;
}

