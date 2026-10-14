void __cdecl decl_tag_copy_specifier_flags(c1_tag_symbol *tag,c1_specifier_words *specifier)

{
  byte bVar1;
  
  if ((specifier->declspec & 0xc) != 0) {
    bVar1 = (tag->flags22 ^ specifier->declspec) & 4 ^ tag->flags22;
    tag->flags22 = bVar1;
    tag->flags22 = (bVar1 ^ specifier->declspec) & 8 ^ bVar1;
  }
  return;
}

