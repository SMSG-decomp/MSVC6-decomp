void * __fastcall scope_skip_prototype_scopes(c1_scope_stack *scopes)

{
  bool bVar1;
  c1_scope_object *scope;
  
  scope = scopes->current;
  bVar1 = false;
  if (scope->level == '\x01') {
    do {
      if (scopes->objects[scopes->depth] == scope) {
        bVar1 = true;
      }
      scope = scope->parent;
    } while (scope->level == '\x01');
    if (bVar1) {
      (*scope->vtbl->has_entries)(scope);
    }
  }
  return scope;
}

