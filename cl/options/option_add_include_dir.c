void __cdecl option_add_include_dir(char *dir,optdesc *idesc)

{
  size_t blanks;
  size_t len;
  optrec *user;
  char *full;
  char *p;
  char *p_2;
  optrec *pass_recs;
  int index;
  cl_optrec *pr;
  
  blanks = _mbsspn((uchar *)dir,(uchar *)" \t");
  len = strlen(dir);
  if (blanks < len) {
    index = 0;
    g_include_argv[1] = dir;
    user = option_match_and_take_argument(idesc,g_include_argv,&index);
    if (g_enc != 0) {
      full = xmalloc(0x400);
      p = path_full(full,user->value,0x400);
      if (p != (char *)0x0) {
        xfree(user->value);
        p_2 = xstrdup(full);
        user->value = p_2;
      }
      xfree(full);
    }
    (user->src).desc = idesc;
    list_append(&g_driver_ctx_ptr->user_options,user);
    pass_recs = action_parse_list(idesc->actions,user);
    for (pr = pass_recs; pr != (cl_optrec *)0x0; pr = pr->next) {
      (pr->src).owner = user;
      user->refcount = user->refcount + '\x01';
    }
    list_append(&g_driver_ctx_ptr->pass_options,pass_recs);
  }
  return;
}

