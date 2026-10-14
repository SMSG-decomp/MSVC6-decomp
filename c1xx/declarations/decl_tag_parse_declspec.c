c1_u8 __fastcall decl_tag_parse_declspec(void *tag)

{
  undefined4 unaff_EDI;
  
  if ((*(int *)tag == 0) && (*(int *)((int)tag + 4) == 0)) {
    decl_parse_declspec((byte *)((int)tag + 0x10),unaff_EDI);
    return '\x01';
  }
  return '\0';
}

