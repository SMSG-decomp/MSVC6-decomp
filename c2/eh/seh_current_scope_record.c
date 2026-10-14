c2_seh_try_scope * seh_current_scope_record(void)

{
  if (g_seh_scope_depth != 0) {
    return (c2_seh_try_scope *)(&g_seh_except_nesting)[g_seh_scope_depth];
  }
  return (c2_seh_try_scope *)0x0;
}

