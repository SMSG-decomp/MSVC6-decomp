void * __cdecl class_current_definition_name(void)

{
  if (-1 < g_class_depth) {
    return (g_class_def_stack[g_class_depth].cls)->name;
  }
  return (void *)0x0;
}

