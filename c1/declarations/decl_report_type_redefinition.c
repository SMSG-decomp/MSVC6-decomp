c1_tag_symbol * __cdecl decl_report_type_redefinition(c1_tag_symbol *tag)

{
  diag_error(0xb,tag,tag->type);
  tag->flags2 = tag->flags2 | 1;
  return tag;
}

