c1_symbol * __cdecl class_current_definition(void)

{
  if (-1 < g_class_depth) {
    return g_class_def_stack[g_class_depth].cls;
  }
  return (c1_symbol *)0x0;
}

