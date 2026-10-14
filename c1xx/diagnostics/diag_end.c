int __fastcall diag_end(c1_diag_context *ctx)

{
  int iVar1;
  
  if (ctx->nesting == 1) {
    if (ctx->state == 2) {
      ctx->state = 4;
      diag_queue_release_pending((int *)ctx);
      diag_run_context_notes(ctx);
    }
    arena_reset_ptr(g_arenas + 9);
    ctx->state = 0;
  }
  iVar1 = ctx->nesting + -1;
  ctx->nesting = iVar1;
  return iVar1;
}

