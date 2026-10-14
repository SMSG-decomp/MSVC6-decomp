int __fastcall coff_section_reloc_bytes(c2_coff_section_out *sec)

{
  int iVar1;
  c2_coff_reloc_chunk *pcVar2;
  
  if (sec->nrelocs == 0) {
    return 0;
  }
  iVar1 = 0;
  if (0xfffe < sec->nrelocs) {
    iVar1 = 10;
  }
  pcVar2 = sec->relocs;
  do {
    pcVar2 = pcVar2->last;
    iVar1 = iVar1 + pcVar2->count * 10;
  } while (pcVar2 != sec->relocs);
  return iVar1;
}

