void __cdecl rtti_reset_pending_descriptors(void)

{
  g_rtti_type_descriptors = (c1_vector *)0x0;
  g_rtti_base_class_descriptor_queue = (c1_vector *)0x0;
  g_rtti_base_class_arrays = (c1_vector *)0x0;
  g_rtti_class_hierarchy_descriptors = (c1_vector *)0x0;
  g_rtti_object_locator_queue = (c1_vector *)0x0;
  return;
}

