uint32_t __fastcall coff_section_symbol_index(uint32_t n)

{
  int *piVar1;
  
  if (g_coff_section_numbers_final != 0) {
    piVar1 = coff_chunked_array_get(g_coff_sections,n);
    return (uint)*(ushort *)(*piVar1 + 0x30);
  }
  piVar1 = coff_chunked_array_get(g_coff_sections,n);
  return -(uint)*(ushort *)(*piVar1 + 0x30) - 2;
}

