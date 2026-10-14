void __fastcall cv_add_secrel_section_relocs(int offset,void *sym)

{
  coff_add_reloc_typed(offset,sym,0xb);
  coff_add_reloc_typed(offset + 4,sym,10);
  return;
}

