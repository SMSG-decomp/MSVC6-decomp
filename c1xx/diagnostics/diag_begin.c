void __thiscall diag_begin(c1_diag_context *ctx,int position)

{
  int iVar1;
  
  iVar1 = ctx->nesting + 1;
  ctx->nesting = iVar1;
  if (iVar1 == 1) {
    ctx->state = 1;
    if (position == 0) {
      position = g_token_position;
    }
    ctx->position = position;
    ctx->indent = 0;
  }
  return;
}

