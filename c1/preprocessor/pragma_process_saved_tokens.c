int __cdecl pragma_process_saved_tokens(c1_token *token)

{
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  c1_declaration *stream;
  int iVar3;
  
  stream = (token->value).decl;
  (**(code **)((int)stream->name + 0x14))();
  token_source_push(&g_token_position,(int)stream,7,0,0,&g_token_position);
  iVar3 = pragma_dispatch();
  pragma_expect_dash_token();
  if (g_token_source != (c1_token_source_frame *)0x0) {
    ppcVar1 = &g_token_source->prev;
    g_token_position = g_token_source->position;
    pp_Var2 = &g_token_source->on_pop;
    g_token_source = *ppcVar1;
    if (*pp_Var2 != (_func_240 *)0x0) {
      (**pp_Var2)();
    }
  }
  return iVar3;
}

