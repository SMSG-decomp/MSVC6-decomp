void __cdecl temp_prefix_create(driver_ctx *ctx)

{
  char *prefix;
  size_t len;
  char *prefix_2;
  char *prefix_3;
  char dir [1024];
  char last;
  
  if (ctx->temp_prefix == (char *)0x0) {
    prefix = getenv("TMP");
    if (prefix == (char *)0x0) {
      prefix_2 = xstrdup("XXXXXX");
    }
    else {
      strcpy(dir,prefix);
      len = strlen(dir);
      last = dir[len - 1];
      if (((last != '\\') && (last != ':')) && (last != '/')) {
        dir[len] = '\\';
        dir[len + 1] = '\0';
      }
      prefix_2 = str_concat_new(dir,"XXXXXX");
    }
    ctx->temp_prefix = prefix_2;
    prefix_3 = _mktemp(prefix_2);
    ctx->temp_prefix = prefix_3;
  }
  else {
    g_batch_allowed = 0;
  }
  return;
}

