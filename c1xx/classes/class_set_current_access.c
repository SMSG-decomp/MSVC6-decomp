void __cdecl class_set_current_access(c1_u8 access)

{
  g_class_def_stack[g_class_depth].flags =
       (g_class_def_stack[g_class_depth].flags ^ access) & 3 ^
       g_class_def_stack[g_class_depth].flags;
  return;
}

