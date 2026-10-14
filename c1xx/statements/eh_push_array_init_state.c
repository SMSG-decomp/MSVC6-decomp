void __cdecl eh_push_array_init_state(c1_symbol *sym)

{
  c1_type *pcVar1;
  byte bVar2;
  
  g_init_declaration_depth = g_init_declaration_depth + 1;
  bVar2 = sym->storage & 7;
  if ((bVar2 == 0) || (3 < bVar2)) {
    pcVar1 = sym->type;
    bVar2 = (byte)pcVar1->code;
    if ((bVar2 & 0x8f) == 0x83) {
      while ((char)bVar2 < '\0') {
        pcVar1 = pcVar1->base;
        bVar2 = (byte)pcVar1->code;
      }
      if ((pcVar1->code & 0x200) != 0) {
        g_eh_array_init_symbol = sym;
        g_eh_array_init_state = g_eh_current_state;
        list_push_in_arena((int *)&g_eh_state_stack,4);
        g_eh_state_stack->value = g_eh_context_kind;
        g_eh_context_kind = 7;
      }
    }
  }
  return;
}

