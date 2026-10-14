int __cdecl class_is_innermost_being_defined(int cls)

{
  if (-1 < g_class_depth) {
    return CONCAT31((int3)((uint)g_class_def_stack[g_class_depth].cls >> 8),
                    (fe_name *)cls == (g_class_def_stack[g_class_depth].cls)->name);
  }
  return g_class_depth & 0xffffff00;
}

