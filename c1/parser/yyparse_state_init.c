void __fastcall yyparse_state_init(c1_yyparse_state *state)

{
  state->vsp = (c1_yystype *)state;
  state->lookahead = (c1_token *)0x0;
  state->state = 0;
  state->errflag = 0;
  state->nerrs = 0;
  state->ssp = (short *)((int)state->vs + 0x5ffe);
  return;
}

