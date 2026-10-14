void __cdecl decl_merge_redeclaration_fragment(char allocate_bit,c1_u8 flags22,c1_symbol *sym)

{
  if ((flags22 & 4) == 0) {
    sym->flags22 = flags22 | 8;
    sym->flags1 = sym->flags1 & 0xfd;
    return;
  }
  if (allocate_bit != '\0') {
    sym->flags1 = sym->flags1 & 0xfd;
  }
  return;
}

