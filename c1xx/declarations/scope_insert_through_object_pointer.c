void __thiscall scope_insert_through_object_pointer(void **holder,c1_symbol *sym)

{
  (**(code **)(*(int *)*holder + 8))(sym);
  return;
}

