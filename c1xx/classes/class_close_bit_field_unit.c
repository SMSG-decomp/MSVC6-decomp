void __cdecl class_close_bit_field_unit(void)

{
  if ((g_class_def_stack[g_class_depth].flags & 0x20) != 0) {
    g_class_def_stack[g_class_depth].offset =
         g_class_def_stack[g_class_depth].offset +
         (int)(char)(&g_type_rank_table)[(byte)g_class_def_stack[g_class_depth].bitfield_type & 0xf]
    ;
    return;
  }
  class_append_alignment_member
            ((int)(char)(&g_type_rank_table)
                        [(byte)g_class_def_stack[g_class_depth].bitfield_type & 0xf]);
  return;
}

