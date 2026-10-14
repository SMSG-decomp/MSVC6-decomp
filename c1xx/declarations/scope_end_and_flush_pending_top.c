void __cdecl scope_end_and_flush_pending_top(char end_scope)

{
  if (end_scope != '\0') {
    scope_end_block();
  }
  if (((PTR_104d2cb8 != (c1_vector *)0x0) && (PTR_104d2cb8->count != 0)) &&
     (PTR_104d2cb8->data[PTR_104d2cb8->count - 1] != (void *)0x0)) {
    il_emit_goto(*(c1_node **)((int)PTR_104d2cb8->data[PTR_104d2cb8->count - 1] + 0x10));
  }
  return;
}

