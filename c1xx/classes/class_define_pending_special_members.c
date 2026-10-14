char __cdecl class_define_pending_special_members(void)

{
  c1_symbol *sym;
  char cVar1;
  c1_symbol_vector *v;
  c1_symbol *key;
  c1_symbol_vector_iter local_c;
  
  v = (c1_symbol_vector *)0x0;
  if ((g_error_count != 0) || (g_pending_special_members == (c1_symbol_vector *)0x0)) {
    return '\0';
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x4000000;
  vector_iterator_init(&local_c,g_pending_special_members);
  cVar1 = vector_iter_next((int *)&local_c);
  sym = local_c.current;
  do {
    if (cVar1 == '\0') {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfbffffff;
      vector_release((int)g_pending_special_members);
      g_pending_special_members = v;
      return '\x01';
    }
    local_c.current = sym;
    switch((sym->tail).fn.special_kind) {
    case '\0':
    case '\x0e':
    case '\x0f':
    case '\x10':
      break;
    default:
      key = g_scope_vector->entries[(short)sym->scope_index];
      goto LAB_1041f3d6;
    case '\v':
    case '\f':
    case '\r':
      if (g_current_scope->current == g_current_scope->global_scope) goto switchD_1041f3bf_caseD_11;
      if (v == (c1_symbol_vector *)0x0) {
        v = (c1_symbol_vector *)symtab_record_new_kind4();
      }
      if (v->count == v->capacity) {
        v = vector_grow_checked(v);
      }
      v->entries[(short)v->count] = sym;
      v->count = v->count + 1;
      break;
    case '\x11':
switchD_1041f3bf_caseD_11:
      key = sym;
LAB_1041f3d6:
      class_queue_special_member_definition(&key->kind,sym);
    }
    cVar1 = vector_iter_next((int *)&local_c);
    sym = local_c.current;
  } while( true );
}

