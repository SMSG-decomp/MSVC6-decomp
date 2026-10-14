void __cdecl pch_relocate_global_tables(void)

{
  c1_pch_relocator *ppcVar1;
  
  ppcVar1 = g_pch_relocation_table;
  do {
    (**ppcVar1)();
    if (g_abort_requested != 0) {
      c1_abort_if_running();
    }
    ppcVar1 = ppcVar1 + 1;
  } while ((int)ppcVar1 < 0x1065b16c);
  return;
}

