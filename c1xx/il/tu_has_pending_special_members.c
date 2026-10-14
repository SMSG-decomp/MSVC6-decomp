char __cdecl tu_has_pending_special_members(void)

{
  char cVar1;
  c1_symbol_vector_iter local_c;
  
  if ((g_error_count == 0) && (g_pending_special_members != (c1_symbol_vector *)0x0)) {
    if (g_current_scope->current == g_current_scope->global_scope) {
switchD_104b3fa3_caseD_1:
      return '\x01';
    }
    vector_iterator_init(&local_c,g_pending_special_members);
    cVar1 = vector_iter_next((int *)&local_c);
    if (cVar1 != '\0') {
      do {
        switch(((local_c.current)->tail).fn.special_kind) {
        case '\0':
        case '\v':
        case '\f':
        case '\r':
        case '\x0e':
        case '\x0f':
        case '\x10':
          cVar1 = vector_iter_next((int *)&local_c);
          if (cVar1 == '\0') {
            return '\0';
          }
          break;
        default:
          goto switchD_104b3fa3_caseD_1;
        }
      } while( true );
    }
  }
  return '\0';
}

