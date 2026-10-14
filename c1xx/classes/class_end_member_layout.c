void __cdecl class_end_member_layout(c1_symbol *cls)

{
  if ((g_class_def_stack[g_class_depth].bitfield_type != 0) &&
     (g_class_def_stack[g_class_depth].bit_offset != '\0')) {
    class_close_bit_field_unit();
  }
  class_warn_packing_sensitive_alignment((uint)g_class_def_stack[g_class_depth].alignment);
  ((cls->detail).cls)->members_end = g_class_def_stack[g_class_depth].offset;
  return;
}

