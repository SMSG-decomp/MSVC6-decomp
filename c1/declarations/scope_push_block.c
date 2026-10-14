void __thiscall scope_push_block(c1_scope_stack *scopes,c1_scope_object *block)

{
  bool bVar1;
  byte bVar2;
  
  if (scopes->objects[scopes->depth] != block) {
    bVar1 = (*block->vtbl->has_entries)(block);
    if (bVar1) {
      bVar2 = scopes->depth + 1;
      scopes->depth = bVar2;
      if (0x7f < bVar2) {
        diag_fatal_simple(0x3d);
      }
      scopes->objects[scopes->depth] = block;
    }
  }
  return;
}

