c1_deferred_parse * __thiscall
tmpl_instantiation_context_init
          (c1_deferred_parse *rec,c1_symbol *fn,c1_type **param_type,c1_node *default_arg,
          c1_deferred_parse *prev)

{
  c1xx_token_stream *stream;
  c1_function_params *params;
  
  rec->prev = prev;
  rec->fn = fn;
  rec->keep_state = '\x01';
  rec->parse_pending = '\x01';
  rec->set_cc_10 = '\0';
  params = (fn->type->extra).params;
  rec->params = params;
  rec->last_default = params->defaults->link;
  rec->default_arg = default_arg;
  rec->param_type = param_type;
  rec->saved_tokens = default_arg->left;
  if ((g_compile_flags_cc & 0x10) == 0) {
    rec->set_cc_10 = '\x01';
    g_compile_flags_cc = g_compile_flags_cc | 0x10;
  }
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  stream = rec->saved_tokens->left;
  rec->stream = stream;
  (*stream->vtbl->start)(stream);
  token_source_push((c1_token_reader *)&g_token_position,rec->stream,10,0,(void *)0x0,
                    &g_token_position);
  return rec;
}

