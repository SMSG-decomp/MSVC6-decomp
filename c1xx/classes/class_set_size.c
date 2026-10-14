void __cdecl class_set_size(c1_symbol *cls)

{
  c1_u8 *pcVar1;
  
  ((cls->detail).cls)->size = g_class_def_stack[g_class_depth].offset;
  if (((cls->detail).cls)->size == 0) {
    g_class_def_stack[g_class_depth].offset = 1;
    ((cls->detail).cls)->size = 1;
    ((cls->detail).cls)->layout_flags3b = ((cls->detail).cls)->layout_flags3b | 8;
    pcVar1 = &((cls->detail).cls)->layout_flags3b;
    *pcVar1 = *pcVar1 | 4;
  }
  return;
}

