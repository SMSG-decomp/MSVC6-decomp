int __fastcall coff_symbol_value(uint16_t section)

{
  int *piVar1;
  
  piVar1 = coff_chunked_array_get(g_coff_sections,(uint)section);
  return *(int *)(*piVar1 + 8);
}

