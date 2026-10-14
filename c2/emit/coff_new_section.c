uint16_t __fastcall coff_new_section(char *name,uint32_t characteristics,int comdat,int reuse)

{
  c2_coff_section *pcVar1;
  c2_coff_list *list;
  c2_coff_section *desc;
  uint32_t uVar2;
  
  if (((reuse != 0) && (-1 < g_coff_reuse_section_index)) &&
     (pcVar1 = g_coff_reuse_sections[g_coff_reuse_section_index], pcVar1 != (c2_coff_section *)0x0))
  {
    g_coff_reuse_section_index = g_coff_reuse_section_index + 1;
    if (comdat != 0) {
      *(byte *)&pcVar1->flags = (byte)pcVar1->flags | 8;
    }
    pcVar1->signature = 0;
    pcVar1->fn_signature = 0;
    pcVar1->name = name;
    pcVar1->characteristics = characteristics;
    return pcVar1->number;
  }
  desc = (*g_coff_alloc_fn)(0x20);
  if (comdat != 0) {
    *(byte *)&desc->flags = (byte)desc->flags | 8;
  }
  list = g_coff_sections;
  desc->characteristics = characteristics;
  uVar2 = coff_list_append(list,desc);
  desc->number = (uint16_t)uVar2;
  desc->name = name;
  desc->signature = 0;
  desc->fn_signature = 0;
  return (uint16_t)uVar2;
}

