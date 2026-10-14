void __cdecl rtti_emit_pending_descriptors(void)

{
  vector_for_each(g_rtti_type_descriptors,rtti_emit_type_descriptor);
  vector_for_each(g_rtti_base_class_descriptor_queue,rtti_emit_base_class_descriptor);
  vector_for_each(g_rtti_base_class_arrays,rtti_emit_base_class_array);
  vector_for_each(g_rtti_class_hierarchy_descriptors,rtti_emit_class_hierarchy_descriptor);
  vector_for_each(g_rtti_object_locator_queue,rtti_emit_complete_object_locator);
  g_rtti_type_descriptors = (c1_vector *)0x0;
  g_rtti_base_class_descriptor_queue = (c1_vector *)0x0;
  g_rtti_base_class_arrays = (c1_vector *)0x0;
  g_rtti_class_hierarchy_descriptors = (c1_vector *)0x0;
  g_rtti_object_locator_queue = (c1_vector *)0x0;
  return;
}

