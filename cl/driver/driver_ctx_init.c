void __cdecl driver_ctx_init(char *argv0,driver_ctx *ctx)

{
  char *dir;
  
  memset(ctx,0,0x28);
  dir = path_directory_of(argv0);
  ctx->cl_dir = dir;
  return;
}

