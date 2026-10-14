void __fastcall tmpl_context_note(c1_tmpl_context_note *ctx)

{
  diag_note(ctx->note,ctx->position,ctx->sym);
  return;
}

