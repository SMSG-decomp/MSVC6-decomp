bool __fastcall scope_has_entries(c1_scope_object *scope)

{
  return (scope->entries).buckets != (void **)0x0;
}

