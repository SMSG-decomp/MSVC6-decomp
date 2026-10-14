void __thiscall scope_insert_through_object(void *scopes,c1_symbol *sym)

{
  (**(code **)(**(int **)((int)scopes + 4) + 4))(sym);
  return;
}

