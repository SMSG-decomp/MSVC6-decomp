void __cdecl pass_resolve_program(driver_ctx *ctx)

{
  char *s;
  int diff;
  size_t len;
  char *t_2;
  char *dll_path;
  size_t len_2;
  char *s_2;
  char *t;
  char *s_3;
  char *pcVar1;
  char ext [256];
  uint dll_where;
  uint exe_where;
  uint where;
  char *exe_path;
  cl_pass *pass;
  char *s_4;
  
  pass = ctx->pass;
  if ((pass->flags & 2) != 0) {
    return;
  }
  pass->flags = pass->flags | 2;
  s = path_search_program(ctx->cl_dir,pass->program,&where);
  if (where != 0) {
    _splitpath(s,(char *)0x0,(char *)0x0,(char *)0x0,ext);
    diff = _stricmp(ext,".dll");
    if (diff == 0) {
      pass->flags = pass->flags | 4;
    }
    goto LAB_0040349c;
  }
  xfree(s);
  len = strlen(pass->program);
  t_2 = xmalloc(len + 5);
  strcpy(t_2,pass->program);
  strcat(t_2,".dll");
  dll_path = path_search_program(ctx->cl_dir,t_2,&dll_where);
  s_4 = ".exe";
  len_2 = strlen(t_2);
  strcpy(t_2 + (len_2 - 4),s_4);
  exe_path = path_search_program(ctx->cl_dir,t_2,&exe_where);
  pcVar1 = dll_path;
  if (dll_where == 0) {
    if (exe_where != 0) goto LAB_0040348c;
    xfree(dll_path);
    xfree(exe_path);
    exe_path = xstrdup(pass->program);
  }
  else {
    if ((exe_where == 0) || ((int)dll_where <= (int)exe_where)) {
      pass->flags = pass->flags | 4;
      pcVar1 = exe_path;
      exe_path = dll_path;
    }
LAB_0040348c:
    xfree(pcVar1);
  }
  xfree(t_2);
  s = exe_path;
LAB_0040349c:
  pass->program = s;
  if (pass->extra != (char *)0x0) {
    s_2 = path_directory_of(s);
    t = path_search_program(s_2,pass->extra,&where);
    pass->extra = t;
    xfree(s_2);
  }
  if (pass->host != (char *)0x0) {
    s_3 = path_search_program(ctx->cl_dir,pass->host,&where);
    pass->host = s_3;
  }
  return;
}

