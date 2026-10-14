c1_u8 __fastcall decl_tag_parse_declspec(c1_tag_record *tag)

{
  if ((tag->name == (void *)0x0) && (tag->tag == (c1_tag_symbol *)0x0)) {
    decl_parse_declspec(&tag->words);
    return '\x01';
  }
  return '\0';
}

