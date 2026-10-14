void __cdecl pch_mark_rtti_type_descriptors(void)

{
  pch_mark_vector_slots(g_rtti_type_descriptors,pch_mark_rtti_type_descriptor_nop);
  return;
}

