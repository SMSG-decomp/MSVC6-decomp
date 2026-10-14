void __cdecl class_check_base_of_symbol(int p1,int p2,c1_symbol *sym,int p4)

{
  if (sym == (c1_symbol *)0x0) {
    return;
  }
  class_check_base_class(p1,(char)p2,*(c1_symbol **)(*(int *)sym->type + 8));
  return;
}

