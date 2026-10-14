void __cdecl tmpl_set_definition_tokens(c1xx_token_stream *tokens,c1_symbol *tmpl)

{
  if (PTR_104d1600 == (c1_symtab *)0x0) {
    PTR_104d1600 = symtab_new(0x10,0,0xb,10,'\x01','\x01');
  }
  symtab_insert(PTR_104d1600,tmpl,tokens);
  return;
}

