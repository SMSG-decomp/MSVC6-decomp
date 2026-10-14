void __cdecl global_helper_name_plain(void)

{
  short sVar1;
  fe_name *pfVar2;
  
  sVar1 = g_block_number;
  g_block_number = 2;
  (PTR_104d1b38->x28).block_number = 2;
  PTR_104d1b38->flags1 = PTR_104d1b38->flags1 & 0xfc;
  pfVar2 = name_intern_symbol_decorated(PTR_104d1b38);
  PTR_104d1b38->name = pfVar2;
  PTR_104d1b38->flags1 = PTR_104d1b38->flags1 & 0xfe | 2;
  g_block_number = sVar1;
  return;
}

