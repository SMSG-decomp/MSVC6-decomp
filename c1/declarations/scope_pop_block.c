void __fastcall scope_pop_block(c1_scope_stack *scopes)

{
  bool bVar1;
  
  bVar1 = (*scopes->current->vtbl->has_entries)(scopes->current);
  if (bVar1) {
    if (scopes->current != scopes->objects[scopes->depth]) {
      diag_fatal_simple(0x1fa);
    }
    scopes->objects[scopes->depth] = (c1_scope_object *)0x0;
    scopes->depth = scopes->depth + 0xff;
  }
  return;
}

