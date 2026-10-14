void __cdecl
tmpl_record_definition
          (c1_symbol *tmpl,c1_sym_list *params,c1xx_token_stream *decl_tokens,
          c1xx_token_stream *body_tokens)

{
  tmpl_set_parameter_list(params,tmpl);
  tmpl_definition_table_insert(decl_tokens,tmpl);
  if (body_tokens != (c1xx_token_stream *)0x0) {
    tmpl_set_definition_tokens(body_tokens,tmpl);
  }
  return;
}

