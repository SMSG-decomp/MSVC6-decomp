c1_u8 __thiscall decl_tag_take_name(c1_tag_record *tag,c1_token *token)

{
  if ((tag->name == (void *)0x0) && (tag->tag == (c1_tag_symbol *)0x0)) {
    tag->unk08 = (c1_u32)token;
    tag->name = (token->value).ptr;
    return '\x01';
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
  tag->name_pending = '\0';
  return '\0';
}

