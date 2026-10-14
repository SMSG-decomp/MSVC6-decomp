c1_symtab * __cdecl class_ensure_copy_ctor_closure_table(void)

{
  if (g_copy_ctor_closure_table == (c1_symtab *)0x0) {
    g_copy_ctor_closure_table = symtab_new(0x1f,0,0,0,'\x01','\x01');
  }
  return g_copy_ctor_closure_table;
}

