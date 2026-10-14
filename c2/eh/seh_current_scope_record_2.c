void * seh_current_scope_record_2(void)

{
  if (g_seh_scope_depth == 0) {
    return (void *)0x0;
  }
  return (void *)(&g_seh_except_nesting)[g_seh_scope_depth];
}

