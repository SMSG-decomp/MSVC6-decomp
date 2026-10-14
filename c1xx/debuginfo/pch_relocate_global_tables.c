void __cdecl pch_relocate_global_tables(void)

{
  void **entry_cell;
  
  entry_cell = &g_pch_relocation_table;
  do {
    (**entry_cell)();
    if (g_abort_requested != 0) {
      c1xx_abort_if_running();
    }
    entry_cell = entry_cell + 1;
  } while ((int)entry_cell < 0x104cae7c);
  return;
}

