void __fastcall coff_section_set_flags(uint16_t section,uint32_t characteristics)

{
  void *pvVar1;
  
  pvVar1 = coff_chunked_array_get(g_coff_sections,(uint)section);
  *(uint *)((int)pvVar1 + 8) = *(uint *)((int)pvVar1 + 8) | characteristics;
  return;
}

