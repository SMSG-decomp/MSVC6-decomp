void __thiscall scope_vector_add(c1_symbol *sym,char kind)

{
  c1_u16 cVar1;
  
  cVar1 = 0;
  if (g_scope_vector != (c1_symbol_vector *)0x0) {
    cVar1 = g_scope_vector->count;
  }
  if (kind == '\x04') {
    ((sym->detail).cls)->scope_index = cVar1;
  }
  else if ((kind == '\a') || (kind == '\b')) {
    (sym->x28).block_number = cVar1;
  }
  else if (kind == '\x19') {
    *(c1_u16 *)&sym->type->base = cVar1;
  }
  if ((cVar1 != 0) && (cVar1 != 0xffff)) {
    if (g_scope_vector->count == g_scope_vector->capacity) {
      g_scope_vector = vector_grow_checked(g_scope_vector);
    }
    g_scope_vector->entries[(short)g_scope_vector->count] = sym;
    g_scope_vector->count = g_scope_vector->count + 1;
    return;
  }
  diag_fatal_simple(0x41);
}

