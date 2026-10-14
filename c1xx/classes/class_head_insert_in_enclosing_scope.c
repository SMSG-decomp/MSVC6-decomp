void __thiscall class_head_insert_in_enclosing_scope(void *holder,c1_symbol *sym)

{
  int *piVar1;
  
  piVar1 = (int *)scope_parent_skipping_kind_fa(holder);
  (**(code **)(*piVar1 + 8))(sym);
  return;
}

