int __fastcall coff_section_linenum_bytes(c2_coff_section_out *sec)

{
  int iVar1;
  c2_coff_lineno_chunk *pcVar2;
  
  if (sec->nlines == 0) {
    return 0;
  }
  iVar1 = 0;
  pcVar2 = sec->lines;
  do {
    pcVar2 = pcVar2->last;
    iVar1 = iVar1 + pcVar2->count * 6;
  } while (pcVar2 != sec->lines);
  return iVar1;
}

