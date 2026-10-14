int __cdecl run_pass_list(int *passes,driver_ctx *ctx,run_pass_list_fn *fn)

{
  int pass;
  
  pass = *passes;
  do {
    if (pass == 5) {
      return g_exit_failed;
    }
    if ((g_passes[pass].flags & 1) != 0) {
      ctx->pass = g_passes + pass;
      g_passes[pass].flags = g_passes[pass].flags | 8;
      pass_resolve_program(ctx);
      g_exit_failed = (*fn)(ctx);
      if (g_exit_failed != 0) {
        return g_exit_failed;
      }
    }
    pass = passes[1];
    passes = passes + 1;
  } while( true );
}

