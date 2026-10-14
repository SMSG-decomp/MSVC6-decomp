void __cdecl expr_set_overload_target_and_check_access(c1_symbol *sym,int target)

{
  if (sym != (c1_symbol *)0x0) {
    *(int *)(*(int *)sym->type + 8) = target;
    access_check_member(sym);
  }
  return;
}

