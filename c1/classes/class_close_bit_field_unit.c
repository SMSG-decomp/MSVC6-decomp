void class_close_bit_field_unit(void)

{
  if ((g_struct_layouts[g_class_depth].flags & 4) != 0) {
    g_struct_layouts[g_class_depth].offset =
         g_struct_layouts[g_class_depth].offset +
         (int)(char)(&g_type_rank_table)[(byte)g_struct_layouts[g_class_depth].bitfield_type & 0xf];
    return;
  }
  class_add_padding_member
            ((int)(char)(&g_type_rank_table)
                        [(byte)g_struct_layouts[g_class_depth].bitfield_type & 0xf]);
  return;
}

